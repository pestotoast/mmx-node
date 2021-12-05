/**
Copyright 2018 Chia Network Inc

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
***/

#ifndef INLUDE_MMX_NODE_VDF_VDF_H_
#define INLUDE_MMX_NODE_VDF_VDF_H_

#include <chiavdf/src/include.h>
#include <chiavdf/src/picosha2.h>
#include <chiavdf/src/parameters.h>
#include <chiavdf/src/integer.h>
#include <chiavdf/src/vdf_new.h>
#include <chiavdf/src/nucomp.h>
#include <chiavdf/src/proof_common.h>
#include <chiavdf/src/vdf_original.h>
#include <chiavdf/src/create_discriminant.h>
#include <chiavdf/src/util.h>
#include <chiavdf/src/verifier.h>

#include <vdf/provers.h>


//always works
inline
void repeated_square_original(vdf_original &vdfo, form& f, const integer& D, const integer& L, uint64 base, uint64 iterations, INUDUPLListener *nuduplListener) {
    vdf_original::form f_in,*f_res;
    f_in.a[0]=f.a.impl[0];
    f_in.b[0]=f.b.impl[0];
    f_in.c[0]=f.c.impl[0];
    f_res=&f_in;

    for (uint64_t i=0; i < iterations; i++) {
        f_res = vdfo.square(*f_res);

        if(nuduplListener!=NULL)
            nuduplListener->OnIteration(NL_FORM,f_res,base+i);
    }

    mpz_set(f.a.impl, f_res->a);
    mpz_set(f.b.impl, f_res->b);
    mpz_set(f.c.impl, f_res->c);
}

inline
Proof ProveOneWesolowski(uint64_t iters, integer& D, form f, OneWesolowskiCallback* weso, std::atomic<bool>& stopped)
{
    Segment sg(
        /*start=*/0,
        /*length=*/iters,
        /*x=*/f,
        /*y=*/weso->result
    );
    OneWesolowskiProver prover(sg, D, weso->forms.get(), stopped);
    prover.start();

    int d_bits = D.num_bits();
    std::vector<unsigned char> y_serialized;
    std::vector<unsigned char> proof_serialized;
    y_serialized = SerializeForm(weso->result, d_bits);
    form proof_form = prover.GetProof();
    proof_serialized = SerializeForm(proof_form, d_bits);
    Proof proof(y_serialized, proof_serialized);
    proof.witness_type = 0;
    return proof;
}

inline
Proof ProveTwoWeso(integer& D, form x, uint64_t iters, uint64_t done_iterations,
    TwoWesolowskiCallback* weso, int depth, std::atomic<bool>& stop_signal)
{
    integer L=root(-D, 4);
    if (depth == 2) {
        if (stop_signal)
            return Proof();

        vdf_original vdfo_proof;
        uint64 checkpoint = (done_iterations + iters) - (done_iterations + iters) % 100;
        form y = *(weso->GetForm(checkpoint));
        repeated_square_original(vdfo_proof, y, D, L, 0, (done_iterations + iters) % 100, NULL);

        Segment sg(
            /*start=*/done_iterations,
            /*length=*/iters,
            /*x=*/x,
            /*y=*/y
        );
        TwoWesolowskiProver prover(sg, D, weso, stop_signal);
        prover.GenerateProof();

        if (stop_signal)
            return Proof();
        form proof = prover.GetProof();

        int d_bits = D.num_bits();
        std::vector<unsigned char> y_bytes = SerializeForm(y, d_bits);
        std::vector<unsigned char> proof_bytes = SerializeForm(proof, d_bits);
        Proof final_proof=Proof(y_bytes, proof_bytes);
        return final_proof;
    }

    uint64_t iterations1, iterations2;
    iterations1 = iters * 2 / 3;
    iterations1 = iterations1 - iterations1 % 100;
    iterations2 = iters - iterations1;
    if (stop_signal)
        return Proof();

    form y1 = *(weso->GetForm(done_iterations + iterations1));
    Segment sg(
        /*start=*/done_iterations,
        /*lenght=*/iterations1,
        /*x=*/x,
        /*y=*/y1
    );
    TwoWesolowskiProver prover(sg, D, weso, stop_signal);
    prover.start();
    Proof proof2 = ProveTwoWeso(D, y1, iterations2, done_iterations + iterations1, weso, depth + 1, stop_signal);

    while (!stop_signal && !prover.IsFinished()) {
        std::this_thread::sleep_for (std::chrono::milliseconds(10));
    }
    if (stop_signal)
        return Proof();
    form proof = prover.GetProof();

    int d_bits = D.num_bits();
    Proof final_proof;
    final_proof.y = proof2.y;

    uint8_t bytes[8];
    Int64ToBytes(bytes, iterations1);
    std::vector<uint8_t> proof_bytes(proof2.proof);

    VectorAppendArray(proof_bytes, bytes, sizeof(bytes));
    VectorAppend(proof_bytes, GetB(D, x, y1).to_bytes());
    VectorAppend(proof_bytes, SerializeForm(proof, d_bits));
    final_proof.proof = proof_bytes;
    if (depth == 0) {
        final_proof.witness_type = 2;
    }
    return final_proof;
}



#endif /* INLUDE_MMX_NODE_VDF_VDF_H_ */

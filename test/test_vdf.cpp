/*
 * test_vdf.cpp
 *
 *  Created on: Dec 5, 2021
 *      Author: mad
 */

#include <mmx/ProofOfTime.hxx>
#include <vnx/vnx.h>

#include <vdf/vdf.h>

#include <iostream>



int main(int argc, char** argv)
{
	assert(fesetround(FE_TOWARDZERO) == 0); //truncated rounding

	uint64_t num_iters = 200 * 1000;
	std::vector<uint8_t> seed(32);

	integer D = CreateDiscriminant(seed);
	integer L = root(-D, 4);

	form x = form::generator(D);

	OneWesolowskiCallback callback(D, x, num_iters);
//	TwoWesolowskiCallback callback(D, x);

	std::cout << "D = " << D.to_string() << std::endl;
	std::cout << "L = " << L.to_string() << std::endl;
	std::cout << "x = {" << x.a.to_string() << ", " << x.b.to_string() << ", " << x.c.to_string() << "}" << std::endl;
	std::cout << "kl = " << callback.kl << std::endl;

	form y = x;
	PulmarkReducer reducer;
	std::atomic<bool> stopped {false};

	const auto vdf_begin = vnx::get_wall_time_micros();

	for(uint64_t i = 0; i < num_iters; i++)
	{
		nudupl_form(y, y, D, L);

		if(i % 100 == 0 && i > 0) {
			reducer.reduce(y);
		}
		callback.OnIteration(NL_FORM, &y, i);
	}
//	vdf_original vdfo;
//	repeated_square_original(vdfo, y, D, L, 0, num_iters, &callback);

	std::cout << "VDF took " << (vnx::get_wall_time_micros() - vdf_begin) / 1000 << " ms" << std::endl;

	std::cout << "y = {" << y.a.to_string() << ", " << y.b.to_string() << ", " << y.c.to_string() << "}" << std::endl;

	const auto proof_begin = vnx::get_wall_time_micros();

	const auto proof = ProveOneWesolowski(num_iters, D, y, &callback, stopped);
//	const auto proof = ProveTwoWeso(D, y, num_iters, 0, &callback, 0, stopped);

	std::cout << "Proof took " << (vnx::get_wall_time_micros() - proof_begin) / 1000 << " ms" << std::endl;

	std::cout << "proof.y.size() = " << proof.y.size() << std::endl;
	std::cout << "proof.proof.size() = " << proof.proof.size() << std::endl;

	const auto x_s = SerializeForm(x, D.num_bits());

	std::vector<unsigned char> bytes;
    bytes.insert(bytes.end(), proof.y.begin(), proof.y.end());
    bytes.insert(bytes.end(), proof.proof.begin(), proof.proof.end());

	const auto verify_begin = vnx::get_wall_time_micros();

	form proof_y = DeserializeForm(D, proof.y.data(), proof.y.size());
    form proof_form = DeserializeForm(D, proof.proof.data(), proof.proof.size());

    bool is_valid = false;
	VerifyWesolowskiProof(D, x, proof_y, proof_form, num_iters, is_valid);
	if(!is_valid) {
		std::cout << "VerifyWesolowskiProof() failed!" << std::endl;
	}
//	if(!CheckProofOfTimeNWesolowski(D, DEFAULT_ELEMENT, bytes.data(), bytes.size(), num_iters, proof.witness_type)) {
//		std::cout << "CheckProofOfTimeNWesolowski() failed!" << std::endl;
//	}

	std::cout << "Verify took " << (vnx::get_wall_time_micros() - verify_begin) / 1000 << " ms" << std::endl;

	return 0;
}


#ifndef CALLBACK_H
#define CALLBACK_H

#define NL_SQUARESTATE 1
#define NL_FORM 2

// Applies to n-weso.
const int kWindowSize = 20;

// Applies only to 2-weso.
const int kMaxItersAllowed = 8e8;
const int kSwitchIters = 91000000;


class INUDUPLListener{
public:
    virtual void OnIteration(int type, void *data, uint64 iteration)=0;
};

class WesolowskiCallback :public INUDUPLListener {
public:
    WesolowskiCallback(integer& D) {
        vdfo = new vdf_original();
        reducer = new PulmarkReducer();
        this->D = D;
        this->L = root(-D, 4);
    }

    virtual ~WesolowskiCallback() {
        delete(vdfo);
        delete(reducer);
    }

    void reduce(form& inf) {
        reducer->reduce(inf);
    }

    void SetForm(int type, void *data, form* mulf, bool reduced = false) {
        switch(type) {
            case NL_FORM:
            {
                //cout << "NL_FORM" << endl;

                vdf_original::form *f=(vdf_original::form *)data;

                mpz_set(mulf->a.impl, f->a);
                mpz_set(mulf->b.impl, f->b);
                mpz_set(mulf->c.impl, f->c);
                break;
            }
            default:
                cout << "Unknown case" << endl;
        }
        if (reduced) {
            reduce(*mulf);
        }
    }

    virtual void OnIteration(int type, void *data, uint64_t iteration) = 0;

    std::unique_ptr<form[]> forms;
    std::atomic<int64_t> iterations{0};
    integer D;
    integer L;
    PulmarkReducer* reducer;
    vdf_original* vdfo;
};

class OneWesolowskiCallback: public WesolowskiCallback {
  public:
    OneWesolowskiCallback(integer& D, form& f, uint64_t wanted_iter) : WesolowskiCallback(D) {
        uint32_t k, l;
        this->wanted_iter = wanted_iter;
        if (wanted_iter >= (1 << 16)) {
            ApproximateParameters(wanted_iter, k, l);
        } else {
            k = 10;
            l = 1;
        }
        kl = k * l;
        uint64_t space_needed = wanted_iter / (k * l) + 100;
        forms.reset(new form[space_needed]);
        forms[0] = f;
    }

    void OnIteration(int type, void *data, uint64_t iteration) {
        iteration++;
        if (iteration > wanted_iter) 
            return ;

        if (iteration % kl == 0) {
            uint64_t pos = iteration / kl;
            form* mulf = &forms[pos];
            SetForm(type, data, mulf);
        }
        if (iteration == wanted_iter) {
            SetForm(type, data, &result);
        }
    }

    uint64_t wanted_iter;
    uint32_t kl;
    form result;
};

class TwoWesolowskiCallback: public WesolowskiCallback {
  public:
    TwoWesolowskiCallback(integer& D, form f) : WesolowskiCallback(D) {
        int space_needed = kSwitchIters / 10 + (kMaxItersAllowed - kSwitchIters) / 100;
        forms.reset(new form[space_needed]);
        forms[0] = f;
        kl = 10;
    }

    int GetPosition(uint64_t power) {
        return power / 10;
    }

    form *GetForm(uint64_t power) {
        return &(forms[GetPosition(power)]);
    }

    void OnIteration(int type, void *data, uint64_t iteration) {
        iteration++;
        if (iteration % kl == 0) {
            uint64_t pos = GetPosition(iteration);
            form* mulf = &forms[pos];
            SetForm(type, data, mulf);
        }
    }

    uint32_t kl;
};


#endif // CALLBACK_H

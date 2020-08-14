// Generated by rstantools.  Do not edit by hand.

/*
    bsem is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    bsem is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with bsem.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_factorialNA_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_factorialNA");
    reader.add_event(58, 56, "end", "model_factorialNA");
    return reader;
}
#include <stan_meta_header.hpp>
class model_factorialNA
  : public stan::model::model_base_crtp<model_factorialNA> {
private:
        int K;
        int Nv;
        int Ne;
        int Nob;
        int Nna;
        matrix_d X;
        std::vector<std::vector<int> > idob;
        std::vector<std::vector<int> > idna;
        matrix_d v;
        std::vector<double> dsigma2;
        std::vector<double> a;
        std::vector<double> b;
public:
    model_factorialNA(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_factorialNA(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_factorialNA_namespace::model_factorialNA";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "K", "int", context__.to_vec());
            K = int(0);
            vals_i__ = context__.vals_i("K");
            pos__ = 0;
            K = vals_i__[pos__++];
            check_greater_or_equal(function__, "K", K, 1);
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "Nv", "int", context__.to_vec());
            Nv = int(0);
            vals_i__ = context__.vals_i("Nv");
            pos__ = 0;
            Nv = vals_i__[pos__++];
            check_greater_or_equal(function__, "Nv", Nv, 1);
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "Ne", "int", context__.to_vec());
            Ne = int(0);
            vals_i__ = context__.vals_i("Ne");
            pos__ = 0;
            Ne = vals_i__[pos__++];
            check_greater_or_equal(function__, "Ne", Ne, 1);
            current_statement_begin__ = 5;
            context__.validate_dims("data initialization", "Nob", "int", context__.to_vec());
            Nob = int(0);
            vals_i__ = context__.vals_i("Nob");
            pos__ = 0;
            Nob = vals_i__[pos__++];
            check_greater_or_equal(function__, "Nob", Nob, 1);
            current_statement_begin__ = 6;
            context__.validate_dims("data initialization", "Nna", "int", context__.to_vec());
            Nna = int(0);
            vals_i__ = context__.vals_i("Nna");
            pos__ = 0;
            Nna = vals_i__[pos__++];
            check_greater_or_equal(function__, "Nna", Nna, 1);
            current_statement_begin__ = 7;
            validate_non_negative_index("X", "Nv", Nv);
            validate_non_negative_index("X", "Ne", Ne);
            context__.validate_dims("data initialization", "X", "matrix_d", context__.to_vec(Nv,Ne));
            X = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(Nv, Ne);
            vals_r__ = context__.vals_r("X");
            pos__ = 0;
            size_t X_j_2_max__ = Ne;
            size_t X_j_1_max__ = Nv;
            for (size_t j_2__ = 0; j_2__ < X_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < X_j_1_max__; ++j_1__) {
                    X(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            current_statement_begin__ = 8;
            validate_non_negative_index("idob", "Nob", Nob);
            validate_non_negative_index("idob", "2", 2);
            context__.validate_dims("data initialization", "idob", "int", context__.to_vec(Nob,2));
            idob = std::vector<std::vector<int> >(Nob, std::vector<int>(2, int(0)));
            vals_i__ = context__.vals_i("idob");
            pos__ = 0;
            size_t idob_k_0_max__ = Nob;
            size_t idob_k_1_max__ = 2;
            for (size_t k_1__ = 0; k_1__ < idob_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < idob_k_0_max__; ++k_0__) {
                    idob[k_0__][k_1__] = vals_i__[pos__++];
                }
            }
            size_t idob_i_0_max__ = Nob;
            size_t idob_i_1_max__ = 2;
            for (size_t i_0__ = 0; i_0__ < idob_i_0_max__; ++i_0__) {
                for (size_t i_1__ = 0; i_1__ < idob_i_1_max__; ++i_1__) {
                    check_greater_or_equal(function__, "idob[i_0__][i_1__]", idob[i_0__][i_1__], 1);
                }
            }
            current_statement_begin__ = 9;
            validate_non_negative_index("idna", "Nna", Nna);
            validate_non_negative_index("idna", "2", 2);
            context__.validate_dims("data initialization", "idna", "int", context__.to_vec(Nna,2));
            idna = std::vector<std::vector<int> >(Nna, std::vector<int>(2, int(0)));
            vals_i__ = context__.vals_i("idna");
            pos__ = 0;
            size_t idna_k_0_max__ = Nna;
            size_t idna_k_1_max__ = 2;
            for (size_t k_1__ = 0; k_1__ < idna_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < idna_k_0_max__; ++k_0__) {
                    idna[k_0__][k_1__] = vals_i__[pos__++];
                }
            }
            size_t idna_i_0_max__ = Nna;
            size_t idna_i_1_max__ = 2;
            for (size_t i_0__ = 0; i_0__ < idna_i_0_max__; ++i_0__) {
                for (size_t i_1__ = 0; i_1__ < idna_i_1_max__; ++i_1__) {
                    check_greater_or_equal(function__, "idna[i_0__][i_1__]", idna[i_0__][i_1__], 1);
                }
            }
            current_statement_begin__ = 10;
            validate_non_negative_index("v", "Nv", Nv);
            validate_non_negative_index("v", "K", K);
            context__.validate_dims("data initialization", "v", "matrix_d", context__.to_vec(Nv,K));
            v = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(Nv, K);
            vals_r__ = context__.vals_r("v");
            pos__ = 0;
            size_t v_j_2_max__ = K;
            size_t v_j_1_max__ = Nv;
            for (size_t j_2__ = 0; j_2__ < v_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < v_j_1_max__; ++j_1__) {
                    v(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            check_greater_or_equal(function__, "v", v, 0);
            current_statement_begin__ = 12;
            validate_non_negative_index("dsigma2", "Nv", Nv);
            context__.validate_dims("data initialization", "dsigma2", "double", context__.to_vec(Nv));
            dsigma2 = std::vector<double>(Nv, double(0));
            vals_r__ = context__.vals_r("dsigma2");
            pos__ = 0;
            size_t dsigma2_k_0_max__ = Nv;
            for (size_t k_0__ = 0; k_0__ < dsigma2_k_0_max__; ++k_0__) {
                dsigma2[k_0__] = vals_r__[pos__++];
            }
            size_t dsigma2_i_0_max__ = Nv;
            for (size_t i_0__ = 0; i_0__ < dsigma2_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "dsigma2[i_0__]", dsigma2[i_0__], 0);
            }
            current_statement_begin__ = 13;
            validate_non_negative_index("a", "Nv", Nv);
            context__.validate_dims("data initialization", "a", "double", context__.to_vec(Nv));
            a = std::vector<double>(Nv, double(0));
            vals_r__ = context__.vals_r("a");
            pos__ = 0;
            size_t a_k_0_max__ = Nv;
            for (size_t k_0__ = 0; k_0__ < a_k_0_max__; ++k_0__) {
                a[k_0__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 14;
            validate_non_negative_index("b", "Nv", Nv);
            context__.validate_dims("data initialization", "b", "double", context__.to_vec(Nv));
            b = std::vector<double>(Nv, double(0));
            vals_r__ = context__.vals_r("b");
            pos__ = 0;
            size_t b_k_0_max__ = Nv;
            for (size_t k_0__ = 0; k_0__ < b_k_0_max__; ++k_0__) {
                b[k_0__] = vals_r__[pos__++];
            }
            size_t b_i_0_max__ = Nv;
            for (size_t i_0__ = 0; i_0__ < b_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "b[i_0__]", b[i_0__], 0);
            }
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 18;
            validate_non_negative_index("alpha", "Nv", Nv);
            validate_non_negative_index("alpha", "K", K);
            num_params_r__ += (Nv * K);
            current_statement_begin__ = 19;
            validate_non_negative_index("lambda", "K", K);
            validate_non_negative_index("lambda", "Ne", Ne);
            num_params_r__ += (K * Ne);
            current_statement_begin__ = 20;
            validate_non_negative_index("sigma2", "Nv", Nv);
            num_params_r__ += Nv;
            current_statement_begin__ = 21;
            validate_non_negative_index("Xna", "Nna", Nna);
            num_params_r__ += Nna;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_factorialNA() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 18;
        if (!(context__.contains_r("alpha")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable alpha missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("alpha");
        pos__ = 0U;
        validate_non_negative_index("alpha", "Nv", Nv);
        validate_non_negative_index("alpha", "K", K);
        context__.validate_dims("parameter initialization", "alpha", "matrix_d", context__.to_vec(Nv,K));
        Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> alpha(Nv, K);
        size_t alpha_j_2_max__ = K;
        size_t alpha_j_1_max__ = Nv;
        for (size_t j_2__ = 0; j_2__ < alpha_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
                alpha(j_1__, j_2__) = vals_r__[pos__++];
            }
        }
        try {
            writer__.matrix_unconstrain(alpha);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable alpha: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 19;
        if (!(context__.contains_r("lambda")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable lambda missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("lambda");
        pos__ = 0U;
        validate_non_negative_index("lambda", "K", K);
        validate_non_negative_index("lambda", "Ne", Ne);
        context__.validate_dims("parameter initialization", "lambda", "matrix_d", context__.to_vec(K,Ne));
        Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> lambda(K, Ne);
        size_t lambda_j_2_max__ = Ne;
        size_t lambda_j_1_max__ = K;
        for (size_t j_2__ = 0; j_2__ < lambda_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < lambda_j_1_max__; ++j_1__) {
                lambda(j_1__, j_2__) = vals_r__[pos__++];
            }
        }
        try {
            writer__.matrix_unconstrain(lambda);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable lambda: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 20;
        if (!(context__.contains_r("sigma2")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigma2 missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigma2");
        pos__ = 0U;
        validate_non_negative_index("sigma2", "Nv", Nv);
        context__.validate_dims("parameter initialization", "sigma2", "vector_d", context__.to_vec(Nv));
        Eigen::Matrix<double, Eigen::Dynamic, 1> sigma2(Nv);
        size_t sigma2_j_1_max__ = Nv;
        for (size_t j_1__ = 0; j_1__ < sigma2_j_1_max__; ++j_1__) {
            sigma2(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_lb_unconstrain(0, sigma2);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigma2: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 21;
        if (!(context__.contains_r("Xna")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable Xna missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("Xna");
        pos__ = 0U;
        validate_non_negative_index("Xna", "Nna", Nna);
        context__.validate_dims("parameter initialization", "Xna", "vector_d", context__.to_vec(Nna));
        Eigen::Matrix<double, Eigen::Dynamic, 1> Xna(Nna);
        size_t Xna_j_1_max__ = Nna;
        for (size_t j_1__ = 0; j_1__ < Xna_j_1_max__; ++j_1__) {
            Xna(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(Xna);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable Xna: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 18;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> alpha;
            (void) alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                alpha = in__.matrix_constrain(Nv, K, lp__);
            else
                alpha = in__.matrix_constrain(Nv, K);
            current_statement_begin__ = 19;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> lambda;
            (void) lambda;  // dummy to suppress unused var warning
            if (jacobian__)
                lambda = in__.matrix_constrain(K, Ne, lp__);
            else
                lambda = in__.matrix_constrain(K, Ne);
            current_statement_begin__ = 20;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> sigma2;
            (void) sigma2;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma2 = in__.vector_lb_constrain(0, Nv, lp__);
            else
                sigma2 = in__.vector_lb_constrain(0, Nv);
            current_statement_begin__ = 21;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> Xna;
            (void) Xna;  // dummy to suppress unused var warning
            if (jacobian__)
                Xna = in__.vector_constrain(Nna, lp__);
            else
                Xna = in__.vector_constrain(Nna);
            // model body
            current_statement_begin__ = 25;
            for (int i = 1; i <= Nob; ++i) {
                current_statement_begin__ = 26;
                lp_accum__.add(normal_log<propto__>(get_base1(X, get_base1(get_base1(idob, i, "idob", 1), 1, "idob", 2), get_base1(get_base1(idob, i, "idob", 1), 2, "idob", 2), "X", 1), multiply(stan::model::rvalue(alpha, stan::model::cons_list(stan::model::index_uni(get_base1(get_base1(idob, i, "idob", 1), 1, "idob", 2)), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list())), "alpha"), stan::model::rvalue(lambda, stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(get_base1(get_base1(idob, i, "idob", 1), 2, "idob", 2)), stan::model::nil_index_list())), "lambda")), stan::math::sqrt(get_base1(sigma2, get_base1(get_base1(idob, i, "idob", 1), 1, "idob", 2), "sigma2", 1))));
            }
            current_statement_begin__ = 30;
            for (int k = 1; k <= K; ++k) {
                current_statement_begin__ = 31;
                lp_accum__.add(normal_log<propto__>(stan::model::rvalue(alpha, stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list())), "alpha"), 0, stan::math::sqrt(stan::model::rvalue(v, stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list())), "v"))));
            }
            current_statement_begin__ = 35;
            lp_accum__.add(normal_log<propto__>(to_vector(lambda), 0, 1));
            current_statement_begin__ = 38;
            for (int i = 1; i <= Nna; ++i) {
                current_statement_begin__ = 39;
                lp_accum__.add(normal_log<propto__>(get_base1(Xna, i, "Xna", 1), multiply(stan::model::rvalue(alpha, stan::model::cons_list(stan::model::index_uni(get_base1(get_base1(idna, i, "idna", 1), 1, "idna", 2)), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list())), "alpha"), stan::model::rvalue(lambda, stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(get_base1(get_base1(idna, i, "idna", 1), 2, "idna", 2)), stan::model::nil_index_list())), "lambda")), stan::math::sqrt(get_base1(sigma2, get_base1(get_base1(idna, i, "idna", 1), 1, "idna", 2), "sigma2", 1))));
            }
            current_statement_begin__ = 43;
            for (int i = 1; i <= Nv; ++i) {
                current_statement_begin__ = 45;
                if (as_bool(logical_eq(get_base1(dsigma2, i, "dsigma2", 1), 0))) {
                    current_statement_begin__ = 46;
                    lp_accum__.add(gamma_log<propto__>(get_base1(sigma2, i, "sigma2", 1), get_base1(a, i, "a", 1), get_base1(b, i, "b", 1)));
                } else if (as_bool(logical_eq(get_base1(dsigma2, i, "dsigma2", 1), 1))) {
                    current_statement_begin__ = 49;
                    lp_accum__.add(inv_gamma_log<propto__>(get_base1(sigma2, i, "sigma2", 1), get_base1(a, i, "a", 1), get_base1(b, i, "b", 1)));
                } else {
                    current_statement_begin__ = 52;
                    lp_accum__.add(lognormal_log<propto__>(get_base1(sigma2, i, "sigma2", 1), get_base1(a, i, "a", 1), get_base1(b, i, "b", 1)));
                }
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("alpha");
        names__.push_back("lambda");
        names__.push_back("sigma2");
        names__.push_back("Xna");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(Nv);
        dims__.push_back(K);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(K);
        dims__.push_back(Ne);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(Nv);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(Nna);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_factorialNA_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> alpha = in__.matrix_constrain(Nv, K);
        size_t alpha_j_2_max__ = K;
        size_t alpha_j_1_max__ = Nv;
        for (size_t j_2__ = 0; j_2__ < alpha_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
                vars__.push_back(alpha(j_1__, j_2__));
            }
        }
        Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> lambda = in__.matrix_constrain(K, Ne);
        size_t lambda_j_2_max__ = Ne;
        size_t lambda_j_1_max__ = K;
        for (size_t j_2__ = 0; j_2__ < lambda_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < lambda_j_1_max__; ++j_1__) {
                vars__.push_back(lambda(j_1__, j_2__));
            }
        }
        Eigen::Matrix<double, Eigen::Dynamic, 1> sigma2 = in__.vector_lb_constrain(0, Nv);
        size_t sigma2_j_1_max__ = Nv;
        for (size_t j_1__ = 0; j_1__ < sigma2_j_1_max__; ++j_1__) {
            vars__.push_back(sigma2(j_1__));
        }
        Eigen::Matrix<double, Eigen::Dynamic, 1> Xna = in__.vector_constrain(Nna);
        size_t Xna_j_1_max__ = Nna;
        for (size_t j_1__ = 0; j_1__ < Xna_j_1_max__; ++j_1__) {
            vars__.push_back(Xna(j_1__));
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            if (!include_gqs__ && !include_tparams__) return;
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_factorialNA";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t alpha_j_2_max__ = K;
        size_t alpha_j_1_max__ = Nv;
        for (size_t j_2__ = 0; j_2__ < alpha_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "alpha" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        size_t lambda_j_2_max__ = Ne;
        size_t lambda_j_1_max__ = K;
        for (size_t j_2__ = 0; j_2__ < lambda_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < lambda_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "lambda" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        size_t sigma2_j_1_max__ = Nv;
        for (size_t j_1__ = 0; j_1__ < sigma2_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma2" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t Xna_j_1_max__ = Nna;
        for (size_t j_1__ = 0; j_1__ < Xna_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "Xna" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t alpha_j_2_max__ = K;
        size_t alpha_j_1_max__ = Nv;
        for (size_t j_2__ = 0; j_2__ < alpha_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "alpha" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        size_t lambda_j_2_max__ = Ne;
        size_t lambda_j_1_max__ = K;
        for (size_t j_2__ = 0; j_2__ < lambda_j_2_max__; ++j_2__) {
            for (size_t j_1__ = 0; j_1__ < lambda_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "lambda" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        size_t sigma2_j_1_max__ = Nv;
        for (size_t j_1__ = 0; j_1__ < sigma2_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma2" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t Xna_j_1_max__ = Nna;
        for (size_t j_1__ = 0; j_1__ < Xna_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "Xna" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_factorialNA_namespace::model_factorialNA stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif

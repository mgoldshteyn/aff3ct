#ifndef FACTORY_ENCODER_BCH_HPP
#define FACTORY_ENCODER_BCH_HPP

#include <string>

#include "Module/Encoder/Encoder.hpp"
#include "Tools/Code/BCH/BCH_Polynomial_Generator.hpp"

#include "../Encoder.hpp"

namespace aff3ct
{
namespace factory
{
struct Encoder_BCH : public Encoder
{
	static const std::string name;
	static const std::string prefix;

	template <typename B = int>
	static module::Encoder<B>* build(const parameters &params, const tools::BCH_Polynomial_Generator &GF_poly);

	static void build_args(arg_map &req_args, arg_map &opt_args, const std::string p = prefix);
	static void store_args(const arg_val_map &vals, parameters &params, const std::string p = prefix);
	static void make_header(params_list& head_enc, const parameters& params, const bool full = true);
};
}
}

#endif /* FACTORY_ENCODER_BCH_HPP */
/*!
 * \file
 * \brief This class can add/build and check a Cyclic Redundancy Check (CRC) for a set of information bits.
 *
 * \section LICENSE
 * This file is under MIT license (https://opensource.org/licenses/MIT).
 */
#ifndef CRC_HPP_
#define CRC_HPP_

#include <string>
#include <vector>
#include "Tools/Perf/MIPP/mipp.h"

#include "Module/Module.hpp"

/*!
 * \class CRC_interface
 *
 * \brief This class can add/build and check a Cyclic Redundancy Check (CRC) for a set of information bits.
 *
 * \tparam B: type of the bits in the CRC.
 *
 * Please use CRC for inheritance (instead of CRC_interface).
 */
template <typename B>
class CRC_interface : public Module
{
protected:
	const int K; /*!< Number of information bits (the CRC bits are included in K) */

public:
	/*!
	 * \brief Constructor.
	 *
	 * \param K       : number of information bits (the CRC bits are included in K).
	 * \param n_frames: number of frames to process in the CRC.
	 * \param name    : CRC name.
	 */
	CRC_interface(const int K, const int n_frames = 1, const std::string name = "CRC_interface") 
	: Module(n_frames, name), K(K) {}

	/*!
	 * \brief Destructor.
	 */
	virtual ~CRC_interface() {}

	/*!
	 * \brief Get the size of the CRC (the number of bits for the CRC signature).
	 *
	 * \return the size of the CRC.
	 */
	virtual int size() const = 0;

	/*!
	 * \brief Compute and add the CRC in the vector of information bits (the CRC bits are often put at the end of the
	 *        vector).
	 *
	 * \param U_K: contains (K - CRC<B>::size()) information bits, this method add "CRC<B>::size()" bits in U_K.
	 */
	virtual void build(mipp::vector<B>& U_K) = 0;

	/*!
	 * \brief Check if the CRC is verified or not.
	 *
	 * \param V_K: a vector containing information bits plus the CRC bits.
	 *
	 * \return true if the CRC is verified, false otherwise.
	 */
	virtual bool check(const mipp::vector<B>& V_K) = 0;
};

#include "SC_CRC.hpp"

#endif

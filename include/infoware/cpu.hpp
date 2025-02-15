// SPDX-License-Identifier: CC0-1.0
// infoware - C++ System information Library


#pragma once

#include <infoware/linkage.hpp>

#include <cstdint>
#include <string>
#include <vector>


namespace iware {
	namespace cpu {
		enum class architecture_t {
			x64,
			arm,
			itanium,
			x86,
			unknown,
		};

		enum class endianness_t {
			little,
			big,
		};

		enum class instruction_set_t {
			// x86
			s3d_now,
			s3d_now_extended,
			mmx,
			mmx_extended,
			sse,
			sse2,
			sse3,
			ssse3,
			sse4a,
			sse41,
			sse42,
			aes,

			avx,
			avx2,

			avx_512,
			avx_512_f,
			avx_512_cd,
			avx_512_pf,
			avx_512_er,
			avx_512_vl,
			avx_512_bw,
			avx_512_bq,
			avx_512_dq,
			avx_512_ifma,
			avx_512_vbmi,

			hle,

			bmi1,
			bmi2,
			adx,
			mpx,
			sha,
			prefetch_wt1,

			fma3,
			fma4,

			xop,

			rd_rand,

			x64,
			x87_fpu,


			// ARM
			fhm,
			dotprod,
			rdm,
			lse,
			pmnull,
			specres,
			sb,
			frintts,
			lrcpc,
			lrcpc2,
			fcma,
			jscvt,
			pauth,
			pauth2,
			fpac,
			dpb,
			dpb2,
			bf16,
			i8mm,
			ecv,
			les2,
			csv2,
			csv3,
			dit,
			fp16,
			ssbs,
			bti,
			fp_sync_exception,
			neon,
			armv8_1_atomics,
			armv8_2_fhm,
			armv8_2_compnum,
			watchpoint,
			breakpoint,
			armv8_crc32,
			armv8_gpi,
			adv_simd,
			adv_simd_hpfp_cvt,
			ucnormal_mem,
		};

		enum class cache_type_t {
			unified,
			instruction,
			data,
			trace,
		};

		struct quantities_t {
			/// Hyperthreads.
			std::uint32_t logical;
			/// Physical "cores".
			std::uint32_t physical;
			/// Physical CPU units/packages/sockets.
			std::uint32_t packages;
		};

		struct cache_t {
			std::size_t size;
			std::size_t line_size;
			std::uint8_t associativity;
			cache_type_t type;
		};


		/// Returns the quantity of CPU at various gradation.
		INFOWARE_API_LINKAGE quantities_t quantities();

		/// Get CPU's cache properties.
		///
		/// `level` is the cache level (3 -> L3 cache).
		INFOWARE_API_LINKAGE cache_t cache(unsigned int level);

		/// Returns the architecture of the current CPU.
		INFOWARE_API_LINKAGE architecture_t architecture() noexcept;

		/// Returns the current frequency of the current CPU in Hz.
		INFOWARE_API_LINKAGE std::uint64_t frequency() noexcept;

		/// Returns the current endianness of the current CPU.
		INFOWARE_API_LINKAGE endianness_t endianness() noexcept;

		/// Returns the CPU's vendor.
		INFOWARE_API_LINKAGE std::string vendor();

		/// Returns the CPU's vendor according to the CPUID instruction
		INFOWARE_API_LINKAGE std::string vendor_id();

		/// Returns the CPU's model name.
		INFOWARE_API_LINKAGE std::string model_name();

		/// Returns whether an instruction set is supported by the current CPU.
		///
		/// `noexcept` on Windows
		INFOWARE_API_LINKAGE bool instruction_set_supported(instruction_set_t set);

		/// Retrieve all of the instruction sets this hardware supports
		INFOWARE_API_LINKAGE std::vector<instruction_set_t> supported_instruction_sets();
	}  // namespace cpu
}  // namespace iware

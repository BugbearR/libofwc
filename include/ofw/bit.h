#ifndef Ofw_Bit_H_
#define Ofw_Bit_H_

#ifdef Ofw_HAVE_PRAGMA_ONCE
#pragma once
#endif

/**
 * @brief create base bit mask
 * @param type type name (ex. int64_t -> INT64)
 * @param bitCount count of bit
 * @return bit mask
 */
#define Ofw_Bit_toBaseMask(type, bitCount) ((type##_C(1) << (bitCount)) - type##_C(1))

/**
 * @brief create bit mask
 * @param type type name (ex. int64_t -> INT64)
 * @param bitCount count of bit
 * @param base base index (LSB:0)
 * @return bit mask
 */
#define Ofw_Bit_toMask(type, bitCount, base) (Ofw_Bit_toBaseMask(type, bitCount) << (base))

/**
 * @brief get bit masked value
 * @param type type name (ex. int64_t -> INT64)
 * @param value value
 * @param bitCount count of bit
 * @param base base index (LSB:0)
 * @return bit masked value
 */
#define Ofw_Bit_getMasked(type, value, bitCount, base) ((value) & Ofw_Bit_toMask(type, bitCount, base))

/**
 * @brief get bit masked value and shift to base
 * @param type type name (ex. int64_t -> INT64)
 * @param value target value
 * @param bitCount count of bit
 * @param base base index (LSB:0)
 * @return 
 */
#define Ofw_Bit_getMaskedAndShiftBase(type, value, bitCount, base) (((value) >> (base)) & Ofw_Bit_toBaseMask(type, bitCount, base))

/**
 * @brief clear by bit mask
 * @param type type name (ex. int64_t -> INT64)
 * @param value target value
 * @param bitCount count of bit
 * @param base base index (LSB:0)
 * @return 
 */
#define Ofw_Bit_clearMasked(type, value, bitCount, base) ((value) & ~Ofw_Bit_toMask(type, bitCount, base))

/**
 * @brief set value by bit mask
 * @param type type name (ex. int64_t -> INT64)
 * @param dst target value
 * @param bitCount count of bit
 * @param base base index (LSB:0)
 * @param src target value
 * @return result value
 */
#define Ofw_Bit_setMaskedValue(type, dst, bitCount, base, src) (Ofw_Bit_clearMasked(type, dst, bitCount, base)) | (src) << (base))

#endif /* Ofw_Bit_H_ */

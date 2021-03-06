#include "em_leuart_utils.h"
#if defined(LEUART_COUNT) && (LEUART_COUNT > 0)

#include "em_assert.h"

/***************************************************************************//**
 * @brief
 *   Convert data bits to the enum value in LEUART_Databits_TypeDef.
 *
 * @param[in] bits
 *   The number of bits.
 *
 * @return
 *   Corresponding enum value.
 ******************************************************************************/
__INLINE LEUART_Databits_TypeDef LEUART_DataBits2Def(uint8_t bits)
{
  EFM_ASSERT(bits >= 8 && bits <= 9);

  return (LEUART_Databits_TypeDef) ((bits - 8) << _LEUART_CTRL_DATABITS_SHIFT);
}

/***************************************************************************//**
 * @brief
 *   Convert stop bits (expressed as halves) to the enum value in
 *   LEUART_Stopbits_TypeDef.
 *
 * @param[in] half_bits
 *   The number of half bits (e.g. 1 bit equals 2 half bits).
 *
 * @return
 *   Corresponding enum value.
 ******************************************************************************/
__INLINE LEUART_Stopbits_TypeDef LEUART_StopBits2Def(uint8_t half_bits)
{
  EFM_ASSERT(half_bits == 2 || half_bits == 4);

  return (LEUART_Stopbits_TypeDef) ((half_bits / 4) << _LEUART_CTRL_STOPBITS_SHIFT);
}

/***************************************************************************//**
 * @brief
 *   Convert a number to the enum value in LEUART_Parity_TypeDef.
 *
 * @param[in] number
 *   Odd numbers map to odd parity, even numbers to even parity and zero to no
 *   parity.
 *
 * @return
 *   Corresponding enum value.
 ******************************************************************************/
__INLINE LEUART_Parity_TypeDef LEUART_Parity2Def(uint8_t number)
{
  return (LEUART_Parity_TypeDef) ((number == 0 ? number : (number % 2) + 2) << _LEUART_CTRL_PARITY_SHIFT);
}

/***************************************************************************//**
 * @brief
 *   Set the data bits, stop bits and parity settings.
 *
 * @note
 *   The LEUART peripheral should already be initialized and enabled.
 *
 * @param[in] leuart
 *   A pointer to the LEUART peripheral register block.
 *
 * @param[in] databits
 *   Number of data bits.
 *
 * @param[in] stopbits
 *   Number of stop bits.
 *
 * @param[in] parity
 *   Parity mode.
 ******************************************************************************/
void LEUART_FrameSet(LEUART_TypeDef *leuart,
                     LEUART_Databits_TypeDef databits,
                     LEUART_Stopbits_TypeDef stopbits,
                     LEUART_Parity_TypeDef parity)
{
  /* Configure databits, parity and stopbits. */
  leuart->CTRL = (leuart->CTRL & ~(_LEUART_CTRL_DATABITS_MASK
                                   | _LEUART_CTRL_PARITY_MASK
                                   | _LEUART_CTRL_STOPBITS_MASK))
                 | (uint32_t)(databits)
                 | (uint32_t)(parity)
                 | (uint32_t)(stopbits);
}

#endif /* defined(LEUART_COUNT) && (LEUART_COUNT > 0) */

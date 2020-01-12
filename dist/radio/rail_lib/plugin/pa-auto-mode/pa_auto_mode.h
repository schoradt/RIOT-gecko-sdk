/***************************************************************************//**
 * @file
 * @brief This file contains the type definitions for RAIL structures, enums,
 *   and other types.
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#include "rail.h"
#include "rail_features.h"

#include "em_common.h"

/**
 * @addtogroup RAIL_API
 * @{
 */

/**
 * @addtogroup PA Power Amplifier (PA)
 * @ingroup Transmit
 * @{
 */

/**
 * @enum RAIL_PaBand_t
 * @brief Enum used to specify the band for a PA
 */
RAIL_ENUM(RAIL_PaBand_t) {
  /** Indicates a 2.4GHz band PA. */
  RAIL_PA_BAND_2P4GIG,
  /** Indicates a Sub-GHz band PA. */
  RAIL_PA_BAND_SUBGIG
};

/**
 * @enum RAIL_PaAutoModeConfigEntry_t
 * @brief Struct to ease specification of appropriate ranges
 * within which a PA should be used.
 */
typedef struct RAIL_PaAutoModeConfigEntry {
  /** The minimum (inclusive) deci-dBm power to use with this entry. */
  RAIL_TxPower_t min;
  /** The maximum (inclusive) deci-dBm power to use with this entry. */
  RAIL_TxPower_t max;
  /** The PA that this range of powers applies to. */
  RAIL_TxPowerMode_t mode;
  /** The RF band that this PA works with. */
  RAIL_PaBand_t band;
} RAIL_PaAutoModeConfigEntry_t;

/**
 * The current PA auto mode configuration structure used by the auto mode plugin
 * to control output power.
 */
extern RAIL_PaAutoModeConfigEntry_t RAIL_PaAutoModeConfig[];

/** @} */ // PA Power Amplifier (PA)

/**
 * @}
 * end of RAIL_API
 */

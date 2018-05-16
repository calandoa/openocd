/*
    SPC5 RLA - Copyright (C) 2015 STMicroelectronics

    Licensed under the Apache License, Version 2.0 (the "License").
    You may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
    Portion of the code in this module have been taken from the ChibiOS
    project (ChibiOS - Copyright (C) 2006..2015) licensed under Apache
    2.0 license.
*/

/**
 * @file    irq_cfg.c
 * @brief   IRQ configuration code.
 *
 * @addtogroup IRQ
 * @{
 */

#include "irq.h"

#include "board.h"

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module ISRs.                                                              */
/*===========================================================================*/

/*
 * PIT1_IRQ ISR function (vector 60).
 */
IRQ_HANDLER(PIT1_TimerExpired) {

  IRQ_PROLOGUE();

  pal_togglepad(PORT_C, PC_LED7);
  pal_togglepad(PORT_C, PC_LED8);
  PIT.CH[1].TFLG.R  = 1;         /* Interrupt flag cleared.                  */

  IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Generated initialization code.
 *
 * @special
 */
void irq_cfg_init(void) {

  INTC_PSR(ISR_VECTOR_PIT1_IRQ)=INTC_PSR_ENABLE(INTC_PSR_CORE0, 8);
}

/** @} */

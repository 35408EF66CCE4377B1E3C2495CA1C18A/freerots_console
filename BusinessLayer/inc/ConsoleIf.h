/**
  ******************************************************************************
  * @file    admin_interface.h
  * @author  Mikk Su
  * @version V1.0.0
  * @date    4-Nov-2015
  * @brief   The head file of admin_interface.c
  *
  @verbatim
  ==============================================================================
                     ##### How to use this module #####
  ==============================================================================
    [..]
    No more info !

  @endverbatim
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 AMC</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of AMC nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

#ifndef __CONSOLEIF_H
#define __CONSOLEIF_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "cmsis_os.h"

#define MAX_LEN_CMD_NAME	15		/*!< The max lenght of command name */
#define MAX_LEN_CMD_PARA	35		/*!< The max lenght of command arguments */


typedef struct
{
	uint8_t command[MAX_LEN_CMD_NAME];
	uint8_t para[MAX_LEN_CMD_PARA];
}CommandTypeDef;

//! Admin Interface Status enum.
/*! The return value of command parser. */
typedef enum
{
	aifOK,				/*!< A command parsed succesfully */
	aifBadName,		/*!< Unrecognized command name */
	aifBadPara		/*!< Unrecognized command argument */
}CIFStatus;     /*!< Console Interface Status variable */



/* Exported functions ---------------------------------------------------------*/
void ConsoleIF_Init(void);
void ConsoleIF_WaitForCommand(uint8_t **Command);
CIFStatus ConsoleIF_ParseCommand(uint8_t *command, CommandTypeDef *cmdstructure);
void ConsoleIF_ExcuteCommand(CommandTypeDef *parsedcommand);
#endif


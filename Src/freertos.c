/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  *
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */     
#include "consoleif.h"
#include "led.h"
/* USER CODE END Includes */

/* Variables -----------------------------------------------------------------*/
osThreadId ConsoleTaskHandle;
osThreadId LedBlinkyTaskHandle;
osMessageQId Q_CmdReceptionHandle;

/* USER CODE BEGIN Variables */

/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/
void StartTask_Console(void const * argument);
void StartTask_LedBlinky(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/* Hook prototypes */

/* Init FreeRTOS */

void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
	
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of ConsoleTask */
  osThreadDef(ConsoleTask, StartTask_Console, osPriorityNormal, 0, 128);
  ConsoleTaskHandle = osThreadCreate(osThread(ConsoleTask), NULL);

  /* definition and creation of LedBlinkyTask */
  osThreadDef(LedBlinkyTask, StartTask_LedBlinky, osPriorityNormal, 0, 128);
  LedBlinkyTaskHandle = osThreadCreate(osThread(LedBlinkyTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Create the queue(s) */
  /* definition and creation of Q_CmdReception */
  osMessageQDef(Q_CmdReception, 3, uint32_t);
  Q_CmdReceptionHandle = osMessageCreate(osMessageQ(Q_CmdReception), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
	
  /* USER CODE END RTOS_QUEUES */
}

/* StartTask_Console function */
void StartTask_Console(void const * argument)
{

  /* USER CODE BEGIN StartTask_Console */
	static uint8_t *pcommand;
	static CommandTypeDef parsedcommand;
	CIFStatus retval_parsecmd;
	
	ConsoleIF_Init();
	
  /* Infinite loop */
  for(;;)
  {
		ConsoleIF_WaitForCommand(&pcommand);
		
		retval_parsecmd = ConsoleIF_ParseCommand(pcommand, &parsedcommand);
		
		if(retval_parsecmd == aifOK)
		{
			ConsoleIF_ExcuteCommand(&parsedcommand);

			LED_on(1);
			osDelay(5);
			LED_off(1);
		}
		else
		{
			LED_on(1);
			osDelay(5);
			LED_off(1);
			osDelay(10);
			LED_on(1);
			osDelay(5);
			LED_off(1);
		}
  }
  /* USER CODE END StartTask_Console */
}

/* StartTask_LedBlinky function */
void StartTask_LedBlinky(void const * argument)
{
  /* USER CODE BEGIN StartTask_LedBlinky */
  /* Infinite loop */
  for(;;)
  {
		LED_on(0);
    osDelay(50);
		LED_off(0);
		osDelay(950);
  }
  /* USER CODE END StartTask_LedBlinky */
}

/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

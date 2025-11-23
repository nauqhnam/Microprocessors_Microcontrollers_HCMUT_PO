/* USER CODE BEGIN Header */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE BEGIN 0 */
int timer0_counter = 0;    // Bộ đếm thời gian
int timer0_flag = 0;       // Cờ báo hiệu hết thời gian
int TIMER_CYCLE = 10;      // Chu kỳ timer interrupt (10ms)
void setTimer0(int duration) {
    timer0_counter = duration / TIMER_CYCLE;
    timer0_flag = 0;
}

// Hàm chạy timer
void timer_run() {
    if (timer0_counter > 0) {
        timer0_counter--;
        if (timer0_counter == 0)
            timer0_flag = 1;
    }
}
/* USER CODE END 0 */
void clear7SEG() {
    HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(a3_GPIO_Port, a3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(a4_GPIO_Port, a4_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(a5_GPIO_Port, a5_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(a6_GPIO_Port, a6_Pin, GPIO_PIN_SET);
}

void display7SEG (int num) {
    clear7SEG();
    switch (num) {
        case 0: HAL_GPIO_WritePin(a0_GPIO_Port,a0_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a1_GPIO_Port,a1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a2_GPIO_Port,a2_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a3_GPIO_Port,a3_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a4_GPIO_Port,a4_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a5_GPIO_Port,a5_Pin,GPIO_PIN_RESET);
                break;
        case 1: HAL_GPIO_WritePin(a1_GPIO_Port,a1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a2_GPIO_Port,a2_Pin,GPIO_PIN_RESET);
                break;
        case 2: HAL_GPIO_WritePin(a0_GPIO_Port,a0_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a1_GPIO_Port,a1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a3_GPIO_Port,a3_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a4_GPIO_Port,a4_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a6_GPIO_Port,a6_Pin,GPIO_PIN_RESET);
                break;
        case 3: HAL_GPIO_WritePin(a0_GPIO_Port,a0_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a1_GPIO_Port,a1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a2_GPIO_Port,a2_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a3_GPIO_Port,a3_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a6_GPIO_Port,a6_Pin,GPIO_PIN_RESET);
                break;
        case 4: HAL_GPIO_WritePin(a1_GPIO_Port,a1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a2_GPIO_Port,a2_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a5_GPIO_Port,a5_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a6_GPIO_Port,a6_Pin,GPIO_PIN_RESET);
                break;
        case 5: HAL_GPIO_WritePin(a0_GPIO_Port,a0_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a2_GPIO_Port,a2_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a3_GPIO_Port,a3_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a5_GPIO_Port,a5_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a6_GPIO_Port,a6_Pin,GPIO_PIN_RESET);
                break;
        case 6: HAL_GPIO_WritePin(a0_GPIO_Port,a0_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a2_GPIO_Port,a2_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a3_GPIO_Port,a3_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a4_GPIO_Port,a4_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a5_GPIO_Port,a5_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a6_GPIO_Port,a6_Pin,GPIO_PIN_RESET);
                break;
        case 7: HAL_GPIO_WritePin(a0_GPIO_Port,a0_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a1_GPIO_Port,a1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a2_GPIO_Port,a2_Pin,GPIO_PIN_RESET);
                break;
        case 8: HAL_GPIO_WritePin(a0_GPIO_Port,a0_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a1_GPIO_Port,a1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a2_GPIO_Port,a2_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a3_GPIO_Port,a3_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a4_GPIO_Port,a4_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a5_GPIO_Port,a5_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a6_GPIO_Port,a6_Pin,GPIO_PIN_RESET);
                break;
        case 9: HAL_GPIO_WritePin(a0_GPIO_Port,a0_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a1_GPIO_Port,a1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a2_GPIO_Port,a2_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a3_GPIO_Port,a3_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a5_GPIO_Port,a5_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(a6_GPIO_Port,a6_Pin,GPIO_PIN_RESET);
                break;
        default: clear7SEG(); break;
    }
}
void initState() {
    // tắt tất cả các đoạn
    clear7SEG();

    // disable tất cả 4 LED 7 đoạn
    HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_SET);

    // tắt 2 LED dot và led_red
    HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(led_GPIO_Port, led_Pin, GPIO_PIN_RESET);
}
void clearEN() {
    HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_SET);
}
const unsigned int MAX_LED = 4;
int led_buffer[4] = {0, 0, 0, 0};
void update7SEG(int index) {
	clearEN();
    switch (index) {
        case 0:
            display7SEG(led_buffer[0]);
            HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_RESET);
            break;
        case 1:
            display7SEG(led_buffer[1]);
            HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_RESET);
            break;
        case 2:
            display7SEG(led_buffer[2]);
            HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_RESET);
            break;
        case 3:
            display7SEG(led_buffer[3]);
            HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}
void updateClockBuffer(int hour, int minute) {
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}




/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (&htim2);
   initState();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
   int hour = 15, minute = 8, second = 55;
   setTimer0(1000);
   while (1)
    {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	   if (timer0_flag == 1) {
		                   second++;
		   	               if (second >= 60) {
		   	                   second = 0;
		   	                   minute++;
		   	               }
		   	               if (minute >= 60) {
		   	                   minute = 0;
		   	                   hour++;
		   	               }
		   	               if (hour >= 24) {
		   	                   hour = 0;
		   	               }

		   	               updateClockBuffer(hour, minute);
		   	               setTimer0(1000);
	   }

    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */
  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */
  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */
  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DOT_Pin|led_Pin|en0_Pin|en1_Pin
                          |en2_Pin|en3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a0_Pin|a1_Pin|a2_Pin|a3_Pin
                          |a4_Pin|a5_Pin|a6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DOT_Pin led_Pin en0_Pin en1_Pin
                           en2_Pin en3_Pin */
  GPIO_InitStruct.Pin = DOT_Pin|led_Pin|en0_Pin|en1_Pin
                          |en2_Pin|en3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a0_Pin a1_Pin a2_Pin a3_Pin
                           a4_Pin a5_Pin a6_Pin */
  GPIO_InitStruct.Pin = a0_Pin|a1_Pin|a2_Pin|a3_Pin
                          |a4_Pin|a5_Pin|a6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
int counter = 50;
int idx = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	timer_run();
    if (htim->Instance == TIM2) {
        counter--;

        if (counter == 25 || counter == 0) {
            if (counter == 0) {
                counter = 50;
                HAL_GPIO_TogglePin(GPIOA, led_Pin | DOT_Pin); // DOT blink mỗi 1s
            }

            update7SEG(idx);
            idx = (idx + 1) % 4;
        }
    }



/* USER CODE END 4 */
}
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

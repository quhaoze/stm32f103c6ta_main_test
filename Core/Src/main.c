/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
int work_mode = 1;
int speed_of_wheels = 500;
int battery = 100;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */
#include "OLED.h"
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void show_work_situtation(void)
{
    if(work_mode=1)
    {




    }
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
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,1);
      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,1);
      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,1);
      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1);
      HAL_Delay(1000);
      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,0);
      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,0);
      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,0);
      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,0);
      //现在是test分支
      OLED_Init();//OLED初始
      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,1);
      /*在(16, 0)位置显示字符串"Hello World!"，字体大小为8*16点阵*/
      OLED_ShowString(0, 0, "blog.zeruns.tech", OLED_8X16);
      /*在(0, 18)位置显示字符'A'，字体大小为6*8点阵*/
      OLED_ShowChar(0, 18, 'A', OLED_6X8);

      /*在(16, 18)位置显示字符串"Hello World!"，字体大小为6*8点阵*/
      OLED_ShowString(16, 18, "Hello World!", OLED_6X8);

      /*在(0, 28)位置显示数字12345，长度为5，字体大小为6*8点阵*/
      OLED_ShowNum(0, 28, 12345, 5, OLED_6X8);

      /*在(40, 28)位置显示有符号数字-66，长度为2，字体大小为6*8点阵*/
      OLED_ShowSignedNum(40, 28, -66, 2, OLED_6X8);

      /*在(70, 28)位置显示十六进制数字0xA5A5，长度为4，字体大小为6*8点阵*/
      OLED_ShowHexNum(70, 28, 0xA5A5, 4, OLED_6X8);

      /*在(0, 38)位置显示二进制数字0xA5，长度为8，字体大小为6*8点阵*/
      OLED_ShowBinNum(0, 38, 0xA5, 8, OLED_6X8);

      /*在(60, 38)位置显示浮点数字123.45，整数部分长度为3，小数部分长度为2，字体大小为6*8点阵*/
      OLED_ShowFloatNum(60, 38, 123.45, 3, 2, OLED_6X8);

      /*在(0, 48)位置显示汉字串"你好，世界。"，字体大小为固定的16*16点阵*/
      OLED_ShowChinese(0, 48, "你好，世界。");

      /*在(96, 48)位置显示图像，宽16像素，高16像素，图像数据为Diode数组*/
      OLED_ShowImage(96, 48, 16, 16, Diode);

      /*在(96, 18)位置打印格式化字符串，字体大小为6*8点阵，格式化字符串为"[%02d]"*/
      OLED_Printf(96, 18, OLED_6X8, "[%02d]", 6);

      /*调用OLED_Update函数，将OLED显存数组的内容更新到OLED硬件进行显示*/
      OLED_Update();

     // HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin); // LED电平翻转
      /*延时3000ms，观察现象*/
      HAL_Delay(3000);

      /*清空OLED显存数组*/
      OLED_Clear();

      /*在(5, 8)位置画点*/
      OLED_DrawPoint(5, 8);

      /*获取(5, 8)位置的点*/
      if (OLED_GetPoint(5, 8))
      {
          /*如果指定点点亮，则在(10, 4)位置显示字符串"YES"，字体大小为6*8点阵*/
          OLED_ShowString(10, 4, "YES", OLED_6X8);
      }
      else
      {
          /*如果指定点未点亮，则在(10, 4)位置显示字符串"NO "，字体大小为6*8点阵*/
          OLED_ShowString(10, 4, "NO ", OLED_6X8);
      }

      /*在(40, 0)和(127, 15)位置之间画直线*/
      OLED_DrawLine(40, 0, 127, 15);

      /*在(40, 15)和(127, 0)位置之间画直线*/
      OLED_DrawLine(40, 15, 127, 0);

      /*在(0, 20)位置画矩形，宽12像素，高15像素，未填充*/
      OLED_DrawRectangle(0, 20, 12, 15, OLED_UNFILLED);

      /*在(0, 40)位置画矩形，宽12像素，高15像素，填充*/
      OLED_DrawRectangle(0, 40, 12, 15, OLED_FILLED);

      /*在(20, 20)、(40, 25)和(30, 35)位置之间画三角形，未填充*/
      OLED_DrawTriangle(20, 20, 40, 25, 30, 35, OLED_UNFILLED);

      /*在(20, 40)、(40, 45)和(30, 55)位置之间画三角形，填充*/
      OLED_DrawTriangle(20, 40, 40, 45, 30, 55, OLED_FILLED);

      /*在(55, 27)位置画圆，半径8像素，未填充*/
      OLED_DrawCircle(55, 27, 8, OLED_UNFILLED);

      /*在(55, 47)位置画圆，半径8像素，填充*/
      OLED_DrawCircle(55, 47, 8, OLED_FILLED);

      /*在(82, 27)位置画椭圆，横向半轴12像素，纵向半轴8像素，未填充*/
      OLED_DrawEllipse(82, 27, 12, 8, OLED_UNFILLED);
      // https://blog.zeruns.tech
      /*在(82, 47)位置画椭圆，横向半轴12像素，纵向半轴8像素，填充*/
      OLED_DrawEllipse(82, 47, 12, 8, OLED_FILLED);

      /*在(110, 18)位置画圆弧，半径15像素，起始角度25度，终止角度125度，未填充*/
      OLED_DrawArc(110, 18, 15, 25, 125, OLED_UNFILLED);

      /*在(110, 38)位置画圆弧，半径15像素，起始角度25度，终止角度125度，填充*/
      OLED_DrawArc(110, 38, 15, 25, 125, OLED_FILLED);

      /*调用OLED_Update函数，将OLED显存数组的内容更新到OLED硬件进行显示*/
      OLED_Update();

     // HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin); // LED电平翻转

      /*延时1500ms，观察现象*/
      HAL_Delay(1500);

      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,1);

      while (1)
      {
          HAL_Delay(1000);
          if((speed_of_wheels%2) == 1)
          {
              speed_of_wheels++;
          }
          else
          {
              speed_of_wheels--;
          }
          HAL_Delay(1000);

          //HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_3);
          //OLED_ShowNum(0, 1, 3, 1, 16, 1);

          //OLED_ShowString(0, 5, "hello world", 16, 1);

          //HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_4);

      }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


      /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA1 PA2 PA3 PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

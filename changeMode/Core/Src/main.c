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
#include "lcd.h"
#include "stdio.h"
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
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7Seg(int data);
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
//void show_traffic(uint8_t BacK_Green1, uint8_t BacK_Yellow1, 
//	uint8_t BacK_Green2, uint8_t BacK_Yellow2);
//void sleep();
int status;
int counter1;
int counter2;
enum ledColor{
	GREEN,
	YELLOW,
	RED
};
//void sleep(){
////	if(status == 0)
////	{	
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
//	while(1){	
//	
//	//led yellow blink 1HZ
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);//R1
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);//Y1
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);//G1
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);//R2
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);//Y2
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);//G2
//	HAL_Delay(500);
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);//Y1
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);//Y2
//	HAL_Delay(500);
//	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0){
//		//while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 1);
//		break;
//		status = 0;
//	}

//	}

//}

//void show_traffic(uint8_t BacK_Green1, uint8_t BacK_Yellow1, 
//	uint8_t BacK_Green2, uint8_t BacK_Yellow2){
//	
//	uint8_t c_Green1 = BacK_Green1;
//	uint8_t c_Yellow1 = BacK_Yellow1;
//	uint8_t c_Red1 = BacK_Green1 + BacK_Yellow1;
//	uint8_t BacK_Red1 = c_Red1;
//	enum ledColor cur_color1 = GREEN;
//	
//	uint8_t c_Green2 = BacK_Green2;
//	uint8_t c_Yellow2 = BacK_Yellow2;
//	uint8_t c_Red2 = BacK_Green2 + BacK_Yellow2;
//	uint8_t BacK_Red2 = c_Red2;
//	enum ledColor cur_color2 = RED;
//	
//	uint8_t c_1s = BacK_Green1 + BacK_Red2 + 2;
//	
//	counter1 = BacK_Green1 - 1;
//	counter2 = BacK_Red2 - 1;
//	
//	int sw_led = 0;
//  
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);//R1
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);//G1
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);//Y1
//	
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);//R2
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);//G2
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);//Y2
//	
////	Lcd_Write_Command(0x80);//write first line 1
////	Lcd_Write_String("Mode:");
////	Lcd_Write_Command(0xC0);//write first line 2
////	Lcd_Write_String("Binh Thuong.");
//	
//	while(1){	
//		//if(*sleep_mode == 22) break;
//		if(c_Green1 <= 0){
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
//			c_Green1 = BacK_Green1;
//			cur_color1 = YELLOW;
//			counter1 = BacK_Yellow1 - 1;
//		}
//		if(c_Yellow1 <= 0){
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
//			c_Yellow1 = BacK_Yellow1;
//			cur_color1 = RED;
//			counter1 = BacK_Red1 - 1;
//		}

//		if(c_Red1 <= 0){
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
//			c_Red1 = BacK_Green1 + BacK_Yellow1;
//			cur_color1 = GREEN;
//			counter1 = BacK_Green1 - 1;
//		}
//		if(c_Green2 <= 0){
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
//			c_Green2 = BacK_Green2 - 1;
//			cur_color2 = YELLOW;
//			counter2 = BacK_Yellow2 - 1;
//		}
//		if(c_Yellow2 <= 0){
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
//			c_Yellow2 =BacK_Yellow1 - 1;
//			cur_color2 = RED;
//			counter2 = BacK_Red2 - 1;
//		}
//		if(c_Red2 <= 0){
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
//			c_Red2 = BacK_Green2 + BacK_Yellow2;
//			cur_color2 = GREEN;
//			counter2 = BacK_Green2 - 1;
//		}
//		if(c_1s <= 0){
//			switch(cur_color1){
//				case GREEN:
//						c_Green1--;
//						break;
//				case YELLOW:
//						c_Yellow1--;
//						break;
//				case RED:
//						c_Red1--;
//						break;
//			}
//			switch(cur_color2){
//				case GREEN:
//						c_Green2--;
//						break;
//				case YELLOW:
//						c_Yellow2--;
//						break;
//				case RED:
//						c_Red2--;
//						break;
//			}
//			counter1--;
//			counter2--;
//			c_1s = BacK_Green1 + BacK_Red2 + 2;
//		}
//		switch(sw_led){
//			case 0:
//				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);//EN3
//				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);//EN0
//				display7Seg(counter1/10);
//				sw_led = 1;
//				break;
//			case 1:
//				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);//EN0
//				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);//EN1
//				display7Seg(counter1%10);
//				sw_led = 2;
//				break;
//			case 2:
//				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);//EN1
//				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);//EN2
//				display7Seg(counter2/10);
//				sw_led = 3;
//				break;
//			case 3:
//				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);//EN2
//				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);//EN3
//				display7Seg(counter2%10);
//				sw_led = 0;
//				break;
//		}
//		c_1s--;
//		HAL_Delay(10);
//		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0){
//			//while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1);
//			break;
//			status = 1;
//		}
//		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0){
//			//while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 1);
//			break;
//		}
//		}
//	
//}
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
	lcd_init();
	status = 0;
	lcd_put_cur(0, 0);
		lcd_send_string("Mode: Normal              ");
		//HAL_Delay(10);
		lcd_put_cur(1, 0);
		lcd_send_string("R:28s G:24s Y:4s          ");
		uint8_t c_Green1 = 24;
		uint8_t c_Yellow1 = 4;
		uint8_t c_Red1 = 28;
//		uint8_t BacK_Red1 = c_Red1;
		enum ledColor cur_color1 = GREEN;
		
		uint8_t c_Green2 = 22;
		uint8_t c_Yellow2 = 4;
		uint8_t c_Red2 = 26;
//		uint8_t BacK_Red2 = c_Red2;
		enum ledColor cur_color2 = RED;
		
		uint8_t c_1s = 50;
		
		counter1 = 21;
		counter2 = 25;
		
		int sw_led = 0;
		
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);//R1
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);//G1
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);//Y1
		
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);//R2
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);//G2
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);//Y2
//	lcd_put_cur(0, 0);
//		lcd_send_string("Mode: Normal              ");
//		//HAL_Delay(10);
//		lcd_put_cur(1, 0);
//		lcd_send_string("R:26s G:22s Y:4s          ");
//		show_traffic(22, 4, 22, 4);
//		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0){
//			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0);
//			lcd_put_cur(0, 0);
//			lcd_send_string("Mode: Sleep                ");
//			//HAL_Delay(10);
//			lcd_put_cur(1, 0);
//			lcd_send_string("Yellow blink 1HZ             ");
//			sleep();
//		}
//		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0){
//			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0);
//			lcd_put_cur(0, 0);
//			lcd_send_string("Mode: Rush                ");
//			//HAL_Delay(10);
//			lcd_put_cur(1, 0);
//			lcd_send_string("R:32s G:28s Y:4s              ");
//			show_traffic(28, 4, 28, 4);
//		}
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

		
		//if(*sleep_mode == 22) break;
		if(c_Green1 <= 0){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
			c_Green1 = 22;
			cur_color1 = YELLOW;
			counter1 = 3;
		}
		if(c_Yellow1 <= 0){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			c_Yellow1 = 4;
			cur_color1 = RED;
			counter1 = 25;
		}

		if(c_Red1 <= 0){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			c_Red1 = 26;
			cur_color1 = GREEN;
			counter1 = 21;
		}
		if(c_Green2 <= 0){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
			c_Green2 = 21;
			cur_color2 = YELLOW;
			counter2 = 3;
		}
		if(c_Yellow2 <= 0){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
			c_Yellow2 = 3;
			cur_color2 = RED;
			counter2 = 25;
		}
		if(c_Red2 <= 0){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
			c_Red2 = 25;
			cur_color2 = GREEN;
			counter2 = 21;
		}
		if(c_1s <= 0){
			switch(cur_color1){
				case GREEN:
						c_Green1--;
						break;
				case YELLOW:
						c_Yellow1--;
						break;
				case RED:
						c_Red1--;
						break;
			}
			switch(cur_color2){
				case GREEN:
						c_Green2--;
						break;
				case YELLOW:
						c_Yellow2--;
						break;
				case RED:
						c_Red2--;
						break;
			}
			counter1--;
			counter2--;
			c_1s = 50;
		}
		switch(sw_led){
			case 0:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);//EN3
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);//EN0
				display7Seg(counter1/10);
				sw_led = 1;
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);//EN0
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);//EN1
				display7Seg(counter1%10);
				sw_led = 2;
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);//EN1
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);//EN2
				display7Seg(counter2/10);
				sw_led = 3;
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);//EN2
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);//EN3
				display7Seg(counter2%10);
				sw_led = 0;
				break;
		}
		c_1s--;
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1){
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1);
			break;
		}
	}
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1){
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
			while(1){	
					//led yellow blink 1HZ
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);//R1
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);//Y1
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);//G1
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);//R2
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);//Y2
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);//G2
				HAL_Delay(500);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);//Y1
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);//Y2
				HAL_Delay(500);
				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 1){
					//while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 1);
					break;
					status = 0;
				}

	}
		}
	}



void display7Seg(int data){
	switch (data)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
			break;
	 case 7:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);		
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
			break;
	}
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
  hi2c1.Init.ClockSpeed = 100000;
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
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA2 PA3 PA4 PA5
                           PA6 PA7 PA8 PA9
                           PA10 PA11 PA12 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB14 PB15
                           PB3 PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
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

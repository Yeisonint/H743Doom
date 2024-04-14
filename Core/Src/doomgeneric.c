#include "doomgeneric.h"
#include "doomkeys.h"
//#include "cmsis_os.h"
#include "lcd.h"

uint16_t* DG_ScreenBuffer;
static uint32_t time_since_last_key;
//extern ST7735_Object_t st7735_pObj;
extern ST7735_IO_t st7735_pIO;

void DG_Init()
{
  time_since_last_key = DG_GetTicksMs();

  // Init LCD
  ST7735Ctx.Orientation = ST7735_ORIENTATION_LANDSCAPE_ROT180;
  ST7735Ctx.Panel = HannStar_Panel;
  ST7735Ctx.Type = ST7735_0_9_inch_screen;
  ST7735_RegisterBusIO(&st7735_pObj,&st7735_pIO);
  ST7735_LCD_Driver.Init(&st7735_pObj,ST7735_FORMAT_RBG565,&ST7735Ctx);
  ST7735_LCD_Driver.ReadID(&st7735_pObj,&st7735_id);
//  ST7735_LCD_Driver.DrawBitmap(&st7735_pObj,0,0,yeisonint_logo_160_80);

  // Screen Buffer
  DG_ScreenBuffer = calloc(DOOMGENERIC_RESX * DOOMGENERIC_RESY, sizeof(uint16_t));

  time_since_last_key = DG_GetTicksMs();
}

static int drew_first_frame = 0;

void DG_DrawFrame()
{
	ST7735_LCD_Driver.DrawBitmap(&st7735_pObj,0,0, (uint8_t *)DG_ScreenBuffer);

	if(!drew_first_frame)
	{


	}

	drew_first_frame = 1;
}

void DG_SleepMs(uint32_t ms)
{
//	osDelay(ms);
	HAL_Delay(ms);
}

uint32_t DG_GetTicksMs()
{
//	return xTaskGetTickCount()/configTICK_RATE_HZ ;
	return HAL_GetTick();
}

const int a[][2] = {
		{KEY_ENTER,         1},
		{KEY_ENTER,         0},
		{KEY_ENTER,         1},
		{KEY_ENTER,         0},
		{KEY_ENTER,         1},
		{KEY_ENTER,         0},
		{KEY_ENTER,         1},
		{KEY_ENTER,         0},
		{KEY_ENTER,         1},
		{KEY_ENTER,         0},

		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		//{KEY_UPARROW,       1},
		{KEY_UPARROW,       0},
		{KEY_LEFTARROW,       1},
		{KEY_LEFTARROW,       1},
		{KEY_LEFTARROW,       1},
		{KEY_LEFTARROW,       0},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       0},
		{KEY_LEFTARROW,       1},
		{KEY_LEFTARROW,       0},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		//{KEY_UPARROW,       1},
		{KEY_UPARROW,       0},
		{KEY_RIGHTARROW,       1},
		{KEY_RIGHTARROW,       0},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       0},
		{KEY_LEFTARROW,       1},
		{KEY_LEFTARROW,       0},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       0},
		{KEY_RIGHTARROW,       1},
		{KEY_RIGHTARROW,       0},
		{KEY_UPARROW,       1},
		{KEY_UPARROW,       0},
		{KEY_FIRE,       1},
		{KEY_FIRE,       0},
		{KEY_FIRE,       1},
		{KEY_FIRE,       0},
		{KEY_FIRE,       1},
		{KEY_FIRE,       0},
};
int index1 = 0;

int DG_GetKey(int* pressed, unsigned char* key)
{
//	if(!drew_first_frame)
//	{
//		return 0;
//	}
//	if(index1 == sizeof(a) / sizeof(a[0]))
//	{
//		return 0;
//	}
//	if(DG_GetTicksMs() - time_since_last_key > 200)
//	{
//		*pressed = a[index1][1];
//		*key = a[index1][0];
//		time_since_last_key = DG_GetTicksMs();
//		++index1;
//		return 1;
//	}
	return 0;
}

void DG_SetWindowTitle(const char * title)
{

}

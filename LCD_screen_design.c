#include "mbed.h"
#include "TS_DISCO_F429ZI.h"
#include "LCD_DISCO_F429ZI.h"

LCD_DISCO_F429ZI lcd;
TS_DISCO_F429ZI ts;

int main()
{
    uint16_t x, y;
    uint16_t xsize = lcd.GetXSize();
    uint16_t ysize = lcd.GetYSize();
    TS_StateTypeDef TS_State;
    DigitalOut led_green(LED1);
    DigitalOut led_red(LED2);
    led_red = 0;
    led_green = 0;

    lcd.Clear(LCD_COLOR_WHITE);  // ekranin arka planý


    lcd.SetFont(&Font16);
    lcd.SetTextColor(LCD_COLOR_DARKRED);
    lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"Tevhit Karsli", CENTER_MODE);

    lcd.SetFont(&Font16);
    lcd.SetTextColor(LCD_COLOR_MAGENTA);
    lcd.DisplayStringAt(0, LINE(4), (uint8_t *)"Software Engineering", CENTER_MODE);


    uint16_t w1, w2, h1, h2;
    uint16_t x1, y1, x2, y2;
    w1 = xsize - 20;
    h1 = 60;
    x1 = 10;
    y1 = 120;
    w2 = xsize - 20;
    h2 = 60;
    x2 = 10;
    y2 = 200;

    lcd.SetTextColor(LCD_COLOR_RED);
    lcd.FillRect(x1, y1, w1, h1);

    lcd.SetTextColor(LCD_COLOR_GREEN);
    lcd.FillRect(x2, y2, w2, h2);

    lcd.SetFont(&Font20);
    lcd.SetBackColor(LCD_COLOR_RED);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.DisplayStringAt(0, LINE(7), (uint8_t *)"RED LED", CENTER_MODE);

    lcd.SetFont(&Font20);
    lcd.SetBackColor(LCD_COLOR_GREEN);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.DisplayStringAt(0, LINE(11), (uint8_t *)"GREEN LED", CENTER_MODE);


    while(1)
    {
        ts.GetState(&TS_State);

        if (TS_State.TouchDetected)
        {
            x = TS_State.X;
            y = TS_State.Y;
            if((x > 10 & x < xsize-20)&(y > 120 & y < 180))
            {
                led_red=!led_red;

            }

            if((x>10 & x<xsize-20)&(y>200 & y<260))
            {
                led_green=!led_green;
            }

        }
    }
}

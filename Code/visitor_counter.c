#include <reg51.h>

sbit S1 = P1^0;
sbit S2 = P1^1;

sbit RS = P3^0;
sbit EN = P3^1;

#define LCD P2

int count = 0;

void delay()
{
    int i,j;
    for(i=0;i<300;i++)
    for(j=0;j<1000;j++);
}

void lcd_cmd(unsigned char cmd)
{
    LCD = cmd;
    RS = 0;
    EN = 1;
    delay();
    EN = 0;
}

void lcd_data(unsigned char dat)
{
    LCD = dat;
    RS = 1;
    EN = 1;
    delay();
    EN = 0;
}

void lcd_init()
{
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
}

void display()
{
    lcd_cmd(0x80);
    lcd_data('V');
    lcd_data('i');
    lcd_data('s');
    lcd_data('i');
    lcd_data('t');
    lcd_data('o');
    lcd_data('r');
    lcd_data('s');

    lcd_cmd(0xC0);
    lcd_data((count/10)+'0');
    lcd_data((count%10)+'0');
}

void main()
{
    lcd_init();
    display();

    while(1)
    {
        if(S1==0)      // Sensor 1 triggered
        {
            delay();

            if(S2==0)  // Entry detected
            {
                count++;
                display();

                while(S1==0 || S2==0); // wait until sensors released
            }
        }

        if(S2==0)      // Sensor 2 triggered
        {
            delay();

            if(S1==0)  // Exit detected
            {
                if(count>0)
                count--;

                display();

                while(S1==0 || S2==0);
            }
        }
    }
}

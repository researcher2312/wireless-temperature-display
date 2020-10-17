/*****************************************************************************
* | File      	:   EPD_7in5bc_HD_test.c
* | Author      :   Waveshare team
* | Function    :   5.83inch B&C e-paper test demo
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2019-06-13
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "EPD_Test.h"
#include "EPD_7in5b_HD.h"
#include "ImageData.h"

int EPD_7in5b_HD_test(void)
{
    printf("EPD_7IN5B_HD_test Demo\r\n");
    if(DEV_Module_Init()!=0){
        return -1;
    }

    printf("e-Paper Init and Clear...\r\n");
    EPD_7IN5B_HD_Init();
    EPD_7IN5B_HD_Clear();
    DEV_Delay_ms(500);
//		EPD_7IN5B_HD_ClearRed();
//		DEV_Delay_ms(3000);
//		EPD_7IN5B_HD_ClearBlack();
//		DEV_Delay_ms(3000);

#if 1
    EPD_7IN5B_HD_DisplayImage(gImage_7in5bc_b,gImage_7in5bc_ry,100,50,640,384);
		DEV_Delay_ms(5000);
#endif

    printf("Clear...\r\n");
    EPD_7IN5B_HD_Clear();

    printf("Goto Sleep...\r\n");
    EPD_7IN5B_HD_Sleep();



    // close 5V
    printf("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();
    
    return 0;
}


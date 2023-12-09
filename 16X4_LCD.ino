/* use lcd.print() function to print onto the lcd
 *  
 */

#include <LiquidCrystal.h>

const int rs = 4, en = 2, d4 = 8, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void lcdStart(){
    lcd.begin(20,4);
    delay(100);
}

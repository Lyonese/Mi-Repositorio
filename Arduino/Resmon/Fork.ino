#include <U8glib.h>                           

U8GLIB_SSD1306_128X32 OLED(U8G_I2C_OPT_NONE); 

long int rewrite = 0;                         
const short firstRow = 12;                    
const short secondRow = 27;
const short width = 128;                      

void setup(void) {
  Serial.begin(9600);                         
}

String serialReceive;                         
String CPUstat;
String PROCstat; //Cambiar por SSDstat
String RAMstat;
String RAMtotal;

void loop(void) {
  if(Serial.available() > 0) {                
    serialReceive = Serial.readString();      
  }

  CPUstat = serialReceive.substring(0, 5);
  PROCstat = serialReceive.substring(5, 10);  //Cambiar por SSDstat 
  RAMstat = serialReceive.substring(10, 15);
  RAMtotal = serialReceive.substring(15, 20);     
    
  if (millis()-rewrite > 100) {                
    OLED.firstPage();                          
    do {
      drawOLED();                             
    } while( OLED.nextPage() );
    rewrite = millis();                       
  }
  
  delay(10);                                  
}

void drawOLED(void) {
  OLED.setFont(u8g_font_unifontr);            
  OLED.setPrintPos(0, firstRow);              
  OLED.print("CPU:");                         
  OLED.setPrintPos(35, firstRow);             
  OLED.print(CPUstat);                        
  OLED.setPrintPos(70, firstRow);             
  //OLED.print("%");                           
  OLED.setPrintPos(90, firstRow);             
  OLED.print(PROCstat);   //cambiar por SSDstat                    

  OLED.drawLine(0, firstRow + 2, width, firstRow + 2);  

  OLED.setPrintPos(0, secondRow);             
  OLED.print("RAM:");
  OLED.setPrintPos(35, secondRow);
  OLED.print(RAMstat);
  OLED.setPrintPos(70, secondRow);
  //OLED.print("%");
  OLED.setPrintPos(90, secondRow);
  OLED.print(RAMtotal);
}

#include "HX711.h" 

#define ledon 25 
#define emissor 18
#define DOUT 26                       
#define CLK  27                        

bool lastState = false;

HX711 balanca;                        

float calibration_factor = -22030.00;  

signed long lastTime;


void setup()
{
  Serial.begin(9600);
  balanca.begin(DOUT, CLK);                          
  Serial.println("Balança com HX711 - celula de carga 50 Kg");            
  Serial.println("Pressione t para Tara");           
  balanca.set_scale(calibration_factor);             
  balanca.tare();                                    
  pinMode(emissor, OUTPUT);
  pinMode(ledon, OUTPUT);
  lastTime = millis();
}

void loop()
{
  Serial.print("Peso: ");                            
  Serial.print(balanca.get_units(), 3);            
  Serial.println(" kg");                                                                  
  if (Serial.available())                            
  {
    char temp = Serial.read();                       
    if (temp == 't' || temp == 'T')                  
    {
      balanca.tare();                                
      Serial.println(" Balança zerada");             
    }
  }
   digitalWrite(ledon, HIGH);

  if((millis() - lastTime) > 75)
  {
    if (balanca.get_units() > 1.8)
     {
       if (lastState)
       {
         digitalWrite(emissor, HIGH);
         Serial.println("peso");
       }
       else 
       {
         digitalWrite(emissor, LOW);
       }
        
        lastState = !lastState;

       lastTime = millis();
      }
  }
 
  

} 

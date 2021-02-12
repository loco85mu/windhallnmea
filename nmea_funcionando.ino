const int HALLPin1 = 2;
const int HALLPin2 = 3;
const int HALLPin3 = 4;
const int HALLPin4 = 5;
const int HALLPin5 = 6;
const int HALLPin6 = 7;
const int HALLPin7 = 8;
const int HALLPin8 = 9;
const int HALLPin9 = 10;
int dir;
int i; 
int dirf; 
int veloc;
  
void setup() {
  Serial.begin(38400);
  Serial.println("Esperando sensores");
  pinMode(HALLPin1, INPUT);
  pinMode(HALLPin2, INPUT);
  pinMode(HALLPin3, INPUT);
  pinMode(HALLPin4, INPUT);
  pinMode(HALLPin5, INPUT);
  pinMode(HALLPin6, INPUT);
  pinMode(HALLPin7, INPUT);
  pinMode(HALLPin8, INPUT);
  pinMode(HALLPin9, INPUT);
  }
 
void loop() {
  i=0;
  dir=0;
  if(digitalRead(HALLPin1)==LOW)
  {
    dir= dir + 0; 
    i=i+1;
  }
  if(digitalRead(HALLPin2)==LOW)
  {
    dir=dir + 22;
    i=i+1;   
  }
  if(digitalRead(HALLPin3)==LOW)
  {
   dir=dir + 45;
   i=i+1;  
  }
  if(digitalRead(HALLPin4)==LOW)
  {
    dir=dir + 90;
    i=i+1;  
  }
  if(digitalRead(HALLPin5)==LOW)
  {
    dir=dir + 135;
    i=i+1;  
  }
  if(digitalRead(HALLPin6)==LOW)
  {
    dir=dir + 225;
    i=i +1;   
  }
  if(digitalRead(HALLPin7)==LOW)
  {
    dir=dir + 270;
    i=i +1;   
  }
  if(digitalRead(HALLPin8)==LOW)
  {
    dir=dir + 315;
    i=i +1;  
  }
  if(digitalRead(HALLPin9)==LOW)
  {
    dir=dir + 338;
    i + 1;   
  }
  dirf=dir/i;
  if (dirf>=0) {     /*dir<=135|d|ir>=225*/
    }
    else {dirf = 180;}
    
    
  /*=== MWV - Wind Speed and Angle ===
 *
 * ------------------------------------------------------------------------------
 *         1   2 3   4 5
 *         |   | |   | |
 *  $--MWV,x.x,a,x.x,a*hh<CR><LF>
 * ------------------------------------------------------------------------------
 *
 * Field Number:
 *
 * 1. Wind Angle, 0 to 360 degrees
 * 2. Reference, R = Relative, T = True
 * 3. Wind Speed
 * 4. Wind Speed Units, K/M/N
 * 5. Status, A = Data Valid
 * 6. Checksum
 *
 */
//
// delay to make the output more readable
// build the nmea 0183 string for wind instrument and add checksum
 veloc = 0;
 String Wind = "WIMWV,";                               // WI = Weather instrument MWV wind data
 String WindSpeedUnit = "K,";                          // unit for display N = Nautical Miles
 Wind = Wind + dirf + ",R," + "0" + "," + WindSpeedUnit + "A"; // Builds string to send to serial port
 String data = Wind;
 byte crc = 0;
for(int i=0;i<data.length();i++)                    // creates Checksum for string
 crc=crc^data[i];
Wind="$" + Wind + "*";                              // add line start and end
Serial.print(Wind);                                 // print to serial string
Serial.println(crc,HEX);                            // print checksum and line end

   delay(0);  /*pausa del programa, entre parentesis los milisegundos*/
}

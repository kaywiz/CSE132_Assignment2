/* indicator
 *  
 *  CSE 132 - Assignment 2
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Kelly Wisneski
 *  WUSTL Key: k.wisneski
 *  
 *  and if two are partnered together
 *  
 *  Name:
 *  WUSTL Key:
 */

#define analogPin A0
#define red 11
#define green 9
#define blue 10
int val = 0;
int val1 = 0;
int redVal = 0;
int greenVal = 0;
int blueVal = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val1 = analogRead(analogPin);
  val = analogRead(analogPin);
  if (val1 < 682){
    val = (val1 * 3) / 8; //converts to 255 scale
    redVal = 0;
    greenVal = val;
    blueVal = 255 - val;
    //Serial.print(greenVal);
    //Serial.println(blueVal);
  }
  else{
    greenVal = 0;
    blueVal = 0;
    digitalWrite(red, 255);
    delay(1000);
    digitalWrite(red, 0);
    delay(1000);
  }
  analogWrite(green, greenVal);
  analogWrite(blue, blueVal);
  analogWrite(red, redVal);
  Serial.println(val1);
  delay(50);
}

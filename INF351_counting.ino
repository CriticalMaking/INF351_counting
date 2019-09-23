
/* Code for use in INF 351 - Counting Computer
 *  
 *  for ATTiny 
 *  

   History
   =======
   2019/Sept/23  - First release (mattratto)
*/

int LED1 = 0; 

int countNum = 0; 

int BUTTON_A=3;      
int BUTTON_B=4;

int buttonStateA = 0;         // current state of the button
int lastButtonStateA = 0;     // previous state of the button
int buttonStateB = 0;         // current state of the button
int lastButtonStateB = 0;     // previous state of the button

int button_press; 

void setup(void)
{
  
pinMode(LED1, OUTPUT);


digitalWrite(LED1, HIGH); 

delay(2000); 
digitalWrite(LED1, LOW); 


pinMode(BUTTON_A, INPUT);
pinMode(BUTTON_B, INPUT);

}

void loop(void)
{
  //check buttons 
  buttonStateA = digitalRead(BUTTON_A);
  buttonStateB = digitalRead(BUTTON_B);
  
  // compare the buttonState to its previous state
  if (buttonStateA != lastButtonStateA) {
    if (buttonStateA == LOW) { //try with HIGH and LOW - want activate on press or on release?
     button_press =1;
    }     
    }else if (buttonStateB != lastButtonStateB) {
    if (buttonStateB == LOW) { //try with HIGH and LOW - want activate on press or on release?
     button_press =2;
    }   
    }else button_press=0;
      
   lastButtonStateA = buttonStateA; 
   lastButtonStateB = buttonStateB;

// Process data here 
if (button_press ==1) {
  countNum++;
  button_press=0;
}else if (button_press ==2) {
  countNum--;
  button_press=0; 
}

if (countNum ==0) {
  digitalWrite(LED1, HIGH); 
}else digitalWrite(LED1,LOW); 

}

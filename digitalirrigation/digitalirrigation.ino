String Phone_number = "0725233063";
//this code are necessary to run soil moisture sensor
int ledgreen=11;
int ledred=12;
int sensor=2;
int Buzzer=8;
int x;
int c;
int val1;

void setup(){
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(ledgreen,OUTPUT);
  pinMode(ledred,OUTPUT);
  pinMode(Buzzer,OUTPUT); 
  x=digitalRead(sensor);
 Serial.println("AT+CMGD=1,4"); 
}
void loop(){
   if(x == HIGH){
    digitalWrite(ledgreen,LOW);
    delay(1);
  digitalWrite(ledred,HIGH);
  delay(100);
  digitalWrite(ledred,LOW);
  delay(100);
    digitalWrite(ledred,HIGH);
  delay(100);
  digitalWrite(ledred,LOW);
  delay(100);
    digitalWrite(ledred,HIGH);
  delay(100);
  digitalWrite(ledred,LOW);
  delay(1);

  }
    if(x == LOW){
   
    digitalWrite(ledred,LOW);
    delay(1);
    digitalWrite(ledgreen,HIGH);
   
    delay(1);
    
    
 }
 
    val1 = digitalRead(sensor); //read  input value and store it in val
  {
  if (val1 != x) //button state has chanded
  {
    if (val1 == HIGH) // check if the button is pressed
    {
  Serial.println("AT");  				
  delay(200);
  Serial.println("AT+CMGF=1");
  delay(200);
  Serial.print("AT+CMGS=\"");  	 Serial.print(Phone_number);
  Serial.println("\"");
  delay(200);
  Serial.println(" THERE IS NO WATER IN YOUR SOIL IT IS TIME TO IRRIGATE ");
  delay(500);  
  digitalWrite(Buzzer, HIGH);
  delay(500);
  digitalWrite(Buzzer, LOW);			
  delay(100);
  Serial.write(26);  	
    }
    delay(1);
  }
 x = val1; // save the new state in our variable
  
  }
}

 
 
		  


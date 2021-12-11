String Phone_number = "0736443885";
int led=13;
int Buzzer = 8;
int val1;           // variable for reading the pin status
int x;  // variable to hold the last button state
void setup()
{
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
  x = analogRead(A0); // read the initial state
Serial.println("AT+CMGD=1,4"); 
}

void loop()
{
    int sensorReading=analogRead(A0);
  Serial.println(sensorReading);
  if(sensorReading>800){
  digitalWrite(led,HIGH);
  }
  if(sensorReading>1000){
    digitalWrite(led,LOW);
  }
  val1 = analogRead(A0); //read  input value and store it in val
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
  Serial.println("It is time to irrigate");
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

 
 
		  


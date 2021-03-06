//Aref voltage
const float aref_voltage = 3.29; // tie 3.3V to ARef and measure it with a multimeter
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading
const int sensor1 = 0; // Assigning analog pin A0 to variable 'sensor1'
const int sensor2 = 1; // Assigning analog pin A1 to variable 'sensor2'

//Sets up the LM35 sensor
void LM35setup(){
  pinMode(sensor1,INPUT); // Configuring pin A0 as input
  analogReference(EXTERNAL);
}

//Setup dual LM35s for reading
void LM35DualSetup(){
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  analogReference(EXTERNAL);
}

//Converts sensor data to Celsius
float tempCelsius(int sensor){
  vout=analogRead(sensor);
  vout=(vout*aref_voltage)*100;
  vout /= 1023.0;
  tempc=vout; // Storing value in Degree Celsius
  return tempc;
}

//Converts Celsius to Fahrenheit
float tempFahrenheit(int sensor){
  tempf=(tempCelsius(sensor)*1.8)+32; // Converting to Fahrenheit 
  return tempf;
}

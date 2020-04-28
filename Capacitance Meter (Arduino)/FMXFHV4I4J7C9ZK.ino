/*
	CAPACITANCE METER WITH THE ARDUINO AND THE 741 OPAMP
 	----------------------------------------------------
 	I begin this project after another one named "Capacitance Meter with Arduino and 555 Timer"
 	which resulted in a very simple circuit capable to measure capacitances in the
 	range of about 1 nF to several hundreds of uF.
 	This time I decided to design another capacitance meter but now with the well known and
 	versatile 741 opamp and the arduino.
 	And again I ended up with a very simple and easy to implement project whose programming.
 	is contained in these lines of code.
 	The precition this time is in the range of about 20 pF to hundreds of uF.
 */

float R = 1.0e6;                	//This resistor is part of the RC circuit.
                                        // 0 < C <= 10nF => R = 1 Mohm
                                        // 10 nF < C <= 300 uF => R = 10 kohm
                                        // 300 uF < C <= 2000 uF => R = 1 kohm
float C = 0.;                   	//And this is the capacitor whose capacitance we want to find out.
float RC = 0.;                  	//Variable to hold the RC constant that we'll calculate.
long t_start = 0;              		//Here we'll record the time when the charging process starts.
volatile long t_stop = 0;     		//This variable will keep the time when the charge reaches Vref = VCC/2.
long T = 0;                     	//The time elapsed during the charging from 0V to Vref (T = t_final - t_inicio)
float VCC = 4.50;               	//This value was measured with a voltmeter at the theoretically 5V ouput pin of arduino.
float Vref = VCC / 2;       		//Vref is half VCC because we chose two equal resistors for the voltage divider.
float V0 = 0;				//This is the intitial charge of the capacitor. It is zero because we discharge it completely.
int led_pin = 12;              		//Pin for a led (it is turned on during the charging process).
int source_pin = 11;			//Pin for feeding the circuit RC with VCC via programming.
int switch_pin = 10;			//Pin associated with the push-button switch.
int discharge_pin = 9;			//Pin conected to the R-C node to discharge the capacitor.
float error_correction = 40.;    	//This represents the amount of parasitic capacitance in picoFarads of the circuit
                                        //obtained taking readings without any capacitor installed.
int debounce_delay = 20;                //Time in milliseconds to wait until the push button ends bouncing.


void setup()
{
  Serial.begin(9600);
  attachInterrupt(1, stop, RISING);     //This interrupt is associated with pin 3 (it will detect when the 741 output goes up to HIGH.
  Vref = VCC / 2;						//As said before, because the resistors of the voltage divider are equal.
  pinMode(led_pin, OUTPUT);
  pinMode(source_pin, OUTPUT);
  digitalWrite(source_pin, LOW);        //The RC circuit will not be powered by default.
  pinMode(switch_pin, INPUT);
  pinMode(discharge_pin, INPUT);	//INPUT mode puts this pin into a high impedance state.
  digitalWrite(led_pin, LOW);
}

void loop()
{
  //If the button was pushed we wait for it to get stabilized.
  if(debounce(switch_pin) == LOW)
  {
    pinMode(discharge_pin, OUTPUT);	//We change the mode to OUTPUT so we can set it to low (ground)
    digitalWrite(discharge_pin, LOW);	//This will discharge the capacitor and send the output voltage to LOW.
    delay(100);				//A little delay just to be sure the capacitor gets completely discharged.
    pinMode(discharge_pin, INPUT);	//Setting the pin as INPUT again puts the terminal in a high impedance state
                                        //so it doesn't load the RC circuit influencing the measurement.
                                        //This also starts the capacitor charging process so we must register this instant.
    digitalWrite(source_pin, HIGH);	//We put VCC to source the RC circuit.
    t_start = micros();			//Here we record the initial time.
    digitalWrite(led_pin, HIGH);	//The led is turned on.
  }

  /*When the capacitor reaches Vref (VCC/2), the output of the opamp will go up to HIGH (from 2V to VCC-2V in the 741) and this will fire
   	interrupt 1 associated to pin 3 and the stop() funcion will inmediately be executed by the arduino.
   	The stop() function registers the time when this interrupt takes place in the t_stop variable which will no longer be 0.
   	To enter the following block where the calculations are made, the initial 3 conditions must be met.
   	This is so because I need to filter false readings due to noise when the voltage at the two inputs are iqual.*/
  if (t_stop > 0 and t_start > 0 and (t_stop - t_start) > 0 )
  {
    T = (t_stop - t_start);		//T in microseconds
    RC = -T / log((Vref - VCC) / (V0 - VCC)); 	//VCC = 5V or the value you measured.
    //Vref = VCC/2
    //V0 = 0V
    C = RC / R;				//C in microFarads
    digitalWrite(led_pin, LOW);		//The process has finished, so we turn the led off.

    //Data transmission through serial port
    Serial.println("-----------------------");
    Serial.print("C = ");
    Serial.print(C, 1);
    Serial.println(" uF");
    Serial.print("C = ");
    Serial.print(C * 1000, 1);
    Serial.println(" nF");
    Serial.print("C = ");
    Serial.print(C * 1000000 - error_correction , 0);     //The correction applied has the most influence in very low value capacitors ( picoFarads)
    Serial.println(" pF");
    Serial.println("-----------------------");
    Serial.println();

    //Time variables are reset so the system
    //gets ready for a new measurement.
    t_start = 0;
    t_stop = 0;

    digitalWrite(source_pin, LOW);	//We take off the power from the R-C circuit.
  }
}

// Function attached to interrupt 1
void stop()
{
  t_stop = micros();    //Final time saved.
}

// This function returns the state (HIGH or LOW) of the switch when it gets stabilized
int debounce(int pin)
{
  int state;
  int previous_state;
  previous_state = digitalRead(pin); // store switch state
  for(int counter = 0; counter < debounce_delay; counter++)
  {
    delay(1);                       // wait for 1 millisecond
    state = digitalRead(pin);       // read the pin
    if( state != previous_state)
    {
      counter = 0;                  // reset the counter if the state changes
      previous_state = state;       // and save the current state
    }
  }
  return state;
}



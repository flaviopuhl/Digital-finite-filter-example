int buttonInput 			= 2;		//  Defines the pin of the digital input
int input_non_filtered 		= 0;		
float input_filtered 		= 0;		//	Filtered signal
float input_filtered_prev	= 0;		// 	Filtered signal from previous interation
float alpha 				= 0.05;		//	Filter coefficient.  1 means no filter. As lower the value, more filtered is the signal
int input_state 			= 0;		//  Stores the digital input state


void setup()
{
  Serial.begin(9600);					// Enable serial comm
  
  pinMode(buttonInput, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
    
  input_non_filtered = digitalRead(buttonInput);	// Read the digital input
  
  
  input_filtered = alpha * input_non_filtered + (1-alpha) * input_filtered_prev;
      
  input_filtered_prev = input_filtered;
  
  	if(input_filtered >= 0.95){	input_state = 1;	}
  	if(input_filtered <= 0.05){ input_state = 0;    }
  
  
  if (input_state == 1) {
    // turn LED on
    digitalWrite(13, HIGH);
  } else {
    // turn LED off
    digitalWrite(13, LOW);
  }
  
 
  Serial.print(input_non_filtered);
  Serial.print(","); 
  Serial.print(input_filtered);
  Serial.print(","); 
  Serial.print(input_state);
  Serial.println();
  
  delay(1); // Delay a little bit to improve simulation performance
}



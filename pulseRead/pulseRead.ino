const int pulsePin = 5;

//define some useful vars
unsigned long cur_pulse = 0;

void setup() {
  //set pinmodes
  pinMode(13, OUTPUT);
  pinMode(pulsePin, INPUT);

  //begin serial
  Serial.begin(9600);
}

void loop() {
    Serial.println("Reading pulse width");
    readPulse();
    if (cur_pulse < 25000L){
        Serial.println("Fwd");
    }
    else if (cur_pulse < 35000L){
        Serial.println("Right");
    }
    else if (cur_pulse < 45000L){
        Serial.println("Left");
    }
    else {
        Serial.println("Stop");
    }
    
}

void readPulse(){
    cur_pulse = 0;
    while(cur_pulse < 50000){
        cur_pulse = pulseIn(pulsePin, HIGH);
    }
    return;
}

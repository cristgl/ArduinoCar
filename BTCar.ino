int der1=8;    //In3
int der2=7;    //In4
int izq1=13;   //In1
int izq2=12;   //In2
int PWMizq=11; //ENA
int PWMder=6;  //ENB
int velocidad=150;
int estado = 'g';

void setup() {
  Serial.begin(9600);
  pinMode(der1, OUTPUT); 
  pinMode(der2, OUTPUT);
  pinMode(izq1, OUTPUT); 
  pinMode(izq2, OUTPUT); 
  pinMode(PWMder, OUTPUT);
  pinMode(PWMizq, OUTPUT);

}

void loop() {
  if(Serial.available()>0){
    estado = Serial.read();
  }

  if(estado == 'e'){//forward
    digitalWrite(der1,HIGH);
    digitalWrite(der2,LOW);
    digitalWrite(izq1,LOW);
    digitalWrite(izq2,HIGH);
    analogWrite(PWMder,100);
    analogWrite(PWMizq,100);
  }

  if(estado == 'd'){//right
    digitalWrite(der1,HIGH);
    digitalWrite(der2,LOW);
    digitalWrite(izq1,HIGH);
    digitalWrite(izq2,LOW);
    analogWrite(PWMder,75);
    analogWrite(PWMizq,75);
  }

  if(estado == 'c'){//stop
    digitalWrite(der1,LOW);
    digitalWrite(der2,LOW);
    digitalWrite(izq1,LOW);
    digitalWrite(izq2,LOW);
    analogWrite(PWMder,100);
    analogWrite(PWMizq,100);
  }

  if(estado =='b'){//left
    digitalWrite(der1,LOW);
    digitalWrite(der2,HIGH);
    digitalWrite(izq1,LOW);
    digitalWrite(izq2,HIGH);
    analogWrite(PWMder,75);
    analogWrite(PWMizq,75);
  }

  if(estado == 'a'){//backward
    digitalWrite(der1,LOW);
    digitalWrite(der2,HIGH);
    digitalWrite(izq1,HIGH);
    digitalWrite(izq2,LOW);
    analogWrite(PWMder,100);
    analogWrite(PWMder,100);
  }

}

char serialData;

//motor_A
int IN1 = 9 ;
int IN2 = 8 ;
int velocidadeA = 11;

//motor_B
int IN3 = 7 ;
int IN4 = 6 ;
int velocidadeB = 10;

//variavel auxiliar
int velocidade = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT); // Motor A - Direita
  pinMode(IN2, OUTPUT); // Motor A - Direita - Inverte sentido
  pinMode(IN3, OUTPUT); // Motor B - Esquerda
  pinMode(IN4, OUTPUT); // Motor B - Esquerda - Inverte sentido
  pinMode(velocidadeA, OUTPUT); // Velocidade motor A
  pinMode(velocidadeB, OUTPUT); // Velocidade motor B

}

void loop() {

  if (Serial.available() > 0) {
    serialData = Serial.read();
    Serial.print("Read ");
    Serial.println(serialData);

    if (serialData == 'w') { // Ré
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(velocidadeA, 75);
      analogWrite(velocidadeB, 70);

      delay(2000);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(velocidadeA, 0);
      analogWrite(velocidadeB, 0);
    }

    if (serialData == 's') { // Para frente

      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(velocidadeA, 74);
      analogWrite(velocidadeB, 70);

      delay(2000);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(velocidadeA, 0);
      analogWrite(velocidadeB, 0);
    }

    if (serialData == 'a') { // Para esquerda

      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(velocidadeB, 70);

      delay(980);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(velocidadeA, 0);
      analogWrite(velocidadeB, 0);
      
    }

    if (serialData == 'd') { // Para direita

      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(velocidadeA, 70);


      delay(1000);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(velocidadeA, 0);
      analogWrite(velocidadeB, 0);
      
      
    }

    if (serialData == 'e') { // Parar

      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(velocidadeA, 0);
      analogWrite(velocidadeB, 0);
    }
  }

}

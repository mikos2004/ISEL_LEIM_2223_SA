void setup() {
  Serial.begin(9600);
}

void receiveInt(){
  static const int ESPERA_DIGITO=0;
  static const int RECEBE_DIGITO=1;

  static int num=0;

  static int state = ESPERA_DIGITO;

  switch (state){
    case ESPERA_DIGITO:
    if(Serial.available()>0){
          num = Serial.parseInt();
          state = RECEBE__DIGITO;
        }
    break;

    case RECEBE_DIGITO:
        Serial.println(num);
        num = 0;
        state = ESPERA_DIGITO;
  }
}

void loop() {
  receiveInt();
}
/*
  NAME: Dado Electrónico
  USER: Tomás Martínez
  DATA: 12.08.2022
*/

/**  Pins  **/
#define L7  12
#define L6  11
#define L5  10
#define L4  9
#define L3  8
#define L2  7
#define L1  6
#define KEY 2

/** On/Off leds **/
#define L7on digitalWrite(L7, HIGH)
#define L7off digitalWrite(L7, LOW)
#define L6on digitalWrite(L6, HIGH)
#define L6off digitalWrite(L6, LOW)
#define L5on digitalWrite(L5, HIGH)
#define L5off digitalWrite(L5, LOW)
#define L4on digitalWrite(L4, HIGH)
#define L4off digitalWrite(L4, LOW)
#define L3on digitalWrite(L3, HIGH)
#define L3off digitalWrite(L3, LOW)
#define L2on digitalWrite(L2, HIGH)
#define L2off digitalWrite(L2, LOW)
#define L1on digitalWrite(L1, HIGH)
#define L1off digitalWrite(L1, LOW)

/***** Variables  *****/
byte num = 0;
bool stat = 0;

/*****  myFunctions  *****/
void corre(void);
void siguienteNum(void);
void dado(void);

/*****  SETUP  ***********************/
void setup() {
  pinMode(L7, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L1, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(KEY), corre, CHANGE);
}

/*****  LOOP  ***********************/
void loop() {
  if (stat == 0) {
    siguienteNum();
    dado();
    delay(1000);
  }
}

/*****  MY FUNCTIONS  ***********************/
void corre(void) {
  stat = 1;
  siguienteNum();
  dado();
}

void siguienteNum(void) {
  num++;
  if (num > 6) num = 1;
}

void dado(void) {
  switch (num) {
    case 1: L7off; L6off; L5off; L4on; L3off; L2off; L1off; break;
    case 2: L7on; L6off; L5off; L4off; L3off; L2off; L1on; break;
    case 3: L7off; L6off; L5off; L4on; L3off; L2off; L1off; break;
    case 4: L7on; L6on; L5off; L4off; L3off; L2on; L1on; break;
    case 5: L7on; L6on; L5off; L4on; L3off; L2on; L1on; break;
    case 6: L7off; L6off; L5off; L4on; L3off; L2off; L1off; break;
  }
}

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

//entradas pinos analogicos, para cada porcentagem
int inp25 = A0;
int inp50 = A1;
int inp75 = A2;
int inp100 = A3;

//saidas pinos digitais, para cada porcentagem
int out0 = 1;
int out25 = 2;
int out50 = 3;
int out75 = 4;
int out100 = 5;

int state;//recebe um valor para saber em qual nível está a agua

int sense = 200; //controla a sensibilidade dos pinos de acordo com a corrente elétrica

int retornaValor(int pino){ //retorna 1 para cada pino que estiver em contato com a corrente
  if (analogRead(pino) >= sense){
    return 1;
  } else {
    return 0;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //inicia tela lcd
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.backlight();
  lcd.print("Hello World!");

  //inicia pinos
  pinMode(inp25, INPUT);
  pinMode(inp50, INPUT);
  pinMode(inp75, INPUT);
  pinMode(inp100, INPUT);
  pinMode(out0, OUTPUT);
  pinMode(out25, OUTPUT);
  pinMode(out50, OUTPUT);
  pinMode(out75, OUTPUT);
  pinMode(out100, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //da o valor da variavel state a partir dos pinos que estiverem recebendo corrente
  state = retornaValor(inp25) + retornaValor(inp50) + retornaValor(inp75) + retornaValor(inp100);

  lcd.clear();
  
  //liga os leds e escreve no lcd de acordo com quantos pinos estiverem recebendo corrente
  switch (state){
    case 1:
      digitalWrite(out0, HIGH);
      digitalWrite(out25, HIGH);
      digitalWrite(out50, LOW);
      digitalWrite(out75, LOW);
      digitalWrite(out100, LOW);
      lcd.print("======25%=======");
      break;
    case 2:
      digitalWrite(out0, HIGH);
      digitalWrite(out25, HIGH);
      digitalWrite(out50, HIGH);
      digitalWrite(out75, LOW);
      digitalWrite(out100, LOW);
      lcd.print("======50%=======");
      break;
    case 3:
      digitalWrite(out0, HIGH);
      digitalWrite(out25, HIGH);
      digitalWrite(out50, HIGH);
      digitalWrite(out75, HIGH);
      digitalWrite(out100, LOW);
      lcd.print("======75%=======");
      break;
    case 4:
      digitalWrite(out0, HIGH);
      digitalWrite(out25, HIGH);
      digitalWrite(out50, HIGH);
      digitalWrite(out75, HIGH);
      digitalWrite(out100, HIGH);
      lcd.print("======100%======");
      break;
    default:
      digitalWrite(out0, HIGH);
      digitalWrite(out25, LOW);
      digitalWrite(out50, LOW);
      digitalWrite(out75, LOW);
      digitalWrite(out100, LOW);
      lcd.print("=======0%=======");
      break;
  }
  
  Serial.println(analogRead(inp25));//printa no console para caso de testes
  
  delay(1000);

}

unsigned long tempo = millis();
double flowRate1;
double flowRate2;//Este é o valor que pretende-se calcular
volatile int count1; //Este número precisa ser setado como volátil para garantir que ele seja atualizado corretamente durante o processo de interrupção
volatile int count2;

void setup() {
attachInterrupt(digitalPinToInterrupt(2), Flow1, RISING);//Configura o interruptor 0 (pino 2 no Arduino Uno) para rodar a função "Flow"
attachInterrupt(digitalPinToInterrupt(3), Flow2, RISING);//Configura o interruptor 0 (pino 3 no Arduino Uno) para rodar a função "Flow"
Serial.begin(9600); //Inicia o Serial
}
void loop() {
//SENSOR 1
count1 = 0;//Reseta o contador para iniciarmos a contagem em 0 novamente
count2 = 0;
interrupts();//Habilita o interrupção no Arduino
delay (1000);//Espera 1 segundo
noInterrupts(); //Desabilita o interrupção no Arduino

//Cálculos matemáticos
flowRate1 = (count1 * 2.25);//Conta os pulsos no último segundo e multiplica por 2,25mL, que é a vazão de cada pulso
flowRate1 = flowRate1 * 60;//Converte segundos em minutos, tornando a unidade de medida mL/min
flowRate1 = flowRate1 / 1000;//Converte mL em litros, tornando a unidade de medida L/min
Serial.print(tempo ++);
Serial.print(",");
//Serial.print("Fluxo de Agua Pino2, Sensor 1: ");
Serial.print(" Sensor 1, ");
Serial.println(flowRate1);//Imprime a variável flowRate no Serial
//Serial.print(",");

//SENSOR 2
//Cálculos matemáticos
flowRate2 = (count2 * 2.25);//Conta os pulsos no último segundo e multiplica por 2,25mL, que é a vazão de cada pulso
flowRate2 = flowRate2 * 60;//Converte segundos em minutos, tornando a unidade de medida mL/min
flowRate2 = flowRate2 / 1000;//Converte mL em litros, tornando a unidade de medida L/min

Serial.print(tempo ++);
Serial.print(",");
//Serial.print("Fluxo de Agua Pino3, Sensor 2: ");
Serial.print(" Sensor 2, ");
//Serial.print(",");
//Serial.println(flowRate1);
//
Serial.println(flowRate2);//Imprime a variável flowRate no Serial
//Serial.print(',');


}

void Flow1()
{
count1++; //Quando essa função é chamada, soma-se 1 a variável "count" 
}

void Flow2()
{
count2++; //Quando essa função é chamada, soma-se 1 a variável "count" 
}


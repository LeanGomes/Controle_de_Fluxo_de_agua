int flowPin = 2;    //Este é o pino de entrada no Arduino
double flowRate;    //Este é o valor que pretende-se calcular
volatile int count; //Este número precisa ser setado como volátil para garantir que ele seja atualizado corretamente durante o processo de interrupção
 
void setup() {
  pinMode(flowPin, INPUT); //Seta o pino de entrada
  attachInterrupt(0, Flow, RISING);  //Configura o interruptor 0 (pino 2 no Arduino Uno) para rodar a função "Flow"
  Serial.begin(9600); //Inicia o Serial
}
void loop() {
  count = 0;      // Reseta o contador para iniciarmos a contagem em 0 novamente
  interrupts();   //Habilita o interrupção no Arduino
  delay (1000);   //Espera 1 segundo
  noInterrupts(); //Desabilita o interrupção no Arduino
   
  //Cálculos matemáticos
  flowRate = (count * 2.25);        //Conta os pulsos no último segundo e multiplica por 2,25mL, que é a vazão de cada pulso
  flowRate = flowRate * 60;         //Converte segundos em minutos, tornando a unidade de medida mL/min
  flowRate = flowRate / 1000;       //Converte mL em litros, tornando a unidade de medida L/min
 
  Serial.println(flowRate);         //Imprime a variável flowRate no Serial
}
 
void Flow()
{
   count++; //Quando essa função é chamada, soma-se 1 a variável "count" 
}
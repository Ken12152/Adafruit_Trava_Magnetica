////////////////////////////////// master (ESP-01) /////////////////////////////////
#include <A2a.h>    // (biblioteca de terceiros)

#include "config.h"
#define address 0x08    // endereco configurado igual do arduino

// feeds adafruit
AdafruitIO_Feed *button = io.feed("button");

// comunicacao com slave arduino
A2a ConexaoComArduino;

void setup()
{
  ConexaoComArduino.begin(0, 2);  // GPIO_0, GPIO_2

  
  // adafruit
  io.connect();
  
  button->onMessage(callback);    // configura funcao pra executar quando receber dados do portal Adafruit

  while(io.status() < AIO_CONNECTED) {      // espera conectar
    delay(500);
  }

  button->get();    // armazena ultimo valor do botao do portal Adafruit (normalmente vai ser '0' pq nao vai estar acionado)
  io.run();    
}


void loop()
{
  io.run();

  // Adafruit IO is rate limited for publishing, so a delay is required in
  // between feed->save events. In this example, we will wait three seconds
  // (1000 milliseconds == 1 second) during each loop.
  //delay(3000);

  // Because this sketch isn't publishing, we don't need
  // a delay() in the main program loop.
}


void callback(AdafruitIO_Data *data)    // funcao realizado quando receber dados do portal Adafruit
{
  if(data->toInt() == 1) {    // quando botao for acionado no portal Adafruit envia valor '1'
    ConexaoComArduino.varWireWrite(address, 0, byte(data->toInt()));    // notifica arduino q botao foi acionado 
  }
}

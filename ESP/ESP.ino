#include "config.h"

// nome do feed configurado no adafruit e 'button'
AdafruitIO_Feed *button = io.feed("button");

void setup()
{
  Serial.begin(115200);

  //////////////////////////////////////////
  // Adafruit
  io.connect();
  
  button->onMessage(callback);

  while(io.status() < AIO_CONNECTED) {
    delay(500);
  }

  button->get();
  io.run();
  //////////////////////////////////////////
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


// funcao realizado quando receber dados do portal Adafruit
// (quando pressionar botao)
void callback(AdafruitIO_Data *data)
{
  Serial.write(data->toInt());
}

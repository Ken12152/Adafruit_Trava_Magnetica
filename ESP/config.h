/************************ Adafruit IO Config *******************************/

// Adafruit IO Username and key.
#define IO_USERNAME   "Felipe_Kenzo"
#define IO_KEY        "aio_AogD22DldrC0Em9bhhgMUCbudHZI"

/******************************* WIFI **************************************/

#define WIFI_SSID   "*****"
#define WIFI_PASS   "*****"

#include "AdafruitIO_WiFi.h"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

/****************************************************************************/


#ifdef F_CPU
#undef F_CPU
#define F_CPU 1000000L
#endif


// General settings
#define SKETCH_NAME "Temp&Wilg"
#define SKETCH_VERSION "1.02"
#define MY_NODE_ID 25

// NRF24 radio settings
#define MY_RF24_CE_PIN 8
#define MY_RF24_CS_PIN 9
#define MY_RADIO_NRF24
//#define MY_RF24_ENABLE_ENCRYPTION
//#define MY_RF24_CHANNEL 125
//#define MY_RF24_PA_LEVEL RF24_PA_HIGH
//#define MY_DEBUG_VERBOSE_RF24
//#define MY_RF24_DATARATE RF24_250KBPS


// Optimizations when running on 2032 Coin Cell. Also set nodeManager.setSleepBetweenSend(500) and run the board at 1Mhz
#define MY_TRANSPORT_UPLINK_CHECK_DISABLED
#define MY_TRANSPORT_WAIT_READY_MS  5000
#define MY_SLEEP_TRANSPORT_RECONNECT_TIMEOUT_MS 2000
//#define MY_PARENT_NODE_ID 0
//#define MY_PARENT_NODE_IS_STATIC

/***********************************
* NodeManager configuration
*/

#define NODEMANAGER_SLEEP ON
#define NODEMANAGER_CONDITIONAL_REPORT ON




// import NodeManager library (a nodeManager object will be then made available)
#include <MySensors_NodeManager.h>

/***********************************
* Add your sensors
*/

// Add a battery sensor
#include <sensors/SensorBattery.h>
SensorBattery battery;

#include <sensors/SensorHTU21D.h>
SensorHTU21D htu21;

/***********************************
* Main Sketch
*/

// before
void before() {

/***********************************
* Configure your sensors
*/

	// set reporting interval for all the sensors to 1 minute
	nodeManager.setReportIntervalMinutes(5);
	// set sleep interval to 1 minute
	nodeManager.setSleepMinutes(5);
  battery.setReportIntervalMinutes(240);

  htu21.children.get(1)->setForceUpdateTimerValue(30);
  battery.setMinVoltage(2.1);
  battery.setMaxVoltage(2.6);
  

	// call NodeManager before routine
	nodeManager.before();
}

// presentation
void presentation() {
	// call NodeManager presentation routine
	nodeManager.presentation();
}

// setup
void setup() {
	// call NodeManager setup routine
	nodeManager.setup();
}

// loop
void loop() {
	// call NodeManager loop routine
	nodeManager.loop();
}

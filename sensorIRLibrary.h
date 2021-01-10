//-------------Library For Access MLX90614----------------
#include <Wire.h>
#include <Adafruit_MLX90614.h>

//-------------Setup MLX Sensor-------------------------
#define I2C_ADDR 0x27 //I2C adress for MLX90614
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

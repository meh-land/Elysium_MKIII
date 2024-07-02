#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050_6Axis_MotionApps20.h>

float euler[3];   // [psi, theta, phi] Euler angle
uint8_t fifoBuffer[64]; // FIFO storage buffer
Quaternion q;           // [w, x, y, z] quaternion 
MPU6050 mpu;

//Give the gyro time to start
Wire.setSDA(PB11);
Wire.setSCL(PB10); 
Wire.begin();
Wire.setClock (400000);
// Initialize the MPU6050
mpu.initialize();
mpu.dmpInitialize();
// Calibration Time: generate offsets and calibrate our MPU6050
mpu.CalibrateAccel(6);
mpu.CalibrateGyro(6);
//mpu.PrintActiveOffsets();   
mpu.setDMPEnabled(true);

if(mpu.dmpGetCurrentFIFOPacket(fifoBuffer)){
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetEuler(euler, &q);
    Mpu_Values.data =euler[0] * 180/M_PI;
    Mpu_pub.publish(&Mpu_Values);
}
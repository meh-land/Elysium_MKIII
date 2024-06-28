class Encoder{
  public:
    long counts; ///<encoder counts
    Encoder(float resolution); // constructor
    void setup();
    float calcspeed();
    
  private :
     int prevcount = 0;     ///<previous counts of the encoder
     float prevtime;        ///<previous time of the calculation
     float Espeed = 0 ;     ///<speed of the motor
     float  resolution = 0; ///<the resolution of the encoder
};

float Encoder::calcspeed(){
  float current_time=millis();
  long newcount=counts;
  int dp=newcount-prevcount;
  float dt=current_time- prevtime;
  // calc speed
  Espeed=(60*1000/resolution)*(dp/dt);//in RPM,{speed=dp/dt in counts/ms}
  prevcount=counts; //update postition
  prevtime=current_time; //update time
  return Espeed;
}

class ISR_Encoder : public Encoder{
    public:
        uint8_t PinA;   ///<the first pin of the encoder
        uint8_t PinB;   ///<the second pin if the encoder
    // constructor
    ISR_Encoder(float resolution, uint8_t pinA, uint8_t pinB);
    // method for interrupts on encoder pin A
    void update_ISR_A(void);
    // method for interrupts on encoder pin B
    void update_ISR_B(void);
    // method for encoder setup
    void setup();
};

void ISR_Encoder::setup()
{
    pinMode(PinA, INPUT_PULLUP);
    pinMode(PinB, INPUT_PULLUP);
}

void ISR_Encoder::update_ISR_B(void)
{
    if (digitalRead(PinA) != digitalRead(PinB))
        counts++;
    else
        counts--;
}
void ISR_Encoder::update_ISR_A(void)
{
    if (digitalRead(PinA) == digitalRead(PinB))
        counts++;
    else
        counts--;
}



//Encoder Objects
ISR_Encoder MOTOR_Encoder[] {ISR_Encoder(RESOLUTION,ENCODER_FL_A, ENCODER_FL_B),
                             ISR_Encoder(RESOLUTION,ENCODER_FR_A, ENCODER_FR_B),
                             ISR_Encoder(RESOLUTION,ENCODER_BL_A, ENCODER_BL_B),
                             ISR_Encoder(RESOLUTION,ENCODER_BR_A, ENCODER_BR_B)
                             };
float wheel_speeds [] = {0, 0, 0, 0};
long wheel_pwm [] = {0,0,0,0};
long encoder_counts[] = {0, 0, 0, 0};
float encoder_feedback[] = {0, 0, 0, 0};


//*** Attaching intterupts to the encoder pins ***//
  attachInterrupt(digitalPinToInterrupt(MOTOR_Encoder[0].PinA), Motor_FL_ISR_EncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MOTOR_Encoder[0].PinB), Motor_FL_ISR_EncoderB, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MOTOR_Encoder[1].PinA), Motor_FR_ISR_EncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MOTOR_Encoder[1].PinB), Motor_FR_ISR_EncoderB, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MOTOR_Encoder[2].PinA), Motor_BL_ISR_EncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MOTOR_Encoder[2].PinB), Motor_BL_ISR_EncoderB, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MOTOR_Encoder[3].PinA), Motor_BR_ISR_EncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MOTOR_Encoder[3].PinB), Motor_BR_ISR_EncoderB, CHANGE);








void speedControl()
{
  // Drive Motor FL
  digitalWrite(MOTOR_FL_IN1, wheel_pwm[0] > 0);
  digitalWrite(MOTOR_FL_IN2, wheel_pwm[0] < 0);
  analogWrite(MOTOR_FL_EN, constrain(abs(wheel_pwm[0]), MIN_VEL, MAX_VEL));
  // Drive Motor FR
  digitalWrite(MOTOR_FR_IN1, wheel_pwm[1] > 0);
  digitalWrite(MOTOR_FR_IN2, wheel_pwm[1] < 0);
  analogWrite(MOTOR_FR_EN, constrain(abs(wheel_pwm[1]), MIN_VEL, MAX_VEL));

  // Drive Motor BL
  digitalWrite(MOTOR_BL_IN1, wheel_pwm[2] > 0);
  digitalWrite(MOTOR_BL_IN2, wheel_pwm[2] < 0);
  analogWrite(MOTOR_BL_EN, constrain(abs(wheel_pwm[2]), MIN_VEL, MAX_VEL));
  // Drive Motor BR
  digitalWrite(MOTOR_BR_IN1, wheel_pwm[3] > 0);
  digitalWrite(MOTOR_BR_IN2, wheel_pwm[3] < 0);
  analogWrite(MOTOR_BR_EN, constrain(abs(wheel_pwm[3]), MIN_VEL, MAX_VEL));
}

void Motor_FL_ISR_EncoderA()
{
  MOTOR_Encoder[0].update_ISR_A();
}
void Motor_FL_ISR_EncoderB()
{
  MOTOR_Encoder[0].update_ISR_B();
}
void Motor_FR_ISR_EncoderA()
{
  MOTOR_Encoder[1].update_ISR_A();
}
void Motor_FR_ISR_EncoderB()
{
  MOTOR_Encoder[1].update_ISR_B();
}
void Motor_BL_ISR_EncoderA()
{
  MOTOR_Encoder[2].update_ISR_A();
}
void Motor_BL_ISR_EncoderB()
{
  MOTOR_Encoder[2].update_ISR_B();
}
void Motor_BR_ISR_EncoderA()
{
  MOTOR_Encoder[3].update_ISR_A();
}
void Motor_BR_ISR_EncoderB()
{
  MOTOR_Encoder[3].update_ISR_B();
}
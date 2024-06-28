class PIDControl{
    public:
        PIDControl(float Kp,float Ki,float Kd, float sample_time);
        float calculateOutput(float feedBack);
        void set_parameters(float Kp, float Ki, float Kd);
        void set_setpoint(float setpoint);
    private:
        float Kp = 0, Ki = 0, Kd = 0; 
        float sample_time; 
        float error, previous_error;
        float integralTerm, derivativeTerm; 
        float output;
        float setpoint;
};


float  PIDControl::calculateOutput(float feedBack) {
    error = setpoint - feedBack; 
    integralTerm += Ki * (error * sample_time); 
    integralTerm = constrain(integralTerm,minIntegral,maxIntegral);
    derivativeTerm = Kd * (error - previous_error) / sample_time; 
    output = Kp * error + integralTerm +  derivativeTerm; 
    previous_error = error; 
    if ((abs(setpoint-feedBack)<DEAD_ZONE)&& (0 == setpoint))
    {
      output = 0;
      integralTerm = 0;
    }
    return output;
}
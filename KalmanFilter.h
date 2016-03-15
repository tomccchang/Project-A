/*
 * KalmnFilter.h
 *
 * Created: 2015/10/19 上午 10:41:41
 *  Author: TomCCChang
 */ 


#ifndef KALMANFILTER_H_
#define KALMANFILTER_H_

volatile typedef struct{
	 unsigned char model_flag; // select dynamic model
	
	 float Q;// process noise (input)
	 float R;// measure noise (input) 
	
	 float K; // innovation gain
	 float P; // reliability
	 float P_pri; // priori reliability
	 float P_prev; // P(n-1) // initial condition // default:1
	
	 float Z; // measurement of signal (input)
	
	 float X; // state of signal 
	 float X_Est; // estimation of X (output)
	 float X_PriEst; // priori estimation of X
	 float X_Est_prev; // estimation of X(n -1) // initial condition 
	
	}KalmanFilter;

//@ time update 	
void KalmanFilterPrdict(KalmanFilter * KM);

//@ measurement update
void KalmanFilterCorrect(KalmanFilter * KM, int Z);



#endif /* KALMNFILTER_H_ */

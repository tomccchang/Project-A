/*
 * KalamanFilter.c
 *
 * Created: 2015/10/19 上午 11:16:02
 *  Author: TomCCChang
 */ 

#include "KalmanFilter.h"

//@ time update
void KalmanFilterPrdict(KalmanFilter * KM){
	
	KM->X_PriEst = KM->X_Est_prev; // static model
	KM->P_pri = KM->P_prev + KM->Q;
}

//@ measurement update
void KalmanFilterCorrect(KalmanFilter * KM, int Z){
	KM->Z = Z;
	
	KM->K = KM->P_pri / (KM->P_pri + KM->R);
	KM->X_Est = KM->X_PriEst + KM->K * (Z - KM->X_PriEst);
	KM->P = (1 - KM->K) * KM->P_pri;
	
	// frame update
	KM->X_Est_prev = KM->X_Est;
	KM->P_prev = KM->P;
}

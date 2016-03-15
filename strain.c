/*
* Strain.c
*
* Created: 2015/10/6 下午 01:53:46
*  Author: TomCCChang
*/
#include "strain.h"
#include <math.h>
#include <asf.h> // option

void PrinpicalStrain(Strain *p){
	
	volatile double strain0 = (double)(p->strain0);
	volatile double strain45 = (double)(p->strain45);
	volatile double strain90 = (double)(p->strain90);
	
	//Pre-processing
	volatile double s_center=0.5*(strain0 + strain90);
	volatile double ds1=(strain0 - strain45);
	volatile double ds1_sq=ds1*ds1;
	volatile double ds2=strain45 - strain90;
	volatile double ds2_sq=ds2*ds2;
	volatile double ds_sq_sum=ds1_sq+ds2_sq;
	//equation
	volatile double strain_max=s_center+0.7071*sqrt(ds_sq_sum);
	volatile double strain_min=s_center-0.7071*sqrt(ds_sq_sum);
/*	
	volatile double x, angle_rad;
	if (strain0 - strain90 < 1){ // preventing Number/0 or 0/0
		if (strain0 - strain45 < 1){ // 0/0
			angle_rad = 0;
		}
		else{// Number/0
			angle_rad = 0.786375; // PI/4
		}
	}
	else{
		x = (2*strain45 - strain0 - strain90) / (strain0 - strain90);
		angle_rad = 0.5 * atan(x);
	}
*/	
	volatile double x = (2*strain45 - strain0 - strain90) / (strain0 - strain90);
	volatile double angle_rad = 0.5 * atan(x);
	volatile double angle_deg=57.29747 * angle_rad;
	volatile double angle2_deg=2 * angle_deg;
	
	//get angle 2theta in 1st_quadrant and 2nd_quadrant
	volatile double angle_1st_quadrant = 0, angle_2nd_quadrant = 0;
	if(angle2_deg>=0 && angle2_deg<90){
		angle_1st_quadrant=angle2_deg*0.5;
		angle_2nd_quadrant=angle_1st_quadrant+90;
	}
	else if(angle2_deg<0 && angle2_deg>-90)
	{
		angle_1st_quadrant=(180+angle2_deg)*0.5;
		angle_2nd_quadrant=angle_1st_quadrant+90;
	}
	else
	{
		//debug
	}

	//estimate angle2_deg in which quadrant
	if(2*strain45 > strain0 + strain90){
		p->angle_p1_deg = angle_1st_quadrant;
		p->angle_p2_deg = angle_2nd_quadrant;
	}
	else{
		p->angle_p1_deg = angle_2nd_quadrant;
		p->angle_p2_deg = angle_1st_quadrant;
	}

	// detect angle for abs max strain
	volatile double strain_max_abs = abs(strain_max);
	volatile double strain_min_abs = abs(strain_min);
	if(strain_max_abs > strain_min_abs){
		angle_deg = p->angle_p1_deg;
	}
	if(strain_max_abs < strain_min_abs){
		angle_deg = p->angle_p2_deg;
	}

	//store value
	p->strain_max=(int)strain_max;
	p->strain_min=(int)strain_min;
	p->angle_deg = angle_deg;
	p->angle_rad = angle_rad;
}

void  PrinpicalStrainAll(StrainSensorSet *SensorSet){
	int SensorNum = (int)(SensorSet->SensorNum);
	for(int i = 0; i < SensorNum; i++)
	PrinpicalStrain(&(SensorSet->p[i]));
}


void StrainSensorsInit(StrainSensorSet *SensorSet){
	
	// cerate sensor container
	int SensorNum = (int)(SensorSet->SensorNum);
	SensorSet->p = (Strain*)calloc((size_t)SensorNum ,sizeof(Strain));
	// set initial value
	for(int i = 0; i < SensorNum ;i++){
		SensorSet->p[i].ID= i;
		SensorSet->p[i].strain0 = 20;
		SensorSet->p[i].strain45 = 20;
		SensorSet->p[i].strain90 = 20;
		SensorSet->p[i].strain_min = 20;
		SensorSet->p[i].strain_max = 20;
		SensorSet->p[i].angle_rad = 0;
		SensorSet->p[i].angle_deg = 0;
	}
	
}


/*
Serial.println("ID");
Serial.println(int(p->ID));
Serial.println(p->PositionX);
Serial.println(p->PositionY);
Serial.println(int(p->strain0));
Serial.println(int(p->strain45));
Serial.println(int(p->strain90));
Serial.println(int(p->strain_max));
Serial.println(int(p->strain_min));
Serial.println(int(p->angle_deg));
Serial.println("NEXT");
Serial.println(int(p->AbsMaxStrain));
//Serial.println("Debug");//debug
//Serial.println(int(p->AbsMaxStrain));//debug
*/

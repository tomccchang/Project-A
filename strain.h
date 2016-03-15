/*
* strain.h
*
*  version: from V11
*  Changed Item: Prototype Version 1
*  Created: 2015/10/6 下午 01:27:03
*  Author: TomCCChang
*/


#ifndef STRAIN_H_
#define STRAIN_H_





typedef struct{
	// sensor tag
	int ID;
	
	// physic location
	int PositionX, PositionY;
	
	// original measurement
	int strain0;
	int strain45;
	int strain90;

	// principal strain
	int strain_min;
	int strain_max;
	
	// principal strain angle
	double angle_rad;
	double angle_deg;
	double angle_p1_deg ,angle_p2_deg;//angle for strain_max/strain_min
	
}Strain;


typedef struct{

	Strain* p;// Sensors
	int SensorNum;// Sensor Number

}StrainSensorSet;


//@ Prototype @//
// C style
// core algorithm
void PrinpicalStrain(Strain *p);
// strain analyze on sensors;
void  PrinpicalStrainAll(StrainSensorSet *SensorSet);
// Initialize StrainSensorSet
void StrainSensorsInit(StrainSensorSet *SensorSet);


// for override
void SensorPrint(Strain *p);



//void AnalyzeAll();

//class StrainSensors;
/*
class StrainSensors{
public:
// Sensor
Strain* p;
Strain* vp;
int SensorNum;
static const int Isostrain_th = 0;//Threshold for charging strain status in single point
// virtual space
int x_BA ,y_BA; // bending axis position
int bending; // bending Strength
int bending_degree_deg;
int variance;
//
int MostActiveSensorIndex;

//create function
StrainSensors(int SensorNum){
this->SensorNum=SensorNum;
p=new Strain[SensorNum];

vp=new Strain;

for(int i=0; i<SensorNum; i++){
p[i].ID= i;
p[i].strain0 = 0;
p[i].strain45 = 0;
p[i].strain90 = 0;
p[i].strain_min = 0;
p[i].strain_max = 0;
p[i].angle_rad = 0;
p[i].angle_deg = 0;
}

}//StrainSensors

// Strain anal
void AnalyzeOne(int SensorIndex){
PrinpicalStrain(&p[SensorIndex]);
}

void AnalyzeAll(){
for(int i=0; i<SensorNum; i++){
PrinpicalStrain(&p[i]);
}
}

// Print out sensor data
void PrintOne(int SensorIndex){
SensorPrint(&p[SensorIndex]);
}

void PrintAll(){
for(int i=0; i<SensorNum; i++){
SensorPrint(&p[i]);
}
}

};// class StrainSensors
*/
#endif /* STRAIN_H_ */

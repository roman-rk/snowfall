/*--------------------------------------------------
В этом файле объявлены все глобальные переменные
--------------------------------------------------*/
#ifndef EXTERNVARIABLE_H
#define EXTERNVARIABLE_H
      
extern int TemperatureValueNumber;
extern AnsiString TemperatureValue[]; 
extern TRadioButton *TemperatureValueRDB[];

extern int TemperatureChangeNumber;
extern AnsiString TemperatureChange[];
extern TRadioButton *TemperatureChangeRDB[];

extern int PrecipitationNumber;
extern AnsiString Precipitation[];
extern TRadioButton *PrecipitationRDB[];

extern int RoadConditionNumber;
extern AnsiString RoadCondition[];
extern TRadioButton *RoadConditionRDB[];

extern int PeriodNumber;
extern AnsiString Period[];
extern TRadioButton *PeriodRDB[];

extern int ActionNumber;
extern AnsiString ActionName[];

extern int ActionListNumberRow;
extern int ActionList[][8];

extern int RoadMeaningNumber;
extern AnsiString RoadMeaning[];
extern TRadioButton *RoadMeaningRDB[];

extern int VolumeOfTrafficNumber;
extern AnsiString VolumeOfTraffic[];
extern TRadioButton *VolumeOfTrafficRDB[];

extern int DirectiveNumber;
extern AnsiString Directive[];

extern int DirectiveListNumberRow;
extern int DirectiveList[][7];

extern int TemperatureValueIndex;
extern int TemperatureChangeIndex;
extern int PrecipitationIndex;
extern int RoadConditionIndex;
extern int PeriodIndex;
extern int RoadMeaningIndex;
extern int VolumeOfTrafficIndex;
extern double SnowDensity;
extern double SnowThickness;
extern int RecommendedCarIndex;

extern int TemperatureStatus;
extern int PrecipitationStatus;
extern int RoadConditionStatus;
extern int PeriodStatus;
extern int RoadMeaningStatus;
extern int VolumeOfTrafficStatus;
extern int SnowParameterStatus;
extern int DirectiveStatus;

extern int PreviousTemperatureValueIndex;
extern int PreviousTemperatureChangeIndex;
extern int PreviousPrecipitationIndex;
extern int PreviousRoadConditionIndex;
extern int PreviousPeriodIndex;
extern int PreviousRoadMeaningIndex;
extern int PreviousVolumeOfTrafficIndex;
extern double PreviousSnowDensity;
extern double PreviousSnowThickness;

extern AnsiString Message;
extern AnsiString ActionDatabaseName;
extern AnsiString CarDatabaseName;
extern AnsiString SnowfallTempFile1;
extern AnsiString SnowfallTempFile2;

extern int i;
extern int NumberEnabled;
extern int FirstEnabled;
extern int Checked;

extern AnsiString car[];

#endif

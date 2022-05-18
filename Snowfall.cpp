//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Variable.h"
//---------------------------------------------------------------------------
USEFORM("MainWindow.cpp", frm_Main);
USEFORM("TemperatureConditionWindow.cpp", frm_TemperatureCondition);
USEFORM("PrecipitationWindow.cpp", frm_Precipitation);
USEFORM("RoadConditionWindow.cpp", frm_RoadCondition);
USEFORM("PeriodWindow.cpp", frm_Period);
USEFORM("RoadMeaningWindow.cpp", frm_RoadMeaning);
USEFORM("VolumeOfTrafficWindow.cpp", frm_VolumeOfTraffic);
USEFORM("SnowParameterWindow.cpp", frm_SnowParameter);
USEFORM("ActionDatabaseWindow.cpp", frm_ActionDatabase);
USEFORM("CarDatabaseWindow.cpp", frm_CarDatabase);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(Tfrm_Main), &frm_Main);
                 Application->CreateForm(__classid(Tfrm_TemperatureCondition), &frm_TemperatureCondition);
                 Application->CreateForm(__classid(Tfrm_Precipitation), &frm_Precipitation);
                 Application->CreateForm(__classid(Tfrm_RoadCondition), &frm_RoadCondition);
                 Application->CreateForm(__classid(Tfrm_Period), &frm_Period);
                 Application->CreateForm(__classid(Tfrm_RoadMeaning), &frm_RoadMeaning);
                 Application->CreateForm(__classid(Tfrm_VolumeOfTraffic), &frm_VolumeOfTraffic);
                 Application->CreateForm(__classid(Tfrm_SnowParameter), &frm_SnowParameter);
                 Application->CreateForm(__classid(Tfrm_ActionDatabase), &frm_ActionDatabase);
                 Application->CreateForm(__classid(Tfrm_CarDatabase), &frm_CarDatabase);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------

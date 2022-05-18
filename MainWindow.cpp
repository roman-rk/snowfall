//---------------------------------------------------------------------------

#include <vcl.h>
#include "ExternVariable.h"
#include "MainWindow.h"
#pragma hdrstop

#include "TemperatureConditionWindow.h"
#include "PrecipitationWindow.h"
#include "RoadConditionWindow.h"
#include "PeriodWindow.h"
#include "RoadMeaningWindow.h"
#include "VolumeOfTrafficWindow.h"
#include "SnowParameterWindow.h"
#include "ActionDatabaseWindow.h"
#include "CarDatabaseWindow.h"

#include <io.h>
#include <fstream.h>
#include "Functions.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_Main *frm_Main;
//---------------------------------------------------------------------------
__fastcall Tfrm_Main::Tfrm_Main(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_Main::btn_TemperatureConditionClick(TObject *Sender)
{
        /*--------------------------------------------------
        сделать активным окно выбора температурных условий
        сделать неактивным главное окно
        --------------------------------------------------*/
        frm_TemperatureCondition->Show();
        frm_Main->Enabled=false;
}

//---------------------------------------------------------------------------
// Private Functions
//---------------------------------------------------------------------------

string CalculateDump(int car_index) {
       double result = (car_size[car_index] / GripAngleSin) + 0.3f;
       char buffer[32];
       snprintf(buffer, sizeof(buffer), "%g", result);
       return buffer;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::btn_PrecipitationClick(TObject *Sender)
{
        /*--------------------------------------------------
        сделать активным окно выбора типа осадков
        сделать неактивным главное окно
        --------------------------------------------------*/
        frm_Precipitation->Show();
        frm_Main->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::btn_RoadConditionClick(TObject *Sender)
{
        /*--------------------------------------------------
        сделать активным окно выбора дорожных условий
        сделать неактивным главное окно
        --------------------------------------------------*/
        frm_RoadCondition->Show();
        frm_Main->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::btn_PeriodClick(TObject *Sender)
{
        /*--------------------------------------------------
        сделать активным окно выбора периода
        сделать неактивным главное окно
        --------------------------------------------------*/
        frm_Period->Show();
        frm_Main->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::btn_ActionCalculateClick(TObject *Sender)
{
        /*--------------------------------------------------
        если не задано хотя бы одно условие, то
        выдать сообщение о невозможности произвести расчет
        и прекратить выполнение функции
        --------------------------------------------------*/
        if(TemperatureStatus==0 ||
           PrecipitationStatus==0 ||
           RoadConditionStatus==0 ||
           PeriodStatus==0)
        {
                MessageBox(NULL, "Невозможно выполнить расчет операций, так как некоторые условия не определены. Задайте все условия и повторите операцию.",
                           "Внимание!", MB_OK | MB_TASKMODAL);
                return;
        }
        /*--------------------------------------------------
        если все условия заданы, то произвести поиск
        рекомендуемых операций и вывести результат поиска
        --------------------------------------------------*/
        for(i=0;i<ActionListNumberRow;i++)
                if(TemperatureValueIndex==ActionList[i][0] &&
                   PrecipitationIndex==ActionList[i][1] &&
                   TemperatureChangeIndex==ActionList[i][2] &&
                   RoadConditionIndex==ActionList[i][3] &&
                   PeriodIndex==ActionList[i][4])
                {
                        lbl_SnowClearing->Font->Color=clWindowText;
                        lbl_SandSpread->Font->Color=clWindowText;
                        lbl_SaltSpread->Font->Color=clWindowText;
                        lbl_SnowClearing->Caption=ActionName[ActionList[i][5]];
                        lbl_SandSpread->Caption=ActionName[ActionList[i][6]];
                        lbl_SaltSpread->Caption=ActionName[ActionList[i][7]];
                        break;
                }
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::btn_ClearConditionActionClick(TObject *Sender)
{
        /*--------------------------------------------------
        сбросить все значения в начальные
        --------------------------------------------------*/
        lbl_TemperatureCondition->Font->Color=clRed;
        lbl_TemperatureCondition->Caption=Message;
        lbl_Precipitation->Font->Color=clRed;
        lbl_Precipitation->Caption=Message;
        lbl_RoadCondition->Font->Color=clRed;
        lbl_RoadCondition->Caption=Message;
        lbl_Period->Font->Color=clRed;
        lbl_Period->Caption=Message;
        lbl_SnowClearing->Font->Color=clGreen;
        lbl_SnowClearing->Caption=Message;
        lbl_SandSpread->Font->Color=clGreen;
        lbl_SandSpread->Caption=Message;
        lbl_SaltSpread->Font->Color=clGreen;
        lbl_SaltSpread->Caption=Message;

        TemperatureValueIndex=0;
        TemperatureChangeIndex=0;
        PrecipitationIndex=0;
        RoadConditionIndex=0;
        PeriodIndex=0;

        TemperatureStatus=0;
        PrecipitationStatus=0;
        RoadConditionStatus=0;
        PeriodStatus=0;
        
        for(i=0;i<TemperatureValueNumber;i++)
                TemperatureValueRDB[i]->Enabled=true;
        for(i=0;i<PrecipitationNumber;i++)
                PrecipitationRDB[i]->Enabled=true;
        for(i=0;i<RoadConditionNumber;i++)
                RoadConditionRDB[i]->Enabled=true;

        frm_TemperatureCondition->rdb_TemperatureValue0->Checked=true;
        frm_Precipitation->rdb_Precipitation0->Checked=true;
        frm_RoadCondition->rdb_RoadCondition0->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::AboutProgramClick(TObject *Sender)
{
        /*--------------------------------------------------
        вывести сообщение о назначении программы
        --------------------------------------------------*/
        MessageBox(NULL, "Программа Snowfall предназначена для автоматического определения операций и машин, рекомендуемых для поддержания покрытий в очищенном от снега состоянии",
                           "О программе Snowfall", MB_OK | MB_TASKMODAL);
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        сформировать первоначальный вид окна программы:
        1.скрыть панели выбора действий и машин
        2.скрыть пункт меню "Результат"
        --------------------------------------------------*/
        grb_Action->Hide();
        grb_Car->Hide();
        SaveToFile->Enabled=false;
        SaveToDatabase->Enabled=false;
        Print->Enabled=false;

}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::ActionCalculateClick(TObject *Sender)
{
        /*--------------------------------------------------
        сформировать первоначальный вид окна программы
        при расчете рекомендуемых действий
        --------------------------------------------------*/
        grb_Action->Show();//отобразить панель выбора условий и расчета рекомендуемых действий
        grb_Car->Hide();//скрыть панель выбора условий и расчета рекомендуемой машины
        frm_Main->Caption="Расчет выбора действий";
        ActionCalculate->Enabled=false;//сделать неактивным подпункт меню "Расчет выбора действий"
        CarCalculate->Enabled=true;//сделать активным подпункт меню "Расчет рекомендуемой машины"
        /*--------------------------------------------------
        сделать активными все подпункты меню "Результат"
        --------------------------------------------------*/
        SaveToFile->Enabled=true;
        SaveToDatabase->Enabled=true;
        Print->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::SaveToFileClick(TObject *Sender)
{
        /*--------------------------------------------------
        сохранение результатов работы расчета рекомендуемых действий в файл
        --------------------------------------------------*/
        if(ActionCalculate->Enabled==false)
        {
                /*--------------------------------------------------
                если рекомендуемые операции не рассчитаны, то
                выдать соответствующее сообщение и
                прекратить выполнение функции
                --------------------------------------------------*/
                if(lbl_SnowClearing->Caption==Message)
                {
                        MessageBox(NULL, "Сохранение невозможно, так как расчет рекомендуемых операций не произведен.",
                                "Внимание!", MB_OK | MB_TASKMODAL);
                        return;
                }

                fstream stream;//объявление потока
                unsigned int length;//длина имени файла
                char *file_c;//указатель на имя файла
                AnsiString file_a;//имя файла типа AnsiString

                dlg_SaveToFile->Execute();//запустить окно сохранения
                file_a=dlg_SaveToFile->FileName;//определить имя файла

                length=file_a.Length();//определить длину имени файла
                if(length!=0)//если файл задан (его длина не равна нулю)
                {
                        file_c=AnsiToChar(file_a);//перевести имя файла из типа AnsiString в char *

                        stream.open(file_c,ios::out);//связать поток с файлом

                        /*--------------------------------------------------
                        вывод информации в файл
                        --------------------------------------------------*/
                        stream<<'\n';
                        stream<<"Дата:"<<'\n'<<'\t'<<AnsiToChar(Date())<<'\n'<<'\n';
                        stream<<"Время:"<<'\n'<<'\t'<<AnsiToChar(Time())<<'\n'<<'\n';
                        stream<<"Условия:"<<'\n';
                        stream<<'\t'<<AnsiToChar(btn_TemperatureCondition->Caption)<<" "<<AnsiToChar(lbl_TemperatureCondition->Caption)<<'\n';
                        stream<<'\t'<<AnsiToChar(btn_Precipitation->Caption)<<" "<<AnsiToChar(lbl_Precipitation->Caption)<<'\n';
                        stream<<'\t'<<AnsiToChar(btn_RoadCondition->Caption)<<" "<<AnsiToChar(lbl_RoadCondition->Caption)<<'\n';
                        stream<<'\t'<<AnsiToChar(btn_Period->Caption)<<" "<<AnsiToChar(lbl_Period->Caption)<<'\n';
                        stream<<'\n'<<"Рекомендуемые операции:"<<'\n';
                        stream<<'\t'<<AnsiToChar(stt_SnowClearing->Caption)<<" "<<AnsiToChar(lbl_SnowClearing->Caption)<<'\n';
                        stream<<'\t'<<AnsiToChar(stt_SandSpread->Caption)<<" "<<AnsiToChar(lbl_SandSpread->Caption)<<'\n';
                        stream<<'\t'<<AnsiToChar(stt_SaltSpread->Caption)<<" "<<AnsiToChar(lbl_SaltSpread->Caption)<<'\n';

                        stream.close();//закрыть поток
                        delete file_c;//освободить память, выделенную для имени файла в формате char *
                }
        }

        /*--------------------------------------------------
        сохранение результатов работы расчета рекомендуемой машины в файл
        --------------------------------------------------*/
        if(CarCalculate->Enabled==false)
        {
                if(DirectiveStatus==0 && lbl_RecommendedCar->Caption==Message)
                {
                        MessageBox(NULL, "Сохранение невозможно, так как нет данных для сохранения.",
                                "Внимание!", MB_OK | MB_TASKMODAL);
                        return;
                }

                fstream stream;
                unsigned int length;
                char *file_c;
                AnsiString file_a;

                dlg_SaveToFile->Execute();
                file_a=dlg_SaveToFile->FileName;

                length=file_a.Length();
                if(length!=0)
                {
                        file_c=AnsiToChar(file_a);

                        stream.open(file_c,ios::out);

                        stream<<'\n';
                        stream<<"Дата:"<<'\n'<<'\t'<<AnsiToChar(Date())<<'\n'<<'\n';
                        stream<<"Время:"<<'\n'<<'\t'<<AnsiToChar(Time())<<'\n'<<'\n';
                        stream<<'\n'<<AnsiToChar(btn_RoadMeaning->Caption)<<'\n'<<'\t'<<AnsiToChar(lbl_RoadMeaning->Caption)<<'\n';
                        stream<<'\n'<<AnsiToChar(btn_VolumeOfTraffic->Caption)<<'\n'<<'\t'<<AnsiToChar(lbl_VolumeOfTraffic->Caption)<<'\n';
                        stream<<'\n'<<"Директивные сроки очистки снега и ликвидации гололеда на дороге:"<<'\n';
                        stream<<'\t'<<AnsiToChar(stt_MinWidth->Caption)<<" "<<AnsiToChar(lbl_MinWidth->Caption)<<'\n';
                        stream<<'\t'<<AnsiToChar(stt_MaxThickness->Caption)<<" "<<AnsiToChar(lbl_MaxThickness->Caption)<<'\n';
                        stream<<'\t'<<AnsiToChar(stt_AdmissibleSnowThickness1->Caption)<<" "<<AnsiToChar(lbl_AdmissibleSnowThickness1->Caption)<<'\n';
                        stream<<'\t'<<AnsiToChar(stt_AdmissibleSnowThickness2->Caption)<<" "<<AnsiToChar(lbl_AdmissibleSnowThickness2->Caption)<<'\n';
                        stream<<'\t'<<AnsiToChar(stt_MaxTime->Caption)<<" "<<AnsiToChar(lbl_MaxTime->Caption)<<'\n';
                        stream<<'\n'<<"Параметры снега:"<<'\n';
                        stream<<'\t'<<AnsiToChar(stt_SnowDensity->Caption)<<" "<<AnsiToChar(lbl_SnowDensity->Caption)<<'\n';
                        stream<<'\t'<<AnsiToChar(stt_SnowThickness->Caption)<<" "<<AnsiToChar(lbl_SnowThickness->Caption)<<'\n';
                        stream<<'\n'<<"Рекомендуемая снегоочистительная машина:"<<'\n';
                        stream<<'\t'<<AnsiToChar(lbl_RecommendedCar->Caption);

                        stream.close();
                        delete file_c;
                }
        }      
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::PrintClick(TObject *Sender)
{
        /*--------------------------------------------------
        печать результатов работы программы
        --------------------------------------------------*/
        if(ActionCalculate->Enabled==false)
        {
                /*--------------------------------------------------
                если рекомендуемые операции не рассчитаны, то
                выдать соответствующее сообщение и
                прекратить выполнение функции
                --------------------------------------------------*/
                if(lbl_SnowClearing->Caption=="не определено")
                {
                        MessageBox(NULL, "Печать невозможна, так как расчет рекомендуемых операций не произведен.",
                                  "Внимание!", MB_OK | MB_TASKMODAL);
                        return;
                }

                TPrinter *Prntr = Printer();//связать указатель с существующим принтером

                Prntr->BeginDoc();//начало документа, посылаемого на печать

                Prntr->Canvas->TextOutA(300,300,"Дата: ");
                Prntr->Canvas->TextOutA(300,400,"     "+Date());
                Prntr->Canvas->TextOutA(300,600,"Время: ");
                Prntr->Canvas->TextOutA(300,700,"     "+Time());
                Prntr->Canvas->TextOutA(300,900,"Условия:");
                Prntr->Canvas->TextOutA(300,1000,"     "+btn_TemperatureCondition->Caption+" "+lbl_TemperatureCondition->Caption);
                Prntr->Canvas->TextOutA(300,1100,"     "+btn_Precipitation->Caption+" "+lbl_Precipitation->Caption);
                Prntr->Canvas->TextOutA(300,1200,"     "+btn_RoadCondition->Caption+" "+lbl_RoadCondition->Caption);
                Prntr->Canvas->TextOutA(300,1300,"     "+btn_Period->Caption+" "+lbl_Period->Caption);
                Prntr->Canvas->TextOutA(300,1500,"Рекомендуемые операции:");
                Prntr->Canvas->TextOutA(300,1600,"     "+stt_SnowClearing->Caption+" "+lbl_SnowClearing->Caption);
                Prntr->Canvas->TextOutA(300,1700,"     "+stt_SandSpread->Caption+" "+lbl_SandSpread->Caption);
                Prntr->Canvas->TextOutA(300,1800,"     "+stt_SaltSpread->Caption+" "+lbl_SaltSpread->Caption);

                Prntr->EndDoc();//конец документа, посылаемого на печать
        }
        if(CarCalculate->Enabled==false)
        {
                if(DirectiveStatus==0 && lbl_RecommendedCar->Caption==Message)
                {
                        MessageBox(NULL, "Печать невозможна, так как нет данных для печати.",
                                  "Внимание!", MB_OK | MB_TASKMODAL);
                        return;
                }

                TPrinter *Prntr = Printer();

                Prntr->BeginDoc();

                Prntr->Canvas->TextOutA(300,300,"Дата: ");
                Prntr->Canvas->TextOutA(300,400,"     "+Date());
                Prntr->Canvas->TextOutA(300,600,"Время: ");
                Prntr->Canvas->TextOutA(300,700,"     "+Time());
                Prntr->Canvas->TextOutA(300,900,btn_RoadMeaning->Caption);//road_typr
                Prntr->Canvas->TextOutA(300,1000,"     "+lbl_RoadMeaning->Caption);
                Prntr->Canvas->TextOutA(300,1200,btn_VolumeOfTraffic->Caption);//vehicular_traffic
                Prntr->Canvas->TextOutA(300,1300,"     "+lbl_VolumeOfTraffic->Caption);
                Prntr->Canvas->TextOutA(300,1500,"Директивные сроки очистки снега и ликвидации гололеда на дороге:");
                Prntr->Canvas->TextOutA(300,1600,"     "+stt_MinWidth->Caption+" "+lbl_MinWidth->Caption);
                Prntr->Canvas->TextOutA(300,1700,"     "+stt_MaxThickness->Caption+" "+lbl_MaxThickness->Caption);
                Prntr->Canvas->TextOutA(300,1800,"     "+stt_AdmissibleSnowThickness1->Caption+" "+lbl_AdmissibleSnowThickness1->Caption);
                Prntr->Canvas->TextOutA(300,1900,"     "+stt_AdmissibleSnowThickness2->Caption+" "+lbl_AdmissibleSnowThickness2->Caption);
                Prntr->Canvas->TextOutA(300,2000,"     "+stt_MaxTime->Caption+" "+lbl_MaxTime->Caption);
                Prntr->Canvas->TextOutA(300,2200,"Параметры снега:");
                Prntr->Canvas->TextOutA(300,2300,"     "+stt_SnowDensity->Caption+" "+lbl_SnowDensity->Caption);
                Prntr->Canvas->TextOutA(300,2400,"     "+stt_SnowThickness->Caption+" "+lbl_SnowThickness->Caption);
                Prntr->Canvas->TextOutA(300,2600,"Рекомендуемая снегоочистительная машина:");
                Prntr->Canvas->TextOutA(300,2700,"     "+lbl_RecommendedCar->Caption);
                
                Prntr->EndDoc(); 
        }
        
}
//---------------------------------------------------------------------------


void __fastcall Tfrm_Main::CarCalculateClick(TObject *Sender)
{
        /*--------------------------------------------------
        сформировать первоначальный вид окна программы
        при расчете рекомендуемой машины
        --------------------------------------------------*/
        grb_Action->Hide();//скрыть панель выбора условий и расчета рекомендуемых действий
        grb_Car->Show();//отобразить панель выбора условий и расчета рекомендуемой машины
        frm_Main->Caption="Расчет выбора типа машин";
        CarCalculate->Enabled=false;//сделать неактивным подпункт меню "Расчет выбора типа машин"
        ActionCalculate->Enabled=true;//сделать активным подпункт меню "Расчет рекомендуемых действий"
        /*--------------------------------------------------
        сделать активными все подпункты меню "Результат"
        --------------------------------------------------*/
        SaveToFile->Enabled=true;
        SaveToDatabase->Enabled=true;
        Print->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::btn_RoadMeaningClick(TObject *Sender)
{
        /*--------------------------------------------------
        сделать активным окно выбора административного значения дорог
        сделать неактивным главное окно
        --------------------------------------------------*/
        frm_RoadMeaning->Show();
        frm_Main->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::btn_VolumeOfTrafficClick(TObject *Sender)
{
        /*--------------------------------------------------
        сделать активным окно выбора интенсивности движения
        сделать неактивным главное окно
        --------------------------------------------------*/
        frm_VolumeOfTraffic->Show();
        frm_Main->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::btn_SnowParameterClick(TObject *Sender)
{
        /*--------------------------------------------------
        сделать активным окно выбора параметров снега
        сделать неактивным главное окно
        --------------------------------------------------*/
        frm_SnowParameter->Show();
        frm_Main->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::btn_ClearConditionCarClick(TObject *Sender)
{
        /*--------------------------------------------------
        сбросить все значения в начальные
        --------------------------------------------------*/
        lbl_RoadMeaning->Font->Color=clRed;
        lbl_RoadMeaning->Caption=Message;
        lbl_VolumeOfTraffic->Font->Color=clRed;
        lbl_VolumeOfTraffic->Caption=Message;

        lbl_MinWidth->Caption="";
        lbl_MaxThickness->Caption="";
        lbl_AdmissibleSnowThickness1->Caption="";
        lbl_AdmissibleSnowThickness2->Caption="";
        lbl_MaxTime->Caption="";

        RoadMeaningIndex=0;
        VolumeOfTrafficIndex=0;

        RoadMeaningStatus=0;
        VolumeOfTrafficStatus=0;

        for(i=0;i<RoadMeaningNumber;i++)
                RoadMeaningRDB[i]->Enabled=true;
        for(i=0;i<VolumeOfTrafficNumber;i++)
                VolumeOfTrafficRDB[i]->Enabled=true;

        frm_RoadMeaning->rdb_RoadMeaning0->Checked=true;
        frm_VolumeOfTraffic->rdb_VolumeOfTraffic0->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::btn_CarCalculateClick(TObject *Sender)
{
        int j;
        int temp_car; 
        double temp_d[14];
        double temp_t[14];

        int car_array[14]={5,3,3,5,6,2,2,4,4,1,1,1,0,0};
        double density_array[14]={0.7,0.7,0.7,0.7,0.6,0.6,0.6,0.6,0.6,0.4,0.4,0.4,0.3,0.3};
        double thickness_array[14]={10,10,1.5,1,1.5,1.2,1,0.6,0.5,0.8,0.6,0.4,0.7,0.3};
        
        if(SnowParameterStatus==0)
        {
                MessageBox(NULL, "Невозможно определить рекомендуемую машину, так как не заданы значения плотности и толщины снега",
                                "Внимание!", MB_OK | MB_TASKMODAL);
                return;
        }

        for(i=0;i<14;i++)
        {
                temp_d[i]=density_array[i]-SnowDensity;
                temp_t[i]=thickness_array[i]-SnowThickness;
        }

        for(i=0;i<14;i++)
                if(temp_d[i]<0)
                        break;

        i--;

        if(i==-1)
        {
                MessageBox(NULL, "Невозможно подобрать машину для данных условий",
                                "Внимание!", MB_OK | MB_TASKMODAL);
                return;
        }

        for(j=i;j>=0;j--)
                if(temp_t[j]>=0)
                        break;

        if(j==-1)
        {
                MessageBox(NULL, "Невозможно подобрать машину для данных условий",
                                "Внимание!", MB_OK | MB_TASKMODAL);
                return;
        }

        RecommendedCarIndex=car_array[j];

        lbl_RecommendedCar->Font->Color=clWindowText;
        string capition = car[RecommendedCarIndex] + " с рекомендуемой длиной отвала не менее " + CalculateDump(RecommendedCarIndex) + " метров";
        lbl_RecommendedCar->Caption=caption;
        
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::SaveToDatabaseClick(TObject *Sender)
{
        /*--------------------------------------------------
        сохранение результатов работы расчета рекомендуемых действий в базу данных
        --------------------------------------------------*/
        if(ActionCalculate->Enabled==false)
        {
                /*--------------------------------------------------
                если рекомендуемые операции не рассчитаны, то
                выдать соответствующее сообщение и
                прекратить выполнение функции
                --------------------------------------------------*/
                if(lbl_SnowClearing->Caption==Message)
                {
                        MessageBox(NULL, "Сохранение невозможно, так как расчет рекомендуемых операций не произведен.",
                                "Внимание!", MB_OK | MB_TASKMODAL);
                        return;
                }

                fstream stream;//объявление потока
                unsigned int length;//длина имени файла
                char *file_c;//указатель на имя файла
                AnsiString file_a;//имя файла типа AnsiString

                dlg_SaveToFile->FileName="SnowfallActionDatabase.txt";
                dlg_SaveToFile->Execute();//запустить окно сохранения
                file_a=dlg_SaveToFile->FileName;//определить имя файла

                if(FileExists(file_a))
                        RenameFile(file_a,file_a+"_temp");

                length=file_a.Length();//определить длину имени файла
                if(length!=0)//если файл задан (его длина не равна нулю)
                {
                        file_c=AnsiToChar(file_a);//перевести имя файла из типа AnsiString в char *

                        for(i=0;i<ActionListNumberRow;i++)
                                if(TemperatureValueIndex==ActionList[i][0] &&
                                   PrecipitationIndex==ActionList[i][1] &&
                                   TemperatureChangeIndex==ActionList[i][2] &&
                                   RoadConditionIndex==ActionList[i][3] &&
                                   PeriodIndex==ActionList[i][4])
                                        break;

                        /*--------------------------------------------------
                        вывод информации в файл
                        --------------------------------------------------*/
                        stream.open(file_c,ios::out);//связать поток с файлом
                        
                        stream<<" ";
                        stream<<AnsiToChar(Date())<<" ";
                        stream<<AnsiToChar(Time())<<" ";
                        stream<<TemperatureValueIndex<<" ";
                        stream<<TemperatureChangeIndex<<" ";
                        stream<<PrecipitationIndex<<" ";
                        stream<<RoadConditionIndex<<" ";
                        stream<<PeriodIndex<<" "; 
                        stream<<ActionList[i][5]<<" ";
                        stream<<ActionList[i][6]<<" ";
                        stream<<ActionList[i][7];

                        fstream stream_fromfile;

                        stream_fromfile.open(AnsiToChar(file_a+"_temp"),ios::in);

                        char symbol;

                        while(1)
	                {
		                symbol=stream_fromfile.get();
		                if(symbol==EOF)
			                break;
                                stream.put(symbol);
                        }

                        stream.close();
                        stream_fromfile.close();
                        
                        delete file_c;//освободить память, выделенную для имени файла в формате char *
                }
                DeleteFile(file_a+"_temp");
        }

        /*--------------------------------------------------
        сохранение результатов работы расчета рекомендуемой машины в базу данных
        --------------------------------------------------*/
        if(CarCalculate->Enabled==false)
        {
                /*--------------------------------------------------
                если рекомендуемые операции не рассчитаны, то
                выдать соответствующее сообщение и
                прекратить выполнение функции
                --------------------------------------------------*/
                if(DirectiveStatus==0 || lbl_RecommendedCar->Caption==Message)
                {
                        MessageBox(NULL, "Сохранение в базу данных невозможно, так как расчет всех данных не произведен.",
                                "Внимание!", MB_OK | MB_TASKMODAL);
                        return;
                }

                fstream stream;//объявление потока
                unsigned int length;//длина имени файла
                char *file_c;//указатель на имя файла
                AnsiString file_a;//имя файла типа AnsiString

                dlg_SaveToFile->FileName="SnowfallCarDatabase.txt";
                dlg_SaveToFile->Execute();//запустить окно сохранения
                file_a=dlg_SaveToFile->FileName;//определить имя файла

                if(FileExists(file_a))
                        RenameFile(file_a,file_a+"_temp");

                length=file_a.Length();//определить длину имени файла
                if(length!=0)//если файл задан (его длина не равна нулю)
                {
                        file_c=AnsiToChar(file_a);//перевести имя файла из типа AnsiString в char *

                        for(i=0;i<ActionListNumberRow;i++)
                                if(RoadMeaningIndex==DirectiveList[i][0] &&
                                   VolumeOfTrafficIndex==DirectiveList[i][1])
                                        break;

                        /*--------------------------------------------------
                        вывод информации в файл
                        --------------------------------------------------*/
                        stream.open(file_c,ios::out);//связать поток с файлом
                        
                        stream<<" ";
                        stream<<AnsiToChar(Date())<<" ";
                        stream<<AnsiToChar(Time())<<" ";
                        stream<<RoadMeaningIndex<<" ";
                        stream<<VolumeOfTrafficIndex<<" "; 
                        stream<<DirectiveList[i][2]<<" ";
                        stream<<DirectiveList[i][3]<<" ";
                        stream<<DirectiveList[i][4]<<" ";
                        stream<<DirectiveList[i][5]<<" ";
                        stream<<DirectiveList[i][6]<<" ";
                        stream<<SnowDensity<<" ";
                        stream<<SnowThickness<<" ";
                        stream<<RecommendedCarIndex;

                        fstream stream_fromfile;

                        stream_fromfile.open(AnsiToChar(file_a+"_temp"),ios::in);

                        char symbol;

                        while(1)
	                {
		                symbol=stream_fromfile.get();
		                if(symbol==EOF)
			                break;
                                stream.put(symbol);
                        }

                        stream.close();
                        stream_fromfile.close();
                        
                        delete file_c;//освободить память, выделенную для имени файла в формате char *
                }
                DeleteFile(file_a+"_temp");        
        }
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_Main::OpenActionDatabaseClick(TObject *Sender)
{
        /*--------------------------------------------------
        открыть базу данных рекомендуемых действий в файл
        --------------------------------------------------*/
        OpenActionDatabase->Enabled=false;

        AnsiString file_a;//имя файла типа AnsiString
        unsigned int length;//длина имени файла

        dlg_OpenFile->FileName="SnowfallActionDatabase.txt";
        dlg_OpenFile->Execute();//запустить окно сохранения
        file_a=dlg_OpenFile->FileName;//определить имя файла

        if(!FileExists(file_a))
        {
                MessageBox(NULL, "База данных не существует.",
                                "Внимание!", MB_OK | MB_TASKMODAL);
                OpenActionDatabase->Enabled=true;
                return;
        }

        length=file_a.Length();//определить длину имени файла
        if(length!=0)//если файл задан (его длина не равна нулю)
        {
                frm_ActionDatabase->Show();
                frm_ActionDatabase->mem_ActionDatabase->Clear();
                fstream stream;//объявление потока
                char *file_c;//указатель на имя файла
                file_c=AnsiToChar(file_a);//перевести имя файла из типа AnsiString в char *
                char temp_line[15];
                AnsiString line;
                int index1,index2;

                stream.open(file_c,ios::in);//связать поток с файлом
                while(1)
                {       
                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add("Дата:");
                        stream>>temp_line;
                        line="          "+(AnsiString)temp_line;
                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add(line);

                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add("Время:");
                        stream>>temp_line;
                        line="          "+(AnsiString)temp_line;
                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add(line);

                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add("Условия:");
                        stream>>index1;
                        stream>>index2;
                        line="          Температурные условия: "+TemperatureValue[index1]+ ", "+TemperatureChange[index2]+" температуры";
                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add(line);
                         
                        stream>>index1;
                        line="          Тип осадков: "+Precipitation[index1];
                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add(line);

                        stream>>index1;
                        line="          Дорожные условия: "+RoadCondition[index1];
                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add(line);

                        stream>>index1;
                        line="          Период: "+Period[index1];
                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add(line);

                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add("Рекомендуемые операции:");
                        stream>>index1;
                        line="          Снегоочистка: "+ActionName[index1];
                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add(line);

                        stream>>index1;
                        line="          Разбрасывание песка: "+ActionName[index1];
                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add(line);

                        stream>>index1;
                        line="          Разбрасывание соли: "+ActionName[index1];
                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add(line);

                        frm_ActionDatabase->mem_ActionDatabase->Lines->Add("");
                        
                        if(stream.peek()==EOF)
                                break;
                }
                stream.close();
        }
}
//---------------------------------------------------------------------------


void __fastcall Tfrm_Main::OpenCarDatabaseClick(TObject *Sender)
{
        /*--------------------------------------------------
        открыть базу данных рекомендуемых действий в файл
        --------------------------------------------------*/
        OpenCarDatabase->Enabled=false;

        AnsiString file_a;//имя файла типа AnsiString
        unsigned int length;//длина имени файла
        
        dlg_OpenFile->FileName="SnowfallCarDatabase.txt";
        dlg_OpenFile->Execute();//запустить окно сохранения
        file_a=dlg_OpenFile->FileName;//определить имя файла

        if(!FileExists(file_a))
        {
                MessageBox(NULL, "База данных не существует.",
                                "Внимание!", MB_OK | MB_TASKMODAL);
                OpenCarDatabase->Enabled=true;
                return;
        }

        length=file_a.Length();//определить длину имени файла
        if(length!=0)//если файл задан (его длина не равна нулю)
        {
                frm_CarDatabase->Show();
                frm_CarDatabase->mem_CarDatabase->Clear();
                fstream stream;//объявление потока
                char *file_c;//указатель на имя файла
                file_c=AnsiToChar(file_a);//перевести имя файла из типа AnsiString в char *
                char temp_line[15];
                AnsiString line;
                int index;

                stream.open(file_c,ios::in);//связать поток с файлом
                while(1)
                {       
                        frm_CarDatabase->mem_CarDatabase->Lines->Add("Дата:");
                        stream>>temp_line;
                        line="          "+(AnsiString)temp_line;
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);

                        frm_CarDatabase->mem_CarDatabase->Lines->Add("Время:");
                        stream>>temp_line;
                        line="          "+(AnsiString)temp_line;
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);

                        frm_CarDatabase->mem_CarDatabase->Lines->Add("Народнохозяйственное и административное значение дорог:");
                        stream>>index;
                        line="          "+RoadMeaning[index];
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);

                        frm_CarDatabase->mem_CarDatabase->Lines->Add("Интенсивность движения:");
                        stream>>index;
                        line="          "+VolumeOfTraffic[index];
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);

                        //------------------------------
                        frm_CarDatabase->mem_CarDatabase->Lines->Add("Директивные сроки очистки снега и ликвидации гололеда на дороге: ");

                        stream>>index;
                        line="          Минимальная ширина полностью очищенной поверхности проезжей части, м: "+Directive[index];
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);

                        stream>>index;
                        line="          Максимальная толщина слоя рыхлого снега на поверхности проезжей части, мм: "+Directive[index];
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);

                        stream>>index;
                        line="          Допустимая толщина уплотненного слоя снега на покрытии, мм: "+Directive[index];
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);

                        stream>>index;
                        line="          Допустиая толщина уплотненного снега на обочинах, мм: "+Directive[index];
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);

                        stream>>index;
                        line="          Максимальный срок окончания снегоочистки и ликвидации гололеда: "+Directive[index];
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);
                        //------------------------------

                        frm_CarDatabase->mem_CarDatabase->Lines->Add("Параметры снега:");
                        stream>>temp_line;
                        line="          Плотность снега: "+(AnsiString)temp_line+" г/см3";
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);
                        stream>>temp_line;
                        line="          Толщина снега: "+(AnsiString)temp_line+" м";
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);

                        frm_CarDatabase->mem_CarDatabase->Lines->Add("Рекомендуемая снегоочистительная машина:");
                        stream>>index;
                        line="          "+car[index];
                        frm_CarDatabase->mem_CarDatabase->Lines->Add(line);

                        frm_CarDatabase->mem_CarDatabase->Lines->Add("");

                        if(stream.peek()==EOF)
                                break;
                }
                stream.close();
        }
}

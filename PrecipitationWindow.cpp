/*--------------------------------------------------
В этом файле приведен код, определяющий работу окна выбора типа осадков
--------------------------------------------------*/
//---------------------------------------------------------------------------

#include <vcl.h>
#include "ExternVariable.h"
#include "MainWindow.h"
#pragma hdrstop

#include "TemperatureConditionWindow.h"
#include "PrecipitationWindow.h"
#include "RoadConditionWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_Precipitation *frm_Precipitation;
//---------------------------------------------------------------------------
__fastcall Tfrm_Precipitation::Tfrm_Precipitation(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_Precipitation::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        присвоение элементам списка PrecipitationRDB значений указателей на радиокнопки,
        определяющие различные типы осадков. Это позволит в дальнейшем обращаться к
        радиокнопкам не по указателю, а по индексу
        --------------------------------------------------*/
        PrecipitationRDB[0]=rdb_Precipitation0;
        PrecipitationRDB[1]=rdb_Precipitation1;
        PrecipitationRDB[2]=rdb_Precipitation2;
        /*--------------------------------------------------
        присвоение названий радиокнопкам и выделение одной из кнопок
        --------------------------------------------------*/
        for(int i=0;i<PrecipitationNumber;i++)
                PrecipitationRDB[i]->Caption=Precipitation[i];
        PrecipitationRDB[PrecipitationIndex]->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_Precipitation::btn_PrecipitationOKClick(
      TObject *Sender)
{
        frm_Precipitation->Hide();//скрыть окно выбора типа осадков
        frm_Main->Enabled=true;//сделать активным главное окно

        PreviousPrecipitationIndex=PrecipitationIndex;

        for(i=0;i<PrecipitationNumber;i++)//поиск выделенной радиокнопки
                if(PrecipitationRDB[i]->Checked==true)
                {
                        PrecipitationIndex=i;
                        break;
                }

        /*--------------------------------------------------
        так как выбор определенного значения типа осадков соответствует
        не всем температурам и дорожным условиям,
        то в соответствующих окнах необходимо некоторые радиокнопки сделать неактивными
        --------------------------------------------------*/
        /*--------------------------------------------------
        все радиокнопки в окнах выбора температуры и дорожных условий делаются неактивными
        --------------------------------------------------*/
        for(i=0;i<RoadConditionNumber;i++)
                RoadConditionRDB[i]->Enabled=false;
        for(i=0;i<TemperatureValueNumber;i++)
                TemperatureValueRDB[i]->Enabled=false;

        /*--------------------------------------------------
        просматривается ActionList в поисках строк где индекс выбранного типа осадков
        совпадает с индексом выбранной радиокнопки.
        Для каждой такой строки выполняется:
        1.делается активной радиокнопка температуры, индекс которой находится в этой строке
        2.делается активной радиокнопка дорожных условий, индекс которой находится в этой строке
        --------------------------------------------------*/
        for(i=0;i<ActionListNumberRow;i++)
                if(PrecipitationIndex==ActionList[i][1])
                {
                        TemperatureValueRDB[ActionList[i][0]]->Enabled=true;
                        RoadConditionRDB[ActionList[i][3]]->Enabled=true;
                }

        /*--------------------------------------------------
        подсчитывается общее число активных радиокнопок в окне выбора значения температуры,
        определяется номер первой активной радиокнопки,
        определяется номер отмеченной радиокнопки
        --------------------------------------------------*/
        PreviousTemperatureValueIndex=TemperatureValueIndex;

        NumberEnabled=0;
        for(i=TemperatureValueNumber-1;i>=0;i--)
        {
                if(TemperatureValueRDB[i]->Enabled==true)
                {
                        NumberEnabled++;
                        FirstEnabled=i;
                }
                if(TemperatureValueRDB[i]->Checked==true)
                        Checked=i;
        }
        /*--------------------------------------------------
        если выделенная радиокнопка в окне выбора значения температуры неактивна,
        то выделяем первую активную радиокнопку
        --------------------------------------------------*/
        if(TemperatureValueRDB[Checked]->Enabled==false)
        {
                TemperatureValueIndex=FirstEnabled;
                TemperatureValueRDB[FirstEnabled]->Checked=true;
        }

        /*--------------------------------------------------
        если произошла смена выделенной кнопки в окне выбора значения температуры,
        то отмечаем, что значение температуры не определено и выводим соответствующее сообщение
        --------------------------------------------------*/
        if(PreviousTemperatureValueIndex!=TemperatureValueIndex)
        {
                frm_Main->lbl_TemperatureCondition->Font->Color=clRed;
                frm_Main->lbl_TemperatureCondition->Caption=Message;
                TemperatureStatus=0;
        }

        /*--------------------------------------------------
        если количество активных кнопок в окне выбора значения температуры равно 1,
        то отмечаем, что значение температуры определено и выводим значение выбранной температуры
        --------------------------------------------------*/
        if(NumberEnabled==1)
        {
                frm_Main->lbl_TemperatureCondition->Font->Color=clWindowText;
                frm_Main->lbl_TemperatureCondition->Caption=TemperatureValue[TemperatureValueIndex]+", "+TemperatureChange[TemperatureChangeIndex]+" температуры";
                TemperatureStatus=1;
        }

        /*--------------------------------------------------
        подсчитывается общее число активных радиокнопок в окне выбора дорожных условий,
        определяется номер первой активной радиокнопки,
        определяется номер отмеченной радиокнопки
        --------------------------------------------------*/
        PreviousRoadConditionIndex=RoadConditionIndex;

        NumberEnabled=0;
        for(i=RoadConditionNumber-1;i>=0;i--)
        {
                if(RoadConditionRDB[i]->Enabled==true)
                {
                        NumberEnabled++;
                        FirstEnabled=i;
                }
                if(RoadConditionRDB[i]->Checked==true)
                        Checked=i;
        }

        /*--------------------------------------------------
        если выделенная радиокнопка в окне выбора дорожных условий,
        то выделяем первую активную радиокнопку
        --------------------------------------------------*/
        if(RoadConditionRDB[Checked]->Enabled==false)
        {
                RoadConditionIndex=FirstEnabled;
                RoadConditionRDB[FirstEnabled]->Checked=true;
        }

        /*--------------------------------------------------
        если произошла смена выделенной кнопки в окне выбора дорожных условий,
        то отмечаем, что дорожные условия не определены и выводим соответствующее сообщение
        --------------------------------------------------*/
        if(PreviousRoadConditionIndex!=RoadConditionIndex)
        {
                frm_Main->lbl_RoadCondition->Font->Color=clRed;
                frm_Main->lbl_RoadCondition->Caption=Message;
                RoadConditionStatus=0;
        }

        /*--------------------------------------------------
        если количество активных кнопок в окне выбора дорожных условий равно 1,
        то отмечаем, что дорожные условия определены и выводим выбранные дорожные условия
        --------------------------------------------------*/
        if(NumberEnabled==1)
        {
                frm_Main->lbl_RoadCondition->Font->Color=clWindowText;
                frm_Main->lbl_RoadCondition->Caption=RoadConditionRDB[RoadConditionIndex]->Caption;
                RoadConditionStatus=1;
        }

        /*--------------------------------------------------
        если произошли изменения в выборе условий, то необходимо заново произвести расчет,
        для чего выводятся соответствующие сообщения
        --------------------------------------------------*/
        if(PreviousTemperatureValueIndex!=TemperatureValueIndex ||
           PreviousTemperatureChangeIndex!=TemperatureChangeIndex ||
           PreviousPrecipitationIndex!=PrecipitationIndex ||
           PreviousRoadConditionIndex!=RoadConditionIndex)
        {
                frm_Main->lbl_SnowClearing->Font->Color=clGreen;
                frm_Main->lbl_SnowClearing->Caption=Message;
                frm_Main->lbl_SandSpread->Font->Color=clGreen;
                frm_Main->lbl_SandSpread->Caption=Message;
                frm_Main->lbl_SaltSpread->Font->Color=clGreen;
                frm_Main->lbl_SaltSpread->Caption=Message;
        }

        /*--------------------------------------------------
        отображение наименования выбранного типа осадков в главном окне
        --------------------------------------------------*/
        frm_Main->lbl_Precipitation->Font->Color=clWindowText;
        frm_Main->lbl_Precipitation->Caption=Precipitation[PrecipitationIndex];
        PrecipitationStatus=1;//отмечаем, что тип осадков выбран
}
//---------------------------------------------------------------------------

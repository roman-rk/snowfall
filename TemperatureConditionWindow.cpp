/*--------------------------------------------------
В этом файле приведен код, определяющий работу окна выбора температурных условий
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
Tfrm_TemperatureCondition *frm_TemperatureCondition;

//---------------------------------------------------------------------------
__fastcall Tfrm_TemperatureCondition::Tfrm_TemperatureCondition(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall Tfrm_TemperatureCondition::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        присвоение элементам списка TemperatureValueRDB значений указателей на радиокнопки,
        определяющие различные значения температуры. Это позволит в дальнейшем обращаться к
        радиокнопкам не по указателю, а по индексу
        --------------------------------------------------*/
        TemperatureValueRDB[0]=rdb_TemperatureValue0;
        TemperatureValueRDB[1]=rdb_TemperatureValue1;
        TemperatureValueRDB[2]=rdb_TemperatureValue2;
        /*--------------------------------------------------
        присвоение названий радиокнопкам и выделение одной из кнопок
        --------------------------------------------------*/
        for(i=0;i<TemperatureValueNumber;i++)
                TemperatureValueRDB[i]->Caption=TemperatureValue[i];
        TemperatureValueRDB[TemperatureValueIndex]->Checked=true;

        /*--------------------------------------------------
        присвоение элементам списка TemperatureChangeRDB значений указателей на радиокнопки,
        определяющие различные значения температуры. Это позволит в дальнейшем обращаться к
        радиокнопкам не по указателю, а по индексу
        --------------------------------------------------*/
        TemperatureChangeRDB[0]=rdb_TemperatureChange0;
        TemperatureChangeRDB[1]=rdb_TemperatureChange1;
        /*--------------------------------------------------
        присвоение названий радиокнопкам и выделение одной из кнопок
        --------------------------------------------------*/
        for(i=0;i<TemperatureChangeNumber;i++)
                TemperatureChangeRDB[i]->Caption=TemperatureChange[i];
        TemperatureChangeRDB[TemperatureChangeIndex]->Checked=true; 
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_TemperatureCondition::btn_TemperatureConditionOKClick(
      TObject *Sender)
{
        frm_TemperatureCondition->Hide();//скрыть окно выбора температурных условий
        frm_Main->Enabled=true;//сделать активным главное окно

        PreviousTemperatureValueIndex=TemperatureValueIndex;

        for(i=0;i<TemperatureValueNumber;i++)//поиск выделенной радиокнопки значения температуры
                if(TemperatureValueRDB[i]->Checked==true)
                {
                        TemperatureValueIndex=i;
                        break;
                }


        PreviousTemperatureChangeIndex=TemperatureChangeIndex;

        for(i=0;i<TemperatureChangeNumber;i++)//поиск выделенной радиокнопки изменения температуры
                if(TemperatureChangeRDB[i]->Checked==true)
                {
                        TemperatureChangeIndex=i;
                        break;
                }

        /*--------------------------------------------------
        так как выбор определенного значения температуры соответствует
        не всем дорожным условиям и типам осадков,
        то в соответствующих окнах необходимо некоторые радиокнопки сделать неактивными
        --------------------------------------------------*/
        /*--------------------------------------------------
        все радиокнопки в окнах выбора дорожных условий и типа осадков делаются неактивными
        --------------------------------------------------*/
        for(i=0;i<RoadConditionNumber;i++)
                RoadConditionRDB[i]->Enabled=false;
        for(i=0;i<PrecipitationNumber;i++)
                PrecipitationRDB[i]->Enabled=false;

        /*--------------------------------------------------
        просматривается ActionList в поисках строк где индекс выбранного значения температуры
        совпадает с индексом выбранной радиокнопки.
        Для каждой такой строки выполняется:
        1.делается активной радиокнопка дорожных условий, индекс которой находится в этой строке
        2.делается активной радиокнопка типа осадков, индекс которой находится в этой строке
        --------------------------------------------------*/
        for(i=0;i<ActionListNumberRow;i++)
                if(TemperatureValueIndex==ActionList[i][0])
                {
                        PrecipitationRDB[ActionList[i][1]]->Enabled=true;
                        RoadConditionRDB[ActionList[i][3]]->Enabled=true;
                }

        /*--------------------------------------------------
        подсчитывается общее число активных радиокнопок в окне выбора типа осадков,
        определяется номер первой активной радиокнопки,
        определяется номер отмеченной радиокнопки
        --------------------------------------------------*/
        PreviousPrecipitationIndex=PrecipitationIndex;

        NumberEnabled=0;
        for(i=PrecipitationNumber-1;i>=0;i--)
        {
                if(PrecipitationRDB[i]->Enabled==true)
                {
                        NumberEnabled++;
                        FirstEnabled=i;
                }
                if(PrecipitationRDB[i]->Checked==true)
                        Checked=i;
        }

        /*--------------------------------------------------
        если выделенная радиокнопка в окне выбора типа осадков неактивна,
        то выделяем первую активную радиокнопку
        --------------------------------------------------*/
        if(PrecipitationRDB[Checked]->Enabled==false)
        {
                PrecipitationIndex=FirstEnabled;
                PrecipitationRDB[FirstEnabled]->Checked=true;
        }

        /*--------------------------------------------------
        если произошла смена выделенной кнопки в окне выбора типа осадков,
        то отмечаем, что тип осадков не определен и выводим соответствующее сообщение
        --------------------------------------------------*/
        if(PreviousPrecipitationIndex!=PrecipitationIndex)
        {
                frm_Main->lbl_Precipitation->Font->Color=clRed;
                frm_Main->lbl_Precipitation->Caption=Message;
                PrecipitationStatus=0;
        }

        /*--------------------------------------------------
        если количество активных кнопок в окне выбора типа осадков равно 1,
        то отмечаем, что тип осадков определен и выводим значение выбранного типа осадков
        --------------------------------------------------*/
        if(NumberEnabled==1)
        {
                frm_Main->lbl_Precipitation->Font->Color=clWindowText;
                frm_Main->lbl_Precipitation->Caption=PrecipitationRDB[PrecipitationIndex]->Caption;
                PrecipitationStatus=1;
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
        отображение наименования выбранных температурных условий в главном окне
        --------------------------------------------------*/
        frm_Main->lbl_TemperatureCondition->Font->Color=clWindowText;
        frm_Main->lbl_TemperatureCondition->Caption=TemperatureValue[TemperatureValueIndex]+", "+TemperatureChange[TemperatureChangeIndex]+" температуры";
        TemperatureStatus=1;//отмечаем, что температурные условия выбраны
}
//---------------------------------------------------------------------------


/*--------------------------------------------------
В этом файле приведен код, определяющий работу окна выбора дорожных условий
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
Tfrm_RoadCondition *frm_RoadCondition;
//---------------------------------------------------------------------------
__fastcall Tfrm_RoadCondition::Tfrm_RoadCondition(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_RoadCondition::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        присвоение элементам списка RoadConditionRDB значений указателей на радиокнопки,
        определяющие различные дорожные условия. Это позволит в дальнейшем обращаться к
        радиокнопкам не по указателю, а по индексу
        --------------------------------------------------*/
        RoadConditionRDB[0]=rdb_RoadCondition0;
        RoadConditionRDB[1]=rdb_RoadCondition1;
        RoadConditionRDB[2]=rdb_RoadCondition2;
        RoadConditionRDB[3]=rdb_RoadCondition3;
        /*--------------------------------------------------
        присвоение названий радиокнопкам и выделение одной из кнопок
        --------------------------------------------------*/
        for(int i=0;i<RoadConditionNumber;i++)
                RoadConditionRDB[i]->Caption=RoadCondition[i];
        RoadConditionRDB[RoadConditionIndex]->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_RoadCondition::btn_RoadConditionOKClick(
      TObject *Sender)
{
        frm_RoadCondition->Hide();//скрыть окно выбора дорожных условий
        frm_Main->Enabled=true;//сделать активным главное окно

        PreviousRoadConditionIndex=RoadConditionIndex;

        for(i=0;i<RoadConditionNumber;i++)//поиск выделенной радиокнопки
                if(RoadConditionRDB[i]->Checked==true)
                {
                        RoadConditionIndex=i;
                        break;
                }

        /*--------------------------------------------------
        так как выбор определенного значения дорожного условия соответствует
        не всем температурам и типам осадков,
        то в соответствующих окнах необходимо некоторые радиокнопки сделать неактивными
        --------------------------------------------------*/
        /*--------------------------------------------------
        все радиокнопки в окнах выбора температуры и типа осадков делаются неактивными
        --------------------------------------------------*/
        for(i=0;i<PrecipitationNumber;i++)
                PrecipitationRDB[i]->Enabled=false;
        for(i=0;i<TemperatureValueNumber;i++)
                TemperatureValueRDB[i]->Enabled=false;

        /*--------------------------------------------------
        просматривается ActionList в поисках строк где индекс выбранного дорожного условия
        совпадает с индексом выбранной радиокнопки.
        Для каждой такой строки выполняется:
        1.делается активной радиокнопка температуры, индекс которой находится в этой строке
        2.делается активной радиокнопка типа осадков, индекс которой находится в этой строке
        --------------------------------------------------*/
        for(i=0;i<ActionListNumberRow;i++)
                if(RoadConditionIndex==ActionList[i][3])
                {
                        TemperatureValueRDB[ActionList[i][0]]->Enabled=true;
                        PrecipitationRDB[ActionList[i][1]]->Enabled=true;
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
        если выделенная радиокнопка в окне выбора значения температуры,
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
        отображение наименования выбранных дорожных условий в главном окне
        --------------------------------------------------*/
        frm_Main->lbl_RoadCondition->Font->Color=clWindowText;
        frm_Main->lbl_RoadCondition->Caption=RoadCondition[RoadConditionIndex];
        RoadConditionStatus=1;//отмечаем, что дорожные условия выбраны
}
//---------------------------------------------------------------------------

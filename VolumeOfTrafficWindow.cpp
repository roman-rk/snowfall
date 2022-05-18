//---------------------------------------------------------------------------

#include <vcl.h>
#include "ExternVariable.h"
#include "MainWindow.h"
#pragma hdrstop

#include "VolumeOfTrafficWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_VolumeOfTraffic *frm_VolumeOfTraffic;
//---------------------------------------------------------------------------
__fastcall Tfrm_VolumeOfTraffic::Tfrm_VolumeOfTraffic(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_VolumeOfTraffic::btn_VolumeOfTrafficOKClick(
      TObject *Sender)
{
        frm_VolumeOfTraffic->Hide();//скрыть окно выбора интенсивности движения
        frm_Main->Enabled=true;//сделать активным главное окно

        PreviousVolumeOfTrafficIndex=VolumeOfTrafficIndex;

        for(i=0;i<VolumeOfTrafficNumber;i++)//поиск выделенной радиокнопки интенсивности движения
                if(VolumeOfTrafficRDB[i]->Checked==true)
                {
                        VolumeOfTrafficIndex=i;
                        break;
                }

        /*--------------------------------------------------
        так как выбор определенного  значения интенсивности движения соответствует
        не всем административным значениям дорог,
        то в соответствующем окне необходимо некоторые радиокнопки сделать неактивными
        --------------------------------------------------*/
        /*--------------------------------------------------
        все радиокнопки в окне выбора административного значения дороги делаются неактивными
        --------------------------------------------------*/
        for(i=0;i<RoadMeaningNumber;i++)
                RoadMeaningRDB[i]->Enabled=false;


        /*--------------------------------------------------
        просматривается DirectiveList в поисках строк где индекс выбранной интенсивности движения
        совпадает с индексом выбранной радиокнопки.
        Для каждой такой строки выполняется:
        1.делается активной радиокнопка административного значения дороги, индекс которой находится в этой строке
        --------------------------------------------------*/
        for(i=0;i<DirectiveListNumberRow;i++)
                if(VolumeOfTrafficIndex==DirectiveList[i][1])
                        RoadMeaningRDB[DirectiveList[i][0]]->Enabled=true;

        /*--------------------------------------------------
        подсчитывается общее число активных радиокнопок в окне выбора административного значения дороги,
        определяется номер первой активной радиокнопки,
        определяется номер отмеченной радиокнопки
        --------------------------------------------------*/
        PreviousRoadMeaningIndex=RoadMeaningIndex;

        NumberEnabled=0;
        for(i=RoadMeaningNumber-1;i>=0;i--)
        {
                if(RoadMeaningRDB[i]->Enabled==true)
                {
                        NumberEnabled++;
                        FirstEnabled=i;
                }
                if(RoadMeaningRDB[i]->Checked==true)
                        Checked=i;
        }

        /*--------------------------------------------------
        если выделенная радиокнопка в окне выбора административного значения дороги неактивна,
        то выделяем первую активную радиокнопку
        --------------------------------------------------*/
        if(RoadMeaningRDB[Checked]->Enabled==false)
        {
                RoadMeaningIndex=FirstEnabled;
                RoadMeaningRDB[FirstEnabled]->Checked=true;
        }

        /*--------------------------------------------------
        если произошла смена выделенной кнопки в окне выбора административного значения дороги,
        то отмечаем, что значение дороги не определено и выводим соответствующее сообщение
        --------------------------------------------------*/
        if(PreviousRoadMeaningIndex!=RoadMeaningIndex)
        {
                frm_Main->lbl_RoadMeaning->Font->Color=clRed;
                frm_Main->lbl_RoadMeaning->Caption=Message;
                RoadMeaningStatus=0;
        }

        /*--------------------------------------------------
        если количество активных кнопок в окне выбора значения дороги равно 1,
        то отмечаем, что значение дороги определено и выводим административное значение дороги
        --------------------------------------------------*/
        if(NumberEnabled==1)
        {
                frm_Main->lbl_RoadMeaning->Font->Color=clWindowText;
                frm_Main->lbl_RoadMeaning->Caption=RoadMeaningRDB[RoadMeaningIndex]->Caption;
                RoadMeaningStatus=1;
        }
        
        /*--------------------------------------------------
        если произошли изменения в выборе условий, то необходимо заново произвести расчет,
        для чего выводятся соответствующие сообщения
        --------------------------------------------------*/
        if(RoadMeaningStatus==1)
        {
                for(i=0;i<DirectiveListNumberRow;i++)
                        if(VolumeOfTrafficIndex==DirectiveList[i][1] && RoadMeaningIndex==DirectiveList[i][0])
                                break;
                frm_Main->lbl_MinWidth->Caption=Directive[DirectiveList[i][2]];
                frm_Main->lbl_MaxThickness->Caption=Directive[DirectiveList[i][3]];
                frm_Main->lbl_AdmissibleSnowThickness1->Caption=Directive[DirectiveList[i][4]];
                frm_Main->lbl_AdmissibleSnowThickness2->Caption=Directive[DirectiveList[i][5]];
                frm_Main->lbl_MaxTime->Caption=Directive[DirectiveList[i][6]];
        }

        /*--------------------------------------------------
        отображение наименования выбранной интенсивности движения в главном окне
        --------------------------------------------------*/
        frm_Main->lbl_VolumeOfTraffic->Font->Color=clWindowText;
        frm_Main->lbl_VolumeOfTraffic->Caption=VolumeOfTraffic[VolumeOfTrafficIndex];
        VolumeOfTrafficStatus=1;//отмечаем, что интенсивность движения выбрана

        if(RoadMeaningStatus==1 && VolumeOfTrafficStatus==1)
                DirectiveStatus=1;
        else
                DirectiveStatus=0;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_VolumeOfTraffic::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        присвоение элементам списка VolumeOfTrafficRDB значений указателей на радиокнопки,
        определяющие различные значения интенсивности движения. Это позволит в дальнейшем обращаться к
        радиокнопкам не по указателю, а по индексу
        --------------------------------------------------*/
        VolumeOfTrafficRDB[0]=rdb_VolumeOfTraffic0;
        VolumeOfTrafficRDB[1]=rdb_VolumeOfTraffic1;
        VolumeOfTrafficRDB[2]=rdb_VolumeOfTraffic2;
        VolumeOfTrafficRDB[3]=rdb_VolumeOfTraffic3;
        VolumeOfTrafficRDB[4]=rdb_VolumeOfTraffic4;
        VolumeOfTrafficRDB[5]=rdb_VolumeOfTraffic5;
        /*--------------------------------------------------
        присвоение названий радиокнопкам и выделение одной из кнопок
        --------------------------------------------------*/
        for(i=0;i<VolumeOfTrafficNumber;i++)
                VolumeOfTrafficRDB[i]->Caption=VolumeOfTraffic[i];
        VolumeOfTrafficRDB[VolumeOfTrafficIndex]->Checked=true;
}
//---------------------------------------------------------------------------

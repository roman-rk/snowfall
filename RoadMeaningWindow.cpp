//---------------------------------------------------------------------------

#include <vcl.h>
#include "ExternVariable.h"
#include "MainWindow.h"
#pragma hdrstop

#include "RoadMeaningWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_RoadMeaning *frm_RoadMeaning;
//---------------------------------------------------------------------------
__fastcall Tfrm_RoadMeaning::Tfrm_RoadMeaning(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_RoadMeaning::btn_RoadMeaningOKClick(TObject *Sender)
{
        frm_RoadMeaning->Hide();//скрыть окно выбора административного значения дорог
        frm_Main->Enabled=true;//сделать активным главное окно

        PreviousRoadMeaningIndex=RoadMeaningIndex;

        for(i=0;i<RoadMeaningNumber;i++)//поиск выделенной радиокнопки административного значения дороги
                if(RoadMeaningRDB[i]->Checked==true)
                {
                        RoadMeaningIndex=i;
                        break;
                }

        /*--------------------------------------------------
        так как выбор определенного административного значения дороги соответствует
        не всем интенсивностям движения,
        то в соответствующем окне необходимо некоторые радиокнопки сделать неактивными
        --------------------------------------------------*/
        /*--------------------------------------------------
        все радиокнопки в окне выбора интенсивности движения делаются неактивными
        --------------------------------------------------*/
        for(i=0;i<VolumeOfTrafficNumber;i++)
                VolumeOfTrafficRDB[i]->Enabled=false;


        /*--------------------------------------------------
        просматривается DirectiveList в поисках строк где индекс выбранного административного значения дороги
        совпадает с индексом выбранной радиокнопки.
        Для каждой такой строки выполняется:
        1.делается активной радиокнопка интенсивности движения, индекс которой находится в этой строке
        --------------------------------------------------*/
        for(i=0;i<DirectiveListNumberRow;i++)
                if(RoadMeaningIndex==DirectiveList[i][0])
                        VolumeOfTrafficRDB[DirectiveList[i][1]]->Enabled=true;

        /*--------------------------------------------------
        подсчитывается общее число активных радиокнопок в окне выбора интенсивности движения,
        определяется номер первой активной радиокнопки,
        определяется номер отмеченной радиокнопки
        --------------------------------------------------*/
        PreviousVolumeOfTrafficIndex=VolumeOfTrafficIndex;

        NumberEnabled=0;
        for(i=VolumeOfTrafficNumber-1;i>=0;i--)
        {
                if(VolumeOfTrafficRDB[i]->Enabled==true)
                {
                        NumberEnabled++;
                        FirstEnabled=i;
                }
                if(VolumeOfTrafficRDB[i]->Checked==true)
                        Checked=i;
        }

        /*--------------------------------------------------
        если выделенная радиокнопка в окне выбора интенсивности движения неактивна,
        то выделяем первую активную радиокнопку
        --------------------------------------------------*/
        if(VolumeOfTrafficRDB[Checked]->Enabled==false)
        {
                VolumeOfTrafficIndex=FirstEnabled;
                VolumeOfTrafficRDB[FirstEnabled]->Checked=true;
        }

        /*--------------------------------------------------
        если произошла смена выделенной кнопки в окне выбора интенсивности движения,
        то отмечаем, что интенсивность движения не определена и выводим соответствующее сообщение
        --------------------------------------------------*/
        if(PreviousVolumeOfTrafficIndex!=VolumeOfTrafficIndex)
        {
                frm_Main->lbl_VolumeOfTraffic->Font->Color=clRed;
                frm_Main->lbl_VolumeOfTraffic->Caption=Message;
                VolumeOfTrafficStatus=0;
        }

        /*--------------------------------------------------
        если количество активных кнопок в окне выбора интенсивности движения равно 1,
        то отмечаем, что интенсивность движения определена и выводим значение выбранной интенсивности движения
        --------------------------------------------------*/
        if(NumberEnabled==1)
        {
                frm_Main->lbl_VolumeOfTraffic->Font->Color=clWindowText;
                frm_Main->lbl_VolumeOfTraffic->Caption=VolumeOfTrafficRDB[VolumeOfTrafficIndex]->Caption;
                VolumeOfTrafficStatus=1;
        }
        
        /*--------------------------------------------------
        если произошли изменения в выборе условий, то необходимо заново произвести расчет,
        для чего выводятся соответствующие сообщения
        --------------------------------------------------*/
        if(VolumeOfTrafficStatus==1)
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
        отображение наименования выбранного административного значения дорог в главном окне
        --------------------------------------------------*/
        frm_Main->lbl_RoadMeaning->Font->Color=clWindowText;
        frm_Main->lbl_RoadMeaning->Caption=RoadMeaning[RoadMeaningIndex];
        RoadMeaningStatus=1;//отмечаем, что административное значение дороги выбрано
        
        if(RoadMeaningStatus==1 && VolumeOfTrafficStatus==1)
                DirectiveStatus=1;
        else
                DirectiveStatus=0;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_RoadMeaning::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        присвоение элементам списка RoadMeaningRDB значений указателей на радиокнопки,
        определяющие различные административные значения дорог. Это позволит в дальнейшем обращаться к
        радиокнопкам не по указателю, а по индексу
        --------------------------------------------------*/
        RoadMeaningRDB[0]=rdb_RoadMeaning0;
        RoadMeaningRDB[1]=rdb_RoadMeaning1;
        RoadMeaningRDB[2]=rdb_RoadMeaning2;
        RoadMeaningRDB[3]=rdb_RoadMeaning3;
        RoadMeaningRDB[4]=rdb_RoadMeaning4;
        /*--------------------------------------------------
        присвоение названий радиокнопкам и выделение одной из кнопок
        --------------------------------------------------*/
        for(i=0;i<RoadMeaningNumber;i++)
                RoadMeaningRDB[i]->Caption=RoadMeaning[i];
        RoadMeaningRDB[RoadMeaningIndex]->Checked=true;
}
//---------------------------------------------------------------------------

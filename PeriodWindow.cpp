/*--------------------------------------------------
¬ этом файле приведен код, определ€ющий работу окна выбора периода
--------------------------------------------------*/
//---------------------------------------------------------------------------

#include <vcl.h>
#include "ExternVariable.h"
#include "MainWindow.h"
#pragma hdrstop

#include "PeriodWindow.h"   
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_Period *frm_Period;
//---------------------------------------------------------------------------
__fastcall Tfrm_Period::Tfrm_Period(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_Period::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        присвоение элементам списка PeriodRDB значений указателей на радиокнопки,
        определ€ющие различные периоды. Ёто позволит в дальнейшем обращатьс€ к
        радиокнопкам не по указателю, а по индексу
        --------------------------------------------------*/
        PeriodRDB[0]=rdb_Period0;
        PeriodRDB[1]=rdb_Period1;
        PeriodRDB[2]=rdb_Period2;
        /*--------------------------------------------------
        присвоение названий радиокнопкам и выделение одной из кнопок
        --------------------------------------------------*/
        for(int i=0;i<PeriodNumber;i++)
                PeriodRDB[i]->Caption=Period[i];
        PeriodRDB[PeriodIndex]->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_Period::btn_PeriodOKClick(TObject *Sender)
{
        frm_Period->Hide();//скрыть окно выбора периода
        frm_Main->Enabled=true;//сделать активным главное окно

        PreviousPeriodIndex=PeriodIndex;

        for(int i=0;i<PeriodNumber;i++)//поиск выделенной радиокнопки
                if(PeriodRDB[i]->Checked==true)
                {
                        PeriodIndex=i;
                        break;
                }

        /*--------------------------------------------------
        отображение наименовани€ выбранного периода в главном окне
        --------------------------------------------------*/
        frm_Main->lbl_Period->Font->Color=clWindowText;
        frm_Main->lbl_Period->Caption=Period[PeriodIndex];

        /*--------------------------------------------------
        если вновь выбранный период отличен от предыдущего, то
        необходимо проводить новый расчет рекомендуемых операций
        и, поэтому, определенные до этого рекомендуемые операции сбрасываютс€
        --------------------------------------------------*/
        if(PreviousPeriodIndex!=PeriodIndex)
        {
                frm_Main->lbl_SnowClearing->Font->Color=clGreen;
                frm_Main->lbl_SnowClearing->Caption=Message;
                frm_Main->lbl_SandSpread->Font->Color=clGreen;
                frm_Main->lbl_SandSpread->Caption=Message;
                frm_Main->lbl_SaltSpread->Font->Color=clGreen;
                frm_Main->lbl_SaltSpread->Caption=Message;
        }

        PeriodStatus=1;//отмечаем, что период выбран
}
//---------------------------------------------------------------------------


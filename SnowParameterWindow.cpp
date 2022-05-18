//---------------------------------------------------------------------------

#include <vcl.h>
#include "ExternVariable.h"
#include "MainWindow.h"
#pragma hdrstop

#include "SnowParameterWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_SnowParameter *frm_SnowParameter;
//---------------------------------------------------------------------------
__fastcall Tfrm_SnowParameter::Tfrm_SnowParameter(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_SnowParameter::btn_SnowParameterOKClick(
      TObject *Sender)
{
        frm_SnowParameter->Hide();//скрыть окно выбора условий снега
        frm_Main->Enabled=true;//сделать активным главное окно

        PreviousSnowDensity=SnowDensity;
        PreviousSnowThickness=SnowThickness;

        if((edt_SnowDensity->Text).ToDouble()<=0 || (edt_SnowDensity->Text).ToDouble()>=0.9 || (edt_SnowThickness->Text).ToDouble()<=0 || (edt_SnowThickness->Text).ToDouble()>=10)
        {
                MessageBox(NULL, "«начение толщины или плотности снега задано неверно. «адайте значение плотности снега строго в диапазоне от 0 до 0,9 г/см3, а толщину снега строго от 0 до 10 м и повторите операцию.",
                           "¬нимание!", MB_OK | MB_TASKMODAL);
                return;
        }

        SnowDensity=(edt_SnowDensity->Text).ToDouble();
        SnowThickness=(edt_SnowThickness->Text).ToDouble();

        if(PreviousSnowDensity!=SnowDensity || PreviousSnowThickness!=SnowThickness)
        {
                frm_Main->lbl_RecommendedCar->Font->Color=clRed;
                frm_Main->lbl_RecommendedCar->Caption="не определено";
        }

        frm_Main->lbl_SnowDensity->Font->Color=clWindowText;
        frm_Main->lbl_SnowThickness->Font->Color=clWindowText;
        frm_Main->lbl_SnowDensity->Caption=edt_SnowDensity->Text+" "+stt_SnowDensityDimension->Caption;
        frm_Main->lbl_SnowThickness->Caption=edt_SnowThickness->Text+" "+stt_SnowThicknessDimension->Caption;

        SnowParameterStatus=1;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_SnowParameter::FormCreate(TObject *Sender)
{
        edt_SnowDensity->Text=SnowDensity;
        edt_SnowThickness->Text=SnowThickness;
}
//---------------------------------------------------------------------------


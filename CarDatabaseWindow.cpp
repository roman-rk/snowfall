//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CarDatabaseWindow.h"
#include "MainWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_CarDatabase *frm_CarDatabase;
//---------------------------------------------------------------------------
__fastcall Tfrm_CarDatabase::Tfrm_CarDatabase(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_CarDatabase::btn_CarDatabaseCloseClick(
      TObject *Sender)
{
        frm_CarDatabase->Hide();
        frm_Main->OpenCarDatabase->Enabled=True;
}
//---------------------------------------------------------------------------

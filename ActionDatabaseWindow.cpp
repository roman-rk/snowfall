//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ActionDatabaseWindow.h"
#include "MainWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_ActionDatabase *frm_ActionDatabase;
//---------------------------------------------------------------------------
__fastcall Tfrm_ActionDatabase::Tfrm_ActionDatabase(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_ActionDatabase::btn_ActionDatabaseCloseClick(
      TObject *Sender)
{
        frm_ActionDatabase->Hide();
        frm_Main->OpenActionDatabase->Enabled=True;        
}
//---------------------------------------------------------------------------

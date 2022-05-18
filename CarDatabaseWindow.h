//---------------------------------------------------------------------------

#ifndef CarDatabaseWindowH
#define CarDatabaseWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tfrm_CarDatabase : public TForm
{
__published:	// IDE-managed Components
        TButton *btn_CarDatabaseClose;
        TMemo *mem_CarDatabase;
        void __fastcall btn_CarDatabaseCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_CarDatabase(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_CarDatabase *frm_CarDatabase;
//---------------------------------------------------------------------------
#endif

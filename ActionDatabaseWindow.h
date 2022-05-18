//---------------------------------------------------------------------------

#ifndef ActionDatabaseWindowH
#define ActionDatabaseWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tfrm_ActionDatabase : public TForm
{
__published:	// IDE-managed Components
        TMemo *mem_ActionDatabase;
        TButton *btn_ActionDatabaseClose;
        void __fastcall btn_ActionDatabaseCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_ActionDatabase(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_ActionDatabase *frm_ActionDatabase;
//---------------------------------------------------------------------------
#endif

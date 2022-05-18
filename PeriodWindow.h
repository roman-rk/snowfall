//---------------------------------------------------------------------------

#ifndef PeriodWindowH
#define PeriodWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tfrm_Period : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *grd_Period;
        TButton *btn_PeriodOK;
        TRadioButton *rdb_Period0;
        TRadioButton *rdb_Period1;
        TRadioButton *rdb_Period2;
        void __fastcall btn_PeriodOKClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_Period(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_Period *frm_Period;
//---------------------------------------------------------------------------
#endif

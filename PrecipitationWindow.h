//---------------------------------------------------------------------------

#ifndef PrecipitationWindowH
#define PrecipitationWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tfrm_Precipitation : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *grb_Precipitation;
        TButton *btn_PrecipitationOK;
        TRadioButton *rdb_Precipitation0;
        TRadioButton *rdb_Precipitation1;
        TRadioButton *rdb_Precipitation2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btn_PrecipitationOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_Precipitation(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_Precipitation *frm_Precipitation;
//---------------------------------------------------------------------------
#endif

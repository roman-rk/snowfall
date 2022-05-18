//---------------------------------------------------------------------------

#ifndef SnowParameterWindowH
#define SnowParameterWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tfrm_SnowParameter : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *grb_SnowParameter;
        TStaticText *stt_SnowDensity;
        TStaticText *stt_SnowThickness;
        TStaticText *stt_SnowDensityDimension;
        TStaticText *stt_SnowThicknessDimension;
        TEdit *edt_SnowDensity;
        TButton *btn_SnowParameterOK;
        TEdit *edt_SnowThickness;
        void __fastcall btn_SnowParameterOKClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_SnowParameter(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_SnowParameter *frm_SnowParameter;
//---------------------------------------------------------------------------
#endif

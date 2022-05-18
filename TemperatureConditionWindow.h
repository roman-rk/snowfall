//---------------------------------------------------------------------------

#ifndef TemperatureConditionWindowH
#define TemperatureConditionWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tfrm_TemperatureCondition : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *grb_TemperatureCondition;
        TGroupBox *grb_TemperatureValue;
        TButton *btn_TemperatureConditionOK;
        TRadioButton *rdb_TemperatureValue0;
        TRadioButton *rdb_TemperatureValue1;
        TRadioButton *rdb_TemperatureValue2;
        TRadioButton *rdb_TemperatureChange0;
        TRadioButton *rdb_TemperatureChange1;
        TGroupBox *grb_TemperatureChange;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btn_TemperatureConditionOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_TemperatureCondition(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_TemperatureCondition *frm_TemperatureCondition;
//---------------------------------------------------------------------------
#endif

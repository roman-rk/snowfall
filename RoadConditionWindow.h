//---------------------------------------------------------------------------

#ifndef RoadConditionWindowH
#define RoadConditionWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tfrm_RoadCondition : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *grb_RoadCondition;
        TButton *btn_RoadConditionOK;
        TRadioButton *rdb_RoadCondition0;
        TRadioButton *rdb_RoadCondition1;
        TRadioButton *rdb_RoadCondition2;
        TRadioButton *rdb_RoadCondition3;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btn_RoadConditionOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_RoadCondition(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_RoadCondition *frm_RoadCondition;
//---------------------------------------------------------------------------
#endif

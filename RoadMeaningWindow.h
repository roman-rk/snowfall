//---------------------------------------------------------------------------

#ifndef RoadMeaningWindowH
#define RoadMeaningWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tfrm_RoadMeaning : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TRadioButton *rdb_RoadMeaning0;
        TRadioButton *rdb_RoadMeaning1;
        TRadioButton *rdb_RoadMeaning2;
        TRadioButton *rdb_RoadMeaning3;
        TRadioButton *rdb_RoadMeaning4;
        TButton *btn_RoadMeaningOK;
        void __fastcall btn_RoadMeaningOKClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_RoadMeaning(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_RoadMeaning *frm_RoadMeaning;
//---------------------------------------------------------------------------
#endif

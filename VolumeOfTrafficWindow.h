//---------------------------------------------------------------------------

#ifndef VolumeOfTrafficWindowH
#define VolumeOfTrafficWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tfrm_VolumeOfTraffic : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *grb_VolumeOfTraffic;
        TRadioButton *rdb_VolumeOfTraffic0;
        TRadioButton *rdb_VolumeOfTraffic1;
        TRadioButton *rdb_VolumeOfTraffic2;
        TRadioButton *rdb_VolumeOfTraffic3;
        TRadioButton *rdb_VolumeOfTraffic4;
        TRadioButton *rdb_VolumeOfTraffic5;
        TButton *btn_VolumeOfTrafficOK;
        void __fastcall btn_VolumeOfTrafficOKClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_VolumeOfTraffic(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_VolumeOfTraffic *frm_VolumeOfTraffic;
//---------------------------------------------------------------------------
#endif

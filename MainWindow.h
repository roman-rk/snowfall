//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class Tfrm_Main : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *Menu;
        TMenuItem *Calculate;
        TMenuItem *Result;
        TMenuItem *AboutProgram;
        TMenuItem *ActionCalculate;
        TMenuItem *CarCalculate;
        TMenuItem *SaveToFile;
        TMenuItem *Print;
        TButton *btn_TemperatureCondition;
        TButton *btn_RoadCondition;
        TButton *btn_Precipitation;
        TButton *btn_Period;
        TButton *btn_ActionCalculate;
        TStaticText *stt_SnowClearing;
        TStaticText *stt_SandSpread;
        TStaticText *stt_SaltSpread;
        TLabel *lbl_TemperatureCondition;
        TLabel *lbl_Precipitation;
        TLabel *lbl_RoadCondition;
        TLabel *lbl_Period;
        TLabel *lbl_SnowClearing;
        TLabel *lbl_SandSpread;
        TLabel *lbl_SaltSpread;
        TGroupBox *grb_Action;
        TButton *btn_ClearConditionAction;
        TSaveDialog *dlg_SaveToFile;
        TMenuItem *SaveToDatabase;
        TMenuItem *OpenDatabase;
        TMenuItem *OpenActionDatabase;
        TMenuItem *OpenCarDatabase;
        TSaveDialog *dlg_SaveToDatabase;
        TGroupBox *grb_Car;
        TButton *btn_RoadMeaning;
        TButton *btn_VolumeOfTraffic;
        TButton *btn_CarCalculate;
        TButton *btn_SnowParameter;
        TGroupBox *grb_Directive;
        TLabel *lbl_RoadMeaning;
        TLabel *lbl_VolumeOfTraffic;
        TStaticText *stt_SnowDensity;
        TStaticText *stt_SnowThickness;
        TGroupBox *grb_RecommendCar;
        TLabel *lbl_RecommendedCar;
        TLabel *lbl_SnowDensity;
        TLabel *lbl_SnowThickness;
        TStaticText *stt_MinWidth;
        TStaticText *stt_MaxThickness;
        TStaticText *stt_AdmissibleSnowThickness1;
        TStaticText *stt_AdmissibleSnowThickness2;
        TStaticText *stt_MaxTime;
        TLabel *lbl_MinWidth;
        TLabel *lbl_MaxThickness;
        TLabel *lbl_AdmissibleSnowThickness1;
        TLabel *lbl_AdmissibleSnowThickness2;
        TLabel *lbl_MaxTime;
        TButton *btn_ClearConditionCar;
        TOpenDialog *dlg_OpenFile;
        void __fastcall btn_TemperatureConditionClick(TObject *Sender);
        void __fastcall btn_PrecipitationClick(TObject *Sender);
        void __fastcall btn_RoadConditionClick(TObject *Sender);
        void __fastcall btn_PeriodClick(TObject *Sender);
        void __fastcall btn_ActionCalculateClick(TObject *Sender);
        void __fastcall btn_ClearConditionActionClick(TObject *Sender);
        void __fastcall AboutProgramClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ActionCalculateClick(TObject *Sender);
        void __fastcall SaveToFileClick(TObject *Sender);
        void __fastcall PrintClick(TObject *Sender);
        void __fastcall CarCalculateClick(TObject *Sender);
        void __fastcall btn_RoadMeaningClick(TObject *Sender);
        void __fastcall btn_VolumeOfTrafficClick(TObject *Sender);
        void __fastcall btn_SnowParameterClick(TObject *Sender);
        void __fastcall btn_ClearConditionCarClick(TObject *Sender);
        void __fastcall btn_CarCalculateClick(TObject *Sender);
        void __fastcall SaveToDatabaseClick(TObject *Sender);
        void __fastcall OpenActionDatabaseClick(TObject *Sender);
        void __fastcall OpenCarDatabaseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_Main(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_Main *frm_Main;
//---------------------------------------------------------------------------
#endif

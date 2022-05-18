/*--------------------------------------------------
� ���� ����� �������� ���, ������������ ������ ���� ������ ���� �������
--------------------------------------------------*/
//---------------------------------------------------------------------------

#include <vcl.h>
#include "ExternVariable.h"
#include "MainWindow.h"
#pragma hdrstop

#include "TemperatureConditionWindow.h"
#include "PrecipitationWindow.h"
#include "RoadConditionWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_Precipitation *frm_Precipitation;
//---------------------------------------------------------------------------
__fastcall Tfrm_Precipitation::Tfrm_Precipitation(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_Precipitation::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        ���������� ��������� ������ PrecipitationRDB �������� ���������� �� �����������,
        ������������ ��������� ���� �������. ��� �������� � ���������� ���������� �
        ������������ �� �� ���������, � �� �������
        --------------------------------------------------*/
        PrecipitationRDB[0]=rdb_Precipitation0;
        PrecipitationRDB[1]=rdb_Precipitation1;
        PrecipitationRDB[2]=rdb_Precipitation2;
        /*--------------------------------------------------
        ���������� �������� ������������ � ��������� ����� �� ������
        --------------------------------------------------*/
        for(int i=0;i<PrecipitationNumber;i++)
                PrecipitationRDB[i]->Caption=Precipitation[i];
        PrecipitationRDB[PrecipitationIndex]->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_Precipitation::btn_PrecipitationOKClick(
      TObject *Sender)
{
        frm_Precipitation->Hide();//������ ���� ������ ���� �������
        frm_Main->Enabled=true;//������� �������� ������� ����

        PreviousPrecipitationIndex=PrecipitationIndex;

        for(i=0;i<PrecipitationNumber;i++)//����� ���������� �����������
                if(PrecipitationRDB[i]->Checked==true)
                {
                        PrecipitationIndex=i;
                        break;
                }

        /*--------------------------------------------------
        ��� ��� ����� ������������� �������� ���� ������� �������������
        �� ���� ������������ � �������� ��������,
        �� � ��������������� ����� ���������� ��������� ����������� ������� �����������
        --------------------------------------------------*/
        /*--------------------------------------------------
        ��� ����������� � ����� ������ ����������� � �������� ������� �������� �����������
        --------------------------------------------------*/
        for(i=0;i<RoadConditionNumber;i++)
                RoadConditionRDB[i]->Enabled=false;
        for(i=0;i<TemperatureValueNumber;i++)
                TemperatureValueRDB[i]->Enabled=false;

        /*--------------------------------------------------
        ��������������� ActionList � ������� ����� ��� ������ ���������� ���� �������
        ��������� � �������� ��������� �����������.
        ��� ������ ����� ������ �����������:
        1.�������� �������� ����������� �����������, ������ ������� ��������� � ���� ������
        2.�������� �������� ����������� �������� �������, ������ ������� ��������� � ���� ������
        --------------------------------------------------*/
        for(i=0;i<ActionListNumberRow;i++)
                if(PrecipitationIndex==ActionList[i][1])
                {
                        TemperatureValueRDB[ActionList[i][0]]->Enabled=true;
                        RoadConditionRDB[ActionList[i][3]]->Enabled=true;
                }

        /*--------------------------------------------------
        �������������� ����� ����� �������� ����������� � ���� ������ �������� �����������,
        ������������ ����� ������ �������� �����������,
        ������������ ����� ���������� �����������
        --------------------------------------------------*/
        PreviousTemperatureValueIndex=TemperatureValueIndex;

        NumberEnabled=0;
        for(i=TemperatureValueNumber-1;i>=0;i--)
        {
                if(TemperatureValueRDB[i]->Enabled==true)
                {
                        NumberEnabled++;
                        FirstEnabled=i;
                }
                if(TemperatureValueRDB[i]->Checked==true)
                        Checked=i;
        }
        /*--------------------------------------------------
        ���� ���������� ����������� � ���� ������ �������� ����������� ���������,
        �� �������� ������ �������� �����������
        --------------------------------------------------*/
        if(TemperatureValueRDB[Checked]->Enabled==false)
        {
                TemperatureValueIndex=FirstEnabled;
                TemperatureValueRDB[FirstEnabled]->Checked=true;
        }

        /*--------------------------------------------------
        ���� ��������� ����� ���������� ������ � ���� ������ �������� �����������,
        �� ��������, ��� �������� ����������� �� ���������� � ������� ��������������� ���������
        --------------------------------------------------*/
        if(PreviousTemperatureValueIndex!=TemperatureValueIndex)
        {
                frm_Main->lbl_TemperatureCondition->Font->Color=clRed;
                frm_Main->lbl_TemperatureCondition->Caption=Message;
                TemperatureStatus=0;
        }

        /*--------------------------------------------------
        ���� ���������� �������� ������ � ���� ������ �������� ����������� ����� 1,
        �� ��������, ��� �������� ����������� ���������� � ������� �������� ��������� �����������
        --------------------------------------------------*/
        if(NumberEnabled==1)
        {
                frm_Main->lbl_TemperatureCondition->Font->Color=clWindowText;
                frm_Main->lbl_TemperatureCondition->Caption=TemperatureValue[TemperatureValueIndex]+", "+TemperatureChange[TemperatureChangeIndex]+" �����������";
                TemperatureStatus=1;
        }

        /*--------------------------------------------------
        �������������� ����� ����� �������� ����������� � ���� ������ �������� �������,
        ������������ ����� ������ �������� �����������,
        ������������ ����� ���������� �����������
        --------------------------------------------------*/
        PreviousRoadConditionIndex=RoadConditionIndex;

        NumberEnabled=0;
        for(i=RoadConditionNumber-1;i>=0;i--)
        {
                if(RoadConditionRDB[i]->Enabled==true)
                {
                        NumberEnabled++;
                        FirstEnabled=i;
                }
                if(RoadConditionRDB[i]->Checked==true)
                        Checked=i;
        }

        /*--------------------------------------------------
        ���� ���������� ����������� � ���� ������ �������� �������,
        �� �������� ������ �������� �����������
        --------------------------------------------------*/
        if(RoadConditionRDB[Checked]->Enabled==false)
        {
                RoadConditionIndex=FirstEnabled;
                RoadConditionRDB[FirstEnabled]->Checked=true;
        }

        /*--------------------------------------------------
        ���� ��������� ����� ���������� ������ � ���� ������ �������� �������,
        �� ��������, ��� �������� ������� �� ���������� � ������� ��������������� ���������
        --------------------------------------------------*/
        if(PreviousRoadConditionIndex!=RoadConditionIndex)
        {
                frm_Main->lbl_RoadCondition->Font->Color=clRed;
                frm_Main->lbl_RoadCondition->Caption=Message;
                RoadConditionStatus=0;
        }

        /*--------------------------------------------------
        ���� ���������� �������� ������ � ���� ������ �������� ������� ����� 1,
        �� ��������, ��� �������� ������� ���������� � ������� ��������� �������� �������
        --------------------------------------------------*/
        if(NumberEnabled==1)
        {
                frm_Main->lbl_RoadCondition->Font->Color=clWindowText;
                frm_Main->lbl_RoadCondition->Caption=RoadConditionRDB[RoadConditionIndex]->Caption;
                RoadConditionStatus=1;
        }

        /*--------------------------------------------------
        ���� ��������� ��������� � ������ �������, �� ���������� ������ ���������� ������,
        ��� ���� ��������� ��������������� ���������
        --------------------------------------------------*/
        if(PreviousTemperatureValueIndex!=TemperatureValueIndex ||
           PreviousTemperatureChangeIndex!=TemperatureChangeIndex ||
           PreviousPrecipitationIndex!=PrecipitationIndex ||
           PreviousRoadConditionIndex!=RoadConditionIndex)
        {
                frm_Main->lbl_SnowClearing->Font->Color=clGreen;
                frm_Main->lbl_SnowClearing->Caption=Message;
                frm_Main->lbl_SandSpread->Font->Color=clGreen;
                frm_Main->lbl_SandSpread->Caption=Message;
                frm_Main->lbl_SaltSpread->Font->Color=clGreen;
                frm_Main->lbl_SaltSpread->Caption=Message;
        }

        /*--------------------------------------------------
        ����������� ������������ ���������� ���� ������� � ������� ����
        --------------------------------------------------*/
        frm_Main->lbl_Precipitation->Font->Color=clWindowText;
        frm_Main->lbl_Precipitation->Caption=Precipitation[PrecipitationIndex];
        PrecipitationStatus=1;//��������, ��� ��� ������� ������
}
//---------------------------------------------------------------------------

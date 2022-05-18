/*--------------------------------------------------
� ���� ����� �������� ���, ������������ ������ ���� ������ �������� �������
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
Tfrm_RoadCondition *frm_RoadCondition;
//---------------------------------------------------------------------------
__fastcall Tfrm_RoadCondition::Tfrm_RoadCondition(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_RoadCondition::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        ���������� ��������� ������ RoadConditionRDB �������� ���������� �� �����������,
        ������������ ��������� �������� �������. ��� �������� � ���������� ���������� �
        ������������ �� �� ���������, � �� �������
        --------------------------------------------------*/
        RoadConditionRDB[0]=rdb_RoadCondition0;
        RoadConditionRDB[1]=rdb_RoadCondition1;
        RoadConditionRDB[2]=rdb_RoadCondition2;
        RoadConditionRDB[3]=rdb_RoadCondition3;
        /*--------------------------------------------------
        ���������� �������� ������������ � ��������� ����� �� ������
        --------------------------------------------------*/
        for(int i=0;i<RoadConditionNumber;i++)
                RoadConditionRDB[i]->Caption=RoadCondition[i];
        RoadConditionRDB[RoadConditionIndex]->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_RoadCondition::btn_RoadConditionOKClick(
      TObject *Sender)
{
        frm_RoadCondition->Hide();//������ ���� ������ �������� �������
        frm_Main->Enabled=true;//������� �������� ������� ����

        PreviousRoadConditionIndex=RoadConditionIndex;

        for(i=0;i<RoadConditionNumber;i++)//����� ���������� �����������
                if(RoadConditionRDB[i]->Checked==true)
                {
                        RoadConditionIndex=i;
                        break;
                }

        /*--------------------------------------------------
        ��� ��� ����� ������������� �������� ��������� ������� �������������
        �� ���� ������������ � ����� �������,
        �� � ��������������� ����� ���������� ��������� ����������� ������� �����������
        --------------------------------------------------*/
        /*--------------------------------------------------
        ��� ����������� � ����� ������ ����������� � ���� ������� �������� �����������
        --------------------------------------------------*/
        for(i=0;i<PrecipitationNumber;i++)
                PrecipitationRDB[i]->Enabled=false;
        for(i=0;i<TemperatureValueNumber;i++)
                TemperatureValueRDB[i]->Enabled=false;

        /*--------------------------------------------------
        ��������������� ActionList � ������� ����� ��� ������ ���������� ��������� �������
        ��������� � �������� ��������� �����������.
        ��� ������ ����� ������ �����������:
        1.�������� �������� ����������� �����������, ������ ������� ��������� � ���� ������
        2.�������� �������� ����������� ���� �������, ������ ������� ��������� � ���� ������
        --------------------------------------------------*/
        for(i=0;i<ActionListNumberRow;i++)
                if(RoadConditionIndex==ActionList[i][3])
                {
                        TemperatureValueRDB[ActionList[i][0]]->Enabled=true;
                        PrecipitationRDB[ActionList[i][1]]->Enabled=true;
                }
        /*--------------------------------------------------
        �������������� ����� ����� �������� ����������� � ���� ������ ���� �������,
        ������������ ����� ������ �������� �����������,
        ������������ ����� ���������� �����������
        --------------------------------------------------*/
        PreviousPrecipitationIndex=PrecipitationIndex;

        NumberEnabled=0;
        for(i=PrecipitationNumber-1;i>=0;i--)
        {
                if(PrecipitationRDB[i]->Enabled==true)
                {
                        NumberEnabled++;
                        FirstEnabled=i;
                }
                if(PrecipitationRDB[i]->Checked==true)
                        Checked=i;
        }

        /*--------------------------------------------------
        ���� ���������� ����������� � ���� ������ ���� ������� ���������,
        �� �������� ������ �������� �����������
        --------------------------------------------------*/
        if(PrecipitationRDB[Checked]->Enabled==false)
        {
                PrecipitationIndex=FirstEnabled;
                PrecipitationRDB[FirstEnabled]->Checked=true;
        }

        /*--------------------------------------------------
        ���� ��������� ����� ���������� ������ � ���� ������ ���� �������,
        �� ��������, ��� ��� ������� �� ��������� � ������� ��������������� ���������
        --------------------------------------------------*/
        if(PreviousPrecipitationIndex!=PrecipitationIndex)
        {
                frm_Main->lbl_Precipitation->Font->Color=clRed;
                frm_Main->lbl_Precipitation->Caption=Message;
                PrecipitationStatus=0;
        }

        /*--------------------------------------------------
        ���� ���������� �������� ������ � ���� ������ ���� ������� ����� 1,
        �� ��������, ��� ��� ������� ��������� � ������� �������� ���������� ���� �������
        --------------------------------------------------*/
        if(NumberEnabled==1)
        {
                frm_Main->lbl_Precipitation->Font->Color=clWindowText;
                frm_Main->lbl_Precipitation->Caption=PrecipitationRDB[PrecipitationIndex]->Caption;
                PrecipitationStatus=1;
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
        ���� ���������� ����������� � ���� ������ �������� �����������,
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
        ����������� ������������ ��������� �������� ������� � ������� ����
        --------------------------------------------------*/
        frm_Main->lbl_RoadCondition->Font->Color=clWindowText;
        frm_Main->lbl_RoadCondition->Caption=RoadCondition[RoadConditionIndex];
        RoadConditionStatus=1;//��������, ��� �������� ������� �������
}
//---------------------------------------------------------------------------

/*--------------------------------------------------
� ���� ����� �������� ���, ������������ ������ ���� ������ ������������� �������
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
Tfrm_TemperatureCondition *frm_TemperatureCondition;

//---------------------------------------------------------------------------
__fastcall Tfrm_TemperatureCondition::Tfrm_TemperatureCondition(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall Tfrm_TemperatureCondition::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        ���������� ��������� ������ TemperatureValueRDB �������� ���������� �� �����������,
        ������������ ��������� �������� �����������. ��� �������� � ���������� ���������� �
        ������������ �� �� ���������, � �� �������
        --------------------------------------------------*/
        TemperatureValueRDB[0]=rdb_TemperatureValue0;
        TemperatureValueRDB[1]=rdb_TemperatureValue1;
        TemperatureValueRDB[2]=rdb_TemperatureValue2;
        /*--------------------------------------------------
        ���������� �������� ������������ � ��������� ����� �� ������
        --------------------------------------------------*/
        for(i=0;i<TemperatureValueNumber;i++)
                TemperatureValueRDB[i]->Caption=TemperatureValue[i];
        TemperatureValueRDB[TemperatureValueIndex]->Checked=true;

        /*--------------------------------------------------
        ���������� ��������� ������ TemperatureChangeRDB �������� ���������� �� �����������,
        ������������ ��������� �������� �����������. ��� �������� � ���������� ���������� �
        ������������ �� �� ���������, � �� �������
        --------------------------------------------------*/
        TemperatureChangeRDB[0]=rdb_TemperatureChange0;
        TemperatureChangeRDB[1]=rdb_TemperatureChange1;
        /*--------------------------------------------------
        ���������� �������� ������������ � ��������� ����� �� ������
        --------------------------------------------------*/
        for(i=0;i<TemperatureChangeNumber;i++)
                TemperatureChangeRDB[i]->Caption=TemperatureChange[i];
        TemperatureChangeRDB[TemperatureChangeIndex]->Checked=true; 
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_TemperatureCondition::btn_TemperatureConditionOKClick(
      TObject *Sender)
{
        frm_TemperatureCondition->Hide();//������ ���� ������ ������������� �������
        frm_Main->Enabled=true;//������� �������� ������� ����

        PreviousTemperatureValueIndex=TemperatureValueIndex;

        for(i=0;i<TemperatureValueNumber;i++)//����� ���������� ����������� �������� �����������
                if(TemperatureValueRDB[i]->Checked==true)
                {
                        TemperatureValueIndex=i;
                        break;
                }


        PreviousTemperatureChangeIndex=TemperatureChangeIndex;

        for(i=0;i<TemperatureChangeNumber;i++)//����� ���������� ����������� ��������� �����������
                if(TemperatureChangeRDB[i]->Checked==true)
                {
                        TemperatureChangeIndex=i;
                        break;
                }

        /*--------------------------------------------------
        ��� ��� ����� ������������� �������� ����������� �������������
        �� ���� �������� �������� � ����� �������,
        �� � ��������������� ����� ���������� ��������� ����������� ������� �����������
        --------------------------------------------------*/
        /*--------------------------------------------------
        ��� ����������� � ����� ������ �������� ������� � ���� ������� �������� �����������
        --------------------------------------------------*/
        for(i=0;i<RoadConditionNumber;i++)
                RoadConditionRDB[i]->Enabled=false;
        for(i=0;i<PrecipitationNumber;i++)
                PrecipitationRDB[i]->Enabled=false;

        /*--------------------------------------------------
        ��������������� ActionList � ������� ����� ��� ������ ���������� �������� �����������
        ��������� � �������� ��������� �����������.
        ��� ������ ����� ������ �����������:
        1.�������� �������� ����������� �������� �������, ������ ������� ��������� � ���� ������
        2.�������� �������� ����������� ���� �������, ������ ������� ��������� � ���� ������
        --------------------------------------------------*/
        for(i=0;i<ActionListNumberRow;i++)
                if(TemperatureValueIndex==ActionList[i][0])
                {
                        PrecipitationRDB[ActionList[i][1]]->Enabled=true;
                        RoadConditionRDB[ActionList[i][3]]->Enabled=true;
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
        ����������� ������������ ��������� ������������� ������� � ������� ����
        --------------------------------------------------*/
        frm_Main->lbl_TemperatureCondition->Font->Color=clWindowText;
        frm_Main->lbl_TemperatureCondition->Caption=TemperatureValue[TemperatureValueIndex]+", "+TemperatureChange[TemperatureChangeIndex]+" �����������";
        TemperatureStatus=1;//��������, ��� ������������� ������� �������
}
//---------------------------------------------------------------------------


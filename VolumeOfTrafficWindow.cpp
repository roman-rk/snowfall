//---------------------------------------------------------------------------

#include <vcl.h>
#include "ExternVariable.h"
#include "MainWindow.h"
#pragma hdrstop

#include "VolumeOfTrafficWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_VolumeOfTraffic *frm_VolumeOfTraffic;
//---------------------------------------------------------------------------
__fastcall Tfrm_VolumeOfTraffic::Tfrm_VolumeOfTraffic(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_VolumeOfTraffic::btn_VolumeOfTrafficOKClick(
      TObject *Sender)
{
        frm_VolumeOfTraffic->Hide();//������ ���� ������ ������������� ��������
        frm_Main->Enabled=true;//������� �������� ������� ����

        PreviousVolumeOfTrafficIndex=VolumeOfTrafficIndex;

        for(i=0;i<VolumeOfTrafficNumber;i++)//����� ���������� ����������� ������������� ��������
                if(VolumeOfTrafficRDB[i]->Checked==true)
                {
                        VolumeOfTrafficIndex=i;
                        break;
                }

        /*--------------------------------------------------
        ��� ��� ����� �������������  �������� ������������� �������� �������������
        �� ���� ���������������� ��������� �����,
        �� � ��������������� ���� ���������� ��������� ����������� ������� �����������
        --------------------------------------------------*/
        /*--------------------------------------------------
        ��� ����������� � ���� ������ ����������������� �������� ������ �������� �����������
        --------------------------------------------------*/
        for(i=0;i<RoadMeaningNumber;i++)
                RoadMeaningRDB[i]->Enabled=false;


        /*--------------------------------------------------
        ��������������� DirectiveList � ������� ����� ��� ������ ��������� ������������� ��������
        ��������� � �������� ��������� �����������.
        ��� ������ ����� ������ �����������:
        1.�������� �������� ����������� ����������������� �������� ������, ������ ������� ��������� � ���� ������
        --------------------------------------------------*/
        for(i=0;i<DirectiveListNumberRow;i++)
                if(VolumeOfTrafficIndex==DirectiveList[i][1])
                        RoadMeaningRDB[DirectiveList[i][0]]->Enabled=true;

        /*--------------------------------------------------
        �������������� ����� ����� �������� ����������� � ���� ������ ����������������� �������� ������,
        ������������ ����� ������ �������� �����������,
        ������������ ����� ���������� �����������
        --------------------------------------------------*/
        PreviousRoadMeaningIndex=RoadMeaningIndex;

        NumberEnabled=0;
        for(i=RoadMeaningNumber-1;i>=0;i--)
        {
                if(RoadMeaningRDB[i]->Enabled==true)
                {
                        NumberEnabled++;
                        FirstEnabled=i;
                }
                if(RoadMeaningRDB[i]->Checked==true)
                        Checked=i;
        }

        /*--------------------------------------------------
        ���� ���������� ����������� � ���� ������ ����������������� �������� ������ ���������,
        �� �������� ������ �������� �����������
        --------------------------------------------------*/
        if(RoadMeaningRDB[Checked]->Enabled==false)
        {
                RoadMeaningIndex=FirstEnabled;
                RoadMeaningRDB[FirstEnabled]->Checked=true;
        }

        /*--------------------------------------------------
        ���� ��������� ����� ���������� ������ � ���� ������ ����������������� �������� ������,
        �� ��������, ��� �������� ������ �� ���������� � ������� ��������������� ���������
        --------------------------------------------------*/
        if(PreviousRoadMeaningIndex!=RoadMeaningIndex)
        {
                frm_Main->lbl_RoadMeaning->Font->Color=clRed;
                frm_Main->lbl_RoadMeaning->Caption=Message;
                RoadMeaningStatus=0;
        }

        /*--------------------------------------------------
        ���� ���������� �������� ������ � ���� ������ �������� ������ ����� 1,
        �� ��������, ��� �������� ������ ���������� � ������� ���������������� �������� ������
        --------------------------------------------------*/
        if(NumberEnabled==1)
        {
                frm_Main->lbl_RoadMeaning->Font->Color=clWindowText;
                frm_Main->lbl_RoadMeaning->Caption=RoadMeaningRDB[RoadMeaningIndex]->Caption;
                RoadMeaningStatus=1;
        }
        
        /*--------------------------------------------------
        ���� ��������� ��������� � ������ �������, �� ���������� ������ ���������� ������,
        ��� ���� ��������� ��������������� ���������
        --------------------------------------------------*/
        if(RoadMeaningStatus==1)
        {
                for(i=0;i<DirectiveListNumberRow;i++)
                        if(VolumeOfTrafficIndex==DirectiveList[i][1] && RoadMeaningIndex==DirectiveList[i][0])
                                break;
                frm_Main->lbl_MinWidth->Caption=Directive[DirectiveList[i][2]];
                frm_Main->lbl_MaxThickness->Caption=Directive[DirectiveList[i][3]];
                frm_Main->lbl_AdmissibleSnowThickness1->Caption=Directive[DirectiveList[i][4]];
                frm_Main->lbl_AdmissibleSnowThickness2->Caption=Directive[DirectiveList[i][5]];
                frm_Main->lbl_MaxTime->Caption=Directive[DirectiveList[i][6]];
        }

        /*--------------------------------------------------
        ����������� ������������ ��������� ������������� �������� � ������� ����
        --------------------------------------------------*/
        frm_Main->lbl_VolumeOfTraffic->Font->Color=clWindowText;
        frm_Main->lbl_VolumeOfTraffic->Caption=VolumeOfTraffic[VolumeOfTrafficIndex];
        VolumeOfTrafficStatus=1;//��������, ��� ������������� �������� �������

        if(RoadMeaningStatus==1 && VolumeOfTrafficStatus==1)
                DirectiveStatus=1;
        else
                DirectiveStatus=0;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_VolumeOfTraffic::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        ���������� ��������� ������ VolumeOfTrafficRDB �������� ���������� �� �����������,
        ������������ ��������� �������� ������������� ��������. ��� �������� � ���������� ���������� �
        ������������ �� �� ���������, � �� �������
        --------------------------------------------------*/
        VolumeOfTrafficRDB[0]=rdb_VolumeOfTraffic0;
        VolumeOfTrafficRDB[1]=rdb_VolumeOfTraffic1;
        VolumeOfTrafficRDB[2]=rdb_VolumeOfTraffic2;
        VolumeOfTrafficRDB[3]=rdb_VolumeOfTraffic3;
        VolumeOfTrafficRDB[4]=rdb_VolumeOfTraffic4;
        VolumeOfTrafficRDB[5]=rdb_VolumeOfTraffic5;
        /*--------------------------------------------------
        ���������� �������� ������������ � ��������� ����� �� ������
        --------------------------------------------------*/
        for(i=0;i<VolumeOfTrafficNumber;i++)
                VolumeOfTrafficRDB[i]->Caption=VolumeOfTraffic[i];
        VolumeOfTrafficRDB[VolumeOfTrafficIndex]->Checked=true;
}
//---------------------------------------------------------------------------

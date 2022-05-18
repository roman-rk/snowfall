//---------------------------------------------------------------------------

#include <vcl.h>
#include "ExternVariable.h"
#include "MainWindow.h"
#pragma hdrstop

#include "RoadMeaningWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_RoadMeaning *frm_RoadMeaning;
//---------------------------------------------------------------------------
__fastcall Tfrm_RoadMeaning::Tfrm_RoadMeaning(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_RoadMeaning::btn_RoadMeaningOKClick(TObject *Sender)
{
        frm_RoadMeaning->Hide();//������ ���� ������ ����������������� �������� �����
        frm_Main->Enabled=true;//������� �������� ������� ����

        PreviousRoadMeaningIndex=RoadMeaningIndex;

        for(i=0;i<RoadMeaningNumber;i++)//����� ���������� ����������� ����������������� �������� ������
                if(RoadMeaningRDB[i]->Checked==true)
                {
                        RoadMeaningIndex=i;
                        break;
                }

        /*--------------------------------------------------
        ��� ��� ����� ������������� ����������������� �������� ������ �������������
        �� ���� �������������� ��������,
        �� � ��������������� ���� ���������� ��������� ����������� ������� �����������
        --------------------------------------------------*/
        /*--------------------------------------------------
        ��� ����������� � ���� ������ ������������� �������� �������� �����������
        --------------------------------------------------*/
        for(i=0;i<VolumeOfTrafficNumber;i++)
                VolumeOfTrafficRDB[i]->Enabled=false;


        /*--------------------------------------------------
        ��������������� DirectiveList � ������� ����� ��� ������ ���������� ����������������� �������� ������
        ��������� � �������� ��������� �����������.
        ��� ������ ����� ������ �����������:
        1.�������� �������� ����������� ������������� ��������, ������ ������� ��������� � ���� ������
        --------------------------------------------------*/
        for(i=0;i<DirectiveListNumberRow;i++)
                if(RoadMeaningIndex==DirectiveList[i][0])
                        VolumeOfTrafficRDB[DirectiveList[i][1]]->Enabled=true;

        /*--------------------------------------------------
        �������������� ����� ����� �������� ����������� � ���� ������ ������������� ��������,
        ������������ ����� ������ �������� �����������,
        ������������ ����� ���������� �����������
        --------------------------------------------------*/
        PreviousVolumeOfTrafficIndex=VolumeOfTrafficIndex;

        NumberEnabled=0;
        for(i=VolumeOfTrafficNumber-1;i>=0;i--)
        {
                if(VolumeOfTrafficRDB[i]->Enabled==true)
                {
                        NumberEnabled++;
                        FirstEnabled=i;
                }
                if(VolumeOfTrafficRDB[i]->Checked==true)
                        Checked=i;
        }

        /*--------------------------------------------------
        ���� ���������� ����������� � ���� ������ ������������� �������� ���������,
        �� �������� ������ �������� �����������
        --------------------------------------------------*/
        if(VolumeOfTrafficRDB[Checked]->Enabled==false)
        {
                VolumeOfTrafficIndex=FirstEnabled;
                VolumeOfTrafficRDB[FirstEnabled]->Checked=true;
        }

        /*--------------------------------------------------
        ���� ��������� ����� ���������� ������ � ���� ������ ������������� ��������,
        �� ��������, ��� ������������� �������� �� ���������� � ������� ��������������� ���������
        --------------------------------------------------*/
        if(PreviousVolumeOfTrafficIndex!=VolumeOfTrafficIndex)
        {
                frm_Main->lbl_VolumeOfTraffic->Font->Color=clRed;
                frm_Main->lbl_VolumeOfTraffic->Caption=Message;
                VolumeOfTrafficStatus=0;
        }

        /*--------------------------------------------------
        ���� ���������� �������� ������ � ���� ������ ������������� �������� ����� 1,
        �� ��������, ��� ������������� �������� ���������� � ������� �������� ��������� ������������� ��������
        --------------------------------------------------*/
        if(NumberEnabled==1)
        {
                frm_Main->lbl_VolumeOfTraffic->Font->Color=clWindowText;
                frm_Main->lbl_VolumeOfTraffic->Caption=VolumeOfTrafficRDB[VolumeOfTrafficIndex]->Caption;
                VolumeOfTrafficStatus=1;
        }
        
        /*--------------------------------------------------
        ���� ��������� ��������� � ������ �������, �� ���������� ������ ���������� ������,
        ��� ���� ��������� ��������������� ���������
        --------------------------------------------------*/
        if(VolumeOfTrafficStatus==1)
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
        ����������� ������������ ���������� ����������������� �������� ����� � ������� ����
        --------------------------------------------------*/
        frm_Main->lbl_RoadMeaning->Font->Color=clWindowText;
        frm_Main->lbl_RoadMeaning->Caption=RoadMeaning[RoadMeaningIndex];
        RoadMeaningStatus=1;//��������, ��� ���������������� �������� ������ �������
        
        if(RoadMeaningStatus==1 && VolumeOfTrafficStatus==1)
                DirectiveStatus=1;
        else
                DirectiveStatus=0;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_RoadMeaning::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        ���������� ��������� ������ RoadMeaningRDB �������� ���������� �� �����������,
        ������������ ��������� ���������������� �������� �����. ��� �������� � ���������� ���������� �
        ������������ �� �� ���������, � �� �������
        --------------------------------------------------*/
        RoadMeaningRDB[0]=rdb_RoadMeaning0;
        RoadMeaningRDB[1]=rdb_RoadMeaning1;
        RoadMeaningRDB[2]=rdb_RoadMeaning2;
        RoadMeaningRDB[3]=rdb_RoadMeaning3;
        RoadMeaningRDB[4]=rdb_RoadMeaning4;
        /*--------------------------------------------------
        ���������� �������� ������������ � ��������� ����� �� ������
        --------------------------------------------------*/
        for(i=0;i<RoadMeaningNumber;i++)
                RoadMeaningRDB[i]->Caption=RoadMeaning[i];
        RoadMeaningRDB[RoadMeaningIndex]->Checked=true;
}
//---------------------------------------------------------------------------

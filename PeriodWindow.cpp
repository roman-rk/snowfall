/*--------------------------------------------------
� ���� ����� �������� ���, ������������ ������ ���� ������ �������
--------------------------------------------------*/
//---------------------------------------------------------------------------

#include <vcl.h>
#include "ExternVariable.h"
#include "MainWindow.h"
#pragma hdrstop

#include "PeriodWindow.h"   
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm_Period *frm_Period;
//---------------------------------------------------------------------------
__fastcall Tfrm_Period::Tfrm_Period(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_Period::FormCreate(TObject *Sender)
{
        /*--------------------------------------------------
        ���������� ��������� ������ PeriodRDB �������� ���������� �� �����������,
        ������������ ��������� �������. ��� �������� � ���������� ���������� �
        ������������ �� �� ���������, � �� �������
        --------------------------------------------------*/
        PeriodRDB[0]=rdb_Period0;
        PeriodRDB[1]=rdb_Period1;
        PeriodRDB[2]=rdb_Period2;
        /*--------------------------------------------------
        ���������� �������� ������������ � ��������� ����� �� ������
        --------------------------------------------------*/
        for(int i=0;i<PeriodNumber;i++)
                PeriodRDB[i]->Caption=Period[i];
        PeriodRDB[PeriodIndex]->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm_Period::btn_PeriodOKClick(TObject *Sender)
{
        frm_Period->Hide();//������ ���� ������ �������
        frm_Main->Enabled=true;//������� �������� ������� ����

        PreviousPeriodIndex=PeriodIndex;

        for(int i=0;i<PeriodNumber;i++)//����� ���������� �����������
                if(PeriodRDB[i]->Checked==true)
                {
                        PeriodIndex=i;
                        break;
                }

        /*--------------------------------------------------
        ����������� ������������ ���������� ������� � ������� ����
        --------------------------------------------------*/
        frm_Main->lbl_Period->Font->Color=clWindowText;
        frm_Main->lbl_Period->Caption=Period[PeriodIndex];

        /*--------------------------------------------------
        ���� ����� ��������� ������ ������� �� �����������, ��
        ���������� ��������� ����� ������ ������������� ��������
        �, �������, ������������ �� ����� ������������� �������� ������������
        --------------------------------------------------*/
        if(PreviousPeriodIndex!=PeriodIndex)
        {
                frm_Main->lbl_SnowClearing->Font->Color=clGreen;
                frm_Main->lbl_SnowClearing->Caption=Message;
                frm_Main->lbl_SandSpread->Font->Color=clGreen;
                frm_Main->lbl_SandSpread->Caption=Message;
                frm_Main->lbl_SaltSpread->Font->Color=clGreen;
                frm_Main->lbl_SaltSpread->Caption=Message;
        }

        PeriodStatus=1;//��������, ��� ������ ������
}
//---------------------------------------------------------------------------


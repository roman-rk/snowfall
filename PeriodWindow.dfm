object frm_Period: Tfrm_Period
  Left = 812
  Top = 171
  Width = 148
  Height = 162
  AutoSize = True
  BorderIcons = []
  Caption = #1055#1077#1088#1080#1086#1076
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnHide = btn_PeriodOKClick
  PixelsPerInch = 96
  TextHeight = 13
  object grd_Period: TGroupBox
    Left = 0
    Top = 0
    Width = 140
    Height = 135
    TabOrder = 0
    object btn_PeriodOK: TButton
      Left = 33
      Top = 100
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 0
      OnClick = btn_PeriodOKClick
    end
    object rdb_Period0: TRadioButton
      Left = 10
      Top = 25
      Width = 125
      Height = 17
      TabOrder = 1
    end
    object rdb_Period1: TRadioButton
      Left = 10
      Top = 50
      Width = 125
      Height = 17
      TabOrder = 2
    end
    object rdb_Period2: TRadioButton
      Left = 10
      Top = 75
      Width = 125
      Height = 17
      TabOrder = 3
    end
  end
end

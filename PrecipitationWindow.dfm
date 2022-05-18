object frm_Precipitation: Tfrm_Precipitation
  Left = 799
  Top = 124
  Width = 168
  Height = 162
  AutoSize = True
  BorderIcons = []
  Caption = #1058#1080#1087' '#1086#1089#1072#1076#1082#1086#1074
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnHide = btn_PrecipitationOKClick
  PixelsPerInch = 96
  TextHeight = 13
  object grb_Precipitation: TGroupBox
    Left = 0
    Top = 0
    Width = 160
    Height = 135
    TabOrder = 0
    object btn_PrecipitationOK: TButton
      Left = 43
      Top = 100
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 0
      OnClick = btn_PrecipitationOKClick
    end
    object rdb_Precipitation0: TRadioButton
      Left = 10
      Top = 25
      Width = 113
      Height = 17
      TabOrder = 1
    end
    object rdb_Precipitation1: TRadioButton
      Left = 10
      Top = 50
      Width = 113
      Height = 17
      TabOrder = 2
    end
    object rdb_Precipitation2: TRadioButton
      Left = 10
      Top = 75
      Width = 113
      Height = 17
      TabOrder = 3
    end
  end
end

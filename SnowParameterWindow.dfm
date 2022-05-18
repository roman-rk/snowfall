object frm_SnowParameter: Tfrm_SnowParameter
  Left = 764
  Top = 373
  Width = 233
  Height = 127
  AutoSize = True
  BorderIcons = []
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1089#1085#1077#1075#1072
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnHide = btn_SnowParameterOKClick
  PixelsPerInch = 96
  TextHeight = 13
  object grb_SnowParameter: TGroupBox
    Left = 0
    Top = 0
    Width = 225
    Height = 100
    TabOrder = 0
    object stt_SnowDensity: TStaticText
      Left = 10
      Top = 15
      Width = 93
      Height = 17
      Caption = #1055#1083#1086#1090#1085#1086#1089#1090#1100' '#1089#1085#1077#1075#1072':'
      TabOrder = 0
    end
    object stt_SnowThickness: TStaticText
      Left = 10
      Top = 40
      Width = 112
      Height = 17
      Caption = #1058#1086#1083#1097#1080#1085#1072' '#1089#1083#1086#1103' '#1089#1085#1077#1075#1072':'
      TabOrder = 1
    end
    object stt_SnowDensityDimension: TStaticText
      Left = 185
      Top = 15
      Width = 34
      Height = 17
      Caption = #1075'/'#1089#1084'3'
      TabOrder = 2
    end
    object stt_SnowThicknessDimension: TStaticText
      Left = 185
      Top = 40
      Width = 12
      Height = 17
      Caption = #1084
      TabOrder = 3
    end
    object edt_SnowDensity: TEdit
      Left = 125
      Top = 13
      Width = 57
      Height = 21
      TabOrder = 4
    end
    object btn_SnowParameterOK: TButton
      Left = 72
      Top = 65
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 5
      OnClick = btn_SnowParameterOKClick
    end
    object edt_SnowThickness: TEdit
      Left = 125
      Top = 38
      Width = 57
      Height = 21
      TabOrder = 6
    end
  end
end

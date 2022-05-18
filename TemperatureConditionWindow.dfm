object frm_TemperatureCondition: Tfrm_TemperatureCondition
  Left = 820
  Top = 201
  Width = 178
  Height = 262
  AutoSize = True
  BorderIcons = []
  Caption = #1058#1077#1084#1087#1077#1088#1072#1090#1091#1088#1085#1099#1077' '#1091#1089#1083#1086#1074#1080#1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnHide = btn_TemperatureConditionOKClick
  PixelsPerInch = 96
  TextHeight = 13
  object grb_TemperatureCondition: TGroupBox
    Left = 0
    Top = 0
    Width = 170
    Height = 235
    TabOrder = 0
    object grb_TemperatureValue: TGroupBox
      Left = 10
      Top = 15
      Width = 150
      Height = 100
      Caption = ' '#1058#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072' '
      TabOrder = 0
      object rdb_TemperatureValue0: TRadioButton
        Left = 10
        Top = 25
        Width = 113
        Height = 17
        TabOrder = 0
      end
      object rdb_TemperatureValue1: TRadioButton
        Left = 10
        Top = 50
        Width = 113
        Height = 17
        TabOrder = 1
      end
      object rdb_TemperatureValue2: TRadioButton
        Left = 10
        Top = 75
        Width = 113
        Height = 17
        TabOrder = 2
      end
    end
    object grb_TemperatureChange: TGroupBox
      Left = 10
      Top = 120
      Width = 150
      Height = 75
      Caption = ' '#1048#1079#1084#1077#1085#1077#1085#1080#1077' '#1090#1077#1084#1087#1077#1088#1072#1090#1091#1088#1099' '
      TabOrder = 1
      object rdb_TemperatureChange0: TRadioButton
        Left = 10
        Top = 25
        Width = 113
        Height = 17
        TabOrder = 0
      end
      object rdb_TemperatureChange1: TRadioButton
        Left = 10
        Top = 50
        Width = 113
        Height = 17
        TabOrder = 1
      end
    end
    object btn_TemperatureConditionOK: TButton
      Left = 48
      Top = 200
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 2
      OnClick = btn_TemperatureConditionOKClick
    end
  end
end

object frm_RoadCondition: Tfrm_RoadCondition
  Left = 849
  Top = 531
  Width = 148
  Height = 187
  AutoSize = True
  BorderIcons = []
  Caption = #1044#1086#1088#1086#1078#1085#1099#1077' '#1091#1089#1083#1086#1074#1080#1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnHide = btn_RoadConditionOKClick
  PixelsPerInch = 96
  TextHeight = 13
  object grb_RoadCondition: TGroupBox
    Left = 0
    Top = 0
    Width = 140
    Height = 160
    TabOrder = 0
    object btn_RoadConditionOK: TButton
      Left = 33
      Top = 125
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 0
      OnClick = btn_RoadConditionOKClick
    end
    object rdb_RoadCondition0: TRadioButton
      Left = 10
      Top = 25
      Width = 120
      Height = 17
      TabOrder = 1
    end
    object rdb_RoadCondition1: TRadioButton
      Left = 10
      Top = 50
      Width = 120
      Height = 17
      TabOrder = 2
    end
    object rdb_RoadCondition2: TRadioButton
      Left = 10
      Top = 75
      Width = 120
      Height = 17
      TabOrder = 3
    end
    object rdb_RoadCondition3: TRadioButton
      Left = 10
      Top = 100
      Width = 120
      Height = 17
      TabOrder = 4
    end
  end
end

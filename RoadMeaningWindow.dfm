object frm_RoadMeaning: Tfrm_RoadMeaning
  Left = 523
  Top = 538
  Width = 483
  Height = 212
  AutoSize = True
  BorderIcons = []
  Caption = #1047#1085#1072#1095#1077#1085#1080#1077' '#1076#1086#1088#1086#1075#1080
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnHide = btn_RoadMeaningOKClick
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 475
    Height = 185
    TabOrder = 0
    object rdb_RoadMeaning0: TRadioButton
      Left = 10
      Top = 25
      Width = 460
      Height = 17
      TabOrder = 0
    end
    object rdb_RoadMeaning1: TRadioButton
      Left = 10
      Top = 50
      Width = 460
      Height = 17
      TabOrder = 1
    end
    object rdb_RoadMeaning2: TRadioButton
      Left = 10
      Top = 75
      Width = 460
      Height = 17
      TabOrder = 2
    end
    object rdb_RoadMeaning3: TRadioButton
      Left = 10
      Top = 100
      Width = 460
      Height = 17
      TabOrder = 3
    end
    object rdb_RoadMeaning4: TRadioButton
      Left = 10
      Top = 125
      Width = 460
      Height = 17
      TabOrder = 4
    end
    object btn_RoadMeaningOK: TButton
      Left = 203
      Top = 150
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 5
      OnClick = btn_RoadMeaningOKClick
    end
  end
end

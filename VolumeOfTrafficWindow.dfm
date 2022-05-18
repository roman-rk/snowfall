object frm_VolumeOfTraffic: Tfrm_VolumeOfTraffic
  Left = 816
  Top = 119
  Width = 183
  Height = 237
  AutoSize = True
  BorderIcons = []
  Caption = #1048#1085#1090#1077#1085#1089#1080#1074#1085#1086#1089#1090#1100' '#1076#1074#1080#1078#1077#1085#1080#1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnHide = btn_VolumeOfTrafficOKClick
  PixelsPerInch = 96
  TextHeight = 13
  object grb_VolumeOfTraffic: TGroupBox
    Left = 0
    Top = 0
    Width = 175
    Height = 210
    TabOrder = 0
    object rdb_VolumeOfTraffic0: TRadioButton
      Left = 10
      Top = 25
      Width = 160
      Height = 17
      TabOrder = 0
    end
    object rdb_VolumeOfTraffic1: TRadioButton
      Left = 10
      Top = 50
      Width = 160
      Height = 17
      TabOrder = 1
    end
    object rdb_VolumeOfTraffic2: TRadioButton
      Left = 10
      Top = 75
      Width = 160
      Height = 17
      TabOrder = 2
    end
    object rdb_VolumeOfTraffic3: TRadioButton
      Left = 10
      Top = 100
      Width = 160
      Height = 17
      TabOrder = 3
    end
    object rdb_VolumeOfTraffic4: TRadioButton
      Left = 10
      Top = 125
      Width = 160
      Height = 17
      TabOrder = 4
    end
    object rdb_VolumeOfTraffic5: TRadioButton
      Left = 10
      Top = 150
      Width = 160
      Height = 17
      TabOrder = 5
    end
    object btn_VolumeOfTrafficOK: TButton
      Left = 53
      Top = 175
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 6
      OnClick = btn_VolumeOfTrafficOKClick
    end
  end
end

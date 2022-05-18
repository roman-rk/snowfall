object frm_Main: Tfrm_Main
  Left = 203
  Top = 106
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Snowfall'
  ClientHeight = 310
  ClientWidth = 500
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = Menu
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object grb_Action: TGroupBox
    Left = 0
    Top = 0
    Width = 500
    Height = 310
    TabOrder = 0
    object lbl_SaltSpread: TLabel
      Left = 175
      Top = 290
      Width = 75
      Height = 13
      Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lbl_Period: TLabel
      Left = 175
      Top = 118
      Width = 75
      Height = 13
      Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lbl_Precipitation: TLabel
      Left = 175
      Top = 54
      Width = 75
      Height = 13
      Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lbl_RoadCondition: TLabel
      Left = 175
      Top = 86
      Width = 75
      Height = 13
      Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lbl_SandSpread: TLabel
      Left = 175
      Top = 255
      Width = 75
      Height = 13
      Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lbl_TemperatureCondition: TLabel
      Left = 175
      Top = 22
      Width = 75
      Height = 13
      Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object lbl_SnowClearing: TLabel
      Left = 175
      Top = 220
      Width = 75
      Height = 13
      Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object btn_TemperatureCondition: TButton
      Left = 10
      Top = 16
      Width = 150
      Height = 25
      Caption = #1058#1077#1084#1087#1077#1088#1072#1090#1091#1085#1099#1077' '#1091#1089#1083#1086#1074#1080#1103':'
      TabOrder = 0
      OnClick = btn_TemperatureConditionClick
    end
    object btn_RoadCondition: TButton
      Left = 10
      Top = 80
      Width = 150
      Height = 25
      Caption = #1044#1086#1088#1086#1078#1085#1099#1077' '#1091#1089#1083#1086#1074#1080#1103':'
      TabOrder = 1
      OnClick = btn_RoadConditionClick
    end
    object btn_Precipitation: TButton
      Left = 10
      Top = 48
      Width = 150
      Height = 25
      Caption = #1058#1080#1087' '#1086#1089#1072#1076#1082#1086#1074':'
      TabOrder = 2
      OnClick = btn_PrecipitationClick
    end
    object btn_Period: TButton
      Left = 10
      Top = 112
      Width = 150
      Height = 25
      Caption = #1055#1077#1088#1080#1086#1076':'
      TabOrder = 3
      OnClick = btn_PeriodClick
    end
    object btn_ActionCalculate: TButton
      Left = 267
      Top = 170
      Width = 200
      Height = 25
      Caption = #1056#1072#1089#1095#1077#1090' '#1088#1077#1082#1086#1084#1077#1085#1076#1091#1077#1084#1099#1093' '#1086#1087#1077#1088#1072#1094#1080#1081'...'
      TabOrder = 4
      OnClick = btn_ActionCalculateClick
    end
    object stt_SaltSpread: TStaticText
      Left = 10
      Top = 290
      Width = 115
      Height = 17
      Caption = #1056#1072#1079#1073#1088#1072#1089#1099#1074#1072#1085#1080#1077' '#1089#1086#1083#1080':'
      TabOrder = 5
    end
    object stt_SandSpread: TStaticText
      Left = 10
      Top = 255
      Width = 121
      Height = 17
      Caption = #1056#1072#1079#1073#1088#1072#1089#1099#1074#1072#1085#1080#1077' '#1087#1077#1089#1082#1072':'
      TabOrder = 6
    end
    object stt_SnowClearing: TStaticText
      Left = 10
      Top = 220
      Width = 77
      Height = 17
      Caption = #1057#1085#1077#1075#1086#1086#1095#1080#1089#1090#1082#1072':'
      TabOrder = 7
    end
    object btn_ClearConditionAction: TButton
      Left = 33
      Top = 170
      Width = 200
      Height = 25
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1091#1089#1083#1086#1074#1080#1103
      TabOrder = 8
      OnClick = btn_ClearConditionActionClick
    end
  end
  object grb_Car: TGroupBox
    Left = 0
    Top = 0
    Width = 500
    Height = 310
    TabOrder = 1
    object lbl_RoadMeaning: TLabel
      Left = 35
      Top = 40
      Width = 75
      Height = 13
      Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lbl_VolumeOfTraffic: TLabel
      Left = 230
      Top = 66
      Width = 75
      Height = 13
      Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lbl_SnowDensity: TLabel
      Left = 140
      Top = 227
      Width = 75
      Height = 13
      Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lbl_SnowThickness: TLabel
      Left = 140
      Top = 242
      Width = 75
      Height = 13
      Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object btn_RoadMeaning: TButton
      Left = 10
      Top = 10
      Width = 340
      Height = 25
      Caption = #1053#1072#1088#1086#1076#1085#1086#1093#1086#1079#1103#1081#1089#1090#1074#1077#1085#1085#1086#1077' '#1080' '#1072#1076#1084#1080#1085#1080#1089#1090#1088#1072#1090#1080#1074#1085#1086#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1076#1086#1088#1086#1075':'
      TabOrder = 0
      OnClick = btn_RoadMeaningClick
    end
    object btn_VolumeOfTraffic: TButton
      Left = 10
      Top = 60
      Width = 200
      Height = 25
      Caption = #1048#1085#1090#1077#1085#1089#1080#1074#1085#1086#1089#1090#1100' '#1076#1074#1080#1078#1077#1085#1080#1103':'
      TabOrder = 1
      OnClick = btn_VolumeOfTrafficClick
    end
    object btn_CarCalculate: TButton
      Left = 290
      Top = 230
      Width = 200
      Height = 25
      Caption = #1056#1072#1089#1095#1077#1090' '#1088#1077#1082#1086#1084#1077#1085#1076#1091#1077#1084#1086#1081' '#1084#1072#1096#1080#1085#1099'...'
      TabOrder = 2
      OnClick = btn_CarCalculateClick
    end
    object btn_SnowParameter: TButton
      Left = 10
      Top = 195
      Width = 110
      Height = 25
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1089#1085#1077#1075#1072
      TabOrder = 3
      OnClick = btn_SnowParameterClick
    end
    object grb_Directive: TGroupBox
      Left = 5
      Top = 90
      Width = 490
      Height = 100
      Caption = 
        ' '#1044#1080#1088#1077#1082#1090#1080#1074#1085#1099#1077' '#1089#1088#1086#1082#1080' '#1086#1095#1080#1089#1090#1082#1080' '#1089#1085#1077#1075#1072' '#1080' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1080' '#1075#1086#1083#1086#1083#1077#1076#1072' '#1085#1072' '#1076#1086#1088#1086#1075#1077 +
        ' '
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 4
      object lbl_MinWidth: TLabel
        Left = 411
        Top = 20
        Width = 3
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lbl_MaxThickness: TLabel
        Left = 425
        Top = 35
        Width = 3
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lbl_AdmissibleSnowThickness1: TLabel
        Left = 347
        Top = 50
        Width = 3
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lbl_AdmissibleSnowThickness2: TLabel
        Left = 317
        Top = 65
        Width = 3
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lbl_MaxTime: TLabel
        Left = 384
        Top = 80
        Width = 3
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object stt_MinWidth: TStaticText
        Left = 5
        Top = 20
        Width = 401
        Height = 17
        Caption = 
          #1052#1080#1085#1080#1084#1072#1083#1100#1085#1072#1103' '#1096#1080#1088#1080#1085#1072' '#1087#1086#1083#1085#1086#1089#1090#1100#1102' '#1086#1095#1080#1097#1077#1085#1085#1086#1081' '#1087#1086#1074#1077#1088#1093#1085#1086#1089#1090#1080' '#1087#1088#1086#1077#1079#1078#1077#1081' '#1095#1072#1089#1090 +
          #1080', '#1084':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object stt_MaxThickness: TStaticText
        Left = 5
        Top = 35
        Width = 415
        Height = 17
        Caption = 
          #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1072#1103' '#1090#1086#1083#1097#1080#1085#1072' '#1089#1083#1086#1103' '#1088#1099#1093#1083#1086#1075#1086' '#1089#1085#1077#1075#1072' '#1085#1072' '#1087#1086#1074#1077#1088#1093#1085#1086#1089#1090#1080' '#1087#1088#1086#1077#1079#1078#1077#1081' ' +
          #1095#1072#1089#1090#1080', '#1084':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object stt_AdmissibleSnowThickness1: TStaticText
        Left = 5
        Top = 50
        Width = 337
        Height = 17
        Caption = #1044#1086#1087#1091#1089#1090#1080#1084#1072#1103' '#1090#1086#1083#1097#1080#1085#1072' '#1091#1087#1083#1086#1090#1085#1077#1085#1085#1086#1075#1086' '#1089#1083#1086#1103' '#1089#1085#1077#1075#1072' '#1085#1072' '#1087#1086#1082#1088#1099#1090#1080#1080', '#1084#1084':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object stt_AdmissibleSnowThickness2: TStaticText
        Left = 5
        Top = 65
        Width = 307
        Height = 17
        Caption = #1044#1086#1087#1091#1089#1090#1080#1084#1072#1103' '#1090#1086#1083#1097#1080#1085#1072' '#1091#1087#1083#1086#1090#1085#1077#1085#1085#1086#1075#1086' '#1089#1085#1077#1075#1072' '#1085#1072' '#1086#1073#1086#1095#1080#1085#1072#1093', '#1084#1084':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object stt_MaxTime: TStaticText
        Left = 5
        Top = 80
        Width = 374
        Height = 17
        Caption = 
          #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1099#1081' '#1089#1088#1086#1082' '#1086#1082#1086#1085#1095#1072#1085#1080#1103' '#1089#1085#1077#1075#1086#1086#1095#1080#1089#1090#1082#1080' '#1080' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1080' '#1075#1086#1083#1086#1083#1077#1076#1072', ' +
          #1095':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
      end
    end
    object stt_SnowDensity: TStaticText
      Left = 10
      Top = 225
      Width = 93
      Height = 17
      Caption = #1055#1083#1086#1090#1085#1086#1089#1090#1100' '#1089#1085#1077#1075#1072':'
      TabOrder = 5
    end
    object stt_SnowThickness: TStaticText
      Left = 10
      Top = 240
      Width = 112
      Height = 17
      Caption = #1058#1086#1083#1097#1080#1085#1072' '#1089#1083#1086#1103' '#1089#1085#1077#1075#1072':'
      TabOrder = 6
    end
    object grb_RecommendCar: TGroupBox
      Left = 5
      Top = 260
      Width = 490
      Height = 45
      Caption = ' '#1056#1077#1082#1086#1084#1077#1085#1076#1091#1077#1084#1072#1103' '#1089#1085#1077#1075#1086#1086#1095#1080#1089#1090#1080#1090#1077#1083#1100#1085#1072#1103' '#1084#1072#1096#1080#1085#1072' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      object lbl_RecommendedCar: TLabel
        Left = 30
        Top = 20
        Width = 75
        Height = 13
        Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
    end
    object btn_ClearConditionCar: TButton
      Left = 370
      Top = 60
      Width = 125
      Height = 25
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1091#1089#1083#1086#1074#1080#1103
      TabOrder = 8
      OnClick = btn_ClearConditionCarClick
    end
  end
  object Menu: TMainMenu
    Left = 368
    Top = 16
    object Calculate: TMenuItem
      Caption = #1056#1072#1089#1095#1077#1090
      object ActionCalculate: TMenuItem
        Caption = #1056#1072#1089#1095#1077#1090' '#1074#1099#1073#1086#1088#1072' '#1076#1077#1089#1090#1074#1080#1081
        OnClick = ActionCalculateClick
      end
      object CarCalculate: TMenuItem
        Caption = #1056#1072#1089#1095#1077#1090' '#1074#1099#1073#1086#1088#1072' '#1090#1080#1087#1072' '#1084#1072#1096#1080#1085
        OnClick = CarCalculateClick
      end
    end
    object Result: TMenuItem
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090
      object SaveToFile: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1092#1072#1081#1083
        OnClick = SaveToFileClick
      end
      object SaveToDatabase: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093
        OnClick = SaveToDatabaseClick
      end
      object OpenDatabase: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1073#1072#1079#1091' '#1076#1072#1085#1099#1093'...'
        object OpenActionDatabase: TMenuItem
          Caption = #1044#1077#1081#1089#1090#1074#1080#1081
          OnClick = OpenActionDatabaseClick
        end
        object OpenCarDatabase: TMenuItem
          Caption = #1058#1080#1087#1072' '#1084#1072#1096#1080#1085
          OnClick = OpenCarDatabaseClick
        end
      end
      object Print: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100
        OnClick = PrintClick
      end
    end
    object AboutProgram: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      OnClick = AboutProgramClick
    end
  end
  object dlg_SaveToFile: TSaveDialog
    Left = 400
    Top = 16
  end
  object dlg_SaveToDatabase: TSaveDialog
    Options = [ofHideReadOnly, ofFileMustExist, ofCreatePrompt]
    Left = 432
    Top = 16
  end
  object dlg_OpenFile: TOpenDialog
    Left = 464
    Top = 16
  end
end

object frm_CarDatabase: Tfrm_CarDatabase
  Left = 380
  Top = 164
  Width = 558
  Height = 412
  AutoSize = True
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #1041#1072#1079#1072' '#1076#1072#1085#1085#1099#1093' '#1088#1077#1082#1086#1084#1077#1085#1076#1091#1077#1084#1099#1093' '#1084#1072#1096#1080#1085
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnHide = btn_CarDatabaseCloseClick
  PixelsPerInch = 96
  TextHeight = 13
  object btn_CarDatabaseClose: TButton
    Left = 238
    Top = 360
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 0
    OnClick = btn_CarDatabaseCloseClick
  end
  object mem_CarDatabase: TMemo
    Left = 0
    Top = 0
    Width = 550
    Height = 353
    ScrollBars = ssVertical
    TabOrder = 1
  end
end

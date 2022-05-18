object frm_ActionDatabase: Tfrm_ActionDatabase
  Left = 279
  Top = 450
  Width = 393
  Height = 413
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #1041#1072#1079#1072' '#1076#1072#1085#1085#1099#1093' '#1088#1077#1082#1086#1084#1077#1085#1076#1091#1077#1084#1099#1093' '#1076#1077#1081#1089#1090#1074#1080#1081
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnHide = btn_ActionDatabaseCloseClick
  PixelsPerInch = 96
  TextHeight = 13
  object mem_ActionDatabase: TMemo
    Left = 0
    Top = 0
    Width = 385
    Height = 353
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object btn_ActionDatabaseClose: TButton
    Left = 155
    Top = 360
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 1
    OnClick = btn_ActionDatabaseCloseClick
  end
end

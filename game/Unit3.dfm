object Form3: TForm3
  Left = 0
  Top = 0
  Caption = #1052#1086#1088#1089#1082#1086#1081' '#1073#1086#1081'. '#1048#1075#1088#1072
  ClientHeight = 455
  ClientWidth = 664
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 47
    Height = 13
    Caption = #1052#1086#1077' '#1087#1086#1083#1077
  end
  object Label2: TLabel
    Left = 343
    Top = 8
    Width = 88
    Height = 13
    Caption = #1055#1086#1083#1077' '#1087#1088#1086#1090#1080#1074#1085#1080#1082#1072
  end
  object Label3: TLabel
    Left = 8
    Top = 361
    Width = 81
    Height = 13
    Caption = #1048#1089#1090#1086#1088#1080#1103' '#1087#1072#1088#1090#1080#1080
  end
  object DrawGrid1: TDrawGrid
    Left = 8
    Top = 27
    Width = 313
    Height = 313
    ColCount = 10
    DefaultColWidth = 30
    DefaultRowHeight = 30
    FixedCols = 0
    RowCount = 10
    FixedRows = 0
    TabOrder = 0
    OnDrawCell = DrawGrid1DrawCell
  end
  object DrawGrid2: TDrawGrid
    Left = 343
    Top = 27
    Width = 313
    Height = 313
    ColCount = 10
    DefaultColWidth = 30
    DefaultRowHeight = 30
    FixedCols = 0
    RowCount = 10
    FixedRows = 0
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 8
    Top = 380
    Width = 313
    Height = 67
    TabOrder = 2
  end
  object CheckBox1: TCheckBox
    Left = 343
    Top = 422
    Width = 121
    Height = 17
    Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100' '#1086#1088#1077#1086#1083#1099
    TabOrder = 3
  end
  object MainMenu1: TMainMenu
    Left = 32
    Top = 280
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1087#1086#1083#1077
      end
    end
    object N3: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      object N4: TMenuItem
        Caption = #1048#1075#1088#1072' '#1089' '#1082#1086#1084#1087#1100#1102#1090#1077#1088#1086#1084
      end
      object N5: TMenuItem
        Caption = #1048#1075#1088#1072' '#1086#1085#1083#1072#1081#1085
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 96
    Top = 280
  end
end

object DataModule2: TDataModule2
  OldCreateOrder = False
  Height = 180
  Width = 201
  object OpenDialog1: TOpenDialog
    DefaultExt = '.txt'
    Filter = 'Text file|*.txt|All|*.*'
    Left = 32
    Top = 8
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.txt'
    Filter = 'Text file|*.txt|All|*.*'
    Left = 128
    Top = 8
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'GameRooms'
    Left = 32
    Top = 64
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=D:\Da' +
      'niil\Projects\sea-battle-game\server\Win32\Debug\ship_war.mdb;Mo' +
      'de=Share Deny None;Persist Security Info=False;Jet OLEDB:System ' +
      'database="";Jet OLEDB:Registry Path="";Jet OLEDB:Database Passwo' +
      'rd="";Jet OLEDB:Engine Type=5;Jet OLEDB:Database Locking Mode=1;' +
      'Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk Transa' +
      'ctions=1;Jet OLEDB:New Database Password="";Jet OLEDB:Create Sys' +
      'tem Database=False;Jet OLEDB:Encrypt Database=False;Jet OLEDB:Do' +
      'n'#39't Copy Locale on Compact=False;Jet OLEDB:Compact Without Repli' +
      'ca Repair=False;Jet OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 128
    Top = 64
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 32
    Top = 120
  end
end

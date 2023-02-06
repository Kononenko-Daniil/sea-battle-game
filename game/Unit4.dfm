object DataModule4: TDataModule4
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Height = 172
  Width = 128
  object OpenDialog1: TOpenDialog
    DefaultExt = '.txt'
    Filter = 'Text files|*.txt|All|*.*'
    Left = 48
    Top = 62
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.txt'
    Filter = 'Text files|*.txt|All|*.*'
    Left = 48
    Top = 6
  end
end

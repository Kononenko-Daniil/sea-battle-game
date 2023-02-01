object DataModule4: TDataModule4
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Height = 118
  Width = 239
  object OpenDialog1: TOpenDialog
    DefaultExt = '.txt'
    Filter = 'Text files|*.txt|All|*.*'
    Left = 16
    Top = 14
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.txt'
    Filter = 'Text files|*.txt|All|*.*'
    Left = 96
    Top = 14
  end
end

object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #12479#12452#12510#12540
  ClientHeight = 194
  ClientWidth = 304
  Color = 4081734
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Yu Gothic UI'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 17
  object Label1: TLabel
    Left = 24
    Top = 35
    Width = 256
    Height = 77
    Caption = '00:00:00'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clCream
    Font.Height = -64
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 139
    Top = 139
    Width = 13
    Height = 17
    Caption = #20998
    Font.Charset = ANSI_CHARSET
    Font.Color = 4966540
    Font.Height = -13
    Font.Name = 'Yu Gothic UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 243
    Top = 139
    Width = 13
    Height = 17
    Caption = #31186
    Font.Charset = ANSI_CHARSET
    Font.Color = 4966540
    Font.Height = -13
    Font.Name = 'Yu Gothic UI'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 111
    Top = 162
    Width = 85
    Height = 25
    Caption = 'Start'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 2962483
    Font.Height = -16
    Font.Name = 'Yu Gothic UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 57
    Top = 131
    Width = 57
    Height = 25
    Alignment = taCenter
    Color = clCream
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 2962483
    Font.Height = -13
    Font.Name = 'Yu Gothic UI'
    Font.Style = []
    ImeMode = imDisable
    MaxLength = 4
    NumbersOnly = True
    ParentFont = False
    PopupMenu = PopupMenu1
    TabOrder = 1
    Text = '0'
  end
  object Edit2: TEdit
    Left = 165
    Top = 131
    Width = 57
    Height = 25
    Alignment = taCenter
    Color = clCream
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 2962483
    Font.Height = -13
    Font.Name = 'Yu Gothic UI'
    Font.Style = []
    ImeMode = imDisable
    MaxLength = 2
    NumbersOnly = True
    ParentFont = False
    PopupMenu = PopupMenu1
    TabOrder = 2
    Text = '0'
  end
  object Button3: TButton
    Left = 222
    Top = 162
    Width = 75
    Height = 25
    Caption = 'Reset'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 2962483
    Font.Height = -16
    Font.Name = 'Yu Gothic UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button3Click
  end
  object UpDown1: TUpDown
    Left = 114
    Top = 131
    Width = 17
    Height = 25
    Associate = Edit1
    Max = 10000
    TabOrder = 4
    Thousands = False
  end
  object UpDown2: TUpDown
    Left = 222
    Top = 131
    Width = 16
    Height = 25
    Associate = Edit2
    Max = 59
    TabOrder = 5
  end
  object Button2: TButton
    Left = 8
    Top = 161
    Width = 41
    Height = 25
    Caption = #35373#23450
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 2962483
    Font.Height = -13
    Font.Name = 'Yu Gothic UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button2Click
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 208
    Top = 16
  end
  object NotificationCenter1: TNotificationCenter
    Left = 144
    Top = 24
  end
  object PopupMenu1: TPopupMenu
    Left = 64
    Top = 80
    object SetDefault: TMenuItem
      Caption = #36215#21205#26178#12398#20516#12395#12475#12483#12488
      OnClick = SetDefaultClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object Set1: TMenuItem
      Caption = '3'#20998
      OnClick = Set1Click
    end
    object Set2: TMenuItem
      Caption = '3'#20998
      OnClick = Set2Click
    end
    object Set3: TMenuItem
      Caption = '3'#20998
      OnClick = Set3Click
    end
    object Set4: TMenuItem
      Caption = '3'#20998
      OnClick = Set4Click
    end
    object Set5: TMenuItem
      Caption = '3'#20998
      OnClick = Set5Click
    end
  end
end

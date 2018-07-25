object Form1: TForm1
  Left = 0
  Top = 0
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
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  DesignSize = (
    304
    194)
  PixelsPerInch = 96
  TextHeight = 17
  object Label1: TLabel
    Left = 24
    Top = 35
    Width = 256
    Height = 77
    Anchors = [akTop]
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
    Anchors = [akTop]
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
    Anchors = [akTop]
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
    Anchors = [akBottom]
    Caption = 'START'
    Default = True
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
    Left = 55
    Top = 131
    Width = 57
    Height = 25
    Alignment = taCenter
    Anchors = [akTop]
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
    OnChange = Edit1Change
  end
  object Edit2: TEdit
    Left = 159
    Top = 131
    Width = 57
    Height = 25
    Alignment = taCenter
    Anchors = [akTop]
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
    OnChange = Edit2Change
  end
  object Button3: TButton
    Left = 222
    Top = 162
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'RESET'
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
    Left = 116
    Top = 131
    Width = 17
    Height = 25
    Anchors = [akTop]
    Associate = Edit1
    Max = 10000
    TabOrder = 4
    Thousands = False
  end
  object UpDown2: TUpDown
    Left = 216
    Top = 131
    Width = 16
    Height = 25
    Anchors = [akTop]
    Associate = Edit2
    Max = 59
    TabOrder = 5
  end
  object Button2: TButton
    Left = 8
    Top = 161
    Width = 41
    Height = 25
    Anchors = [akLeft, akBottom]
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
      Caption = #23653#27508
      object a1: TMenuItem
        Caption = 'a'
        OnClick = a1Click
      end
      object b1: TMenuItem
        Caption = 'b'
        OnClick = b1Click
      end
      object c1: TMenuItem
        Caption = 'c'
        OnClick = c1Click
      end
      object d1: TMenuItem
        Caption = 'd'
        OnClick = d1Click
      end
      object e1: TMenuItem
        Caption = 'e'
        OnClick = e1Click
      end
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object Start1: TMenuItem
      Caption = #12473#12479#12540#12488
      OnClick = Start1Click
    end
    object Stop1: TMenuItem
      Caption = #12473#12488#12483#12503
      OnClick = Stop1Click
    end
    object Reset1: TMenuItem
      Caption = #12522#12475#12483#12488
      OnClick = Reset1Click
    end
  end
  object ActionList1: TActionList
    Left = 240
    Top = 88
    object ActionStartStop: TAction
      Caption = 'ActionStartStop'
      ShortCut = 49235
      OnExecute = ActionStartStopExecute
    end
    object ActionReset: TAction
      Caption = 'ActionReset'
      ShortCut = 49234
      OnExecute = ActionResetExecute
    end
  end
end

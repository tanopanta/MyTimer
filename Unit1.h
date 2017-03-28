//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <System.Notification.hpp>
#include <Vcl.ComCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.StdActns.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TTimer *Timer1;
	TLabel *Label1;
	TButton *Button1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button3;
	TUpDown *UpDown1;
	TUpDown *UpDown2;
	TButton *Button2;
	TNotificationCenter *NotificationCenter1;
	TPopupMenu *PopupMenu1;
	TMenuItem *SetDefault;
	TMenuItem *N1;
	TActionList *ActionList1;
	TAction *ActionStartStop;
	TAction *ActionReset;
	TMenuItem *N2;
	TMenuItem *Start1;
	TMenuItem *Stop1;
	TMenuItem *Reset1;
	TMenuItem *a1;
	TMenuItem *b1;
	TMenuItem *c1;
	TMenuItem *d1;
	TMenuItem *e1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SetDefaultClick(TObject *Sender);
	void __fastcall Set1Click(TObject *Sender);
	void __fastcall Set2Click(TObject *Sender);
	void __fastcall Set3Click(TObject *Sender);
	void __fastcall Set4Click(TObject *Sender);
	void __fastcall Set5Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionStartStopExecute(TObject *Sender);
	void __fastcall ActionResetExecute(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Start1Click(TObject *Sender);
	void __fastcall Stop1Click(TObject *Sender);
	void __fastcall Reset1Click(TObject *Sender);



private:	// ユーザー宣言

public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
	void __fastcall EndProcessing();
	void __fastcall HistorySetting(int num);
	void __fastcall SetClick(int num);
    void __fastcall EditChange();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

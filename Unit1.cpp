//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Unit1.h"
#include <IniFiles.hpp>
#include "Unit2.h"

#define HISTORY_SIZE 5
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

bool isStart = false;
int count = 0;
bool isTochu = false;
time_t startTime;
int endTime;

int historyTime[HISTORY_SIZE] = {180,180,180,180,180};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(isStart){
		isStart = false;
		Button1->Caption = "START";
		Timer1->Enabled = false;
		endTime -= difftime(time(NULL),startTime);
	}else{

		if(!isTochu){
			if(Edit1->Text == EmptyStr || Edit2->Text == EmptyStr){
				Edit1->Text = "0";
				Edit2->Text = "0";
				return;
			}
			count = StrToInt(Edit1->Text) * 60 +  StrToInt(Edit2->Text);

			HistorySetting(count);
			isTochu = true;
			endTime = count;
		}
		startTime = time(NULL);
		isStart = true;
		Button1->Caption = "STOP";
		Label1->Caption = AnsiString().sprintf("%02d:%02d:%02d",count / 3600,(count - (count / 3600) * 3600)/ 60,count % 60);
		Timer1->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HistorySetting(int num)
{
	bool isExist = false;
	int tmp,i;
	UnicodeString str;
	for(i = 0;i < HISTORY_SIZE;i++){
		if(historyTime[i] == num){
			isExist = true;
			break;
		}
	}
	if(isExist){
		if(i == 0){
			return;
		}
		tmp = historyTime[i];
		for(int j = i;j  > 0;j--){
			historyTime[j] = historyTime[j - 1];
		}
		historyTime[0] = tmp;
	}else{
		historyTime[4] = historyTime[3];
		historyTime[3] = historyTime[2];
		historyTime[2] = historyTime[1];
		historyTime[1] = historyTime[0];
		historyTime[0] = count;
	}
	for(int i = 0;i < HISTORY_SIZE;i++){
		str = IntToStr(historyTime[i] / 60) + "分" + IntToStr(historyTime[i] % 60) + "秒";
		PopupMenu1->Items->Items[1]->Items[i]->Caption = str;

	}
}

//--------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	count = endTime - difftime(time(NULL),startTime);
	Label1->Caption = AnsiString().sprintf("%02d:%02d:%02d",count / 3600,(count - (count / 3600) * 3600)/ 60,count % 60);
	if(count <= 0){
		if(count > -3){
			//数秒だったら0
			Label1->Caption = "00:00:00";
		}
		EndProcessing();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	isTochu = false;
	isStart = false;
	Timer1->Enabled = false;
	if(Edit1->Text == EmptyStr || Edit2->Text == EmptyStr){
		Edit1->Text = "0";
		Edit2->Text = "0";
	}else{
		Label1->Caption = AnsiString().sprintf("%02d:%02d:%02d",StrToInt(Edit1->Text) / 60,StrToInt(Edit1->Text) % 60,StrToInt(Edit2->Text));
	}
	Button1->Caption = "START";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EndProcessing()
{
	UnicodeString message = Form2->EditNotifyMessage->Text;
	isStart = false;
	isTochu = false;
	Form1->Timer1->Enabled = false;
	Form1->Button1->Caption = "RESTART";

	if(Form2->CheckBox3->Checked){
		TNotification *MyNotification = NotificationCenter1->CreateNotification();
		try{
			MyNotification->Name = "mytimer";
			MyNotification->AlertBody = message;
			MyNotification->Title = "タイマー";
			NotificationCenter1->PresentNotification(MyNotification);
		}__finally{
			delete MyNotification;
		}
	}else{
		if(Form2->CheckBox1->Checked){
			MessageBeep(MB_OK);
		}
		if(Form2->CheckBox4->Checked){
			Application->MessageBox(message.c_str(),L"タイマー",MB_OK);
		}else{
			ShowWindow(Form1->Handle,SW_RESTORE);
			SetWindowPos(Form1->Handle,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);
			Application->MessageBox(message.c_str(),L"タイマー",MB_OK);
			SetWindowPos(Form1->Handle,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);
		}
	}
	return;
}

//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	//設定画面の表示
	Form2->Show();
	Form2->Left = Form1->Left + 50;
	Form2->Top = Form1->Top + 50;

}
//---------------------------------------------------------------------------
//設定の読み込み
void __fastcall TForm1::FormShow(TObject *Sender)
{
	TIniFile *ini;
    UnicodeString str;
	try{
		ini = new TIniFile( ChangeFileExt( Application->ExeName, ".ini" ) );
		Edit1->Text = ini->ReadInteger("Form", "DefaultMinute", 30);
		Form2->Edit1->Text = Edit1->Text;
		Edit2->Text = ini->ReadInteger("Form", "DefaultSecond", 0);
		Form2->Edit2->Text = Edit2->Text;
		Form2->EditNotifyMessage->Text = ini->ReadString("Form","NotifyMessage","時間です");
		Form2->CheckBox1->Checked = ini->ReadBool("Form","NotificationSound",True);
		//Form2->CheckBox2->Checked = ini->ReadBool("Form","DoubleBuffering",False);
		Form2->CheckBox3->Checked = ini->ReadBool("Form","UseActionCenter",False);
		Form2->CheckBox4->Checked = ini->ReadBool("Form","DisplayTopMost",False);

		for(int i = 0;i < HISTORY_SIZE;i++){
		   historyTime[i] = ini->ReadInteger("History", "His" + IntToStr(i),180);

		}
	}__finally{
		delete ini;
	}
	//以下変更処理
	if(Form2->CheckBox4->Checked){
		SetWindowPos(Handle, HWND_TOPMOST, 0, 0, 0, 0,SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW);
	}

	for(int i = 0;i < HISTORY_SIZE;i++){
		str = IntToStr(historyTime[i] / 60) + "分" + IntToStr(historyTime[i] % 60) + "秒";
		PopupMenu1->Items->Items[1]->Items[i]->Caption = str;
	}
	str = Form2->Edit1->Text + "分" + Form2->Edit2->Text + "秒";
	PopupMenu1->Items->Items[0]->Caption = str;

	Label1->Caption = AnsiString().sprintf("%02d:%02d:%02d",StrToInt(Edit1->Text) / 60,StrToInt(Edit1->Text) % 60 + StrToInt(Edit2->Text) / 60,StrToInt(Edit2->Text) % 60);
	//Form1->DoubleBuffered = Form2->CheckBox2->Checked;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::SetDefaultClick(TObject *Sender)
{
	Edit1->Text = Form2->Edit1->Text;
	Edit2->Text = Form2->Edit2->Text;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SetClick(int num)
{
	Edit1->Text = historyTime[num] / 60;
	Edit2->Text = historyTime[num] % 60;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	TIniFile *ini;
	try{
		ini = new TIniFile( ChangeFileExt( Application->ExeName, ".ini" ) );
		for(int i = 0;i < HISTORY_SIZE;i++){
		   ini->WriteInteger("History", "His" + IntToStr(i), historyTime[i]);
		}
	}__finally{
		delete ini;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ActionStartStopExecute(TObject *Sender)
{
	Button1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ActionResetExecute(TObject *Sender)
{
	Button3Click(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit1Change(TObject *Sender)
{
	 EditChange();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
	EditChange();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditChange()
{
	if(!isTochu){
		if(Edit1->Text == EmptyStr || Edit2->Text == EmptyStr){
			//
		}else{
			Label1->Caption = AnsiString().sprintf("%02d:%02d:%02d",StrToInt(Edit1->Text) / 60,StrToInt(Edit1->Text) % 60 + StrToInt(Edit2->Text) / 60,StrToInt(Edit2->Text) % 60);
		}
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Start1Click(TObject *Sender)
{
	Button1Click(Sender);
	PopupMenu1->Items->Items[1]->Caption = "changed";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Stop1Click(TObject *Sender)
{
	 if(!isStart){
		return;
	 }
	 Button1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Reset1Click(TObject *Sender)
{
	 Button3Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::a1Click(TObject *Sender)
{
	 SetClick(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b1Click(TObject *Sender)
{
	 SetClick(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::c1Click(TObject *Sender)
{
	 SetClick(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::d1Click(TObject *Sender)
{
	 SetClick(3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::e1Click(TObject *Sender)
{
	SetClick(4);
}
//---------------------------------------------------------------------------


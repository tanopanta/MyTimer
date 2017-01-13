//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Unit1.h"
#include <IniFiles.hpp>
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

bool isStart = false;
int count = 0;
bool isTochu = false;
time_t startTime;
int endTime;
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
		Button1->Caption = "Start";
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
			isTochu = true;
			endTime = count;
		}
		startTime = time(NULL);
		isStart = true;
		Button1->Caption = "Stop";
		Label1->Caption = AnsiString().sprintf("%02d:%02d:%02d",count / 3600,(count - (count / 3600) * 3600)/ 60,count % 60);
		Timer1->Enabled = true;
	}
}
//---------------------------------------------------------------------------



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
	Button1->Caption = "Start";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EndProcessing()
{
	UnicodeString message = Form2->EditNotifyMessage->Text;
	isStart = false;
	isTochu = false;
	Form1->Timer1->Enabled = false;
	Form1->Button1->Caption = "ReStart";


	if(Form2->CheckBox3->Checked){
		TNotification *MyNotification = NotificationCenter1->CreateNotification();
		MyNotification->Name = "mytimer";
		MyNotification->AlertBody = message;
		MyNotification->Title = "タイマー";
		NotificationCenter1->PresentNotification(MyNotification);
		delete MyNotification;
		if(count < -3){
			SetWindowPos(Form1->Handle,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);
			Application->MessageBoxW(message.c_str(),L"タイマー",MB_OK);
			SetWindowPos(Form1->Handle,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);
		}
	}else{
		if(Form2->CheckBox1->Checked){
			MessageBeep(MB_OK);
		}
		if(Form2->CheckBox4->Checked){
			Application->MessageBox(message.c_str(),L"タイマー",MB_OK);
		}else{
			SetWindowPos(Form1->Handle,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);
			Application->MessageBox(message.c_str(),L"タイマー",MB_OK);
			SetWindowPos(Form1->Handle,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);
		}
	}
	return;
}



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
	ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
	Edit1->Text = ini->ReadInteger("Form", "DefaultMinute", 30);
	Edit2->Text = ini->ReadInteger("Form", "DefaultSecond", 0);
	Form2->EditNotifyMessage->Text = ini->ReadString("Form","NotifyMessage","時間です");
	Form2->CheckBox1->Checked = ini->ReadBool("Form","NotificationSound",True);
	//Form2->CheckBox2->Checked = ini->ReadBool("Form","DoubleBuffering",False);
	Form2->CheckBox3->Checked = ini->ReadBool("Form","UseActionCenter",False);
	Form2->CheckBox4->Checked = ini->ReadBool("Form","DisplayTopMost",False);
	delete ini;
	if(Form2->CheckBox4->Checked){
		SetWindowPos(Handle, HWND_TOPMOST, 0, 0, 0, 0,SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW);
	}
	//Form1->DoubleBuffered = Form2->CheckBox2->Checked;
}
//---------------------------------------------------------------------------




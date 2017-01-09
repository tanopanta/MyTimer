//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include <IniFiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

bool isTopMost = false;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	TIniFile *ini;
	ini = new TIniFile(ChangeFileExt(Application->ExeName, ".INI" ));
	ini->WriteInteger("Form", "DefaultMinute", StrToInt(Edit1->Text));
	ini->WriteInteger("Form", "DefaultSecond", StrToInt(Edit2->Text));
	ini->WriteBool("Form","NotificationSound",CheckBox1->Checked);
	//ini->WriteBool("Form","DoubleBuffering",CheckBox2->Checked);
	ini->WriteBool("Form","UseActionCenter",CheckBox3->Checked);
	ini->WriteBool("Form","DisplayTopMost",CheckBox4->Checked);
	delete ini;

	//Form1->DoubleBuffered = CheckBox2->Checked;
	if(CheckBox4->Checked){
		SetWindowPos(Form1->Handle, HWND_TOPMOST, 0, 0, 0, 0,SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW);
	}else{
		if(isTopMost){
			SetWindowPos(Form1->Handle, HWND_NOTOPMOST, 0, 0, 0, 0,SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW);
		}
	}

	Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	LoadSettings();
	Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
	LoadSettings();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LoadSettings()
{
	TIniFile *ini;
	ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
	Edit1->Text = ini->ReadInteger("Form", "DefaultMinute", 30);
	Edit2->Text = ini->ReadInteger("Form", "DefaultSecond", 0);
	CheckBox1->Checked = ini->ReadBool("Form","NotificationSound",True);
	//CheckBox2->Checked = ini->ReadBool("Form","DoubleBuffering",False);
	CheckBox3->Checked = ini->ReadBool("Form","UseActionCenter",False);
	CheckBox4->Checked = ini->ReadBool("Form","DisplayTopMost",False);
	delete ini;
	isTopMost = CheckBox4->Checked;
}

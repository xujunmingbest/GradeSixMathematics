#pragma once

#include "tool.h"
#include "教学大纲.h"

namespace 数学教学软件 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	/// <summary>
	/// Login 摘要
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			CheckForIllegalCrossThreadCalls = false;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Font = gcnew System::Drawing::Font("宋体", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel, ((byte)(134)));

			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	protected:


	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 27;
			this->listBox1->Location = System::Drawing::Point(0, 153);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(758, 139);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Login::listBox1_SelectedIndexChanged);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(109, 40);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(526, 35);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 5;
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(758, 292);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->listBox1);
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"数学教学软件";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Login_Load(System::Object^  sender, System::EventArgs^  e) {
		Thread ^ t;
		t = gcnew Thread(gcnew ThreadStart(this,&Login::show));
		t -> Start();
	}

			 void show() {
				 progressBar1->Value = 0;
				 progressBar1->Minimum = 0;
				 progressBar1->Maximum = 3;

					 DateTime^ dt = DateTime::Now;
					 String^ str = dt->ToString("yyyy-MM-dd HH:mm:ss: ");
					 progressBar1->Value++;
					 listBox1->Items->Add(str + "正在验证软件合法性");
					 if (!AlarmCheck()) {
						 MessageBox::Show("您未购买软件,程序即将退出");
						 exit(-1);
					 }
					 listBox1->Items->Add(str + "正在加载配置");
					 progressBar1->Value++;
					 listBox1->TopIndex = listBox1->Items->Count - 1;
					 listBox1->Items->Add(str + "验证完成");
					 progressBar1->Value++;
					 this->Close();
				 
			 }
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}

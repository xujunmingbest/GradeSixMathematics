#pragma once
#include "比和百分比.h"
namespace 数学教学软件 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	/// <summary>
	/// 教学大纲 摘要
	/// </summary>
	public ref class 教学大纲 : public System::Windows::Forms::Form
	{
	public:
		教学大纲(void)
		{
			InitializeComponent();
			Thread^ t = gcnew Thread(gcnew ThreadStart(this,&教学大纲::Control));
			t->Start();
			//
			//TODO:  在此处添加构造函数代码
			//
		}
		void Control() {
			while (1) {
				g_c.Stop();
				this->Visible = true;
			}
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~教学大纲()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->Font = (gcnew System::Drawing::Font(L"楷体", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(226, 128);
			this->button1->TabIndex = 0;
			this->button1->Text = L"比和百分比";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &教学大纲::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button2->Font = (gcnew System::Drawing::Font(L"楷体", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button2->Location = System::Drawing::Point(640, 315);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 128);
			this->button2->TabIndex = 1;
			this->button2->Text = L"退出";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &教学大纲::button2_Click);
			// 
			// 教学大纲
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(891, 455);
			this->ControlBox = false;
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->Name = L"教学大纲";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"教学大纲";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &教学大纲::教学大纲_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void 教学大纲_Load(System::Object^  sender, System::EventArgs^  e) {
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->Font = gcnew System::Drawing::Font("宋体", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel, ((byte)(134)));
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		exit(0);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		(gcnew 比和百分比)->Show();
		this->Visible = false;
	}
	};
}

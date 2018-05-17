#pragma once
#include "tool.h"
namespace 数学教学软件 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// 比和百分比 摘要
	/// </summary>
	public ref class 比和百分比 : public System::Windows::Forms::Form
	{
	public:
		比和百分比(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~比和百分比()
		{

			g_c.Start();
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// 比和百分比
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(950, 472);
			this->Name = L"比和百分比";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"比和百分比";
			this->Load += gcnew System::EventHandler(this, &比和百分比::比和百分比_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void 比和百分比_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}

#pragma once
#include "tool.h"
namespace ��ѧ��ѧ��� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// �ȺͰٷֱ� ժҪ
	/// </summary>
	public ref class �ȺͰٷֱ� : public System::Windows::Forms::Form
	{
	public:
		�ȺͰٷֱ�(void)
		{
			InitializeComponent();
			//
			//TODO:  �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~�ȺͰٷֱ�()
		{

			g_c.Start();
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ�޸�
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// �ȺͰٷֱ�
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(950, 472);
			this->Name = L"�ȺͰٷֱ�";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�ȺͰٷֱ�";
			this->Load += gcnew System::EventHandler(this, &�ȺͰٷֱ�::�ȺͰٷֱ�_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void �ȺͰٷֱ�_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}

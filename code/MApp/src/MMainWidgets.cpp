#include "MMainWidgets.h"

#include <QFileDialog>

#include "../form/ui_CreateBook.h"
#include "../form/ui_HelpBook.h"
//#include "ComponentXml.h"

MCreateBookWindow::MCreateBookWindow(QWidget* parent /*= nullptr*/)
	:QWidget(parent),
	ui(new Ui::CreateBook)
{
	ui->setupUi(this);
	//m_xmlcom = GET_COMPONENT(ComponentXml);
}

MCreateBookWindow::~MCreateBookWindow()
{

}

void MCreateBookWindow::on_PathSet_clicked()
{
	QString::fromLocal8Bit("");
	QString filePath = QFileDialog::getExistingDirectory(this, tr_ch("选择文件"), "");// , tr_ch("配置文件 (*.xml)"));
	if (!filePath.isEmpty()) {
		ui->lineEdit_Path->setText(filePath);
	}
}

void MCreateBookWindow::on_create_Btn_clicked()
{
	//if (m_xmlcom)
	//{
	//	m_xmlcom->CreatNewBook(ui->lineEdit_Name->text(), ui->lineEdit_Path->text());
	//}
	
}

MHelpBookWindow::MHelpBookWindow(QWidget* parent /*= nullptr*/)
	:QWidget(parent),
	ui(new Ui::HelpBook)
{
	ui->setupUi(this);
}

MHelpBookWindow::~MHelpBookWindow()
{

}

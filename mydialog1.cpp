#include "mydialog1.h"
#include "ui_mydialog1.h"
#include <QFileInfo>
#include <QDateTime>
#include <QTextStream>
using namespace std;

const int N = 1000008;
const int n = 58;
QString text1[N];
QChar text_flag1[N];
int count_text1 = 0;
int input_text_flag = 0;
int output_text_flag = 0;
int input_picture_flag = 0;
int choice_id = 0;
int choice_num[n] = {2, 2, 2, 3, 3, 2, 2, 2, 2, 2};
QString choice_content[n][4];
int is_making_choice = 0;

void InitChoice(){
    choice_content[0][0] = "我们已经研发出预防药物了";
    choice_content[0][1] = "（隐瞒）";
    choice_content[1][0] = "（同意）";
    choice_content[1][1] = "（不同意）";
    choice_content[2][0] = "（同意）";
    choice_content[2][1] = "（不同意）";
    choice_content[3][0] = "（你去）";
    choice_content[3][1] = "（他去）";
    choice_content[3][2] = "随便派个人去吧";
    choice_content[4][0] = "（正常药物）";
    choice_content[4][1] = "（失活药物）";
    choice_content[4][2] = "（添加CPD的药物）";
    choice_content[5][0] = "（是）";
    choice_content[5][1] = "（不是）";
    choice_content[6][0] = "（告知真相）";
    choice_content[6][1] = "（隐瞒）";
    choice_content[7][0] = "（索要基地指挥权）";
    choice_content[7][1] = "（囚禁）";
    choice_content[8][0] = "（告知真相）";
    choice_content[8][1] = "（隐瞒）";
    choice_content[9][0] = "（扔到基地外自生自灭）";
    choice_content[9][1] = "（作为实验体留在实验室）";
    return;
}

void ReadText1(){
    /*剧情1文本读入*/
    int count = 0;
    QFile file1(":/mytxt/text1.txt");
    if(!file1.open(QIODevice::ReadOnly)){
        text1[1] = "暂且用这种方式报错，文件打开失败";
        //这里计划可以加入一个处理报错的函数
        return;
    }
    QTextStream stream1(&file1);
    while(!stream1.atEnd()){
        QString temp = stream1.read(1);
        text_flag1[++count] = temp[0];
        text1[count] = stream1.readLine();
    }
    file1.close();
    return;
}

MyDialog1::MyDialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog1)
{
    ui->setupUi(this);
    ui->BtnC1->setVisible(false);
    ui->BtnC2->setVisible(false);
    ui->BtnC3->setVisible(false);
    InitChoice();
}

MyDialog1::~MyDialog1()
{
    delete ui;
}

void MyDialog1::setPicture1(){
    ui->label_2->setStyleSheet("border-image: url(:/mypic/image/testpic.jpg);");
    ui->label_2->setText("");
    return;
}

void MyDialog1::MakeChoice(){
    if(choice_num[choice_id] == 2){
        ui->BtnC1->setText(choice_content[choice_id][0]);
        ui->BtnC2->setText(choice_content[choice_id][1]);
        ui->BtnC1->setVisible(true);
        ui->BtnC2->setVisible(true);
    }else if(choice_num[choice_id] == 3){
        ui->BtnC1->setText(choice_content[choice_id][0]);
        ui->BtnC2->setText(choice_content[choice_id][1]);
        ui->BtnC3->setText(choice_content[choice_id][2]);
        ui->BtnC1->setVisible(true);
        ui->BtnC2->setVisible(true);
        ui->BtnC3->setVisible(true);
    }
    is_making_choice = 1;
    choice_id++;
    return;
}

void MyDialog1::on_NexSenBtn_clicked()
{
    if(is_making_choice) return;
    if(input_text_flag == 0){
        ReadText1();
        input_text_flag = 1;
        ui->label->setAlignment(Qt::AlignHCenter);
        ui->label->setAlignment(Qt::AlignVCenter);
        ui->label->setWordWrap(true);
    }
    count_text1++;
    if(output_text_flag == 1){
        output_text_flag = 0;
        MakeChoice();
    }else{
        ui->label->setText(text1[count_text1]);
        if((text_flag1[count_text1] == '@' || text_flag1[count_text1] == '#') && output_text_flag == 0){
            output_text_flag = 1;
        }
    }
    return;
}

void MyDialog1::on_BtnC1_clicked()
{
    count_text1 += -1;
    //这里通过对count_text1的调整进入分支剧情，具体数值需要文本内容确定后填写
    ui->BtnC1->setVisible(false);
    ui->BtnC2->setVisible(false);
    ui->BtnC3->setVisible(false);
    is_making_choice = 0;
    on_NexSenBtn_clicked();
    return;
}

void MyDialog1::on_BtnC2_clicked()
{
    count_text1 += -1;
    //这里通过对count_text1的调整进入分支剧情，具体数值需要文本内容确定后填写
    ui->BtnC1->setVisible(false);
    ui->BtnC2->setVisible(false);
    ui->BtnC3->setVisible(false);
    is_making_choice = 0;
    on_NexSenBtn_clicked();
    return;
}

void MyDialog1::on_BtnC3_clicked()
{
    count_text1 += -1;
    //这里通过对count_text1的调整进入分支剧情，具体数值需要文本内容确定后填写
    ui->BtnC1->setVisible(false);
    ui->BtnC2->setVisible(false);
    ui->BtnC3->setVisible(false);
    is_making_choice = 0;
    on_NexSenBtn_clicked();
    return;
}


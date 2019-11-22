#include "dialogmesice.h"
#include "ui_dialogmesice.h"
#include "dialogmesice_zeme.h"
#include "dialogmesice_mars.h"
#include "dialogmesice_jupiter.h"
#include "dialogmesice_saturn.h"
#include "dialogmesice_uran.h"
#include "dialogmesice_neptun.h"
#include "dialogmesice_pluto.h"
#include "dialogmesice_haumea.h"
#include "dialogmesice_makemake.h"
#include "dialogmesice_eris.h"
#include "dialogvsechnymesice.h"


DialogMesice::DialogMesice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMesice)
{
    ui->setupUi(this);
    mesice_zeme = new DialogMesice_Zeme(this);
    mesice_mars = new DialogMesice_Mars(this);
    mesice_jupiter = new DialogMesice_Jupiter(this);
    mesice_saturn = new DialogMesice_Saturn(this);
    mesice_uran = new DialogMesice_Uran(this);
    mesice_neptun = new DialogMesice_Neptun(this);
    mesice_pluto = new DialogMesice_Pluto(this);
    mesice_haumea = new DialogMesice_Haumea(this);
    mesice_makemake = new DialogMesice_Makemake(this);
    mesice_eris = new DialogMesice_Eris(this);
    mesice_vsechny =  new DialogVsechnyMesice(this);

}

DialogMesice::~DialogMesice()
{
    delete ui;
}

void DialogMesice::on_pushButton_5_clicked()
{
    mesice_zeme ->show();
}

void DialogMesice::on_pushButton_4_clicked()
{
    mesice_mars ->show();
}

void DialogMesice::on_pushButton_3_clicked()
{
    mesice_jupiter ->show();
}

void DialogMesice::on_pushButton_2_clicked()
{
    mesice_saturn ->show();
}

void DialogMesice::on_pushButton_clicked()
{
    mesice_uran ->show();
}

void DialogMesice::on_pushButton_10_clicked()
{
    mesice_neptun ->show();
}

void DialogMesice::on_pushButton_9_clicked()
{
    mesice_pluto ->show();
}

void DialogMesice::on_pushButton_8_clicked()
{
    mesice_haumea ->show();
}

void DialogMesice::on_pushButton_7_clicked()
{
    mesice_makemake ->show();
}

void DialogMesice::on_pushButton_6_clicked()
{
    mesice_eris ->show();
}

void DialogMesice::on_pushButton_11_clicked()
{
    mesice_vsechny->show();
}

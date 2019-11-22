#include "dialogplanety.h"
#include "ui_dialogplanety.h"
#include "dialogmerkur.h"
#include "dialogvenuse.h"
#include "dialogzeme.h"
#include "dialogmars.h"
#include "dialogjupiter.h"
#include "dialogsaturn.h"
#include "dialoguran.h"
#include "dialogneptun.h"
#include "dialogceres.h"
#include "dialogpluto.h"
#include "dialoghaumea.h"
#include "dialogmakemake.h"
#include "dialogeris.h"
#include "dialogvsechnyplanety.h"

DialogPlanety::DialogPlanety(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPlanety)
{
    ui->setupUi(this);
    merkur = new DialogMerkur(this);
    venuse = new DialogVenuse(this);
    zeme = new DialogZeme(this);
    mars = new DialogMars(this);
    jupiter = new DialogJupiter(this);
    saturn = new DialogSaturn(this);
    uran = new DialogUran(this);
    neptun = new DialogNeptun(this);
    ceres = new DialogCeres(this);
    pluto = new DialogPluto(this);
    haumea = new DialogHaumea(this);
    makemake = new DialogMakemake(this);
    eris = new DialogEris(this);
    vsechny = new DialogVsechnyPlanety(this);
}


DialogPlanety::~DialogPlanety()
{
    delete ui;
}

void DialogPlanety::on_pushButton_5_clicked()
{
    merkur ->show();
}

void DialogPlanety::on_pushButton_4_clicked()
{
    venuse ->show();
}

void DialogPlanety::on_pushButton_7_clicked()
{
    zeme ->show();
}

void DialogPlanety::on_pushButton_8_clicked()
{
    mars ->show();
}

void DialogPlanety::on_pushButton_6_clicked()
{
    jupiter ->show();
}

void DialogPlanety::on_pushButton_3_clicked()
{
    saturn ->show();
}

void DialogPlanety::on_pushButton_2_clicked()
{
    uran ->show();
}

void DialogPlanety::on_pushButton_clicked()
{
    neptun ->show();
}

void DialogPlanety::on_pushButton_10_clicked()
{
    ceres ->show();
}

void DialogPlanety::on_pushButton_13_clicked()
{
    pluto ->show();
}

void DialogPlanety::on_pushButton_12_clicked()
{
    haumea ->show();
}

void DialogPlanety::on_pushButton_11_clicked()
{
    makemake ->show();
}

void DialogPlanety::on_pushButton_9_clicked()
{
    eris -> show();
}

void DialogPlanety::on_pushButton_14_clicked()
{
    vsechny -> show();
}

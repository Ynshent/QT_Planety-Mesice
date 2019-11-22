#include "dialogvsechnymesice.h"
#include "ui_dialogvsechnymesice.h"

#include <QSqlDatabase>
#include <QSqlQuery>

DialogVsechnyMesice::DialogVsechnyMesice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogVsechnyMesice)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("planety.db");
    db.open();

    model_vsechnymesice  = new QSqlQueryModel;
    ui->tableViewVsechnyMesice->setModel(model_vsechnymesice);
}

DialogVsechnyMesice::~DialogVsechnyMesice()
{
    delete ui;
    delete model_vsechnymesice;
}

void DialogVsechnyMesice::on_checkBox_2_clicked(bool checked_rok)
{
    if(checked_rok==true)
    {
        rok = 1;
        VsechnyMesiceZmena();
    }
    else
    {
        rok = 0;
        VsechnyMesiceZmena();
    }
}

void DialogVsechnyMesice::on_checkBox_4_clicked(bool checked_doba)
{
    if(checked_doba==true)
    {
        doba = 1;
        VsechnyMesiceZmena();
    }
    else
    {
        doba = 0;
        VsechnyMesiceZmena();
    }
}

void DialogVsechnyMesice::on_checkBox_6_clicked(bool checked_rozmer)
{
    if(checked_rozmer==true)
    {
        rozmer = 1;
        VsechnyMesiceZmena();
    }
    else
    {
        rozmer = 0;
        VsechnyMesiceZmena();
    }
}

void DialogVsechnyMesice::on_checkBox_5_clicked(bool checked_objem)
{
    if(checked_objem==true)
    {
        objem = 1;
        VsechnyMesiceZmena();
    }
    else
    {
        objem = 0;
        VsechnyMesiceZmena();
    }
}

void DialogVsechnyMesice::on_checkBox_7_clicked(bool checked_hmotnost)
{
    if(checked_hmotnost==true)
    {
        hmotnost = 1;
        VsechnyMesiceZmena();
    }
    else
    {
        hmotnost = 0;
        VsechnyMesiceZmena();
    }
}

void DialogVsechnyMesice::on_checkBox_3_clicked(bool checked_pocetpristani)
{
    if(checked_pocetpristani==true)
    {
        pocet_pristani = 1;
        VsechnyMesiceZmena();
    }
    else
    {
        pocet_pristani = 0;
        VsechnyMesiceZmena();
    }
}

void DialogVsechnyMesice::on_checkBox_clicked(bool checked_objevitel)
{
    if(checked_objevitel==true)
    {
        objevitel = 1;
        VsechnyMesiceZmena();
    }
    else
    {
        objevitel = 0;
        VsechnyMesiceZmena();
    }
}


void DialogVsechnyMesice::VsechnyMesiceZmena()
{
    //1 checkbox----------------------------------------------------------
    if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    //2 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    //3 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    //4 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    //5 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    //6 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else
    {
        VsechnyMesiceZmena2();
    }

}
void DialogVsechnyMesice::VsechnyMesiceZmena2()
{
    if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    //7 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_vsechnymesice->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
    else
    {
        model_vsechnymesice->setQuery("SELECT  FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m");
    }
}

#include "dialogmesice_pluto.h"
#include "ui_dialogmesice_pluto.h"

#include <QSqlDatabase>
#include <QSqlQuery>

DialogMesice_Pluto::DialogMesice_Pluto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMesice_Pluto)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("planety.db");
    db.open();

    model_mesicepluto  = new QSqlQueryModel;
    ui->tableViewMesicePluto->setModel(model_mesicepluto);

    ui->comboBox->addItem("Všechny měsíce");
    ui->comboBox->addItem("Charon");
    ui->comboBox->addItem("Nix");
    ui->comboBox->addItem("Hydra");
    ui->comboBox->addItem("Styx");
    ui->comboBox->addItem("Kerberos");
}

DialogMesice_Pluto::~DialogMesice_Pluto()
{
    delete ui;
    delete model_mesicepluto;
}

void DialogMesice_Pluto::on_checkBox_2_clicked(bool checked_rok)
{
    if(checked_rok==true)
    {
        rok = 1;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
    else
    {
        rok = 0;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
}

void DialogMesice_Pluto::on_checkBox_4_clicked(bool checked_doba)
{
    if(checked_doba==true)
    {
        doba = 1;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
    else
    {
        doba = 0;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
}

void DialogMesice_Pluto::on_checkBox_6_clicked(bool checked_rozmer)
{
    if(checked_rozmer==true)
    {
        rozmer = 1;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
    else
    {
        rozmer = 0;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
}

void DialogMesice_Pluto::on_checkBox_5_clicked(bool checked_objem)
{
    if(checked_objem==true)
    {
        objem = 1;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
    else
    {
        objem = 0;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
}

void DialogMesice_Pluto::on_checkBox_7_clicked(bool checked_hmotnost)
{
    if(checked_hmotnost==true)
    {
        hmotnost = 1;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
    else
    {
        hmotnost = 0;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
}

void DialogMesice_Pluto::on_checkBox_3_clicked(bool checked_pocetpristani)
{
    if(checked_pocetpristani==true)
    {
        pocet_pristani = 1;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
    else
    {
        pocet_pristani = 0;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
}

void DialogMesice_Pluto::on_checkBox_clicked(bool checked_objevitel)
{
    if(checked_objevitel==true)
    {
        objevitel = 1;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
    else
    {
        objevitel = 0;
        if(mesice == "Všechny měsíce")
        {
            MesicePlutoZmena();
        }
        else if(mesice == "Charon")
        {
            MesicePlutoCharon();
        }
        else if(mesice == "Nix")
        {
            MesicePlutoNix();
        }
        else if(mesice == "Hydra")
        {
            MesicePlutoHydra();
        }
        else if(mesice == "Styx")
        {
            MesicePlutoStyx();
        }
        else if(mesice == "Kerberos")
        {
            MesicePlutoKerberos();
        }
    }
}


void DialogMesice_Pluto::MesicePlutoZmena()
{
    //1 checkbox----------------------------------------------------------
    if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    //2 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    //3 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    //4 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    //5 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    //6 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else
    {
        MesicePlutoZmena2();
    }

}
void DialogMesice_Pluto::MesicePlutoZmena2()
{
    if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    //7 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
    else
    {
        model_mesicepluto->setQuery("SELECT  FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10");
    }
}

void DialogMesice_Pluto::on_comboBox_activated(const QString &mesice_pluto)
{
    if(mesice_pluto == "Charon")
    {
        MesicePlutoCharon();
    }
    else if(mesice_pluto == "Nix")
    {
        MesicePlutoNix();
    }
    else if(mesice_pluto == "Hydra")
    {
        MesicePlutoHydra();
    }
    else if(mesice_pluto == "Styx")
    {
        MesicePlutoStyx();
    }
    else if(mesice_pluto == "Kerberos")
    {
        MesicePlutoKerberos();
    }
    else
    {
        mesice = ui->comboBox->currentText();
        MesicePlutoZmena();
    }
}

void DialogMesice_Pluto::MesicePlutoCharon()
{
    mesice = ui->comboBox->currentText();
    //1 checkbox----------------------------------------------------------
    if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    //2 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    //3 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    //4 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    //5 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    //6 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else
    {
        MesicePlutoCharon2();
    }
}
void DialogMesice_Pluto::MesicePlutoCharon2()
{
    if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    //7 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
    else
    {
        model_mesicepluto->setQuery("SELECT  FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 142");
    }
}
void DialogMesice_Pluto::MesicePlutoNix()
{
    mesice = ui->comboBox->currentText();
    //1 checkbox----------------------------------------------------------
    if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    //2 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    //3 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    //4 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    //5 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    //6 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else
    {
        MesicePlutoNix2();
    }
}
void DialogMesice_Pluto::MesicePlutoNix2()
{
    if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    //7 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
    else
    {
        model_mesicepluto->setQuery("SELECT  FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 143");
    }
}
void DialogMesice_Pluto::MesicePlutoHydra()
{
    mesice = ui->comboBox->currentText();
    //1 checkbox----------------------------------------------------------
    if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    //2 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    //3 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    //4 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    //5 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    //6 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else
    {
        MesicePlutoHydra2();
    }
}
void DialogMesice_Pluto::MesicePlutoHydra2()
{
    if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    //7 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
    else
    {
        model_mesicepluto->setQuery("SELECT  FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 144");
    }
}
void DialogMesice_Pluto::MesicePlutoStyx()
{
    mesice = ui->comboBox->currentText();
    //1 checkbox----------------------------------------------------------
    if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    //2 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    //3 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    //4 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    //5 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    //6 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else
    {
        MesicePlutoStyx2();
    }
}
void DialogMesice_Pluto::MesicePlutoStyx2()
{
    if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    //7 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
    else
    {
        model_mesicepluto->setQuery("SELECT  FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 145");
    }
}
void DialogMesice_Pluto::MesicePlutoKerberos()
{
    mesice = ui->comboBox->currentText();
    //1 checkbox----------------------------------------------------------
    if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    //2 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    //3 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    //4 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    //5 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    //6 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else
    {
        MesicePlutoKerberos2();
    }
}
void DialogMesice_Pluto::MesicePlutoKerberos2()
{
    if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    //7 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicepluto->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
    else
    {
        model_mesicepluto->setQuery("SELECT  FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 10 AND id_m = 146");
    }
}

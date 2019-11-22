#include "dialogmesice_haumea.h"
#include "ui_dialogmesice_haumea.h"

#include <QSqlDatabase>
#include <QSqlQuery>

DialogMesice_Haumea::DialogMesice_Haumea(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMesice_Haumea)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("planety.db");
    db.open();

    model_mesicehaumea  = new QSqlQueryModel;
    ui->tableViewMesiceHaumea->setModel(model_mesicehaumea);

    ui->comboBox->addItem("Všechny měsíce");
    ui->comboBox->addItem("Hiʻiaka");
    ui->comboBox->addItem("Namaka");
}

DialogMesice_Haumea::~DialogMesice_Haumea()
{
    delete ui;
    delete model_mesicehaumea;
}

void DialogMesice_Haumea::on_checkBox_2_clicked(bool checked_rok)
{
    if(checked_rok==true)
    {
        rok = 1;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
    else
    {
        rok = 0;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
}

void DialogMesice_Haumea::on_checkBox_4_clicked(bool checked_doba)
{
    if(checked_doba==true)
    {
        doba = 1;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
    else
    {
        doba = 0;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
}

void DialogMesice_Haumea::on_checkBox_6_clicked(bool checked_rozmer)
{
    if(checked_rozmer==true)
    {
        rozmer = 1;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
    else
    {
        rozmer = 0;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
}

void DialogMesice_Haumea::on_checkBox_5_clicked(bool checked_objem)
{
    if(checked_objem==true)
    {
        objem = 1;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
    else
    {
        objem = 0;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
}

void DialogMesice_Haumea::on_checkBox_7_clicked(bool checked_hmotnost)
{
    if(checked_hmotnost==true)
    {
        hmotnost = 1;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
    else
    {
        hmotnost = 0;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
}

void DialogMesice_Haumea::on_checkBox_3_clicked(bool checked_pocetpristani)
{
    if(checked_pocetpristani==true)
    {
        pocet_pristani = 1;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
    else
    {
        pocet_pristani = 0;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
}

void DialogMesice_Haumea::on_checkBox_clicked(bool checked_objevitel)
{
    if(checked_objevitel==true)
    {
        objevitel = 1;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
    else
    {
        objevitel = 0;
        if(mesice == "Všechny měsíce")
        {
            MesiceHaumeaZmena();
        }
        else if(mesice == "Hiʻiaka")
        {
            MesiceHaumeaHiiaka();
        }
        else if(mesice == "Namaka")
        {
            MesiceHaumeaNamaka();
        }
    }
}


void DialogMesice_Haumea::MesiceHaumeaZmena()
{
    //1 checkbox----------------------------------------------------------
    if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    //2 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    //3 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    //4 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    //5 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    //6 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else
    {
        MesiceHaumeaZmena2();
    }

}
void DialogMesice_Haumea::MesiceHaumeaZmena2()
{
    if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    //7 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
    else
    {
        model_mesicehaumea->setQuery("SELECT  FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11");
    }
}



void DialogMesice_Haumea::on_comboBox_activated(const QString &mesice_haumea)
{
    if(mesice_haumea == "Hiʻiaka")
    {
        MesiceHaumeaHiiaka();
    }
    else if(mesice_haumea == "Namaka")
    {
        MesiceHaumeaNamaka();
    }
    else
    {
        mesice = ui->comboBox->currentText();
        MesiceHaumeaZmena();
    }
}

void DialogMesice_Haumea::MesiceHaumeaHiiaka()
{
    mesice = ui->comboBox->currentText();
    //1 checkbox----------------------------------------------------------
    if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    //2 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    //3 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    //4 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    //5 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    //6 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else
    {
        MesiceHaumeaHiiaka2();
    }

}

void DialogMesice_Haumea::MesiceHaumeaHiiaka2()
{
    if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    //7 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
    else
    {
        model_mesicehaumea->setQuery("SELECT  FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 147");
    }
}


void DialogMesice_Haumea::MesiceHaumeaNamaka()
{
    mesice = ui->comboBox->currentText();
    //1 checkbox----------------------------------------------------------
    if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    //2 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    //3 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    //4 checkboxy----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    //5 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    //6 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 0)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 0 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else
    {
        MesiceHaumeaNamaka2();
    }
}

void DialogMesice_Haumea::MesiceHaumeaNamaka2()
{
    if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 0 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 0 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 1 && rozmer == 0 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 1 && doba == 0 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else if(rok == 0 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    //7 checkboxu----------------------------------------------------------
    else if(rok == 1 && doba == 1 && rozmer == 1 && objem == 1 && hmotnost == 1 && pocet_pristani == 1 && objevitel == 1)
    {
        model_mesicehaumea->setQuery("SELECT jmeno, rok_objevu, doba_obehu_h, rozmer, objem, hmotnost, pocet_pristani, objevitel FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
    else
    {
        model_mesicehaumea->setQuery("SELECT  FROM mesice_info JOIN mesice ON mesice.id=mesice_info.id_m WHERE mesice.id_p = 11 AND id_m = 148");
    }
}

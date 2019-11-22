#include "dialogneptun.h"
#include "ui_dialogneptun.h"

#include <QSqlDatabase>
#include <QSqlQuery>

DialogNeptun::DialogNeptun(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNeptun)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("planety.db");
    db.open();

    model_neptun  = new QSqlQueryModel;
    ui->tableViewNeptun->setModel(model_neptun);
}

DialogNeptun::~DialogNeptun()
{
    delete ui;
    delete model_neptun;
}

void DialogNeptun::on_checkBox_2_clicked(bool checked_typ)
{
    if(checked_typ==true)
    {
        typ = 1;
        NeptunZmena();
    }
    else
    {
        typ = 0;
        NeptunZmena();
    }

}

void DialogNeptun::on_checkBox_4_clicked(bool checked_vzd)
{
    if(checked_vzd==true)
    {
        vzd = 1;
        NeptunZmena();
    }
    else
    {
        vzd = 0;
        NeptunZmena();
    }

}

void DialogNeptun::on_checkBox_5_clicked(bool checked_doba)
{
    if(checked_doba==true)
    {
        doba = 1;
        NeptunZmena();
    }
    else
    {
        doba = 0;
        NeptunZmena();
    }
}

void DialogNeptun::on_checkBox_8_clicked(bool checked_delkadne)
{
    if(checked_delkadne==true)
    {
        delka_dne = 1;
        NeptunZmena();
    }
    else
    {
        delka_dne = 0;
        NeptunZmena();
    }
}

void DialogNeptun::on_checkBox_9_clicked(bool checked_polomer)
{
    if(checked_polomer==true)
    {
        polomer = 1;
        NeptunZmena();
    }
    else
    {
        polomer = 0;
        NeptunZmena();
    }
}

void DialogNeptun::on_checkBox_7_clicked(bool checked_teplota)
{
    if(checked_teplota==true)
    {
        teplota = 1;
        NeptunZmena();
    }
    else
    {
        teplota = 0;
        NeptunZmena();
    }
}

void DialogNeptun::on_checkBox_10_clicked(bool checked_hmotnost)
{
    if(checked_hmotnost==true)
    {
        hmotnost = 1;
        NeptunZmena();
    }
    else
    {
        hmotnost = 0;
        NeptunZmena();
    }
}

void DialogNeptun::on_checkBox_6_clicked(bool checked_pocetmesicu)
{
    if(checked_pocetmesicu==true)
    {
        pocet_mesicu = 1;
        NeptunZmena();
    }
    else
    {
        pocet_mesicu = 0;
        NeptunZmena();
    }
}

void DialogNeptun::on_checkBox_3_clicked(bool checked_objevitel)
{
    if(checked_objevitel==true)
    {
        objevitel = 1;
        NeptunZmena();
    }
    else
    {
        objevitel = 0;
        NeptunZmena();
    }
}

void DialogNeptun::on_checkBox_clicked(bool checked_rok)
{
    if(checked_rok==true)
    {
        rok = 1;
        NeptunZmena();
    }
    else
    {
        rok = 0;
        NeptunZmena();
    }
}

void DialogNeptun::NeptunZmena()
{
    //1 checkbox----------------------------------------------------------
    if(vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT rok_objevu FROM planety_info WHERE id_p = 8");
    }
    // Po řadě vše--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    // 2 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km  FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km  FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km  FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    // 3 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else
    {
        NeptunZmena2();
    }
 }
void DialogNeptun::NeptunZmena2()
{
    if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    // 4 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else
    {
        NeptunZmena3();
    }

}

void DialogNeptun::NeptunZmena3()
{

    if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else
    {
        NeptunZmena4();
    }
}
void DialogNeptun::NeptunZmena4()
{
    if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    // 5 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else
    {
        NeptunZmena5();
    }

}

void DialogNeptun::NeptunZmena5()
{
    if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else
    {
        NeptunZmena6();
    }

}

void DialogNeptun::NeptunZmena6()
{
    if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    // 6 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else
    {
        NeptunZmena7();
    }

}

void DialogNeptun::NeptunZmena7()
{
    if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else
    {
        NeptunZmena8();
    }

}
void DialogNeptun::NeptunZmena8()
{
    if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    // 7 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else
    {
        NeptunZmena9();
    }

}
void DialogNeptun::NeptunZmena9()
{
    if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    // 8 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    // 9 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_neptun->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 8");
    }
    else
    {
        model_neptun->setQuery("SELECT FROM planety_info WHERE id_p = 8");
    }
}

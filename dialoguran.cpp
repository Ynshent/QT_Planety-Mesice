#include "dialoguran.h"
#include "ui_dialoguran.h"

#include <QSqlDatabase>
#include <QSqlQuery>


DialogUran::DialogUran(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUran)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("planety.db");
    db.open();

    model_uran  = new QSqlQueryModel;
    ui->tableViewUran->setModel(model_uran);
}

DialogUran::~DialogUran()
{
    delete ui;
    delete model_uran;
}

void DialogUran::on_checkBox_2_clicked(bool checked_typ)
{
    if(checked_typ==true)
    {
        typ = 1;
        UranZmena();
    }
    else
    {
        typ = 0;
        UranZmena();
    }

}

void DialogUran::on_checkBox_4_clicked(bool checked_vzd)
{
    if(checked_vzd==true)
    {
        vzd = 1;
        UranZmena();
    }
    else
    {
        vzd = 0;
        UranZmena();
    }

}

void DialogUran::on_checkBox_5_clicked(bool checked_doba)
{
    if(checked_doba==true)
    {
        doba = 1;
        UranZmena();
    }
    else
    {
        doba = 0;
        UranZmena();
    }
}

void DialogUran::on_checkBox_8_clicked(bool checked_delkadne)
{
    if(checked_delkadne==true)
    {
        delka_dne = 1;
        UranZmena();
    }
    else
    {
        delka_dne = 0;
        UranZmena();
    }
}

void DialogUran::on_checkBox_9_clicked(bool checked_polomer)
{
    if(checked_polomer==true)
    {
        polomer = 1;
        UranZmena();
    }
    else
    {
        polomer = 0;
        UranZmena();
    }
}

void DialogUran::on_checkBox_7_clicked(bool checked_teplota)
{
    if(checked_teplota==true)
    {
        teplota = 1;
        UranZmena();
    }
    else
    {
        teplota = 0;
        UranZmena();
    }
}

void DialogUran::on_checkBox_10_clicked(bool checked_hmotnost)
{
    if(checked_hmotnost==true)
    {
        hmotnost = 1;
        UranZmena();
    }
    else
    {
        hmotnost = 0;
        UranZmena();
    }
}

void DialogUran::on_checkBox_6_clicked(bool checked_pocetmesicu)
{
    if(checked_pocetmesicu==true)
    {
        pocet_mesicu = 1;
        UranZmena();
    }
    else
    {
        pocet_mesicu = 0;
        UranZmena();
    }
}

void DialogUran::on_checkBox_3_clicked(bool checked_objevitel)
{
    if(checked_objevitel==true)
    {
        objevitel = 1;
        UranZmena();
    }
    else
    {
        objevitel = 0;
        UranZmena();
    }
}

void DialogUran::on_checkBox_clicked(bool checked_rok)
{
    if(checked_rok==true)
    {
        rok = 1;
        UranZmena();
    }
    else
    {
        rok = 0;
        UranZmena();
    }
}

void DialogUran::UranZmena()
{
    //1 checkbox----------------------------------------------------------
    if(vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT rok_objevu FROM planety_info WHERE id_p = 7");
    }
    // Po řadě vše--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    // 2 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km  FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km  FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km  FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    // 3 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else
    {
        UranZmena2();
    }
 }
void DialogUran::UranZmena2()
{
    if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    // 4 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else
    {
        UranZmena3();
    }

}

void DialogUran::UranZmena3()
{

    if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else
    {
        UranZmena4();
    }
}
void DialogUran::UranZmena4()
{
    if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    // 5 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else
    {
        UranZmena5();
    }

}

void DialogUran::UranZmena5()
{
    if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else
    {
        UranZmena6();
    }

}

void DialogUran::UranZmena6()
{
    if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    // 6 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else
    {
        UranZmena7();
    }

}

void DialogUran::UranZmena7()
{
    if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else
    {
        UranZmena8();
    }

}
void DialogUran::UranZmena8()
{
    if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    // 7 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else
    {
        UranZmena9();
    }

}
void DialogUran::UranZmena9()
{
    if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    // 8 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    // 9 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_uran->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 7");
    }
    else
    {
        model_uran->setQuery("SELECT FROM planety_info WHERE id_p = 7");
    }
}

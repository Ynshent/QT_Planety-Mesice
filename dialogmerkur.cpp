#include "dialogmerkur.h"
#include "ui_dialogmerkur.h"

#include <QSqlDatabase>
#include <QSqlQuery>



DialogMerkur::DialogMerkur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMerkur)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("planety.db");
    db.open();

    model_merkur  = new QSqlQueryModel;
    ui->tableViewMerkur->setModel(model_merkur);

}

DialogMerkur::~DialogMerkur()
{
    delete ui;
    delete model_merkur;
}


void DialogMerkur::on_checkBox_2_clicked(bool checked_typ)
{
    if(checked_typ==true)
    {
        typ = 1;
        MerkurZmena();
    }
    else
    {
        typ = 0;
        MerkurZmena();
    }

}

void DialogMerkur::on_checkBox_4_clicked(bool checked_vzd)
{
    if(checked_vzd==true)
    {
        vzd = 1;
        MerkurZmena();
    }
    else
    {
        vzd = 0;
        MerkurZmena();
    }

}

void DialogMerkur::on_checkBox_5_clicked(bool checked_doba)
{
    if(checked_doba==true)
    {
        doba = 1;
        MerkurZmena();
    }
    else
    {
        doba = 0;
        MerkurZmena();
    }
}

void DialogMerkur::on_checkBox_8_clicked(bool checked_delkadne)
{
    if(checked_delkadne==true)
    {
        delka_dne = 1;
        MerkurZmena();
    }
    else
    {
        delka_dne = 0;
        MerkurZmena();
    }
}

void DialogMerkur::on_checkBox_9_clicked(bool checked_polomer)
{
    if(checked_polomer==true)
    {
        polomer = 1;
        MerkurZmena();
    }
    else
    {
        polomer = 0;
        MerkurZmena();
    }
}

void DialogMerkur::on_checkBox_7_clicked(bool checked_teplota)
{
    if(checked_teplota==true)
    {
        teplota = 1;
        MerkurZmena();
    }
    else
    {
        teplota = 0;
        MerkurZmena();
    }
}

void DialogMerkur::on_checkBox_10_clicked(bool checked_hmotnost)
{
    if(checked_hmotnost==true)
    {
        hmotnost = 1;
        MerkurZmena();
    }
    else
    {
        hmotnost = 0;
        MerkurZmena();
    }
}

void DialogMerkur::on_checkBox_6_clicked(bool checked_pocetmesicu)
{
    if(checked_pocetmesicu==true)
    {
        pocet_mesicu = 1;
        MerkurZmena();
    }
    else
    {
        pocet_mesicu = 0;
        MerkurZmena();
    }
}

void DialogMerkur::on_checkBox_3_clicked(bool checked_objevitel)
{
    if(checked_objevitel==true)
    {
        objevitel = 1;
        MerkurZmena();
    }
    else
    {
        objevitel = 0;
        MerkurZmena();
    }
}

void DialogMerkur::on_checkBox_clicked(bool checked_rok)
{
    if(checked_rok==true)
    {
        rok = 1;
        MerkurZmena();
    }
    else
    {
        rok = 0;
        MerkurZmena();
    }
}

void DialogMerkur::MerkurZmena()
{
    //1 checkbox----------------------------------------------------------
    if(vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT rok_objevu FROM planety_info WHERE id_p = 1");
    }
    // Po řadě vše--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    // 2 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km  FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km  FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km  FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    // 3 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else
    {
        MerkurZmena2();
    }
 }
void DialogMerkur::MerkurZmena2()
{
    if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    // 4 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else
    {
        MerkurZmena3();
    }

}

void DialogMerkur::MerkurZmena3()
{

    if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else
    {
        MerkurZmena4();
    }

}
void DialogMerkur::MerkurZmena4()
{
    if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    // 5 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else
    {
        MerkurZmena5();
    }

}
void DialogMerkur::MerkurZmena5()
{
    if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else
    {
        MerkurZmena6();
    }

}
void DialogMerkur::MerkurZmena6()
{
    if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    // 6 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else
    {
        MerkurZmena7();
    }

}
void DialogMerkur::MerkurZmena7()
{
    if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else
    {
        MerkurZmena8();
    }

}
void DialogMerkur::MerkurZmena8()
{
    if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    // 7 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else
    {
        MerkurZmena9();
    }

}
void DialogMerkur::MerkurZmena9()
{
    if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    // 8 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    // 9 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_merkur->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 1");
    }
    else
    {
        model_merkur->setQuery("SELECT FROM planety_info WHERE id_p = 1");
    }
}













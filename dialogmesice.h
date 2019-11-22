#ifndef DIALOGMESICE_H
#define DIALOGMESICE_H

#include <QDialog>
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


namespace Ui {
class DialogMesice;
}

class DialogMesice : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMesice(QWidget *parent = nullptr);
    ~DialogMesice();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::DialogMesice *ui;
    DialogMesice_Zeme* mesice_zeme {nullptr};
    DialogMesice_Mars* mesice_mars {nullptr};
    DialogMesice_Jupiter* mesice_jupiter {nullptr};
    DialogMesice_Saturn* mesice_saturn {nullptr};
    DialogMesice_Uran* mesice_uran {nullptr};
    DialogMesice_Neptun* mesice_neptun {nullptr};
    DialogMesice_Pluto* mesice_pluto {nullptr};
    DialogMesice_Haumea* mesice_haumea {nullptr};
    DialogMesice_Makemake* mesice_makemake {nullptr};
    DialogMesice_Eris* mesice_eris {nullptr};
    DialogVsechnyMesice* mesice_vsechny {nullptr};


};

#endif // DIALOGMESICE_H

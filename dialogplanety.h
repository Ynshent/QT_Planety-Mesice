#ifndef DIALOGPLANETY_H
#define DIALOGPLANETY_H

#include <QDialog>
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


namespace Ui {
class DialogPlanety;
}

class DialogPlanety : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPlanety(QWidget *parent = nullptr);
    ~DialogPlanety();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::DialogPlanety *ui;
    DialogMerkur* merkur {nullptr};
    DialogVenuse* venuse {nullptr};
    DialogZeme* zeme {nullptr};
    DialogMars* mars {nullptr};
    DialogJupiter* jupiter {nullptr};
    DialogSaturn* saturn {nullptr};
    DialogUran* uran {nullptr};
    DialogNeptun* neptun {nullptr};
    DialogCeres* ceres {nullptr};
    DialogPluto* pluto {nullptr};
    DialogHaumea* haumea {nullptr};
    DialogMakemake* makemake {nullptr};
    DialogEris* eris {nullptr};
    DialogVsechnyPlanety* vsechny {nullptr};


};

#endif // DIALOGPLANETY_H

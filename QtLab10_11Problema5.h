#ifndef QTLAB10_11PROBLEMA5_H_
#define QTLAB10_11PROBLEMA5_H_

#include <QMainWindow>
#include <QTableWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QLabel>
#include <QDebug>
#include <QRadioButton>
#include <QHeaderView>
#include <QSplitter>
#include <QIcon>
#include <QGraphicsDropShadowEffect>

#include "service.h"

class AppGUI : public QWidget {

public:
    AppGUI(Service& srv) : srv{ srv } {
		initGUI();
		contractGUI();
		connectSignals();
	}

private:
	Service& srv;
	QWidget* contract = new QWidget;
	QTableWidget* table = new QTableWidget;
	QListWidget* lista_contracte = new QListWidget;

	///BUTOANE

	QPushButton* btn_adauga = new QPushButton{ "Adauga" };
	QPushButton* btn_sterge = new QPushButton{ "Sterge" };
	QPushButton* btn_modifica = new QPushButton{ "Modifica" };
	QPushButton* btn_cauta = new QPushButton{ "Cauta" };
	QPushButton* btn_undo = new QPushButton{ "Undo" };
	QPushButton* btn_contract = new QPushButton{ "Contract" };
	QPushButton* sort_denumire = new QPushButton{ "Sorteaza dupa denumire" };
	QPushButton* sort_ore = new QPushButton{ "Sorteaza dupa ore" };
	QPushButton* sort_proftip = new QPushButton{ "Sorteaza dupa profesor + tip" };
	QPushButton* filtrare_ore = new QPushButton{ "Filtreaza dupa ore" };
	QPushButton* filtrare_prof = new QPushButton{ "Filtreaza dupa profesor" };
	QLineEdit* txtfilter = new QLineEdit;
	QPushButton* exit = new QPushButton{ "Exit" };
	QPushButton* load = new QPushButton{ "Load" };

	//Butoane pt contract
	QPushButton* btn_contract_adauga = new QPushButton{ "Adauga la contract" };
	QPushButton* btn_contract_sterge = new QPushButton{ "Goleste contract" };
	QPushButton* btn_contract_genereaza = new QPushButton{ "Genereaza contract" };
	QPushButton* btn_contract_export = new QPushButton{ "Exporta contract" };
	QPushButton* btn_contract_exit = new QPushButton{ "Exit" };


	///LAYOUT

	QLineEdit* txtDenumire = new QLineEdit;
	QLineEdit* txtOre = new QLineEdit;
	QLineEdit* txtProfesor = new QLineEdit;
	QLineEdit* txtTip = new QLineEdit;

	//pt contract
	QLineEdit* txtContractDenumire = new QLineEdit;
	QLineEdit* txtContractFile = new QLineEdit;
	QLineEdit* txtContractProfesor = new QLineEdit;
	QLineEdit* txtContractNumar = new QLineEdit;

	void loadList(const vector<Disciplina>& discipline);
	void loadTable(const vector<Disciplina>& discipline);
	void contractGUI();
	void connectSignals();

	void initGUI();

	void clearTextBox();
	void clearContractTextBox();
	void uiAdauga();
	void uiSterge();
	void uiModifica();
	void uiCauta();
	void uiFilterOre();
	void uiFilterProf();
	void uiSortDenumire();
	void uiSortOre();
	void uiSortProfTip();
	void uiContractAdauga();


	
};

#endif /* QTLAB10_11PROBLEMA5_H_ */
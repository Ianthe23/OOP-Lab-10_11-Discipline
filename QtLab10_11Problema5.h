#ifndef QTLAB10_11PROBLEMA5_H_
#define QTLAB10_11PROBLEMA5_H_

#include <QWidget>
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

#include <QPaintEvent>
#include <QPainter>
#include <QRadioButton>

#include "service.h"
#include "observer.h"

class ContractGUI : public QWidget, public Observable, public Observer {
	friend class AppGUI;
	friend class Service;
	friend class ContractReadOnlyGUI;
private:
	Service& srv;

	//butoane
	QPushButton* empty_contract = new QPushButton{ "&Goleste contract" };
	QPushButton* generate_contract = new QPushButton{ "&Genereaza contract" };
	QPushButton* exit = new QPushButton{ "&Exit" };

	//textboxuri
	QLineEdit* txtContractNumar = new QLineEdit;

	//lista
	QListWidget* lista_contract = new QListWidget;
public:
	explicit ContractGUI(Service& srv) : srv{ srv } {
		srv.addObserver(this);
	};

	void initContractGUI();
	void connectContractSignals();
	void reloadList(const vector<Disciplina>& discipline);
	void update() override {
		reloadList(srv.getAllContract());
	}
};

class ContractReadOnlyGUI : public QWidget, public Observer {
	friend class ContractGUI;
	Service& srv;
	QListWidget* lista_obiecte = new QListWidget;
public:
	explicit ContractReadOnlyGUI(Service& service) : srv{ service } {
		initContractReadOnlyGUI();
		srv.addObserver(this);
	}

	void initContractReadOnlyGUI() {
		this->setWindowIcon(QIcon("icons/contract.jpg"));
		this->setWindowTitle("Desene contracte");
		/*lista_obiecte = new QListWidget();
		QHBoxLayout* layout = new QHBoxLayout;
		layout->addWidget(lista_obiecte);
		setLayout(layout);*/
	}
	
	void update() override {
		repaint();
	}

	void reload() {
		lista_obiecte->clear();
		for (const auto& d : srv.getAllContract()) {
			lista_obiecte->addItem(QString::fromStdString(d.to_string_print()));
		}
	}

	void paintEvent(QPaintEvent* e) override {
		QPainter p(this);
		p.drawImage(0, 0, QImage("icons/book.png"));
		srand(time(0));

		int x = -20;
		for (const auto& elem : srv.getAllContract()) {
			x += 40;
			int forma = rand() % 4;
			int inaltime = rand() % 130;
			int start_y = rand() % 60;
			QColor color;

			int color_num = rand() % 5;
			switch (color_num) {
			case 0:
				color = Qt::red;
				break;
			case 1:
				color = Qt::blue;
				break;
			case 2:
				color = Qt::green;
				break;
			case 3:
				color = Qt::yellow;
				break;
			case 4:
				color = Qt::cyan;
				break;
			default:
				break;
			}

			switch (forma) {
			case 0:
				p.drawRect(x, start_y, 20, inaltime);
				break;
			case 1:
				p.drawEllipse(x, start_y, 20, inaltime);
				break;
			case 2:
				p.fillRect(x, start_y, 20, inaltime, color);
				break;
			default:
				p.fillRect(x, start_y, 20, inaltime, color);
				break;
			}
		}
	}

	~ContractReadOnlyGUI() {
		srv.removeObserver(this);
	}
};


class AppGUI : public QWidget {

public:
    AppGUI(Service& service) : srv{ service } {
		initGUI();
		contract = new ContractGUI(srv);
		contract->initContractGUI();
		contract->connectContractSignals();
		connectSignals();
	}

private:
	Service& srv;
	ContractGUI* contract;
	QTableWidget* table = new QTableWidget;
	QListWidget* list = new QListWidget;
	QListWidget* lista_contracte = new QListWidget;
	QVBoxLayout* listaLayout = new QVBoxLayout;

	///BUTOANE
	vector<QPushButton*> vector_btn;
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
	QPushButton* open_contract = new QPushButton{ "Deschide contract" };
	QPushButton* open_contract_readonly = new QPushButton{ "Deschide contract readonly" };
	QPushButton* add_contract = new QPushButton{ "&Adauga la contract" };
	QPushButton* export_contract = new QPushButton{ "&Exporta contract" };
	QLineEdit* txtDenumireContract = new QLineEdit;
	QLineEdit* txtProfesorContract = new QLineEdit;
	QLineEdit* txtContractFile = new QLineEdit;


	///LAYOUT

	QLineEdit* txtDenumire = new QLineEdit;
	QLineEdit* txtOre = new QLineEdit;
	QLineEdit* txtProfesor = new QLineEdit;
	QLineEdit* txtTip = new QLineEdit;

	void loadList(const vector<Disciplina>& discipline);
	void loadTable(const vector<Disciplina>& discipline);
	void loadListfromTable(const vector<Disciplina>& discipline);
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
	void uiAddContract();

};

#endif /* QTLAB10_11PROBLEMA5_H_ */
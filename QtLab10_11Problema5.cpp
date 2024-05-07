#include "QtLab10_11Problema5.h"

void AppGUI::initGUI() {
	
	this->setWindowIcon(QIcon("icons/school.jpeg"));
	this->setWindowTitle("Aplicatie Discipline");
	QPalette palette = QPalette();
	palette.setColor(QPalette::Window, "#2573cc");

	// Create a gradient for the fading effect
	QLinearGradient gradient(this->width() / 2, 0, this->width(), 0);
	gradient.setColorAt(0, QColor("#2573cc")); // Same color as background
	gradient.setColorAt(1, QColor("#7fb0e8")); // Transparent color

	// Set the gradient as the brush for the background
	palette.setBrush(QPalette::Window, QBrush(gradient));

	///creez fonturile necesare
	QFont font = QFont("Helvetica", 12, 10, false);
	QFont boldFont = font;
	boldFont.setBold(true);

	this->setAutoFillBackground(true); //
	this->setPalette(palette);
	this->setFont(font);

	///Layout principal
	QHBoxLayout* mainLayout = new QHBoxLayout;
	setLayout(mainLayout);

	///Layout lista
	QVBoxLayout* listaLayout = new QVBoxLayout; //layout stanga
	mainLayout->addLayout(listaLayout, 1);

	QLabel *listaLabel = new QLabel("Lista discipline");
	listaLabel->setAlignment(Qt::AlignCenter);
	listaLabel->setFont(boldFont);

	listaLayout->addWidget(listaLabel, 1);
	table->resizeColumnsToContents();
	table->setMinimumSize(500, 200);	
	listaLayout->addWidget(table, 2);
	btn_undo->setIcon(QIcon("icons/undo.jpg"));
	btn_contract->setIcon(QIcon("icons/contract.jpg"));

	// Apply shadow effect to the buttons
	QGraphicsDropShadowEffect* undoShadowEffect = new QGraphicsDropShadowEffect(this);
	undoShadowEffect->setOffset(2, 2);
	btn_undo->setGraphicsEffect(undoShadowEffect);
	
	listaLayout->addWidget(btn_undo);


	QGraphicsDropShadowEffect* contractShadowEffect = new QGraphicsDropShadowEffect(this);
	contractShadowEffect->setOffset(2, 2);
	btn_contract->setGraphicsEffect(contractShadowEffect);
	listaLayout->addWidget(btn_contract);

	///Layout operatii
	QVBoxLayout* operatiiLayout = new QVBoxLayout; //layout dreapta
	
	mainLayout->addLayout(operatiiLayout, 1);

	QFormLayout* formLayout = new QFormLayout;
	operatiiLayout->addLayout(formLayout);
	//apply to line edit the red hover effect
	txtDenumire->setStyleSheet("QLineEdit{font-size: 16px;font-weight: 500;border: 1px solid transparent;border-radius: 4px;padding: 4px 6px;}");
	txtOre->setStyleSheet("QLineEdit{font-size: 16px;font-weight: 500;border: 1px solid transparent;border-radius: 4px;padding: 4px 6px;}");
	txtTip->setStyleSheet("QLineEdit{font-size: 16px;font-weight: 500;border: 1px solid transparent;border-radius: 4px;padding: 4px 6px;}");
	txtProfesor->setStyleSheet("QLineEdit{font-size: 16px;font-weight: 500;border: 1px solid transparent;border-radius: 4px;padding: 4px 6px;}");
	
	//qDebug() << "idk" << txtDenumire->styleSheet();
	formLayout->addRow(new QLabel{ "Denumire: " }, txtDenumire);
	formLayout->addRow(new QLabel{ "Ore: " }, txtOre);
	formLayout->addRow(new QLabel{ "Tip: " }, txtTip);
	formLayout->addRow(new QLabel{ "Profesor: " }, txtProfesor);

	QHBoxLayout* actiuniLayout = new QHBoxLayout;
	operatiiLayout->addLayout(actiuniLayout);
	btn_adauga->setIcon(QIcon("icons/add.jpg"));
	btn_sterge->setIcon(QIcon("icons/delete.jpg"));
	btn_modifica->setIcon(QIcon("icons/modify.jpg"));
	btn_cauta->setIcon(QIcon("icons/search.jpg"));

	QGraphicsDropShadowEffect* adaugaShadowEffect = new QGraphicsDropShadowEffect(this);
	adaugaShadowEffect->setOffset(2, 2);
	btn_adauga->setGraphicsEffect(adaugaShadowEffect);
	actiuniLayout->addWidget(btn_adauga);

	QGraphicsDropShadowEffect* stergeShadowEffect = new QGraphicsDropShadowEffect(this);
	stergeShadowEffect->setOffset(2, 2);
	btn_sterge->setGraphicsEffect(stergeShadowEffect);
	actiuniLayout->addWidget(btn_sterge);

	QGraphicsDropShadowEffect* modificaShadowEffect = new QGraphicsDropShadowEffect(this);
	modificaShadowEffect->setOffset(2, 2);
	btn_modifica->setGraphicsEffect(modificaShadowEffect);
	actiuniLayout->addWidget(btn_modifica);

	QGraphicsDropShadowEffect* cautaShadowEffect = new QGraphicsDropShadowEffect(this);
	cautaShadowEffect->setOffset(2, 2);
	btn_cauta->setGraphicsEffect(cautaShadowEffect);
	actiuniLayout->addWidget(btn_cauta);

	QVBoxLayout* sortLayout = new QVBoxLayout;
	operatiiLayout->addLayout(sortLayout);
	sortLayout->addSpacing(20);

	QLabel *sortLabel = new QLabel("Tip de sortare");
	sortLabel->setAlignment(Qt::AlignCenter);
	sortLabel->setFont(boldFont);

	sortLayout->addWidget(sortLabel, 1);
	sort_denumire->setIcon(QIcon("icons/name.jpg"));
	sort_ore->setIcon(QIcon("icons/hours.jpg"));
	sort_proftip->setIcon(QIcon("icons/teacher.jpg"));

	QGraphicsDropShadowEffect* sortDenumireShadowEffect = new QGraphicsDropShadowEffect(this);
	sortDenumireShadowEffect->setOffset(2, 2);
	sort_denumire->setGraphicsEffect(sortDenumireShadowEffect);
	sortLayout->addWidget(sort_denumire);

	QGraphicsDropShadowEffect* sortOreShadowEffect = new QGraphicsDropShadowEffect(this);
	sortOreShadowEffect->setOffset(2, 2);
	sort_ore->setGraphicsEffect(sortOreShadowEffect);
	sortLayout->addWidget(sort_ore);

	QGraphicsDropShadowEffect* sortProfTipShadowEffect = new QGraphicsDropShadowEffect(this);
	sortProfTipShadowEffect->setOffset(2, 2);
	sort_proftip->setGraphicsEffect(sortProfTipShadowEffect);
	sortLayout->addWidget(sort_proftip);
	sortLayout->addSpacing(20);

	QLabel *filtrareLabel = new QLabel("Filtrari");
	filtrareLabel->setAlignment(Qt::AlignCenter);
	filtrareLabel->setFont(boldFont);

	sortLayout->addWidget(filtrareLabel, 1);

	QFormLayout* filtrareFormLayout = new QFormLayout;
	sortLayout->addLayout(filtrareFormLayout);
	txtfilter->setStyleSheet("QLineEdit{font-size: 16px;font-weight: 500;border: 1px solid transparent;border-radius: 4px;padding: 4px 6px;}");
	filtrareFormLayout->addRow(new QLabel{ "Input: " }, txtfilter);

	QHBoxLayout* filtrareLayout = new QHBoxLayout;
	operatiiLayout->addLayout(filtrareLayout);
	filtrare_ore->setIcon(QIcon("icons/hours.jpg"));
	filtrare_prof->setIcon(QIcon("icons/teacher.jpg"));

	QGraphicsDropShadowEffect* filtrareOreShadowEffect = new QGraphicsDropShadowEffect(this);
	filtrareOreShadowEffect->setOffset(2, 2);
	filtrare_ore->setGraphicsEffect(filtrareOreShadowEffect);
	filtrareLayout->addWidget(filtrare_ore);

	QGraphicsDropShadowEffect* filtrareProfShadowEffect = new QGraphicsDropShadowEffect(this);
	filtrareProfShadowEffect->setOffset(2, 2);
	filtrare_prof->setGraphicsEffect(filtrareProfShadowEffect);
	filtrareLayout->addWidget(filtrare_prof);

	load->setIcon(QIcon("icons/load.jpg"));
	exit->setIcon(QIcon("icons/exit.jpg"));

	QGraphicsDropShadowEffect* loadShadowEffect = new QGraphicsDropShadowEffect(this);
	loadShadowEffect->setOffset(2, 2);
	load->setGraphicsEffect(loadShadowEffect);
	listaLayout->addWidget(load);

	QGraphicsDropShadowEffect* exitShadowEffect = new QGraphicsDropShadowEffect(this);
	exitShadowEffect->setOffset(2, 2);
	exit->setGraphicsEffect(exitShadowEffect);
	operatiiLayout->addSpacing(20);
	operatiiLayout->addWidget(exit);

}

void AppGUI::contractGUI() {
	contract->setWindowTitle("Setare contract");	
	contract->setWindowIcon(QIcon("icons/contract.jpg"));

	QPalette palette_contract = QPalette();
	QLinearGradient gradient(this->width() / 2, 0, this->width(), 0);
	gradient.setColorAt(0, QColor("#2573cc")); // Same color as background
	gradient.setColorAt(1, QColor("#7fb0e8"));

	palette_contract.setBrush(QPalette::Window, QBrush(gradient));
	contract->setAutoFillBackground(true);

	contract->setPalette(palette_contract);
	contract->setFont(QFont("Helvetica", 12, 10, false));

	QHBoxLayout* Layout = new QHBoxLayout;
	contract->setLayout(Layout);

	QVBoxLayout* contractLayout = new QVBoxLayout;
	Layout->addLayout(contractLayout);

	QLabel* contractLabel = new QLabel("Contract");
	contractLabel->setAlignment(Qt::AlignCenter);

	QFont font = QFont("Helvetica", 12, 10, false);
	QFont boldFont = font;
	boldFont.setBold(true);
	contractLabel->setFont(boldFont);

	contractLayout->addWidget(contractLabel);
	QGraphicsDropShadowEffect* stergeContractEffect = new QGraphicsDropShadowEffect(this);
	stergeContractEffect->setOffset(2, 2);
	btn_contract_sterge->setIcon(QIcon("icons/empty.png"));
	btn_contract_sterge->setGraphicsEffect(stergeContractEffect);
	contractLayout->addWidget(btn_contract_sterge);
	contractLayout->addSpacing(20);

	QFormLayout* genereazaLayout = new QFormLayout;
	contractLayout->addLayout(genereazaLayout);

	txtContractDenumire->setStyleSheet("QLineEdit{font-size: 16px;font-weight: 500;border: 1px solid transparent;border-radius: 4px;padding: 4px 6px;}");
	txtContractProfesor->setStyleSheet("QLineEdit{font-size: 16px;font-weight: 500;border: 1px solid transparent;border-radius: 4px;padding: 4px 6px;}");
	genereazaLayout->addRow(new QLabel{ "Denumire: " }, txtContractDenumire);
	genereazaLayout->addRow(new QLabel{ "Profesor: " }, txtContractProfesor);

	QGraphicsDropShadowEffect* adaugaContractEffect = new QGraphicsDropShadowEffect(this);
	adaugaContractEffect->setOffset(2, 2);
	btn_contract_adauga->setGraphicsEffect(adaugaContractEffect);
	btn_contract_adauga->setIcon(QIcon("icons/add.jpg"));
	contractLayout->addWidget(btn_contract_adauga);
	contractLayout->addSpacing(20);

	QLabel *genereazaContractLabel = new QLabel("Genereaza contract");
	genereazaContractLabel->setAlignment(Qt::AlignCenter);
	genereazaContractLabel->setFont(boldFont);
	contractLayout->addWidget(genereazaContractLabel);
	QFormLayout* genereazaContractLayout = new QFormLayout;
	contractLayout->addLayout(genereazaContractLayout);

	txtContractNumar->setStyleSheet("QLineEdit{font-size: 16px;font-weight: 500;border: 1px solid transparent;border-radius: 4px;padding: 4px 6px;}");
	genereazaContractLayout->addRow(new QLabel{ "Numar discipline: " }, txtContractNumar);

	QGraphicsDropShadowEffect* genereazaContractEffect = new QGraphicsDropShadowEffect(this);
	genereazaContractEffect->setOffset(2, 2);
	btn_contract_genereaza->setGraphicsEffect(genereazaContractEffect);
	btn_contract_genereaza->setIcon(QIcon("icons/generate.png"));
	contractLayout->addWidget(btn_contract_genereaza);
	contractLayout->addSpacing(20);

	QLabel *exportaContractLabel = new QLabel("Exporta contract");
	exportaContractLabel->setAlignment(Qt::AlignCenter);
	exportaContractLabel->setFont(boldFont);
	contractLayout->addWidget(exportaContractLabel);
	QFormLayout* exportLayout = new QFormLayout;
	contractLayout->addLayout(exportLayout);

	txtContractFile->setStyleSheet("QLineEdit{font-size: 16px;font-weight: 500;border: 1px solid transparent;border-radius: 4px;padding: 4px 6px;}");
	exportLayout->addRow(new QLabel{ "Nume fisier: " }, txtContractFile);

	QGraphicsDropShadowEffect* exportContractEffect = new QGraphicsDropShadowEffect(this);
	exportContractEffect->setOffset(2, 2);
	btn_contract_export->setGraphicsEffect(exportContractEffect);
	btn_contract_export->setIcon(QIcon("icons/export.png"));
	contractLayout->addWidget(btn_contract_export);

	QVBoxLayout* contractOperatiiLayout = new QVBoxLayout;
	Layout->addLayout(contractOperatiiLayout);

	contractOperatiiLayout->addWidget(lista_contracte);

	QGraphicsDropShadowEffect* exitContractEffect = new QGraphicsDropShadowEffect(this);
	exitContractEffect->setOffset(2, 2);
	btn_contract_exit->setGraphicsEffect(exitContractEffect);
	btn_contract_exit->setIcon(QIcon("icons/exit.jpg"));
	contractOperatiiLayout->addWidget(btn_contract_exit);
}

void AppGUI::loadTable(const vector<Disciplina>& disciplina) {
	this->table->clearContents();
	this->table->setColumnCount(5);
	this->table->setRowCount(disciplina.size() + 1);

	int nr_linie = 0;
	table->verticalHeader()->setVisible(false);
	table->horizontalHeader()->setVisible(false);
	table->setItem(nr_linie, 0, new QTableWidgetItem("Nr."));
	table->setItem(nr_linie, 1, new QTableWidgetItem("Denumire"));
	table->setItem(nr_linie, 2, new QTableWidgetItem("Ore"));
	table->setItem(nr_linie, 3, new QTableWidgetItem("Tip"));
	table->setItem(nr_linie, 4, new QTableWidgetItem("Profesor"));

	nr_linie++;

	for (const auto& Disciplina : disciplina) {
		table->setItem(nr_linie, 0, new QTableWidgetItem(QString::number(nr_linie)));
		table->setItem(nr_linie, 1, new QTableWidgetItem(QString::fromStdString(Disciplina.get_denumire())));
		table->setItem(nr_linie, 2, new QTableWidgetItem(QString::number(Disciplina.get_ore())));
		table->setItem(nr_linie, 3, new QTableWidgetItem(QString::fromStdString(Disciplina.get_tip())));
		table->setItem(nr_linie, 4, new QTableWidgetItem(QString::fromStdString(Disciplina.get_profesor())));
		nr_linie++;
	}
}

void AppGUI::loadList(const vector<Disciplina>& discipline) {
	lista_contracte->clear();
	for (const auto& disciplina : discipline) {
		lista_contracte->addItem(QString::fromStdString(disciplina.get_denumire() + " - prof. " + disciplina.get_profesor()));
	}
}
void AppGUI::clearContractTextBox() {
	txtContractDenumire->clear();
	txtContractProfesor->clear();
}
void AppGUI::uiContractAdauga() {
	string denumire = txtContractDenumire->text().toStdString();
	string profesor = txtContractProfesor->text().toStdString();
	QMessageBox msg;
	msg.setWindowIcon(QIcon("icons/contract.jpg"));

	auto found = srv.filterDenumire(denumire);
	if (found.empty()) {
		msg.warning(contract, "Warning", "Disciplina nu exista in lista de discipline!");
		clearContractTextBox();
		return;
	}

	if (found.size() == 1) {
		try {
			srv.adauga_la_contract(denumire, found[0].get_profesor(), found);
		}
		catch (ContractException& mesaj) {
			msg.warning(contract, "Warning", QString::fromStdString(mesaj.get_mesaj()));
		}
		catch (RepoException& mesaj) {
			msg.warning(contract, "Warning", QString::fromStdString(mesaj.get_mesaj()));
		}
		catch (ValidatorException& mesaj) {
			msg.warning(contract, "Warning", QString::fromStdString(mesaj.get_mesaj()));
		}
	}
	else {
		if (profesor != "") {
			try {
				srv.adauga_la_contract(denumire, profesor, found);
			}
			catch (ContractException& mesaj) {
				msg.warning(contract, "Warning", QString::fromStdString(mesaj.get_mesaj()));
			}
			catch (RepoException& mesaj) {
				msg.warning(contract, "Warning", QString::fromStdString(mesaj.get_mesaj()));
			}
			catch (ValidatorException& mesaj) {
				msg.warning(contract, "Warning", QString::fromStdString(mesaj.get_mesaj()));
			}
		}
		else {
			msg.warning(contract, "Warning", "Introduceti profesorul!");
		}
	}
	clearContractTextBox();
	loadList(srv.getAllContract());
}

void AppGUI::clearTextBox() {
	txtDenumire->clear();
	txtOre->clear();
	txtTip->clear();
	txtProfesor->clear();
}

void AppGUI::uiAdauga() {
	string denumire = txtDenumire->text().toStdString();
	string ore = txtOre->text().toStdString();
	string tip = txtTip->text().toStdString();
	string profesor = txtProfesor->text().toStdString();
	QMessageBox msgBox;
	msgBox.setWindowIcon(QIcon("icons/school.jpeg"));

	qDebug() << denumire << profesor;
	
	int ore_corecte;
	try {
		ore_corecte = stoi(ore);
	}
	catch (std::invalid_argument& mesaj) {
		msgBox.warning(this, "Warning", "Orele trebuie sa fie un numar natural!");	
		return;
	}

	try {
		srv.adaugaSrv(denumire, ore_corecte, tip, profesor);
	}
	catch (RepoException& mesaj) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
	}
	catch (ValidatorException& mesaj) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
	}

	clearTextBox();
	loadTable(srv.getAll());

}

void AppGUI::uiSterge() {
	string denumire= txtDenumire->text().toStdString();
	string profesor = txtProfesor->text().toStdString();
	QMessageBox msgBox;
	msgBox.setWindowIcon(QIcon("icons/school.jpeg"));

	qDebug()<< denumire << profesor;
	
	try {
		srv.stergeSrv(denumire, profesor);
	}
	catch (RepoException& mesaj) {
		msgBox.warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
	}
	catch (ValidatorException& mesaj) {
		msgBox.warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
	}

	clearTextBox();
	loadTable(srv.getAll());
}

void AppGUI::uiModifica() {
	string denumire = txtDenumire->text().toStdString();
	string ore = txtOre->text().toStdString();
	string tip = txtTip->text().toStdString();
	string profesor = txtProfesor->text().toStdString();
	QMessageBox msgBox;
	msgBox.setWindowIcon(QIcon("icons/school.jpeg"));

	qDebug() << denumire << profesor;

	int ore_corecte;
	try {
		ore_corecte = stoi(ore);
	}
	catch (std::invalid_argument& mesaj) {
		msgBox.warning(this, "Warning", "Orele trebuie sa fie un numar natural!");
		return;
	}

	try {
		srv.modificaSrv(denumire, ore_corecte, tip, profesor);
	}
	catch (RepoException& mesaj) {
		msgBox.warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
	}
	catch (ValidatorException& mesaj) {
		msgBox.warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
	}

	clearTextBox();
	loadTable(srv.getAll());
}

void AppGUI::uiCauta() {
	string denumire = txtDenumire->text().toStdString();
	string profesor = txtProfesor->text().toStdString();
	QMessageBox msgBox;
	msgBox.setWindowIcon(QIcon("icons/school.jpeg"));

	qDebug() << denumire << profesor;

	try {
		Disciplina disciplina = srv.cautaSrv(denumire, profesor);
		qDebug() << disciplina.to_string_print();

		vector<Disciplina> discipline;
		discipline.push_back(disciplina);

		clearTextBox();
		loadTable(discipline);
	}
	catch (RepoException& mesaj) {
		msgBox.warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
	}
	catch (ValidatorException& mesaj) {
		msgBox.warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
	}
	txtDenumire->clear();
	txtProfesor->clear();

}

void AppGUI::uiSortDenumire() {
	vector<Disciplina> discipline = srv.sortDenumire();
	loadTable(discipline);
}

void AppGUI::uiSortOre() {
	vector<Disciplina> discipline = srv.sortOre();
	loadTable(discipline);
}

void AppGUI::uiSortProfTip() {
	vector<Disciplina> discipline = srv.sortProfTip();
	loadTable(discipline);
}


void AppGUI::uiFilterOre() {
	string ore = txtfilter->text().toStdString();
	int ore_corecte;
	QMessageBox msgBox;
	msgBox.setWindowIcon(QIcon("icons/school.jpeg"));

	try {
		ore_corecte = stoi(ore);
	}
	catch (std::invalid_argument& mesaj) {
		msgBox.warning(this, "Warning", "Input invalid!!");
		txtfilter->clear();
		return;
	}

	vector<Disciplina> discipline = srv.filterOre(ore_corecte);
	for (const auto& disciplina : discipline) {
		qDebug() << disciplina.to_string_print();
	}

	txtfilter->clear();
	loadTable(discipline);
}

void AppGUI::uiFilterProf() {
	string profesor = txtfilter->text().toStdString();
	qDebug() << profesor;

	vector<Disciplina> discipline = srv.filterProfesor(profesor);
	for (const auto& disciplina : discipline) {
		qDebug() << disciplina.to_string_print();
	}

	txtfilter->clear();
	loadTable(discipline);
}

void AppGUI::connectSignals() {
	QMessageBox msgBox;
	msgBox.setWindowIcon(QIcon("icons/school.jpeg"));

	QObject::connect(exit, &QPushButton::clicked, [&]() {
		QMessageBox exitMessageBox;
		exitMessageBox.setWindowIcon(QIcon("icons/bye.jpg"));

		exitMessageBox.setWindowTitle("Iesire");
		exitMessageBox.setText("La revedere!");

		exitMessageBox.exec();
		this->close();
		});

	QObject::connect(load, &QPushButton::clicked, [&]() {
		this->loadTable(srv.getAll());
		});

	QObject::connect(btn_adauga, &QPushButton::clicked, this, &AppGUI::uiAdauga);
	QObject::connect(btn_sterge, &QPushButton::clicked, this, &AppGUI::uiSterge);
	QObject::connect(btn_modifica, &QPushButton::clicked, this, &AppGUI::uiModifica);
	QObject::connect(btn_cauta, &QPushButton::clicked, this, &AppGUI::uiCauta);

	QObject::connect(sort_denumire, &QRadioButton::clicked, this, &AppGUI::uiSortDenumire);
	QObject::connect(sort_ore, &QRadioButton::clicked, this, &AppGUI::uiSortOre);
	QObject::connect(sort_proftip, &QRadioButton::clicked, this, &AppGUI::uiSortProfTip);

	QObject::connect(filtrare_ore, &QPushButton::clicked, this, &AppGUI::uiFilterOre);
	QObject::connect(filtrare_prof, &QPushButton::clicked, this, &AppGUI::uiFilterProf);

	QObject::connect(btn_undo, &QPushButton::clicked, [&]() {
		try {
			srv.undo();
		}
		catch (RepoException& mesaj) {
			msgBox.warning(this, "Warning", QString::fromStdString(mesaj.get_mesaj()));
		}

		loadTable(srv.getAll());
		});

	QObject::connect(btn_contract, &QPushButton::clicked, [&]() {
		contract->show();
		});

	QObject::connect(btn_contract_exit, &QPushButton::clicked, [&]() {
		contract->close();
		});

	QObject::connect(btn_contract_sterge, &QPushButton::clicked, [&]() {
		srv.empty_contract();
		loadList(srv.getAllContract());
		});
	QMessageBox mesajContract;
	mesajContract.setWindowIcon(QIcon("icons/contract.jpg"));

	QObject::connect(btn_contract_genereaza, &QPushButton::clicked, [&]() {
		string nr_discipline = txtContractNumar->text().toStdString();
		int nr_discipline_corecte;
		try {
			nr_discipline_corecte = stoi(nr_discipline);
		}
		catch (std::invalid_argument& mesaj) {
			txtContractNumar->clear();
			mesajContract.warning(contract, "Warning", "Numarul de discipline trebuie sa fie un numar natural!");
			return;
		}
		try {
			srv.genereaza_contract(nr_discipline_corecte);
		}
		catch (ContractException& mesaj) {
			mesajContract.warning(contract, "Warning", QString::fromStdString(mesaj.get_mesaj()));
		}
		txtContractNumar->clear();
		loadList(srv.getAllContract());
		});

	QObject::connect(btn_contract_adauga, &QPushButton::clicked, this, &AppGUI::uiContractAdauga);
	QObject::connect(btn_contract_export, &QPushButton::clicked, [&]() {
		string nume_fisier = txtContractFile->text().toStdString();
		srv.exporta_contract(nume_fisier);
		txtContractFile->clear();
		});
}
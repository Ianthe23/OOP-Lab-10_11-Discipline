#ifndef MYTABLEMODEL_H_
#define MYTABLEMODEL_H_

#include <QAbstractTableModel>
#include <QAbstractItemView>
#include <iostream>
#include <vector>

#include "domain.h"
using std::vector;

class MyTableModel : public QAbstractTableModel {
	vector<Disciplina> discipline;
public:
	MyTableModel(const vector<Disciplina>& discipline) : discipline{ discipline } {}

	int rowCount(const QModelIndex& parent = QModelIndex{}) const override {
		return discipline.size();
	}

	int columnCount(const QModelIndex& parent = QModelIndex{}) const override {
		return 4;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole) {
			const Disciplina& d = discipline[index.row()];
			switch (index.column()) {
			case 0:
				return QString::fromStdString(d.get_denumire());
			case 1:
				return QString::number(d.get_ore());
			case 2:
				return QString::fromStdString(d.get_tip());
			case 3:
				return QString::fromStdString(d.get_profesor());
			default:
				break;
			}
		}
		return QVariant{};
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
			switch (section) {
			case 0:
				return "Denumire";
			case 1:
				return "Ore";
			case 2:
				return "Tip";
			case 3:
				return "Profesor";
			default:
				break;
			}
		}
		else if (role == Qt::DisplayRole && orientation == Qt::Vertical) {
			return section + 1;
		}
		return QVariant{};
	}
	Disciplina getdisciplina(const vector<Disciplina>& discipline) {
		this->discipline = discipline;
		QModelIndex topLeft = createIndex(0, 0);
		QModelIndex bottomRight = createIndex(rowCount(), columnCount());
		emit dataChanged(topLeft, bottomRight); // notify ca la observer
		emit layoutChanged();
	}
};

#endif // MYTABLEMODEL_H_
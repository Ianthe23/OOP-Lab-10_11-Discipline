#ifndef MYLISTMODEL_H_
#define MYLISTMODEL_H_

#include <QAbstractListModel>
#include <vector>
#include <service.h>
#include <sstream>

using namespace std;

class MyListModel : public QAbstractListModel {
	vector<Disciplina> discipline;
public:
	MyListModel(const vector<Disciplina>& discipline) : discipline{ discipline } {}

	int rowCount(const QModelIndex& parent = QModelIndex{}) const override {
		return discipline.size();
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole) {
			const Disciplina& d = discipline[index.row()];
			stringstream ss;
			ss << d.get_denumire() << " - prof. " << d.get_profesor();
			return QString::fromStdString(ss.str());
		}
		if (role == Qt::UserRole) {
			const Disciplina& d = discipline[index.row()];
			return QString::fromStdString(d.to_string_print());
		}
		return QVariant{};
	}
};

#endif // MYLISTMODEL_H_

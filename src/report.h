//
// Created by xueke on 2021/10/31.
//

#ifndef CHECK_LAADS_ORDER_REPORT_H
#define CHECK_LAADS_ORDER_REPORT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class report;
}
QT_END_NAMESPACE

class report : public QWidget {
 Q_OBJECT
 public:
  report(QString _order_dir,
	  QString  _order_sn,
		 QStringList  _error_files,
		 QStringList  _missing_files,
		 QStringList  _extra_files);

  ~report() override;

 private:
  QString order_dir;
  QString order_sn;
  QStringList error_files;
  QStringList missing_files;
  QStringList extra_files;
  Ui::report *ui;
 private:
  void set_content();
 private slots:
  void create_downloadable_files_link();


};

#endif //CHECK_LAADS_ORDER_REPORT_H

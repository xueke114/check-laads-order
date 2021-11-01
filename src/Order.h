//
// Created by Xueke on 2021/10/29.
//

#ifndef CHECK_LAADS_ORDER_ORDER_H
#define CHECK_LAADS_ORDER_ORDER_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <QObject>
#include <QProgressDialog>
#include <QTimer>
#include "report.h"

#ifdef Q_OS_WINDOWS
#define posix_memalign(p, a, s) \
  (((*(p)) = _aligned_malloc((s), (a))), *(p) ? 0 : errno)
#endif

class Order : public QObject {
 Q_OBJECT
 public:
  Order(QString local_order_dir, QString checksum_file);

  QString get_order_sn() { return order_sn; };

  int get_order_file_number() { return order_files_package.size(); };

  int get_local_file_number() { return local_files_list.size(); };

  bool get_check_result();

  bool calculate_local_cksum();

  void show_report();

 private:
  QString order_sn;
  QMap<QString, QString> order_files_package;
  QStringList local_files_list;
  QMap<QString, QString> local_files_package;

  bool calculate_status;

  QStringList match_files;
  QStringList error_files;
  QStringList missing_files;
  QStringList extra_files;

  report *this_order_report;

 private:
  uint32_t get_file_cksum(FILE *fp);

  void parsing_checksum_file(QString cksum_file);

  void parsing_local_file(QString order_dir);

// 通过对比从cksum文件中提取的文件名和cksum值与从本地文件统计得到的文件名和cksum值
// 筛选出
// 缺失文件——cksum文件中有而本地没有的文件；
// 错误文件——cksum值不匹配的文件；
// 多余文件——本地有而cksum文件中没有的文件
  void compare_cksum();
};

#endif //CHECK_LAADS_ORDER_ORDER_H

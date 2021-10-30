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

#ifdef Q_OS_WINDOWS
#define posix_memalign(p, a, s) \
  (((*(p)) = _aligned_malloc((s), (a))), *(p) ? 0 : errno)
#endif


class Order:public QObject{
Q_OBJECT
public:
    Order(QString local_order_dir, QString checksum_file);

    QString get_order_sn() { return order_sn; };

    int get_order_file_number() { return order_files_package.size(); };

    int get_local_file_number() { return local_files_list.size(); };

    void calculate_local_cksum();
private:
    QString order_sn;
    QMap<QString, QString> order_files_package;
    QStringList local_files_list;
    QMap<QString, QString> local_files_package;

    uint32_t get_file_cksum(FILE *fp);

    void parsing_checksum_file(QString cksum_file);

    void parsing_local_file(QString order_dir);



    void compare_cksum();
};


#endif //CHECK_LAADS_ORDER_ORDER_H
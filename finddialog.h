//マクロはコンパイラを通る前にプリプロセッサによって正当なC++の構文に変換されます


//複数回includeされるのを防ぐ
#ifndef FINDDIALOG_H
#define FINDDIALOG_H
//QDialogはQWidgetを敬称している
#include    <QDialog>

//クラスの存在をコンパイラーに伝える
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

//FindDialogクラスをQDialogのサブクラスとして宣言する.
class FindDialog : public QDialog
{
    Q_OBJECT    //Q_OBJECTマクロはシグナルとスロットを定義する場合必ず宣言しなくてはいけない
    public:
        FindDialog(QWidget *parent = 0);    //parentパラメータで親ウィジェットを指定しています。
                                            //デフォルト値0     これはこのダイアログが親を持たないことを意味している
    
    signals:
        //signal（マクロ）宣言
        //ユーザがfindボタンをクリックしたときにシグナルを2つ送信します
        //Search backwradオプションが指定された場合はfindPrev()シグナル/そうでなければfindNext()シグナル送信
        void findNext(const QString &str , Qt :: CaseSensitivity cs);
        void findPrevios(const QString &str , Qt :: CaseSensitivity cs);

    private slots:
        void findClicked();
        void enableFindButton(const QString &text);

    private:
        QLabel      *label;
        QLineEdit   *lineEdit;
        QCheckBox   *caseCheckBox;
        QCheckBox   *backwardChackBox;
        QPushButton *findButton;
        QPushButton *closeButton;
};
#endif

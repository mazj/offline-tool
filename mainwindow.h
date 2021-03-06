#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>

#include <QStandardItemModel>
#include <QModelIndex>
#include <QMap>
#include <QSet>

#include <QEvent>

#include "entities.h"
#include "utils.h"
#include "parser/importfilexmlparser.h"
#include "generator/exportcronossitexmlgenerator.h"
#include "parser/importxmlvalidator.h"

#include "dialog/logindialog.h"
#include "dialog/selecttimezonedialog.h"
#include "dialog/aboutdialog.h"
#include "dialog/selectsitedialog.h"

#include "widget/comboboxwithcheckboxes.h"
#include "widget/table/proxymodelwithheadermodels.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum TableCellDataType
    {
        SWP_ID = 1001,
        PHASE_ID,
        CL_ITEM_ID,
        PLANNING_TOOL_ID,
        ISSUE_ID
    };

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initialize();
    void initializeViewTable();
    void loadFilterData();
    void loadDictionaryData();

    void clearIssueLog();
    void updateIssueLogStatus(bool isDisabled, bool clearData);
    void updateChecklistItemStatus(bool isDisabled);
    void updateVisabilityOfSiteDetailsSection(bool isDisabled, bool clearData);
    void updateSiteDetailsSection(QSharedPointer<Site> site, QSharedPointer<ChecklistItem> checklistItem);
    void createIssue();
    void updateIssue();
    void createRollbackIssue();
    void timerEvent(QTimerEvent *event);

    void reloadIssueList(QSharedPointer<Checklist> checklist);

private slots:
    void importValidationStatus(bool errorOccurred, ImportXmlFileValidationMessageHandler *messageHandler);
    void on_browseFileButton_clicked();
    void on_exportButton_clicked();
    void onTableClicked(const QModelIndex &index);
    void on_quickDate_clicked(bool checked);
    void on_projectComboBox_activated(int index);
    void on_wpComboBox_activated(int index);
    void on_phaseComboBox_activated(int index);
    void on_actionAbout_triggered();
    void on_actionSelect_Time_Zone_triggered();
    void on_actionExit_triggered();
    void on_clItemUpdateButton_clicked();
    void on_planningToolsValue_activated(int index);
    void on_issueRegularCheckbox_clicked(bool checked);
    void on_issueRollbackCheckbox_clicked(bool checked);
    void planningToolClicked(bool checked);

    void on_issueList_activated(int index);

    void on_issueUpdateButton_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *currentTimeLabel;
    QLabel *selectedTimeZoneLabel;
    QProgressBar *stateProgress;

    LoginDialog *loginDialog;
    SelectSiteDialog *selectSiteDialog;
    SelectTimeZoneDialog *selectTimeZoneDialog;
    AboutDialog *aboutDialog;

    QStandardItemModel *headerModel;
    QStandardItemModel *verticalHeaderModel;
    QStandardItemModel *dataModel;
    ProxyModelWithHeaderModels *proxyModel;
    HierarchicalHeaderView *headerView;

    QStandardItemModel *model;
    QStandardItemModel *planningToolsModel;

    bool importFailed;
    ImportXmlValidator *validator;
    ImportFileXmlParser *parser;
    ExportCronosSiteXmlGenerator *generator;
    QString schemaText;

    Dictionary dictionary;
    QList<QSharedPointer<Site>> sites;
    QList<QSharedPointer<Site>> sitesToView;
    QList<QSharedPointer<Site>> updatedSites;

    QString userName;
    QSharedPointer<Site> selectedSite;
    QSharedPointer<Checklist> selectedChecklist;
    QSharedPointer<ChecklistItem> selectedChecklistItem;
    QSharedPointer<Issue> selectedIssue;

    int timerId;
    bool quickDateInsert;
    QTimeZone selectedTimeZone;

    static constexpr const char* DATE_FORMAT = "dd/MM/yyyy";
    static constexpr const char* TIME_FORMAT = "hh:mm:ss";
    static constexpr const char* DATE_TIME_FORMAT = "dd/MM/yyyy hh:mm:ss";
};

#endif // MAINWINDOW_H

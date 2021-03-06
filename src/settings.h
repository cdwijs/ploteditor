#ifndef SETTINGS_H
#define SETTINGS_H

#include "pch.h"
#include "settings_data.h"

namespace Ui {
class Settings;
}  // namespace Ui

class Settings : public QWidget {
  Q_OBJECT

 public:
  explicit Settings(QWidget *parent = 0);
  ~Settings();

 public:
  QString GetNpcFilePath();
  QString GetSceneFilePath();
  QString GetPlotFilePath();
  QString GetMissionFilePath();

 private:
  // bind the buttons' actions
  void BindActions();

  void SetQLineTextPalette(QLineEdit *, const QString &);

  void LoadSettings();

  void IsHexColroStr(const QString &);

 private slots:
  // ui panel browser the npc file path.
  void FindNpcFilePath();

  // ui panel browser the plot file path.
  void FindPlotFilePath();

  // ui panel browser the scene file path.
  void FindSceneFilePath();

  // ui panel browser the mission file path.
  void FindMissionFilePath();

  void OnNpcFilePathChanged(const QString &);
  void OnPlotFilePathChanged(const QString &);
  void OnSceneFilePathChanged(const QString &);
  void OnMissionFilePathChanged(const QString &);

  void OnColor1Changed(const QString &);
  void OnColor2Changed(const QString &);
  void OnColor3Changed(const QString &);
  void OnColor4Changed(const QString &);
  void OnColor5Changed(const QString &);

 private:
  QString npc_file_path_;
  QString plot_file_path_;
  QString scene_file_path_;
  QString mission_file_path_;

  QString color1_name_;
  QString color2_name_;
  QString color3_name_;
  QString color4_name_;
  QString color5_name_;

 private:
  Ui::Settings *ui;

  SettingsData *settings_data_;
  QRegularExpression *color_hex_checker_;
};

#endif  // SETTINGS_H

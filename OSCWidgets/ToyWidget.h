// Copyright (c) 2016 Electronic Theatre Controls, Inc., http://www.etcconnect.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once
#ifndef TOY_WIDGET_H
#define TOY_WIDGET_H

#ifndef QT_INCLUDE_H
#include "QtInclude.h"
#endif

class EditButton;
class OSCArgument;
class EosLog;

////////////////////////////////////////////////////////////////////////////////

class ToyWidget
	: public QWidget
{
	Q_OBJECT
	
public:
	enum EnumMode
	{
		MODE_DEFAULT,
		MODE_EDIT
	};
	
	ToyWidget(QWidget *parent);
	virtual ~ToyWidget() {}
	
	virtual QWidget* GetWidget() {return m_Widget;}
	virtual EnumMode GetMode() const {return m_Mode;}
	virtual void SetMode(EnumMode mode);
	virtual bool GetVisible() const {return m_Visible;}
	virtual void SetVisible(bool b);
	virtual bool HasVisible() const {return true;}
	virtual void UpdateVisible();
	virtual const QString& GetPath() const {return m_Path;}
	virtual void SetPath(const QString &path);
	virtual bool HasPath() const {return true;}
	virtual const QString& GetPath2() const {return m_Path2;}
	virtual void SetPath2(const QString &path);
	virtual bool HasPath2() const {return false;}
	virtual const QString& GetRecvPath() const {return m_RecvPath;}
	virtual void SetRecvPath(const QString &recvPath);
	virtual const QString& GetFeedbackPath() const {return m_FeedbackPath;}
	virtual void SetFeedbackPath(const QString &feedbackPath);
	virtual bool HasFeedbackPath() const {return false;}
	virtual const QString& GetText() const {return m_Text;}
	virtual void SetText(const QString &text) {m_Text = text;}
	virtual const QString& GetImagePath() const {return m_ImagePath;}
	virtual void SetImagePath(const QString &imagePath) {m_ImagePath = imagePath;}
	virtual const QColor& GetColor() const {return m_Color;}
	virtual void SetColor(const QColor &color) {m_Color = color;}
	virtual const QColor& GetTextColor() const {return m_TextColor;}
	virtual void SetTextColor(const QColor &textColor) {m_TextColor = textColor;}
	virtual bool GetSelected() const;
	virtual void SetSelected(bool selected);
	virtual const QString& GetMin() const {return m_Min;}
	virtual void SetMin(const QString &n) {m_Min = n;}
	virtual const QString& GetMax() const {return m_Max;}
	virtual void SetMax(const QString &n) {m_Max = n;}
	virtual bool HasMinMax() const {return true;}
	virtual const QString& GetMin2() const {return m_Min2;}
	virtual void SetMin2(const QString &n) {m_Min2 = n;}
	virtual const QString& GetMax2() const {return m_Max2;}
	virtual void SetMax2(const QString &n) {m_Max2 = n;}
	virtual bool HasMinMax2() const {return false;}
	virtual const QString& GetBPM() const {return m_BPM;}
	virtual void SetBPM(const QString &bpm) {m_BPM = bpm;}
	virtual bool HasBPM() const {return false;}
	virtual const QString& GetHelpText() const {return m_HelpText;}
	virtual void SetToggle(const bool toggle){m_toggle = toggle;}
	virtual bool HasToggle() const {return false;}
	
	virtual void SetLabel(const QString &label);
	virtual void Recv(const QString &path, const OSCArgument *args, size_t count);
	virtual bool Save(EosLog &log, const QString &path, QStringList &lines);
	virtual bool Load(EosLog &log, const QString &path, QStringList &lines, int &index);
	
signals:
	void edit(ToyWidget*);
	
private slots:
	void onEditButtonClicked(bool checked);

protected:
	EnumMode	m_Mode;
	bool		m_Visible;
	QString		m_Path;
	QString		m_Path2;
	QString		m_RecvPath;
	QString		m_FeedbackPath;
	QString		m_Text;
	QString		m_ImagePath;
	QColor		m_Color;
	QColor		m_TextColor;
	QWidget		*m_Widget;
	QString		m_Min;
	QString		m_Max;
	QString		m_Min2;
	QString		m_Max2;
	QString		m_BPM;
	EditButton	*m_EditButton;
	QString		m_HelpText;
	bool		m_toggle;
	bool		m_visible;
	
	virtual void resizeEvent(QResizeEvent *event);
	virtual void UpdateMode();
	virtual void UpdateToolTip();
};

////////////////////////////////////////////////////////////////////////////////

#endif

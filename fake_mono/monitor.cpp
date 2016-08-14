#include "stdafx.h"
#include "monitor.h"
#include "stats.h"
#include "log.h"

#include "common/stl_helpers.h"

#include "executor_control.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QEvent>

namespace monitor
{

namespace
{

    struct post_event
        : QEvent
    {
        static const QEvent::Type id = QEvent::Type(QEvent::User + 1);
        
        post_event(post_f const &f)
            : QEvent(id)
            , f(f)
        {}

        post_f f;
    };

    void fuck(post_f const &callback)
    {
        post(callback);
    }

    struct monitor_widget
        : QWidget
    {
        monitor_widget(executor_control *control)
            : control_(control)
        {
            auto layout = new QVBoxLayout(this);

            btn_ = new QPushButton("Init watcher");

            connect(btn_, &QPushButton::clicked, boost::bind(&monitor_widget::btn_clicked, this));

            label_ = new QTextEdit();
            layout->addWidget(btn_);
            layout->addWidget(label_);

        }
        
        bool event(QEvent* e) override
        {
            if (e->type() == post_event::id)
            {
                auto e_cast = static_cast<post_event*>(e);
                e_cast->f();
                return true;
            }
            else
            {
                return QWidget::event(e);
            }
        }

        void print(string const &str)
        {
            label_->setText(QString::fromStdString(str));
        }

        void btn_clicked()
        {
            control_->init_watcher();
            btn_->setDisabled(true);
        }

    private:
        QTextEdit *label_ = nullptr;
        QPushButton *btn_ = nullptr;
        executor_control *control_;
    };

    std::unique_ptr<monitor_widget> g_monitor;

    void print_impl(string const &str)
    {
        g_monitor->print(str);
    }

}

void run(executor_control *control)
{
    int argv = 0;
    QApplication app(argv, nullptr);

    g_monitor = std::make_unique<monitor_widget>(control);
    g_monitor->show();
    app.exec();
}

void post(post_f const &f)
{
    QCoreApplication::postEvent(g_monitor.get(), new post_event(f));
}


void print(string const &str)
{
    log_stream() << str << std::flush;
    post(std::bind(print_impl, str));
}

} // namespace monitor
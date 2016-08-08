#include "stdafx.h"
#include "monitor.h"
#include "stats.h"

#include "common/stl_helpers.h"

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

    void fuck()
    {
        int aaa = 5;
    }

    struct monitor_widget
        : QWidget
    {
        monitor_widget(post_service_f const &post_service)
            : post_service_(post_service)
        {
            auto layout = new QVBoxLayout(this);

            auto btn = new QPushButton("Click me!");

            connect(btn, &QPushButton::clicked, 
                [this]()
            {
                post_service_(&fuck);
            });

            label_ = new QTextEdit();
            layout->addWidget(btn);
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

    private:
        QTextEdit *label_ = nullptr;
        post_service_f post_service_;
    };

    std::unique_ptr<monitor_widget> g_monitor;

    void print_impl(string const &str)
    {
        g_monitor->print(str);
    }

}

void run(post_service_f const &post_service)
{
    int argv = 0;
    QApplication app(argv, nullptr);

    g_monitor = std::make_unique<monitor_widget>(post_service);
    g_monitor->show();
    app.exec();
}

void post(post_f const &f)
{
    QCoreApplication::postEvent(g_monitor.get(), new post_event(f));
}


void print(string const &str)
{
    post(std::bind(print_impl, str));
}

} // namespace monitor
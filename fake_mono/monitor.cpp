#include "stdafx.h"
#include "monitor.h"

#include "stl_helpers.h"

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

    struct monitor_widget
        : QWidget
    {
        monitor_widget()
        {
            auto layout = new QVBoxLayout(this);

            label_ = new QTextEdit();
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
    };

    std::unique_ptr<monitor_widget> g_monitor;

    void print_stats(stats_t const &st)
    {
        if (st.empty())
            return;
        
        typedef std::pair<stats_key_t, int> stats_record_t;
        auto cmp = [](stats_record_t const &a, stats_record_t const &b)
        {
            return a.second > b.second;
        };

        vector<stats_record_t> sorted = stl_helpers::container_from_range(st);
        boost::sort(sorted, cmp);

        std::stringstream ss;

        for (auto const &r : sorted)
            ss << r.first.first << "." << r.first.second << ": " << r.second << "\n";
        g_monitor->print(ss.str());
    }
}

void run()
{
    int argv = 0;
    QApplication app(argv, nullptr);

    g_monitor = std::make_unique<monitor_widget>();
    g_monitor->show();
    app.exec();
}

void post(post_f const &f)
{
    QCoreApplication::postEvent(g_monitor.get(), new post_event(f));
}


void update_stats(stats_t const &st)
{
    post(std::bind(print_stats, st));
}

} // namespace monitor
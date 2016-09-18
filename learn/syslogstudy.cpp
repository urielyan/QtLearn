#include "syslogstudy.h"

#include <syslog.h>
SyslogStudy::SyslogStudy(QWidget *parent) : QWidget(parent)
{
    openlog("yangeTest", 0, LOG_AUTH);
    syslog(LOG_INFO, "test");
    closelog();
}


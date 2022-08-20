#include <iostream>
using namespace std;
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
 
 
int main()
{
	//Step 1  实例化Layout对象、Appender对象、Category对象
	log4cpp::Layout    *layout    =  new log4cpp::BasicLayout;
	log4cpp::Appender  *appender  =  new log4cpp::OstreamAppender("default", &std::cout);
	//log4cpp::Appender  *appender  =  new log4cpp::FileAppender("File", "test.txt");
	log4cpp::Category  &log      =  log4cpp::Category::getInstance("test");
 
 
	//Step 2  把Layout对象附着到Appender对象上，把Appender对象附着到Category对象上
	appender->setLayout(layout);
	log.addAppender(appender);
 
 
	//Step 3  设置Category的优先级
	log.setPriority(log4cpp::Priority::DEBUG);
	
	log.alert("DEBUG emerg.");
	log.log(log4cpp::Priority::ALERT, "DEBUG alert.");
	log.error("DEBUG error.");
	log.info("DEBUG warn.");
	log.log(log4cpp::Priority::INFO, "DEBUG info.");
	log.debug("DEBUG debug.");
 
	//
	log.setPriority(log4cpp::Priority::ERROR);
 
	log.alert("ERROR emerg.");
	log.log(log4cpp::Priority::ALERT, "ERROR alert.");
	log.error("ERROR error.");
	log.info("ERROR warn.");
	log.log(log4cpp::Priority::INFO, "ERROR info.");
	log.debug("ERROR debug.");
	
	
 
	log4cpp::Category::shutdown();
 
	return 0;
}

//编译命令  g++ main.cpp -llog4cpp -lpthread
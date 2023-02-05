/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：mysql.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：2021年02月10日
*   描    述：链接mysql
*
#pragma once
================================================================*/
#include <iostream>
#include <Winsock.h>
#include "inherit.cpp"
#include "../tools/mysqlcon8032/include/mysql/jdbc.h"

#if 0
#endif
int main()
{
	MYSQL* con = mysql_init(NULL);
	return 0;
}

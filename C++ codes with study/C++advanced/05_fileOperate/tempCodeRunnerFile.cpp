string buf;
    while(getline(ifs, buf)){ //这些函数都会返回是否后面还有可读内容，如果没有就会返回false ，从而就退出了循环
        cout<<buf<<endl;
    }
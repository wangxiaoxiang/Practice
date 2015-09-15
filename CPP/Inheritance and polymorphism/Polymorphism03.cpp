//  Created by 汪潇翔 on 15/8/20.
//  Copyright (c) 2015年 汪潇翔. All rights reserved.
//

#include <iostream>
using namespace std;

#pragma mark - UParser
class UParser {
    virtual void on_text() = 0;
    virtual void on_image() = 0;
public:
    void parser(const char* file_name)
    {
        this->on_text();
        this->on_image();
    }
};

#pragma mark - UMarkdownParser
class UMarkdownParser: public UParser
{
    void on_text()
    {
        cout<<"MarkdownParser::on_text()"<<endl;
    }
    void on_image()
    {
        cout<<"MarkdownParser::on_image()"<<endl;
    }
public:

};

#pragma mark - main function
int main(int argc, const char * argv[]) {
    UMarkdownParser parser;
    parser.parser("/2015-02-01-多态.md");
    /*
     MarkdownParser::on_text()
     MarkdownParser::on_image()
     */
    return 0;
}

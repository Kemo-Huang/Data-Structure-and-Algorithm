// String.h
class String {
public:
    String (char* str=NULL);
    String (String& another);
    ~String();
    String &operator=(String &str);
private:
    char* data=new char[0];
    unsigned length=0;
}
// String.cpp
String::String(char* str){
    if (str){
        unsigned n = 0;
        while(str[n]!='\0') n++;
        length = n;
        data = new char[n];
        for (int i = 0; i < n; i++){
            data[i] = str[i];
        }
    } else {
        len = 0;
        data = new char[0];
    }
}
String::String(String &another){
    length = another.length;
    data = new char[length];
    for (int i = 0; i < length; i++){
        data[i] = another.data[i];
    }
}
String::~String(){
    delete[] data;
}
String::&operator=(String &s){
    if (this == &s) return *this;
    delete[] data;
    length = s.length;
    for (int i = 0; i < length; i++){
        data[i] = s.data[i];
    }
    return *this;
}

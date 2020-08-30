 #include <stdio.h>//remove

    #include <io.h>

    #include <sys/stat.h>// get file info

   #include <time.h>

   

   #include <iostream>

   using namespace std;

   

   int main(int argc, char* argv[])

   {

       printf("Hello World!\n");

       int iresult;

       struct _stat buf; //in stat head file

       //_FILE__ means the current file. you can assign another file name. IE D:\\QQ文件管理\\Documents\\000.txt"￡?           //获取操作目录

       iresult = _stat(__FILE__,&buf);

       //the seconds from Greenwich 1970-1-1 to now.

       printf("seconds of file create-time  from 1970 :%d\n", buf.st_atime);

      //convert to our define format

      //struct tm *localtime(long *clock)

      long* m_sencodes = &buf.st_atime;

      struct tm* m_localTime = localtime(m_sencodes);

      printf("file Local time : %d:%d:%d\n", m_localTime->tm_hour,m_localTime->tm_min, m_localTime->tm_sec);  

       //Get the current time

       //

       long* mptr_currentSeconds = new long;

       time(mptr_currentSeconds);

       printf("current seconds from 1970 :%d\n", *mptr_currentSeconds);

       m_localTime = localtime(mptr_currentSeconds);

       printf("current Local time : %d:%d:%d\n", m_localTime->tm_hour,m_localTime->tm_min, m_localTime->tm_sec); 

       //compare the two times￡?second

       //double difftime(time_t time2,time_t time1)

      long diffSeconds = difftime(*mptr_currentSeconds, *m_sencodes);

       const int SECONDS_OF_DAY= 86400;

      //how many days?

       int diffDays = diffSeconds/SECONDS_OF_DAY;

       printf("diff time seconds: %d, days: %d\n", diffSeconds, diffDays);

      delete mptr_currentSeconds;

       //ok, now we will list all files in one folder

      struct _finddata_t c_file;

      long hFile;

      if ( (hFile = _findfirst("*.*", &c_file)) == -1L )

          printf("No *.* files in current directory");

       else

      {
          do
         {

               //we show files except sub-directory

               if (c_file.attrib != _A_SUBDIR)

              {

                  printf("%s\n", c_file.name);

              }            

           }         while ( _findnext(hFile, &c_file) == 0 ) ;

              
           _findclose(hFile);

      }
 
       cin.get();

       return 0;

   }

 


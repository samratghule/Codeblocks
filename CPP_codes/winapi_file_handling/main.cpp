#include<iostream>
#include <Windows.h>

using namespace std;
std::string filetext = "File handling test application for testing";
DWORD bytesWritten;
int main()
{
   // Open a handle to the file
   HANDLE hFile = CreateFile(
      "D:\\NewFile21.txt",     // Filename
      GENERIC_WRITE,          // Desired access
      FILE_SHARE_READ,        // Share mode
      NULL,                   // Security attributes
      CREATE_NEW,             // Creates a new file, only if it doesn't already exist
      FILE_ATTRIBUTE_NORMAL,  // Flags and attributes
      NULL);

   if (hFile == INVALID_HANDLE_VALUE)
   {
      cout<<"create file failed\n"<<GetLastError()<<endl;

   }
      cout<<"create file success\n"<<GetLastError()<<endl;
   // Write data to the file
  // std::string strText = "Hello World!"; // For C use LPSTR (char*) or LPWSTR (wchar_t*)

   WriteFile(
      hFile,            // Handle to the file
      filetext.c_str(),  // Buffer to write
      filetext.size(),   // Buffer size
      &bytesWritten,    // Bytes written
      NULL);         // Overlapped

   // Close the handle once we don't need it.
   CloseHandle(hFile);
   system("PAUSE");
   return 0;
}

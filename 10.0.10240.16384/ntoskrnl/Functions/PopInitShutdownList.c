// PopInitShutdownList 
 
int PopInitShutdownList()
{
  int result; // r0

  PopShutdownEvent = 0;
  byte_61F401 = 0;
  byte_61F402 = 4;
  dword_61F404 = 0;
  dword_61F40C = (int)&dword_61F408;
  dword_61F408 = (int)&dword_61F408;
  PopShutdownThreadList = 0;
  PopShutdownQueue = (int)&PopShutdownQueue;
  dword_61F44C = (int)&PopShutdownQueue;
  PopShutdownListMutex = 1;
  dword_61F424 = 0;
  unk_61F428 = 0;
  byte_61F42C = 1;
  byte_61F42D = 0;
  byte_61F42E = 4;
  dword_61F430 = 0;
  dword_61F438 = (int)&dword_61F434;
  dword_61F434 = (int)&dword_61F434;
  result = 0;
  PopShutdownListAvailable = 1;
  return result;
}

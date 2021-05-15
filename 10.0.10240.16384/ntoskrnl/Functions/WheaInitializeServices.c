// WheaInitializeServices 
 
int WheaInitializeServices()
{
  int result; // r0

  result = WheapSetDefaultErrorSourceConfiguration();
  WheapPfaLock = 0;
  WheapPfaList = (int)&WheapPfaList;
  *(_DWORD *)algn_64A0A4 = &WheapPfaList;
  __dmb(0xFu);
  WheapPfaInitialized = 1;
  WheapTriageDumpLock = 1;
  dword_619804 = 0;
  unk_619808 = 0;
  byte_61980C = 1;
  byte_61980D = 0;
  byte_61980E = 4;
  dword_619810 = 0;
  dword_619818 = (int)&dword_619814;
  dword_619814 = (int)&dword_619814;
  return result;
}

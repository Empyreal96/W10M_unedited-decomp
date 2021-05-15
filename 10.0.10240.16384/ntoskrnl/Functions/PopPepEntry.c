// PopPepEntry 
 
int PopPepEntry()
{
  int result; // r0

  PopPepDeviceListLock = 0;
  PopPepDeviceList = (int)&PopPepDeviceList;
  dword_61E4DC = (int)&PopPepDeviceList;
  dword_61E568 = (int)PopPepIdleTimeoutRoutine;
  dword_61E56C = 0;
  PopPepIdleWorkItem = 0;
  PopPepIdleDpc = 19;
  byte_61E501 = 1;
  word_61E502 = 0;
  dword_61E50C = (int)PopPepIdleTimeoutDpcRoutine;
  dword_61E510 = 0;
  dword_61E51C = 0;
  dword_61E508 = 0;
  KeInitializeTimerEx(PopPepIdleTimer, 1);
  result = 0;
  PopPepVetoMaskReadyLock = 0;
  return result;
}

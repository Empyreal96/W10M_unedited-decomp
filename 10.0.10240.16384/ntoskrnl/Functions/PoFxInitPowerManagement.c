// PoFxInitPowerManagement 
 
int PoFxInitPowerManagement()
{
  _DWORD *v0; // r0

  PopFxDeviceList = (int)&PopFxDeviceList;
  dword_61F4D4 = (int)&PopFxDeviceList;
  PopFxPluginList = (int)&PopFxPluginList;
  *(_DWORD *)algn_61F4E4 = &PopFxPluginList;
  PopFxAcpiDeviceList = (int)&PopFxAcpiDeviceList;
  dword_61F4CC = (int)&PopFxAcpiDeviceList;
  PopFxDeviceRegisterHead = (int)&PopFxPluginList;
  PopFxDeviceListLock = 0;
  PopFxPluginLock = 0;
  dword_61F548 = (int)PopFxResidentTimeoutRoutine;
  dword_61F54C = 0;
  PopFxResidentWorkItem = 0;
  PopFxResidentDpc = 19;
  byte_61F561 = 1;
  word_61F562 = 0;
  dword_61F56C = (int)PopFxResidentTimeoutDpcRoutine;
  dword_61F570 = 0;
  dword_61F57C = 0;
  dword_61F568 = 0;
  v0 = KeInitializeTimerEx(PopFxResidentTimer, 1);
  PopFxActiveIdleThreshold *= 10000;
  if ( (unsigned int)PopFxActiveIdleLevel < 3 )
    JUMPOUT(0x96E584);
  return sub_96E580(v0);
}

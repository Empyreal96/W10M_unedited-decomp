// IopInitializePassiveInterruptServices 
 
int IopInitializePassiveInterruptServices()
{
  IopQueryPassiveInterruptRegistryOptions();
  PassiveInterruptList = (int)&PassiveInterruptList;
  dword_630C84 = (int)&PassiveInterruptList;
  PassiveInterruptListLock = 0;
  KeInitializeQueue((int)&PassiveInterruptRealtimeWorkQueue, (unsigned __int8)PassiveInterruptRealtimeWorkerCount);
  return IopCreatePassiveInterruptRealtimeThreads();
}

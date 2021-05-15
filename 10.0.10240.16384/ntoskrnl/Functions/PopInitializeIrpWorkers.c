// PopInitializeIrpWorkers 
 
int PopInitializeIrpWorkers()
{
  int result; // r0
  int v1; // r4

  PopCreateIrpWorkerAllowed = 1;
  PopIrpWorkerCount = 0;
  PopIrpWorkerInFlightCount = 0;
  PopIrpWorkerPendingCount = 0;
  PopIrpWorkerRequested = 0;
  PopIrpThreadList = &PopIrpThreadList;
  dword_61DFA4 = (int)&PopIrpThreadList;
  PopIrpWorkerList = (int)&PopIrpWorkerList;
  dword_61E87C = (int)&PopIrpWorkerList;
  PopIrpWorkerSemaphore = 5;
  byte_61E862 = 5;
  dword_61E864 = 0;
  dword_61E86C = (int)&dword_61E868;
  dword_61E868 = (int)&dword_61E868;
  dword_61E870 = 0x7FFFFFFF;
  PopIrpWorkerControlEvent = 1;
  byte_61DFB1 = 0;
  byte_61DFB2 = 4;
  dword_61DFB4 = 0;
  dword_61DFBC = (int)&dword_61DFB8;
  dword_61DFB8 = (int)&dword_61DFB8;
  PopIrpWorkerMutex = 1;
  dword_61DFC4 = 0;
  unk_61DFC8 = 0;
  byte_61DFCC = 1;
  byte_61DFCD = 0;
  byte_61DFCE = 4;
  dword_61DFD0 = 0;
  dword_61DFD8 = (int)&dword_61DFD4;
  dword_61DFD4 = (int)&dword_61DFD4;
  ExInitializeNPagedLookasideList((int)&PopDynamicIrpWorkerLookaside, 0, 0, 512);
  result = PopCreatePowerThread((int)PopIrpWorkerControl, 0);
  if ( result >= 0 )
  {
    PopIrpWorkerPendingCount = 2;
    v1 = 0;
    while ( 1 )
    {
      result = PopCreatePowerThread((int)PopIrpWorker, 0);
      if ( result < 0 )
        break;
      if ( (unsigned int)++v1 >= 2 )
        return 0;
    }
  }
  return result;
}

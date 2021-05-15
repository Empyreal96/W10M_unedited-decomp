// PopWakeSourceInit 
 
void PopWakeSourceInit()
{
  PopWakeInfoCount = 0;
  PopWakeInfoList = (int)&PopWakeInfoList;
  dword_61F2CC = (int)&PopWakeInfoList;
  PopCurrentWakeInfo = 0;
  PopPendingWakeInfo = 0;
  PopWakeSourceLock = 0;
  PopWakeSourceLockOwner = 0;
  PopWakeSourceAvailable = 0;
  byte_61F2E1 = 0;
  byte_61F2E2 = 4;
  dword_61F2E4 = 1;
  dword_61F2EC = (int)&dword_61F2E8;
  dword_61F2E8 = (int)&dword_61F2E8;
  PopWakeSourceWorkInProgress = 0;
  PopWakeSourceWorkList = (int)&PopWakeSourceWorkList;
  dword_61F2FC = (int)&PopWakeSourceWorkList;
  dword_61F318 = (int)PopUpdateWakeSourceWorker;
  dword_61F31C = 0;
  PopWakeSourceWorkItem = 0;
}

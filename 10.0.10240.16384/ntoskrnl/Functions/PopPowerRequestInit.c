// PopPowerRequestInit 
 
int PopPowerRequestInit()
{
  int v0; // r4
  char v2[8]; // [sp+8h] [bp-68h] BYREF
  int v3[22]; // [sp+10h] [bp-60h] BYREF

  dword_61F834 = 0;
  PopPowerRequestLock = 0;
  PopPowerRequestSpinLock = 0;
  PopPowerRequestObjectCount = 0;
  PopSpecialPowerRequestObjectCount = 0;
  memset(v3, 0, sizeof(v3));
  RtlInitUnicodeString((unsigned int)v2, L"PowerRequest");
  LOWORD(v3[0]) = 88;
  v3[9] = 512;
  v3[11] = 76;
  v3[2] = 402;
  v3[3] = 0x20000;
  v3[4] = 0x20000;
  v3[5] = 0x20000;
  v3[6] = 2031616;
  v3[7] = 2031616;
  v3[14] = (int)PopClosePowerRequestObject;
  v3[15] = (int)PopDeletePowerRequestObject;
  BYTE2(v3[0]) |= 0x14u;
  v0 = ObCreateObjectType();
  if ( v0 >= 0 )
  {
    dword_61F928 = (int)PopPowerRequestCallbackWorker;
    dword_61F92C = 0;
    PopCallbackWorkItem = 0;
    PopPowerRequestObjectList = (int)&PopPowerRequestObjectList;
    dword_61F904 = (int)&PopPowerRequestObjectList;
    PopSpecialPowerRequestObjectList = &PopSpecialPowerRequestObjectList;
    dword_61F8FC = (int)&PopSpecialPowerRequestObjectList;
    PopPowerRequestCallbacks = (int)&PopPowerRequestCallbacks;
    dword_61F914 = (int)&PopPowerRequestCallbacks;
    RtlInitializeGenericTableAvl(
      (int)&PopPowerRequestTable,
      (unsigned int)PopPowerRequestCompare,
      (unsigned int)PopPowerRequestAllocate,
      (int)PopPowerRequestFree,
      0);
    KeInitializeTimerEx(PopExecutionRequiredTimer, 0);
    PopExecutionRequiredTimeoutDpc = 19;
    byte_61F881 = 1;
    word_61F882 = 0;
    dword_61F88C = (int)PopExecutionRequiredTimeoutCallback;
    dword_61F890 = 0;
    dword_61F89C = 0;
    dword_61F888 = 0;
    dword_61F8E8 = (int)PopCheckExecutionRequiredPowerRequests;
    dword_61F8EC = 0;
    PopCheckExecutionRequiredWorker = 0;
  }
  return v0;
}

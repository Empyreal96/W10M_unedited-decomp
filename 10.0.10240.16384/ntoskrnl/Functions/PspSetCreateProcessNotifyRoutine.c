// PspSetCreateProcessNotifyRoutine 
 
int __fastcall PspSetCreateProcessNotifyRoutine(int a1, int a2, int a3)
{
  int v6; // r1
  int *v7; // r7
  _DWORD *v8; // r5
  unsigned int v9; // r4
  unsigned int v10; // r1
  char v11; // r3
  unsigned int v12; // r1
  char v13; // r3
  unsigned int v14; // r3
  unsigned int v15; // r3

  if ( a2 )
    return sub_7F1FD8();
  if ( a3 )
  {
    if ( !MmVerifyCallbackFunction(a1) )
      return -1073741790;
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  v7 = (int *)ExAllocateCallBack(a1, v6);
  if ( v7 )
  {
    v8 = &PspCreateProcessNotifyRoutine;
    v9 = 0;
    while ( !ExCompareExchangeCallBack(v8, v7, 0) )
    {
      ++v9;
      ++v8;
      if ( v9 >= 0x40 )
      {
        ExFreePoolWithTag((unsigned int)v7);
        return -1073741811;
      }
    }
    __dmb(0xBu);
    if ( a3 )
    {
      do
        v12 = __ldrex(&PspCreateProcessNotifyRoutineExCount);
      while ( __strex(v12 + 1, &PspCreateProcessNotifyRoutineExCount) );
      __dmb(0xBu);
      v13 = PspNotifyEnableMask;
      __dmb(0xBu);
      if ( (v13 & 4) != 0 )
        return 0;
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned __int8 *)&PspNotifyEnableMask);
      while ( __strex(v14 | 4, (unsigned __int8 *)&PspNotifyEnableMask) );
    }
    else
    {
      do
        v10 = __ldrex(&PspCreateProcessNotifyRoutineCount);
      while ( __strex(v10 + 1, &PspCreateProcessNotifyRoutineCount) );
      __dmb(0xBu);
      v11 = PspNotifyEnableMask;
      __dmb(0xBu);
      if ( (v11 & 2) != 0 )
        return 0;
      __dmb(0xBu);
      do
        v15 = __ldrex((unsigned __int8 *)&PspNotifyEnableMask);
      while ( __strex(v15 | 2, (unsigned __int8 *)&PspNotifyEnableMask) );
    }
    __dmb(0xBu);
    return 0;
  }
  return -1073741670;
}

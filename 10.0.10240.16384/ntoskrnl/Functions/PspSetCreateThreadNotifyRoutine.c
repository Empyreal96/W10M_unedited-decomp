// PspSetCreateThreadNotifyRoutine 
 
int __fastcall PspSetCreateThreadNotifyRoutine(int a1, int a2)
{
  int *v3; // r7
  _DWORD *v4; // r5
  unsigned int i; // r4
  unsigned int v6; // r1
  char v7; // r3
  unsigned int v8; // r3
  unsigned int v10; // r1
  char v11; // r3
  unsigned int v12; // r3

  v3 = (int *)ExAllocateCallBack(a1, a2 != 0);
  if ( !v3 )
    JUMPOUT(0x7F1F54);
  v4 = &PspCreateThreadNotifyRoutine;
  for ( i = 0; i < 0x40; ++i )
  {
    if ( ExCompareExchangeCallBack(v4, v3, 0) )
    {
      __dmb(0xBu);
      if ( a2 )
      {
        do
          v10 = __ldrex(&PspCreateThreadNotifyRoutineExCount);
        while ( __strex(v10 + 1, &PspCreateThreadNotifyRoutineExCount) );
        __dmb(0xBu);
        v11 = PspNotifyEnableMask;
        __dmb(0xBu);
        if ( (v11 & 0x10) != 0 )
          return 0;
        __dmb(0xBu);
        do
          v12 = __ldrex((unsigned __int8 *)&PspNotifyEnableMask);
        while ( __strex(v12 | 0x10, (unsigned __int8 *)&PspNotifyEnableMask) );
      }
      else
      {
        do
          v6 = __ldrex(&PspCreateThreadNotifyRoutineCount);
        while ( __strex(v6 + 1, &PspCreateThreadNotifyRoutineCount) );
        __dmb(0xBu);
        v7 = PspNotifyEnableMask;
        __dmb(0xBu);
        if ( (v7 & 8) != 0 )
          return 0;
        __dmb(0xBu);
        do
          v8 = __ldrex((unsigned __int8 *)&PspNotifyEnableMask);
        while ( __strex(v8 | 8, (unsigned __int8 *)&PspNotifyEnableMask) );
      }
      __dmb(0xBu);
      return 0;
    }
    ++v4;
  }
  return sub_7F1F4C();
}

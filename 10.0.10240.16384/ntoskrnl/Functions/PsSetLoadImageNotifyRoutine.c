// PsSetLoadImageNotifyRoutine 
 
int __fastcall PsSetLoadImageNotifyRoutine(int a1)
{
  int *v2; // r6
  _DWORD *v3; // r5
  unsigned int v4; // r4
  unsigned int v5; // r2
  char v6; // r3
  unsigned int v7; // r3
  int v9; // [sp+8h] [bp-40h] BYREF
  _DWORD v10[15]; // [sp+Ch] [bp-3Ch] BYREF

  v2 = (int *)ExAllocateCallBack(a1, 0);
  if ( !v2 )
    JUMPOUT(0x7F1FAC);
  v3 = &PspLoadImageNotifyRoutine;
  v4 = 0;
  while ( !ExCompareExchangeCallBack(v3, v2, 0) )
  {
    ++v4;
    ++v3;
    if ( v4 >= 0x40 )
      return sub_7F1FA4();
  }
  __dmb(0xBu);
  do
    v5 = __ldrex(&PspLoadImageNotifyRoutineCount);
  while ( __strex(v5 + 1, &PspLoadImageNotifyRoutineCount) );
  __dmb(0xBu);
  v6 = PspNotifyEnableMask;
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
  {
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned __int8 *)&PspNotifyEnableMask);
    while ( __strex(v7 | 1, (unsigned __int8 *)&PspNotifyEnableMask) );
    __dmb(0xBu);
  }
  v9 = 0;
  v10[0] = a1;
  if ( EtwApiCallsProvRegHandle )
  {
    v10[1] = v10;
    v10[2] = 0;
    v10[3] = 4;
    v10[4] = 0;
    v10[5] = &v9;
    v10[6] = 0;
    v10[7] = 4;
    v10[8] = 0;
    EtwWrite(
      EtwApiCallsProvRegHandle,
      SHIDWORD(EtwApiCallsProvRegHandle),
      (int)KERNEL_AUDIT_API_PSSETLOADIMAGENOTIFYROUTINE,
      0);
  }
  return 0;
}

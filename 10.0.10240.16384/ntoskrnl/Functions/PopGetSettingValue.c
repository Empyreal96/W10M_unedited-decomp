// PopGetSettingValue 
 
int __fastcall PopGetSettingValue(unsigned int a1, int a2, int a3)
{
  int v6; // r5
  int v7; // r10
  unsigned int v8; // r1
  int v9; // r0
  _DWORD *v10; // r0
  unsigned __int8 v11; // r5
  unsigned int v12; // r1
  int v13; // r5
  unsigned __int8 v14; // r6
  unsigned int v15; // r1

  v6 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
  v7 = KfRaiseIrql(1);
  do
    v8 = __ldrex((unsigned __int8 *)&PopSettingLock);
  while ( __strex(v8 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PopSettingLock, v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61F33C = v7;
  v9 = PsGetProcessSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  v10 = PopFindPowerSettingConfiguration(a1, v9);
  if ( v10 )
  {
    v13 = PopMarshalSettingValues(v10, a2 + 4, a3 - 4, a2);
    dword_61F324 = 0;
    v14 = dword_61F33C;
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)&PopSettingLock);
    while ( !v15 && __strex(1u, (unsigned int *)&PopSettingLock) );
    if ( v15 )
      ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v15);
    KfLowerIrql(v14);
    KeAbPostRelease((unsigned int)&PopSettingLock);
  }
  else
  {
    dword_61F324 = 0;
    v11 = dword_61F33C;
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&PopSettingLock);
    while ( !v12 && __strex(1u, (unsigned int *)&PopSettingLock) );
    if ( v12 )
      ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v12);
    KfLowerIrql(v11);
    KeAbPostRelease((unsigned int)&PopSettingLock);
    v13 = -1073741811;
  }
  return v13;
}

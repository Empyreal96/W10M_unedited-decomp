// PopDispatchNotificationsToList 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall PopDispatchNotificationsToList(_DWORD *a1)
{
  int v2; // r5
  int v3; // r0
  unsigned __int8 v4; // r6
  unsigned int v5; // r2
  unsigned int result; // r0
  _DWORD *v7; // r5
  _DWORD *v8; // r6
  int v9; // r3
  int v10; // r3
  unsigned int v11; // r1
  int v12; // r0
  unsigned __int8 v13; // r9
  int v14; // r7
  unsigned int v15; // r1
  int v16; // r9
  int v17; // r7
  int v18; // r10
  unsigned int v19; // r2
  unsigned int v20; // r3
  int v21; // r1 OVERLAPPED
  _DWORD *v22; // r2 OVERLAPPED
  int v23[4]; // [sp+10h] [bp-58h] BYREF
  char v24[72]; // [sp+20h] [bp-48h] BYREF

  v2 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
  v3 = KfRaiseIrql(1);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&PopSettingLock);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    return sub_7F2A34();
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61F33C = v3;
  v7 = (_DWORD *)*a1;
  if ( (_DWORD *)*a1 != a1 )
  {
    do
    {
      v8 = v7;
      while ( 1 )
      {
        v9 = v7[9];
        if ( (v9 & 1) == 0 || (v9 & 2) != 0 )
          break;
        v23[2] = v7[10];
        v23[3] = v7[11];
        v7[9] = v7[9] & 0xFFFFFFFC | 2;
        v12 = PopMarshalSettingValues(v7, v24, 36, v23);
        dword_61F324 = 0;
        v13 = dword_61F33C;
        v14 = v12;
        __dmb(0xBu);
        do
          v15 = __ldrex((unsigned int *)&PopSettingLock);
        while ( !v15 && __strex(1u, (unsigned int *)&PopSettingLock) );
        if ( v15 )
          ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v15);
        KfLowerIrql(v13);
        KeAbPostRelease((unsigned int)&PopSettingLock);
        if ( v14 < 0 )
          v23[0] = 0;
        v16 = ZwUpdateWnfStateData();
        if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
          __fastfail(0x20u);
        v17 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
        v18 = KfRaiseIrql(1);
        do
          v19 = __ldrex((unsigned __int8 *)&PopSettingLock);
        while ( __strex(v19 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
        __dmb(0xBu);
        if ( (v19 & 1) == 0 )
          ExpAcquireFastMutexContended((int)&PopSettingLock, v17);
        if ( v17 )
          *(_BYTE *)(v17 + 14) |= 1u;
        dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        dword_61F33C = v18;
        v20 = v7[9] & 0xFFFFFFFD;
        v7[9] = v20;
        if ( v16 < 0 )
        {
          v7[9] = v20 | 1;
          break;
        }
      }
      v10 = v7[9];
      v7 = (_DWORD *)*v7;
      if ( (v10 & 2) == 0 && (v10 & 4) != 0 )
      {
        *(_QWORD *)&v21 = *(_QWORD *)v8;
        if ( *(_DWORD **)(*v8 + 4) != v8 || (_DWORD *)*v22 != v8 )
          __fastfail(3u);
        *v22 = v21;
        *(_DWORD *)(v21 + 4) = v22;
        PopFreeRegistration(v8);
      }
    }
    while ( v7 != a1 );
    v4 = dword_61F33C;
  }
  dword_61F324 = 0;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PopSettingLock);
  while ( !v11 && __strex(1u, (unsigned int *)&PopSettingLock) );
  if ( v11 )
    ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v11);
  KfLowerIrql(v4);
  result = KeAbPostRelease((unsigned int)&PopSettingLock);
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
    __fastfail(0x20u);
  return result;
}

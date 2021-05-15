// NtQueryDriverEntryOrder 
 
int __fastcall NtQueryDriverEntryOrder(int a1, unsigned int *a2)
{
  unsigned int *v2; // r8
  int v4; // r4
  int v5; // r9
  unsigned int *v6; // r2
  int v7; // r1
  unsigned int v8; // r1
  int v9; // r10
  int v10; // r9
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r1
  unsigned __int16 *v21; // r0
  _DWORD *v22; // r5
  int v23; // t1
  unsigned int v24; // r3
  unsigned int v26; // [sp+Ch] [bp-2Ch] BYREF
  int v27; // [sp+10h] [bp-28h]
  int v28; // [sp+14h] [bp-24h] BYREF
  int _18[12]; // [sp+18h] [bp-20h] BYREF

  v2 = a2;
  _18[11] = (int)a2;
  _18[10] = a1;
  if ( dword_61A1F0 != 2 )
    return -1073741822;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v5 )
  {
    v6 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v6 = (unsigned int *)MmUserProbeAddress;
    *v6 = *v6;
    v7 = 4 * *a2;
    v26 = v7;
    if ( !a1 )
    {
      v7 = 0;
      v26 = 0;
    }
    if ( v7 )
      ProbeForWrite(a1, v7, 4);
    if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v5, (int)&SeSystemEnvironmentPrivilege) )
    {
      v4 = -1073741727;
      v27 = -1073741727;
      return v4;
    }
    v8 = v26;
  }
  else
  {
    v8 = 4 * *a2;
    v26 = v8;
    if ( !a1 )
    {
      v8 = 0;
      v26 = 0;
    }
  }
  if ( v8 )
  {
    v4 = ExLockUserBuffer(a1, v8, v5, 1, _18, &v28);
    if ( v4 < 0 )
      return v4;
    v8 = v26;
    v9 = v28;
    v10 = _18[0];
  }
  else
  {
    v10 = 0;
    v9 = 0;
  }
  v26 = v8 >> 1;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v11 + 308);
  _18[0] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
  v13 = v12;
  do
    v14 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
  while ( __strex(v14 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
  __dmb(0xBu);
  if ( (v14 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v12);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  dword_61A084 = _18[0];
  v4 = HalGetEnvironmentVariableEx(L"DriverOrder", EfiDriverVariablesGuid, v10, &v26);
  dword_61A084 = 0;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&ExpEnvironmentLock);
  while ( !v15 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
  if ( v15 )
    ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v15);
  v16 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  if ( v4 < 0 )
  {
    if ( v4 != -1073741568 )
    {
LABEL_40:
      v19 = v26;
      goto LABEL_41;
    }
    v19 = 0;
    v4 = 0;
  }
  else
  {
    v19 = v26;
    v20 = v26 >> 1;
    v21 = (unsigned __int16 *)(v10 + 2 * (v26 >> 1) - 2);
    v22 = (_DWORD *)(v10 + 4 * (v26 >> 1) - 4);
    if ( v26 >> 1 )
    {
      do
      {
        v23 = *v21--;
        *v22-- = v23;
        --v20;
      }
      while ( v20 );
      goto LABEL_40;
    }
  }
LABEL_41:
  v24 = 2 * v19;
  v26 = 2 * v19;
  if ( v9 )
  {
    ExUnlockUserBuffer(v9);
    v24 = v26;
  }
  *v2 = v24 >> 2;
  v27 = v4;
  return v4;
}

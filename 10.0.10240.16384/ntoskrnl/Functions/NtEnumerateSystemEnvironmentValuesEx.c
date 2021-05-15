// NtEnumerateSystemEnvironmentValuesEx 
 
int __fastcall NtEnumerateSystemEnvironmentValuesEx(int a1, int a2, int *a3, int a4)
{
  int *v4; // r5
  int v7; // r4
  int v8; // r8
  int v9; // r1
  int v10; // r1
  int v11; // r6
  int v12; // r9
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  int v22; // [sp+Ch] [bp-2Ch] BYREF
  int v23; // [sp+10h] [bp-28h]
  int v24; // [sp+14h] [bp-24h] BYREF
  int _18[14]; // [sp+18h] [bp-20h] BYREF

  _18[13] = a4;
  v4 = a3;
  _18[12] = (int)a3;
  _18[11] = a2;
  _18[10] = a1;
  if ( dword_61A1F0 != 2 )
    return -1073741822;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v8 )
  {
    if ( (unsigned int)a3 >= MmUserProbeAddress )
      a3 = (int *)MmUserProbeAddress;
    *a3 = *a3;
    v9 = *v4;
    v22 = *v4;
    if ( !a2 )
    {
      v9 = 0;
      v22 = 0;
    }
    if ( v9 )
      ProbeForWrite(a2, v9, 4);
    if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v8, (int)&SeSystemEnvironmentPrivilege) )
    {
      v7 = -1073741727;
      v23 = -1073741727;
      return v7;
    }
    v10 = v22;
  }
  else
  {
    v10 = *a3;
    v22 = *a3;
    if ( !a2 )
    {
      v10 = 0;
      v22 = 0;
    }
  }
  if ( v10 )
  {
    v7 = ExLockUserBuffer(a2, v10, v8, 1, _18, &v24);
    if ( v7 < 0 )
      return v7;
    v11 = v24;
    v12 = _18[0];
  }
  else
  {
    v12 = 0;
    v11 = 0;
  }
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v13 + 308);
  _18[0] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
  v15 = v14;
  do
    v16 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
  while ( __strex(v16 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
  __dmb(0xBu);
  if ( (v16 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v14);
  if ( v15 )
    *(_BYTE *)(v15 + 14) |= 1u;
  dword_61A084 = _18[0];
  v7 = IoEnumerateEnvironmentVariablesEx(a1, v12, (int)&v22);
  dword_61A084 = 0;
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)&ExpEnvironmentLock);
  while ( !v17 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
  if ( v17 )
    ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v17);
  v18 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x134) + 1;
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(v18);
  if ( v11 )
    ExUnlockUserBuffer(v11);
  *v4 = v22;
  v23 = v7;
  return v7;
}

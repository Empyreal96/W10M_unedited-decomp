// NtSetBootEntryOrder 
 
int __fastcall NtSetBootEntryOrder(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // r6
  unsigned int v4; // r5
  int v5; // r4
  unsigned int v6; // r3
  int v7; // r8
  int v8; // r9
  int v9; // r0
  unsigned int i; // r2
  unsigned int v11; // r1
  unsigned int v12; // r2
  unsigned int v13; // r9
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  unsigned int _38; // [sp+38h] [bp+8h]

  _38 = a1;
  v2 = a2;
  v4 = 0;
  if ( dword_61A1F0 != 2 )
    return -1073741822;
  if ( a2 > 0x3FFFFFFF )
    return -1073741811;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(char *)(v6 + 346);
  if ( *(_BYTE *)(v6 + 346)
    && !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v7, (int)&SeSystemEnvironmentPrivilege) )
  {
    return -1073741727;
  }
  if ( v2 )
  {
    v8 = 4 * v2;
    v9 = ExAllocatePoolWithTag(512, 2 * v2, 1920364101);
    v4 = v9;
    if ( !v9 )
      return -1073741670;
    if ( v7 && v8 )
    {
      if ( (a1 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v9);
      if ( v8 + a1 > MmUserProbeAddress || v8 + a1 < a1 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    for ( i = 0; i < v2; ++i )
    {
      v11 = *(_DWORD *)(a1 + 4 * i);
      if ( v11 > 0xFFFF )
      {
        ExFreePoolWithTag(v9);
        return -1073741811;
      }
      *(_WORD *)(v9 + 2 * i) = v11;
    }
  }
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 308);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
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
  dword_61A084 = v13;
  v5 = IoSetEnvironmentVariableEx(L"BootOrder", EfiBootVariablesGuid, v4, 2 * v2, 1);
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
  if ( v5 == -1073741568 )
    v5 = 0;
  if ( v4 )
    ExFreePoolWithTag(v4);
  return v5;
}

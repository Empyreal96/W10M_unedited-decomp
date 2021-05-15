// NtDeleteDriverEntry 
 
int __fastcall NtDeleteDriverEntry(unsigned int a1)
{
  int v2; // r4
  unsigned int v3; // r3
  unsigned int v4; // r2
  unsigned int v5; // r7
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  unsigned int v9; // r1
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  int v14[2]; // [sp+8h] [bp-38h] BYREF
  char v15[48]; // [sp+10h] [bp-30h] BYREF

  if ( dword_61A1F0 != 2 )
    return -1073741822;
  if ( a1 > 0xFFFF )
    return -1073741811;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(v3 + 346)
    && !SeSinglePrivilegeCheck(
          SeSystemEnvironmentPrivilege,
          dword_9229F4,
          *(char *)(v3 + 346),
          (int)&SeSystemEnvironmentPrivilege) )
  {
    return -1073741727;
  }
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
  while ( __strex(v8 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v6);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  dword_61A084 = v5;
  swprintf_s((int)v15, 11, (int)L"Driver%04X", a1);
  v14[0] = 0;
  v2 = IoGetEnvironmentVariableEx((int)v15, (int)EfiDriverVariablesGuid, 0, (int)v14, 0);
  if ( v2 != -1073741568 )
    goto LABEL_17;
  if ( (a1 & (2 * ((a1 | (2 * a1)) & 0xC4444444))) != 0 )
  {
    swprintf_s((int)v15, 11, (int)L"Driver%04x", a1);
    v14[0] = 0;
    v2 = IoGetEnvironmentVariableEx((int)v15, (int)EfiDriverVariablesGuid, 0, (int)v14, 0);
LABEL_17:
    if ( !v2 || v2 == -1073741789 )
      v2 = IoSetEnvironmentVariableEx((int)v15, (int)EfiDriverVariablesGuid, 0, 0, 1);
  }
  dword_61A084 = 0;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&ExpEnvironmentLock);
  while ( !v9 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
  if ( v9 )
    ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v9);
  v10 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v2;
}

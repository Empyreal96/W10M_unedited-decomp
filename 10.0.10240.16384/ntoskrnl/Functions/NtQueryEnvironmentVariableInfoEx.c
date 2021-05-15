// NtQueryEnvironmentVariableInfoEx 
 
int __fastcall NtQueryEnvironmentVariableInfoEx(int a1, int a2, int a3, int a4)
{
  int v8; // r4
  unsigned int v9; // r2
  unsigned int v10; // r10
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3

  if ( dword_61A1F0 != 2 )
    return -1073741822;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    return -1073741727;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
  v12 = v11;
  do
    v13 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
  while ( __strex(v13 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
  __dmb(0xBu);
  if ( (v13 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v11);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  dword_61A084 = v10;
  v14 = IoQueryEnvironmentVariableInfoEx(a1, a2, a3, a4);
  dword_61A084 = 0;
  v8 = v14;
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
  return v8;
}

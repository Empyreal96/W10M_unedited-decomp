// NtGetEnvironmentVariableEx 
 
int __fastcall NtGetEnvironmentVariableEx(int a1, int a2, int a3, int a4, int a5)
{
  int v9; // r4
  unsigned int v10; // r2
  unsigned int v11; // r10
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3

  if ( dword_61A1F0 != 2 )
    return -1073741822;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    return -1073741727;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 308);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
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
  dword_61A084 = v11;
  v15 = IoGetEnvironmentVariableEx(a1, a2, a3, a4, a5);
  dword_61A084 = 0;
  v9 = v15;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&ExpEnvironmentLock);
  while ( !v16 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
  if ( v16 )
    ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v16);
  v17 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  return v9;
}

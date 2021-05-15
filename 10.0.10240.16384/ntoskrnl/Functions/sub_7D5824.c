// sub_7D5824 
 
void __fastcall sub_7D5824(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r0
  unsigned int v9; // r1
  int v10; // r3
  int v11; // r8
  int v12; // r9
  int v13; // r10
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r5
  unsigned int v17; // r1
  unsigned int v18; // r1
  unsigned int v19; // [sp+Ch] [bp-2Ch]

  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v14 + 308);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
  v16 = v15;
  do
    v17 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
  while ( __strex(v17 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
  __dmb(0xBu);
  if ( (v17 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v15);
  if ( v16 )
    *(_BYTE *)(v16 + 14) |= 1u;
  dword_61A084 = v19;
  IoGetEnvironmentVariableEx(v13, v12, a8, v11, a5);
  dword_61A084 = 0;
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)&ExpEnvironmentLock);
  while ( !v18 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
  if ( v18 )
    ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v18);
  v8 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = (__int16)(*(_WORD *)(v9 + 0x134) + 1);
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  if ( a7 )
    ExUnlockUserBuffer(a7);
  JUMPOUT(0x6D94B2);
}

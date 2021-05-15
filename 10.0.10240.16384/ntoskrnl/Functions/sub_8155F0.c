// sub_8155F0 
 
int __fastcall sub_8155F0(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r0
  unsigned int v6; // r1
  int v7; // r3
  int v9; // r7
  int v10; // r9
  int v11; // r10
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r4
  unsigned int v15; // r1
  int v16; // r0
  int v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // [sp+Ch] [bp-2Ch]
  int (__fastcall *v20)(int); // [sp+34h] [bp-4h]

  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 308);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
  v14 = v13;
  do
    v15 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
  while ( __strex(v15 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
  __dmb(0xBu);
  if ( (v15 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v13);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  dword_61A084 = v19;
  v16 = IoSetEnvironmentVariableEx(v11, v10, 0, v9, a5);
  dword_61A084 = 0;
  v17 = v16;
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)&ExpEnvironmentLock);
  while ( !v18 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
  if ( v18 )
    ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v18);
  v5 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = (__int16)(*(_WORD *)(v6 + 0x134) + 1);
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v5);
  return v20(v17);
}

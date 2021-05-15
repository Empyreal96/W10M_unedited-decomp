// sub_7EA9CC 
 
int sub_7EA9CC()
{
  int v0; // r4
  unsigned int v1; // r1
  int v2; // r0
  unsigned int v3; // r1
  int v4; // r3
  unsigned int *v6; // r6
  int v7; // r7
  unsigned int *v8; // r8
  unsigned int v9; // r9
  int v10; // r10
  int v11; // [sp+0h] [bp-28h]
  int (__fastcall *v12)(int); // [sp+24h] [bp-4h]

  ExfAcquirePushLockExclusiveEx(v6, v7, (unsigned int)v6);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  if ( v10 || *v8 < v9 )
    v0 = HvpViewMapGrowFile(v8, v11, v9);
  else
    v0 = 0;
  __dmb(0xBu);
  do
    v1 = __ldrex(v6);
  while ( __strex(v1 - 1, v6) );
  if ( (v1 & 2) != 0 && (v1 & 4) == 0 )
    ExfTryToWakePushLock(v6);
  v2 = KeAbPostRelease((unsigned int)v6);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = (__int16)(*(_WORD *)(v3 + 0x134) + 1);
  *(_WORD *)(v3 + 308) = v4;
  if ( !v4 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
    KiCheckForKernelApcDelivery(v2);
  return v12(v0);
}

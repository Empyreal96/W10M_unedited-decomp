// sub_819A18 
 
int sub_819A18()
{
  unsigned int v0; // r0
  int v1; // r4
  int v2; // r5
  int v3; // r6
  int v4; // r7
  unsigned int *v5; // r2
  unsigned int v6; // r5
  int v7; // r0
  unsigned int v8; // r1
  __int16 v9; // r3
  int v11[8]; // [sp+0h] [bp-20h] BYREF

  ExfAcquirePushLockExclusiveEx((_DWORD *)(v1 + v3), v2, v1 + v3);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  if ( *(_DWORD *)(v1 + 5980) == -1 )
  {
    v0 = MmGetNumberOfPhysicalPages(0);
    v4 = SmpDirtyStoreCreate(v1, v0 >> 9, 0, v11);
    if ( v4 >= 0 )
    {
      __dmb(0xBu);
      *(_DWORD *)(v1 + 5980) = v11[0];
    }
  }
  else
  {
    v4 = -1073740008;
  }
  __dmb(0xBu);
  v5 = (unsigned int *)(v1 + v3);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 - 1, v5) );
  if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v1 + v3));
  v7 = KeAbPostRelease(v1 + v3);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(v7);
  return ((int (__fastcall *)(int, unsigned int, int, int))v11[7])(v4, v8, v11[0], v11[1]);
}

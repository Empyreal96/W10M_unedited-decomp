// -SmStTrimWsStoreBatch@-$SMKM_STORE@USM_TRAITS@@@@SAXPAU1@PAKPAPAXKK@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStTrimWsStoreBatch(int a1, int *a2, int a3, int a4)
{
  unsigned int *v8; // r7
  unsigned int v9; // r5
  int v10; // r0
  unsigned int v11; // r5
  __int16 v12; // r4
  int v13; // r4
  unsigned int v14; // r2
  int result; // r0
  int v16; // r4
  unsigned int v17; // r2
  int v18; // t1

  v8 = (unsigned int *)(a1 + 3520);
  __dmb(0xBu);
  do
    v9 = __ldrex(v8);
  while ( v9 == 17 && __strex(0, v8) );
  if ( v9 != 17 )
    ExfReleasePushLockShared((_DWORD *)(a1 + 3520));
  v10 = KeAbPostRelease((unsigned int)v8);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x136);
  *(_WORD *)(v11 + 310) = v12 + 1;
  if ( v12 == -1 && *(_DWORD *)(v11 + 100) != v11 + 100 )
    KiCheckForKernelApcDelivery(v10);
  if ( a4 )
  {
    v13 = a4;
    do
    {
      a3 += 4;
      ZwUnlockVirtualMemory();
      --v13;
    }
    while ( v13 );
  }
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v14 + 310);
  result = KeAbPreAcquire((unsigned int)v8, 0, 0);
  v16 = result;
  do
    v17 = __ldrex(v8);
  while ( !v17 && __strex(0x11u, v8) );
  __dmb(0xBu);
  if ( v17 )
    result = ExfAcquirePushLockSharedEx(v8, result, (unsigned int)v8);
  if ( v16 )
    *(_BYTE *)(v16 + 14) |= 1u;
  for ( ; a4; --a4 )
  {
    v18 = *a2++;
    result = SMKM_STORE<SM_TRAITS>::SmStUnmapVirtualRegion(a1, v18);
  }
  return result;
}

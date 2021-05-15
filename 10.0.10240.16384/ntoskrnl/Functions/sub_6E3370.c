// sub_6E3370 
 
int __fastcall sub_6E3370(int a1, int a2, int a3, unsigned int a4, int a5, unsigned int *a6, int a7)
{
  unsigned int v9; // r5
  int v10; // r0
  unsigned int v11; // r6
  int *v13; // r4
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r0
  unsigned int v21; // r2

  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  v10 = KeAbPreAcquire((unsigned int)&ExpFastCacheLock, 0, 0);
  do
    v11 = __ldrex(&ExpFastCacheLock);
  while ( !v11 && __strex(0x11u, &ExpFastCacheLock) );
  __dmb(0xBu);
  if ( v11 )
    return sub_7DB53C(v10);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v13 = &dword_920288[10 * a1];
  if ( v13[5] )
  {
    if ( !a3 )
      ((void (*)(void))ExpTriggerFastCacheReeval)();
    v15 = -1073700221;
  }
  else
  {
    v14 = ExpFindFastCacheDescriptor(a1, a2);
    if ( v14 )
    {
      if ( *((_BYTE *)v13 + 36) && (unsigned __int64)qword_922C10 > *(_QWORD *)(v14 + 32) )
      {
        v20 = sub_76601C(8444);
        if ( !a3 )
          ExpTriggerFastCacheReeval(v20);
        v15 = -1073700222;
      }
      else
      {
        v21 = *(_DWORD *)(v14 + 40);
        *a6 = v21;
        if ( v21 <= a4 )
        {
          memmove(a5, v14 + 44, v21);
          v15 = 0;
        }
        else
        {
          v15 = -1073741789;
        }
      }
    }
    else
    {
      v15 = -1073700223;
    }
  }
  __dmb(0xBu);
  do
    v16 = __ldrex(&ExpFastCacheLock);
  while ( v16 == 17 && __strex(0, &ExpFastCacheLock) );
  if ( v16 != 17 )
    ExfReleasePushLockShared(&ExpFastCacheLock);
  v17 = KeAbPostRelease((unsigned int)&ExpFastCacheLock);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  return v15;
}

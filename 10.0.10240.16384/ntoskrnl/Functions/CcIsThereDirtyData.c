// CcIsThereDirtyData 
 
int __fastcall CcIsThereDirtyData(int a1)
{
  int v2; // r5
  int v3; // r0
  int *i; // r3
  int *v5; // r4
  int v6; // r1
  unsigned int v7; // r2
  int v8; // r4
  int v10; // r3
  int v11; // r3
  unsigned int v12; // r3
  int v13; // r3

  v2 = 0;
  v3 = KeAcquireQueuedSpinLock(5);
  for ( i = (int *)CcDirtySharedCacheMapList; ; i = (int *)v5[22] )
  {
    v5 = i - 22;
    if ( i == &CcDirtySharedCacheMapList )
      break;
    v6 = i[2];
    v7 = *(i - 5) & 0xFFFFFFF8;
    if ( (v6 & 0x800) == 0 && *(_DWORD *)(v7 + 8) == a1 && *(i - 3) && (*(_DWORD *)(v7 + 44) & 0x8000) == 0 )
    {
      v8 = 1;
      goto LABEL_8;
    }
    if ( (unsigned int)++v2 >= 0x14 && (v6 & 0x820) == 0 )
    {
      v10 = i[2] | 0x20;
      __dmb(0xBu);
      v5[24] = v10;
      v11 = v5[19] + 1;
      __dmb(0xBu);
      v5[19] = v11;
      KeReleaseQueuedSpinLock(5, v3);
      v2 = 0;
      v3 = KeAcquireQueuedSpinLock(5);
      v12 = v5[24] & 0xFFFFFFDF;
      __dmb(0xBu);
      v5[24] = v12;
      v13 = v5[19] - 1;
      __dmb(0xBu);
      v5[19] = v13;
    }
  }
  v8 = 0;
LABEL_8:
  KeReleaseQueuedSpinLock(5, v3);
  return v8;
}

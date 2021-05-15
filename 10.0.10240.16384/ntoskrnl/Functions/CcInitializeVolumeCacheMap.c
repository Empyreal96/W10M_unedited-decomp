// CcInitializeVolumeCacheMap 
 
int __fastcall CcInitializeVolumeCacheMap(int a1, int **a2)
{
  int v2; // r3
  int v4; // r6
  int v5; // r0
  int *i; // r2
  int *v7; // r5
  int *v9; // r0
  int v10; // r3
  int *j; // r2
  int **v12; // r1

  v2 = *(_DWORD *)(a1 + 8);
  if ( v2 )
    v4 = *(_DWORD *)(v2 + 8);
  else
    v4 = *(_DWORD *)(a1 + 4);
  v5 = KeAcquireQueuedSpinLock(5);
  for ( i = (int *)CcVolumeCacheMapList; i != &CcVolumeCacheMapList; i = (int *)*i )
  {
    v7 = i - 3;
    if ( *(i - 1) == v4 )
    {
      ++*(i - 2);
LABEL_8:
      KeReleaseQueuedSpinLock(5, v5);
      *a2 = v7;
      return 0;
    }
  }
  KeReleaseQueuedSpinLock(5, v5);
  v9 = (int *)ExAllocatePoolWithTag(512, 144, 1834378051);
  v7 = v9;
  if ( v9 )
  {
    memset(v9, 0, 144);
    *(_WORD *)v7 = 760;
    *((_WORD *)v7 + 1) = 144;
    v10 = v7[1];
    v7[2] = v4;
    v7[1] = v10 + 1;
    v5 = KeAcquireQueuedSpinLock(5);
    for ( j = (int *)CcVolumeCacheMapList; j != &CcVolumeCacheMapList; j = (int *)*j )
    {
      if ( *(j - 1) == v4 )
        return sub_5224B4(v5);
    }
    v12 = (int **)dword_632644;
    v7[3] = (int)&CcVolumeCacheMapList;
    v7[4] = (int)v12;
    if ( *v12 != &CcVolumeCacheMapList )
      __fastfail(3u);
    *v12 = v7 + 3;
    dword_632644 = (int)(v7 + 3);
    goto LABEL_8;
  }
  return -1073741670;
}

// CcIsThereDirtyDataEx 
 
int __fastcall CcIsThereDirtyDataEx(int a1, _DWORD *a2)
{
  int v4; // r5
  int v5; // r0
  int *v6; // r4
  int *v7; // r2
  int v8; // r1

  v4 = 0;
  v5 = KeAcquireQueuedSpinLock(5);
  v6 = (int *)CcVolumeCacheMapList;
  if ( (int *)CcVolumeCacheMapList != &CcVolumeCacheMapList )
  {
    do
    {
      v7 = v6 - 3;
      if ( *(v6 - 1) == *(_DWORD *)(a1 + 8) )
        break;
      v6 = (int *)*v6;
      v7 = 0;
    }
    while ( v6 != &CcVolumeCacheMapList );
    if ( v7 )
    {
      v8 = v7[5];
      if ( v8 || v7[33] )
      {
        if ( a2 )
          *a2 = v7[33] + v8;
        v4 = 1;
      }
    }
  }
  KeReleaseQueuedSpinLock(5, v5);
  return v4;
}

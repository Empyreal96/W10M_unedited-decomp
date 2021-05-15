// CcSetLoggedDataThreshold 
 
int __fastcall CcSetLoggedDataThreshold(int a1, int a2)
{
  int v4; // r0
  int *i; // r2

  v4 = KeAcquireQueuedSpinLock(5);
  for ( i = (int *)CcVolumeCacheMapList; i != &CcVolumeCacheMapList; i = (int *)*i )
  {
    if ( i[3] == a1 )
    {
      i[20] = a2;
      return KeReleaseQueuedSpinLock(5, v4);
    }
  }
  return KeReleaseQueuedSpinLock(5, v4);
}

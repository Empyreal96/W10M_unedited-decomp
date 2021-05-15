// CcPerfLogLoggedStreamsStats 
 
int __fastcall CcPerfLogLoggedStreamsStats(int a1, int a2)
{
  int v4; // r6
  int *i; // r4
  int v6; // r0

  v4 = KeAcquireQueuedSpinLock(5);
  for ( i = (int *)CcVolumeCacheMapList; i != &CcVolumeCacheMapList; i = (int *)*i )
  {
    if ( i[3] )
    {
      v6 = i[24];
      if ( v6 )
      {
        CcPerfLogVolumeLogHandleInfo(v6, a1, a2);
        i[24] = 0;
      }
    }
  }
  return KeReleaseQueuedSpinLock(5, v4);
}

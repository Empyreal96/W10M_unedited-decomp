// KdpSysCheckLowMemory 
 
int __fastcall KdpSysCheckLowMemory(int a1)
{
  int v1; // r3

  v1 = KdpSearchInProgress;
  __dmb(0xBu);
  if ( v1 )
    KdpSearchPhysicalPageRange(a1);
  return 0;
}

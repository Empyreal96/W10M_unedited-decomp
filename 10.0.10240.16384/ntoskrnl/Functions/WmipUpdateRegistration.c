// WmipUpdateRegistration 
 
int __fastcall WmipUpdateRegistration(int a1)
{
  int v1; // r0
  int v2; // r5
  int v3; // r4

  v1 = WmipFindRegEntryByDevice(a1);
  v2 = v1;
  if ( !v1 )
    return -1073741811;
  v3 = WmipQueueRegWork(1, v1);
  WmipUnreferenceRegEntry(v2);
  return v3;
}

// WmipDeregisterDevice 
 
int __fastcall WmipDeregisterDevice(int a1)
{
  _DWORD *v2; // r5
  void **i; // r4

  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v2 = (_DWORD *)WmipFindRegEntryByDevice(a1);
  if ( v2 )
  {
    for ( i = (void **)WmipRegWorkList; i != &WmipRegWorkList; i = (void **)*i )
    {
      if ( i[3] == v2 )
      {
        i[3] = 0;
        WmipUnreferenceRegEntry((int)v2);
      }
    }
  }
  KeReleaseMutex((int)&WmipSMMutex);
  if ( !v2 )
    return -1073741811;
  WmipUnreferenceRegEntry((int)v2);
  WmipDeregisterRegEntry(v2);
  return 0;
}

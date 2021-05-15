// PopQueuePowerRequestCallbacks 
 
int __fastcall PopQueuePowerRequestCallbacks(unsigned __int64 a1)
{
  unsigned __int64 v1; // r4
  int v2; // r2
  int v3; // r2

  v1 = a1;
  if ( !*(_BYTE *)(a1 + 57) )
  {
    v2 = 0;
    while ( !*(_BYTE *)(v2 + a1 + 52) )
    {
      if ( ++v2 >= 5 )
        return a1;
    }
    ObfReferenceObjectWithTag(a1, 1953261124);
    v3 = v1 + 44;
    a1 = __PAIR64__(&PopPowerRequestCallbacks, PopPowerRequestCallbacks);
    *(_QWORD *)(v1 + 44) = __PAIR64__(&PopPowerRequestCallbacks, PopPowerRequestCallbacks);
    if ( *(_DWORD *)(a1 + 4) != HIDWORD(a1) )
      sub_51A0B0(a1);
    *(_DWORD *)(a1 + 4) = v3;
    *(_DWORD *)HIDWORD(a1) = v3;
    *(_BYTE *)(v1 + 57) = 1;
    if ( HIDWORD(v1) && !PopCallbackWorkItemScheduled )
    {
      PopCallbackWorkItemScheduled = 1;
      LODWORD(a1) = ExQueueWorkItem(&PopCallbackWorkItem, 0);
    }
  }
  return a1;
}

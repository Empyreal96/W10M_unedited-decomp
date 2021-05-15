// PipNotifyDependenciesChanged 
 
int __fastcall PipNotifyDependenciesChanged(int result, int a2)
{
  int v2; // r3
  int v3; // r3
  int v4; // r3
  int v5; // r1

  if ( a2 )
  {
    v2 = *(_DWORD *)(a2 + 24);
    if ( v2 )
    {
      if ( *(_DWORD *)(*(_DWORD *)(v2 + 176) + 20) )
        return sub_8114F8();
    }
  }
  if ( result )
  {
    v3 = *(_DWORD *)(result + 24);
    if ( v3 )
    {
      v4 = *(_DWORD *)(*(_DWORD *)(v3 + 176) + 20);
      if ( v4 )
      {
        v5 = *(_DWORD *)(v4 + 24);
        if ( v5 )
          result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v5, 24);
      }
    }
  }
  return result;
}

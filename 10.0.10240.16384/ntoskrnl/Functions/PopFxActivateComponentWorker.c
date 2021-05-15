// PopFxActivateComponentWorker 
 
int __fastcall PopFxActivateComponentWorker(int a1, int a2, int a3, int a4)
{
  int v7; // r0
  int result; // r0

  v7 = PopFxAddRefDevice(a1);
  if ( *(_DWORD *)(a2 + 120) )
    return sub_53FDFC(v7);
  if ( a3 )
    return PopFxCompleteComponentActivation(a1, a2, 0);
  result = PopPluginComponentActive(a1, *(_DWORD *)(a2 + 16), 1, a4);
  if ( result == 1 )
    result = PopFxProcessWork(0, a4);
  return result;
}

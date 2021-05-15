// PiUEventBroadcastDevnodesChangedEvent 
 
int __fastcall PiUEventBroadcastDevnodesChangedEvent(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // r4

  if ( a1 == -1 )
    return ZwUpdateWnfStateData();
  result = MmGetSessionById(a1, a2, a3, a4);
  v5 = result;
  if ( result )
  {
    ZwUpdateWnfStateData();
    result = ObfDereferenceObject(v5);
  }
  return result;
}

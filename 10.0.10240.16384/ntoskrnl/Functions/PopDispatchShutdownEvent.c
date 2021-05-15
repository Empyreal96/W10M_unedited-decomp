// PopDispatchShutdownEvent 
 
int __fastcall PopDispatchShutdownEvent(int result)
{
  int v1; // r4

  __dmb(0xBu);
  do
    v1 = __ldrex(PopShutdownEventCode);
  while ( __strex(0, PopShutdownEventCode) );
  __dmb(0xBu);
  if ( v1 )
  {
    if ( (PoDebug & 0x10) != 0 )
      DbgPrint("PopNotify: Event %x\n", v1);
    result = PopEventCalloutDispatch(1, v1);
  }
  if ( PoPdcCallbacks )
    result = PoPdcCallbacks(result);
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
    __fastfail(0x20u);
  return result;
}

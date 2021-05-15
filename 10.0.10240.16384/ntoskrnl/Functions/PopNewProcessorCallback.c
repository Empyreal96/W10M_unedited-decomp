// PopNewProcessorCallback 
 
void __fastcall PopNewProcessorCallback(int a1, _DWORD *a2)
{
  _BYTE *v2; // r2
  int v3; // r0
  int v4; // r1
  int v5; // r2
  int v6; // r3

  if ( *a2 == 1 )
  {
    if ( !PoDisableSkipTick && PopSkipTickPolicy == 1 && !PopCheckSkipTick() )
    {
      *v2 = 1;
      PopDiagTraceSkipTick(1, 0);
    }
    PpmCheckInitProcessors(0);
    v3 = PpmEnableWmiInterface();
    PpmIdleRegisterDefaultStates(v3, v4, v5, v6);
  }
}

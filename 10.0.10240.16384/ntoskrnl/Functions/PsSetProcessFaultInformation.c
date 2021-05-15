// PsSetProcessFaultInformation 
 
int __fastcall PsSetProcessFaultInformation(int a1, _DWORD *a2)
{
  unsigned int *v3; // r2
  unsigned int v4; // r5
  int result; // r0

  if ( (*a2 & 1) != 0 )
  {
    __dmb(0xBu);
    v3 = (unsigned int *)(a1 + 736);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 | 0x10, v3) );
    __dmb(0xBu);
    if ( (v4 & 0x10) == 0 )
      PsSetProcessTelemetryAppState(a1, 4);
  }
  if ( (*a2 & 2) != 0 )
    result = sub_7D68A4();
  else
    result = 0;
  return result;
}

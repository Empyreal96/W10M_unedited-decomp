// PoDeviceAcquireIrp 
 
int __fastcall PoDeviceAcquireIrp(int result, int a2, int a3)
{
  if ( a2 == 2 || a2 == 3 )
  {
    if ( a3 )
    {
      *(_DWORD *)(*(_DWORD *)(result + 40 * *(char *)(result + 34) + 108) + 20) = a3;
      result = PopDiagTraceDeviceAcquireIrp();
    }
  }
  return result;
}

// PoDeviceReleaseIrp 
 
int __fastcall PoDeviceReleaseIrp(int result, int a2)
{
  int v2; // r4

  if ( a2 == 2 || a2 == 3 )
  {
    v2 = *(_DWORD *)(result + 40 * *(char *)(result + 34) + 108);
    result = PopDiagTraceDeviceReleaseIrp();
    *(_DWORD *)(v2 + 20) = 0;
  }
  return result;
}

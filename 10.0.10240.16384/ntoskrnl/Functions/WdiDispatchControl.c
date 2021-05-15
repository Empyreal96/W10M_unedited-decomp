// WdiDispatchControl 
 
int __fastcall WdiDispatchControl(int *a1)
{
  int result; // r0
  _DWORD v3[6]; // [sp-4h] [bp-18h] BYREF

  if ( !a1 )
    return -1073741811;
  result = EtwGetProviderIdFromHandle(*a1, 0, 1, v3);
  if ( result >= 0 )
    result = WdipStartEndScenario(v3, a1 + 6, a1 + 2, a1[10]);
  return result;
}

// CmpAddDockingInfo 
 
int __fastcall CmpAddDockingInfo(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v7[6]; // [sp+8h] [bp-18h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  v7[0] = *(unsigned __int16 *)(a2 + 4);
  result = NtSetValueKey(a1, (int)&CmpStrDockingStateString, 0, 4, (int)v7, 4u);
  if ( result >= 0 )
  {
    v7[0] = *(unsigned __int16 *)(a2 + 6);
    result = NtSetValueKey(a1, (int)&CmpStrCapabilitiesString, 0, 4, (int)v7, 4u);
    if ( result >= 0 )
    {
      v7[0] = *(_DWORD *)(a2 + 8);
      result = NtSetValueKey(a1, (int)&CmpStrDockIdString, 0, 4, (int)v7, 4u);
      if ( result >= 0 )
      {
        v7[0] = *(_DWORD *)(a2 + 12);
        result = NtSetValueKey(a1, (int)&CmpStrSerialNumberString, 0, 4, (int)v7, 4u);
      }
    }
  }
  return result;
}

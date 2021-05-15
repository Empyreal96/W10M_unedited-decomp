// PopEventCalloutDispatch 
 
int __fastcall PopEventCalloutDispatch(int a1, int a2)
{
  int v3; // r2
  _DWORD v5[2]; // [sp+8h] [bp-8h] BYREF

  v5[0] = a1;
  v5[1] = a2;
  if ( PsWin32CalloutsEstablished )
  {
    if ( a1 == 1 )
      return sub_555A7C();
    if ( a1 == 12 )
      v3 = 0;
    else
      v3 = 2;
    PsInvokeWin32Callout(3, v5, v3, 0);
    if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
      __fastfail(0x20u);
  }
  return a1;
}

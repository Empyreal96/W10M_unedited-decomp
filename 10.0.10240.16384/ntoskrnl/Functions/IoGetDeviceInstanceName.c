// IoGetDeviceInstanceName 
 
int __fastcall IoGetDeviceInstanceName(int a1, int a2)
{
  int v2; // r2

  if ( !a1 )
    JUMPOUT(0x51FEB0);
  v2 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v2 || (*(_DWORD *)(v2 + 268) & 0x20000) != 0 )
    sub_51FE10();
  return PnpConcatenateUnicodeStrings(a2, v2 + 20);
}

// IoGetDeviceInterfaces 
 
int __fastcall IoGetDeviceInterfaces(int a1, int a2, int a3, unsigned __int16 **a4)
{
  int v5; // r1
  int v7; // r1

  v5 = 0;
  if ( a2 )
  {
    v7 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 20);
    if ( !v7 || (*(_DWORD *)(v7 + 268) & 0x20000) != 0 )
      sub_7C8ADC();
    v5 = v7 + 20;
  }
  return IopGetDeviceInterfaces(a1, v5, a3, 0, a4, 0);
}

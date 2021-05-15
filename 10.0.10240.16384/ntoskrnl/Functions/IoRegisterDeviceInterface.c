// IoRegisterDeviceInterface 
 
int __fastcall IoRegisterDeviceInterface(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // r7

  *a4 = 0;
  a4[1] = 0;
  if ( !a1 || (v4 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20)) == 0 || (*(_DWORD *)(v4 + 268) & 0x20000) != 0 )
    JUMPOUT(0x767FB4);
  return sub_7C8FB8();
}

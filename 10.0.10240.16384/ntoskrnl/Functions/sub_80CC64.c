// sub_80CC64 
 
void __fastcall sub_80CC64(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, _DWORD *a10, int a11, int a12, int a13)
{
  int v13; // r8
  _DWORD *v14; // r9
  int v15; // r4
  int v16; // r3

  v15 = IopGetRegistryValue(a13, L"BootConfig", 0, (int *)&a10);
  ZwClose();
  if ( v15 >= 0 && a10[1] == 8 && a10[3] )
  {
    v16 = a10[2];
    if ( !v13 )
      JUMPOUT(0x794046);
    if ( (_DWORD *)((char *)a10 + v16) && PnpIsDuplicateDevice(v13, (char *)a10 + v16) )
    {
      *v14 = 1;
      JUMPOUT(0x794040);
    }
  }
  JUMPOUT(0x79403E);
}

// sub_7E13A8 
 
void __fastcall sub_7E13A8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int *v9; // r8
  _DWORD *v10; // r9
  int v11; // r4

  v11 = PnpReadDeviceConfiguration(a9, 1, v9, v10);
  ZwClose();
  if ( v11 >= 0 )
    JUMPOUT(0x778B7E);
  JUMPOUT(0x778C62);
}

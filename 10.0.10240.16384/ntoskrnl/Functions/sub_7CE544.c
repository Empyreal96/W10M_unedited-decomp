// sub_7CE544 
 
void __fastcall sub_7CE544(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19)
{
  int v19; // r5
  _DWORD *v20; // r6
  int *v21; // r7
  int v22; // r8
  int v23; // r0
  int v24; // [sp+8h] [bp+8h]

  v24 = *v21;
  a8 = 0;
  v23 = KsepRegistryQueryValue(v19, v22, &a8, a19);
  *v21 = v24;
  if ( v23 != -1073741772 )
  {
    if ( v23 >= 0 )
      *v20 |= a8 | 0x10000000;
    JUMPOUT(0x787BA8);
  }
  JUMPOUT(0x787BA6);
}

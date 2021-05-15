// sub_5201C4 
 
void __fastcall sub_5201C4(int a1, int a2, int a3)
{
  int v3; // r4
  _DWORD *v4; // r6
  int v5; // r7
  int v6; // r9
  int *v7; // r6

  if ( v4 )
    *v4 = v5;
  if ( v3 >= 0 )
  {
    v7 = (int *)(v6 + 4 * v3);
    do
    {
      PnpUpdateExtensionFlags(v7, a2, a3, 0);
      --v3;
      --v7;
    }
    while ( v3 >= 0 );
  }
  JUMPOUT(0x4DBE14);
}

// sub_96D63C 
 
void __fastcall sub_96D63C(int a1, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // r6
  int v6; // r7
  int v7; // r8
  int v8; // r0

  a5 = 2048;
  v8 = MiFindLoaderGap(v6, &a5);
  if ( a5 >= 0x800 )
  {
    *(_DWORD *)(v5 + 7184) = v8;
    if ( v8 != v7 )
      JUMPOUT(0x95E3A4);
  }
  JUMPOUT(0x95E396);
}

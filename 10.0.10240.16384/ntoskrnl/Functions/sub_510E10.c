// sub_510E10 
 
void __fastcall sub_510E10(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r5
  unsigned int v10; // r7
  _DWORD *v11; // r8
  int v12; // r0
  int v13; // r0

  if ( v10 >= 4 )
  {
    a9 = 0;
    v12 = RtlComputeCrc32(0, v9, 8u);
    v13 = RtlComputeCrc32(v12, (int)&a9, 4u);
    if ( RtlComputeCrc32(v13, (int)(v11 + 1), v10 - 4) == *v11 )
      JUMPOUT(0x428E72);
  }
  JUMPOUT(0x428F0C);
}

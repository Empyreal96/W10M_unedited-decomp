// sub_53FBB8 
 
void __fastcall sub_53FBB8(int a1, int a2, int a3)
{
  _BYTE *v3; // r5
  unsigned int v4; // r3
  int v5; // r4

  if ( a3 && a2 )
  {
    v4 = *(_DWORD *)(a3 + 44);
    if ( v4 >= *(_DWORD *)(a2 + 148) )
      v4 = *(_DWORD *)(a2 + 148);
    v5 = (unsigned __int8)v4 * (unsigned __int8)v4;
    v3[48] = (unsigned int)(unsigned __int8)v3[50] * v5 / 0x2710;
    v3[49] = (unsigned int)(unsigned __int8)v3[51] * v5 / 0x2710;
  }
  JUMPOUT(0x4AAE60);
}

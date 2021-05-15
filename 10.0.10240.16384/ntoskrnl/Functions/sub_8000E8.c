// sub_8000E8 
 
void __fastcall sub_8000E8(int a1, int a2, unsigned int a3)
{
  int v3; // r3

  if ( a3 >> 21 < 0x20 )
  {
    v3 = *(_DWORD *)(a1 + 4 * (a3 >> 21) - 2);
    if ( v3 )
    {
      if ( *(_DWORD *)(v3 + 4 * ((a3 >> 11) & 0x3FF)) )
        JUMPOUT(0x73A41C);
    }
  }
  JUMPOUT(0x73A430);
}

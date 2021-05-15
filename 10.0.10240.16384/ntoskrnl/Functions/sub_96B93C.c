// sub_96B93C 
 
void __fastcall sub_96B93C(int a1, int a2)
{
  int v2; // r2

  if ( (unsigned int)dword_640508 < 0x80000 )
  {
    if ( (unsigned int)dword_640508 < 0x40000 )
      JUMPOUT(0x95767C);
    v2 = 128;
  }
  else
  {
    v2 = 256;
  }
  *(_DWORD *)(a2 + 3480) = v2;
  JUMPOUT(0x95763C);
}

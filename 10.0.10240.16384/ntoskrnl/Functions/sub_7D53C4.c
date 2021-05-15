// sub_7D53C4 
 
void __fastcall sub_7D53C4(int a1, int a2, int a3, char a4)
{
  _QWORD *v4; // r7
  int v5; // r8

  if ( (a4 & 0x20) == 0 && *(_DWORD *)(v5 + 32) )
  {
    if ( *v4 > 0x3FFFFFFFFFF000ui64 )
      JUMPOUT(0x6D8B04);
    JUMPOUT(0x6D89C2);
  }
  JUMPOUT(0x6D89BE);
}

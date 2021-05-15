// sub_7DEE20 
 
void __fastcall sub_7DEE20(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, char a11, char *a12, char a13)
{
  int v13; // r4
  int v14; // r5

  if ( *(_DWORD *)(v14 + 24) )
  {
    if ( v13 )
    {
      a12 = &a13;
      if ( !RtlLCIDToCultureName(v13, (unsigned int)&a11) )
        JUMPOUT(0x775474);
    }
    JUMPOUT(0x775480);
  }
  JUMPOUT(0x775472);
}

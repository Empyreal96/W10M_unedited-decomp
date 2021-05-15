// sub_7CDEC4 
 
void __fastcall sub_7CDEC4(int a1, int a2)
{
  unsigned int v2; // r5
  unsigned int v3; // r7
  __int16 v4; // r10
  int v5; // r0
  int v6; // r2
  unsigned int v7; // r4

  for ( ; v2; v2 -= v7 )
  {
    v5 = ((v3 >> 12) & 0x3FF) + (*(_DWORD *)((*(_DWORD *)&v4 & (v3 >> 20)) + a2) >> 12);
    v6 = MmPfnDatabase + 24 * v5;
    if ( *(_WORD *)(v6 + 16) != 1 )
      MiBadRefCount(v6);
    v7 = 1024 - (v5 & 0x3FF);
    if ( v7 > v2 )
      v7 = v2;
    MiAddExpansionNonPagedPool(v5, v7);
    a2 = -1070596096;
    v3 += v7 << 12;
  }
  JUMPOUT(0x7733DA);
}

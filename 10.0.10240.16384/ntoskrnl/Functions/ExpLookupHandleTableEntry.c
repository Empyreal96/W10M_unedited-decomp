// ExpLookupHandleTableEntry 
 
int __fastcall ExpLookupHandleTableEntry(int a1, int a2)
{
  int v2; // r0
  unsigned int v3; // r2
  int v5; // r1
  int v6; // r3

  v2 = *(_DWORD *)(a1 + 8);
  v3 = a2 & 0xFFFFFFFC;
  if ( (v2 & 3) == 0 )
  {
    if ( v3 < 0x800 )
      return v2 + 2 * v3;
    return 0;
  }
  if ( (v2 & 3) != 1 )
    return sub_8000E8();
  v5 = a2 & 0x7FC;
  if ( v3 >> 11 >= 0x400 )
    return 0;
  v6 = *(_DWORD *)(v2 + 4 * (v3 >> 11) - 1);
  if ( !v6 )
    return 0;
  return v6 + 2 * v5;
}

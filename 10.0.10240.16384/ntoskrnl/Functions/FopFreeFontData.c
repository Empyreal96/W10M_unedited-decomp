// FopFreeFontData 
 
int __fastcall FopFreeFontData(_DWORD *a1)
{
  int v3; // r0

  if ( (_DWORD *)a1[20] != a1 + 20 )
    return sub_8DFBAC();
  v3 = a1[4];
  if ( v3 )
    BgpFwFreeMemory(v3);
  if ( a1[3] )
    FopFreeMappingTable();
  return BgpFwFreeMemory((int)a1);
}

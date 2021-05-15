// FopFreeMappingTable 
 
int __fastcall FopFreeMappingTable(int a1)
{
  int v2; // r0

  v2 = *(_DWORD *)(a1 + 4);
  if ( v2 )
    BgpFwFreeMemory(v2);
  return BgpFwFreeMemory(a1);
}

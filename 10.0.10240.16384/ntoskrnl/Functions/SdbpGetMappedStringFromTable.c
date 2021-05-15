// SdbpGetMappedStringFromTable 
 
int __fastcall SdbpGetMappedStringFromTable(int a1, int a2, int a3)
{
  int v6; // r3
  int v7; // r5
  int v8; // r0

  if ( *(_DWORD *)(a1 + 8) )
    return sub_817A84();
  if ( !*(_DWORD *)(a1 + 1320) )
  {
    v8 = SdbFindFirstTag(a1, 0, 30721);
    *(_DWORD *)(a1 + 1320) = v8;
    if ( !v8 )
      JUMPOUT(0x817A90);
  }
  v6 = *(_DWORD *)(a1 + 1320);
  v7 = a2 + v6;
  if ( SdbGetTagFromTagID(a1, v7, a3, v6) != 34817 )
    JUMPOUT(0x817A98);
  return SdbpGetMappedTagData(a1, v7);
}

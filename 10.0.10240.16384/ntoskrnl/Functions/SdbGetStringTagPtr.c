// SdbGetStringTagPtr 
 
int __fastcall SdbGetStringTagPtr(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v8; // r3
  int v9; // r0

  v5 = 0;
  if ( !a1 )
    return sub_817A50();
  v8 = SdbGetTagFromTagID(a1, a2, a3, a4) & 0xF000;
  if ( v8 == 0x8000 )
    return SdbpGetMappedTagData(a1, a2);
  if ( v8 == 24576 )
  {
    v9 = SdbpReadStringRef(a1, a2);
    if ( !v9 )
      JUMPOUT(0x817A58);
    return SdbpGetMappedStringFromTable(a1, v9);
  }
  return v5;
}

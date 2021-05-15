// SdbFindNextTag 
 
int __fastcall SdbFindNextTag(int a1, int a2, int a3)
{
  int v4; // r5
  int v6; // r4
  int v7; // r8
  int v9; // r0

  v4 = a3;
  v6 = 0;
  v7 = SdbGetTagFromTagID(a1, a3);
  if ( !v7 )
    return sub_7CCB40();
  while ( 1 )
  {
    v9 = SdbGetNextChild(a1, a2, v4);
    v4 = v9;
    if ( !v9 )
      break;
    if ( SdbGetTagFromTagID(a1, v9) == v7 )
      return v4;
  }
  return v6;
}

// SdbFindFirstTag 
 
int __fastcall SdbFindFirstTag(int a1, int a2, int a3)
{
  int v6; // r5
  int i; // r0
  int v8; // r4

  v6 = 0;
  for ( i = SdbGetFirstChild(a1, a2); ; i = SdbGetNextChild(a1, a2, v8) )
  {
    v8 = i;
    if ( !i )
      break;
    if ( SdbGetTagFromTagID(a1, i) == a3 )
      return v8;
  }
  return v6;
}

// SdbFindFirstNamedTag 
 
int __fastcall SdbFindFirstNamedTag(int a1, int a2, int a3, int a4, int a5)
{
  int v9; // r5
  int i; // r0
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r2
  int v15; // r3
  unsigned __int16 *v16; // r0
  int v17; // r4

  v9 = 0;
  for ( i = SdbGetFirstChild(a1, a2, a3, a4); ; i = SdbGetNextChild(a1, a2, v17) )
  {
    v17 = i;
    if ( !i )
      break;
    if ( SdbGetTagFromTagID(a1, i, v11, v12) == a3 )
    {
      v13 = SdbFindFirstTag(a1, v17, a4);
      if ( v13 )
      {
        v16 = (unsigned __int16 *)SdbGetStringTagPtr(a1, v13, v14, v15);
        if ( !v16 )
        {
          AslLogCallPrintf(1, (int)"SdbFindFirstNamedTag", 152, "Can't get the name string");
          return v9;
        }
        if ( !wcsicmp(a5, v16) )
          return v17;
      }
    }
  }
  return v9;
}

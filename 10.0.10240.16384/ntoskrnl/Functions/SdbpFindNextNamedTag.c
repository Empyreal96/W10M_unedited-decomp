// SdbpFindNextNamedTag 
 
int __fastcall SdbpFindNextNamedTag(int a1, int a2, int a3, int a4, int a5)
{
  int v7; // r5
  int v9; // r4
  int v10; // r9
  int v11; // r0
  int v12; // r2
  int v13; // r3
  int v14; // r6
  unsigned __int16 *v15; // r0
  int v16; // r0
  int v17; // r2
  int v18; // r3

  v7 = a3;
  v9 = 0;
  v10 = SdbGetTagFromTagID(a1, a3, a3, a4);
  if ( v10 )
  {
    while ( 1 )
    {
      v16 = SdbGetNextChild(a1, a2, v7);
      v7 = v16;
      if ( !v16 )
        break;
      if ( SdbGetTagFromTagID(a1, v16, v17, v18) == v10 )
      {
        v11 = SdbFindFirstTag(a1, v7, a4);
        v14 = v11;
        if ( v11 )
        {
          v15 = (unsigned __int16 *)SdbGetStringTagPtr(a1, v11, v12, v13);
          if ( !v15 )
          {
            AslLogCallPrintf(1, (int)"SdbpFindNextNamedTag", 215, "Can't get the name string tagid 0x%lx", v14);
            return v9;
          }
          if ( !wcsicmp(a5, v15) )
            return v7;
        }
      }
    }
  }
  else
  {
    AslLogCallPrintf(1, (int)"SdbpFindNextNamedTag", 198, "Invalid tagid 0x%lx", v7);
  }
  return v9;
}

// SdbpGetExeEntryFlags 
 
int __fastcall SdbpGetExeEntryFlags(int a1, int a2, int *a3)
{
  int v6; // r4
  int v7; // r0
  int v8; // r4
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int v13; // [sp+8h] [bp-30h] BYREF
  _DWORD v14[10]; // [sp+10h] [bp-28h] BYREF

  v14[0] = 0;
  v14[1] = 0;
  v14[2] = 0;
  v14[3] = 0;
  v13 = 0;
  v6 = 0;
  v7 = SdbFindFirstTag(a1, a2, 36868);
  if ( v7 )
  {
    if ( SdbReadBinaryTag(a1, v7, (int)v14, 0x10u) )
    {
      if ( SdbGetEntryFlags(v14, &v13) )
        v8 = v13;
      else
        v8 = 0;
      v9 = SdbFindFirstTag(a1, a2, 28685);
      if ( v9 )
      {
        v8 |= 0x1000u;
        v10 = SdbFindFirstTag(a1, v9, 16400);
        if ( v10 )
        {
          if ( SdbReadDWORDTag(a1, v10, 0) == 2 )
            v8 |= 0x2000u;
        }
      }
      v11 = SdbFindFirstTag(a1, a2, 16434);
      if ( v11 )
        v8 |= SdbReadDWORDTag(a1, v11, 0) << 16;
      *a3 = v8;
      v6 = 1;
    }
    else
    {
      AslLogCallPrintf(1, (int)"SdbpGetExeEntryFlags", 449, "Failed to read the GUID for tiExe 0x%x", a2);
    }
  }
  else
  {
    AslLogCallPrintf(1, (int)"SdbpGetExeEntryFlags", 444, "Failed to read TAG_EXE_ID for tiExe 0x%x", a2);
  }
  return v6;
}

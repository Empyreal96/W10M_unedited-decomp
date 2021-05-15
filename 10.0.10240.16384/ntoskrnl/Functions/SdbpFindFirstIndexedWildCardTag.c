// SdbpFindFirstIndexedWildCardTag 
 
int __fastcall SdbpFindFirstIndexedWildCardTag(int a1, int a2, int a3, int a4, int *a5)
{
  int v7; // r0
  char v9; // r10
  int *v10; // r5
  unsigned int v11; // r8
  unsigned int v12; // r7
  int v13; // r4
  int v14; // r0
  int v15; // r1
  int v16; // r0
  int v17; // r0
  int v18[2]; // [sp+8h] [bp-140h] BYREF
  _DWORD v19[2]; // [sp+10h] [bp-138h] BYREF
  __int16 v20; // [sp+18h] [bp-130h]
  char v21[296]; // [sp+20h] [bp-128h] BYREF

  v18[0] = 0;
  v7 = SdbGetIndex(a1, a2, 24587, v18);
  *a5 = v7;
  if ( !v7 )
    return sub_7CC9B0();
  v9 = v18[0];
  a5[5] = v18[0];
  *((_WORD *)a5 + 6) = 24587;
  a5[8] = a4;
  memset(v21, 0, 260);
  v19[0] = 0;
  v19[1] = 0;
  v20 = 0;
  if ( AslStringUpcaseToMultiByteN(v21) < 0 )
  {
    AslLogCallPrintf(1, "SdbpFindFirstIndexedWildCardTag", 681, "Failed to convert name to multi-byte");
  }
  else
  {
    v10 = (int *)SdbpGetIndex(a1, *a5, v18);
    if ( v10 )
    {
      v11 = v18[0];
      v12 = 0;
      if ( v18[0] )
      {
        while ( 1 )
        {
          memmove((int)v18, (int)v10, 8u);
          v14 = *v10;
          v15 = v10[1];
          if ( (v9 & 2) != 0 )
          {
            SdbpKeyToAnsiString(v14, v15, (char *)v19 + 1);
            LOBYTE(v19[0]) = 42;
          }
          else
          {
            SdbpKeyToAnsiString(v14, v15, v19);
            LOBYTE(v20) = 42;
          }
          if ( AslStringPatternMatchA(v19, v21) )
          {
            v13 = v10[2];
            v16 = SdbFindFirstTag(a1, v13, *((unsigned __int16 *)a5 + 6));
            if ( v16 )
            {
              v17 = SdbGetStringTagPtr(a1, v16);
              if ( v17 )
              {
                if ( AslStringPatternMatchW(v17, a5[8]) )
                  break;
              }
            }
          }
          ++v12;
          v10 += 3;
          if ( v12 >= v11 )
            return 0;
        }
        a5[4] = v12;
        return v13;
      }
    }
    else
    {
      AslLogCallPrintf(1, "SdbpFindFirstIndexedWildCardTag", 691, "Failed to get index by tag id 0x%lx", *a5);
    }
  }
  return 0;
}

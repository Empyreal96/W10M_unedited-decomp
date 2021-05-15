// SdbpCheckForMatch 
 
int __fastcall SdbpCheckForMatch(int a1, int a2, int a3, int a4, int *a5, int a6)
{
  BOOL v10; // r9
  int v11; // r4
  int v12; // r0
  int v13; // r3
  BOOL v14; // r3
  int v16[8]; // [sp+10h] [bp-20h] BYREF

  v16[0] = 0;
  v10 = SdbFindFirstTag(a2, a3, 4109) != 0;
  if ( SdbpMatchOsVersion(a2, a3)
    && SdbpMatchList(v16, a1, a2, a3, a4, 0)
    && (v11 = v16[0]) != 0
    && SdbpGetExeEntryFlags(a2, a3, a6) )
  {
    if ( a5 )
    {
      v12 = SdbFindFirstTag(a2, a3, 12289);
      if ( v12 )
        *a5 = SdbReadWORDTag(a2, v12, 2, v13);
      else
        *a5 = 2;
    }
  }
  else
  {
    v11 = 0;
  }
  v14 = *(_DWORD *)(a4 + 40) && !v10;
  *(_DWORD *)(a4 + 40) = v14;
  return v11;
}

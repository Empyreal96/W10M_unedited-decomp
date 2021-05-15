// SdbpScanIndexes 
 
int __fastcall SdbpScanIndexes(int a1, int a2, int a3)
{
  int result; // r0
  int v5; // r0
  int v6; // r5
  int v7; // r6
  int v8; // r0
  int v9; // r3
  int v10; // r0
  int v11; // r3
  int v12; // r0
  int v13; // r0
  int v14; // r3

  if ( *(_DWORD *)(a1 + 1324) )
    return sub_7CCBB0();
  memset((_BYTE *)(a1 + 40), 0, 1280);
  *(_DWORD *)(a1 + 1324) = 1;
  v5 = SdbGetFirstChild(a1, 0);
  v6 = v5;
  if ( !v5 )
    return AslLogCallPrintf(1, "SdbpScanIndexes", 995, "Failed to get the child index from root", a3);
  if ( SdbGetTagFromTagID(a1, v5) != 30722 )
    return AslLogCallPrintf(1, "SdbpScanIndexes", 1000, "Root child tag is not index tagid 0x%lx", v6);
  *(_DWORD *)(a1 + 36) = 0;
  for ( result = SdbFindFirstTag(a1, v6, 30723); ; result = SdbFindNextTag(a1, v6, v7) )
  {
    v7 = result;
    if ( !result )
      break;
    if ( *(_DWORD *)(a1 + 36) == 32 )
      return AslLogCallPrintf(
               1,
               "SdbpScanIndexes",
               1015,
               "Too many indexes in file: recompile and increase SDB_MAX_INDEXES",
               a3);
    v8 = SdbFindFirstTag(a1, result, 14338);
    if ( !v8 )
      return AslLogCallPrintf(1, "SdbpScanIndexes", 1022, "Index missing TAG_INDEX_TAG", a3);
    *(_WORD *)(a1 + 40 * *(_DWORD *)(a1 + 36) + 44) = SdbReadWORDTag(a1, v8, 0, v9);
    v10 = SdbFindFirstTag(a1, v7, 14339);
    if ( !v10 )
      return AslLogCallPrintf(1, "SdbpScanIndexes", 1031, "Index missing TAG_INDEX_KEY", a3);
    *(_WORD *)(a1 + 40 * *(_DWORD *)(a1 + 36) + 46) = SdbReadWORDTag(a1, v10, 0, v11);
    v12 = SdbFindFirstTag(a1, v7, 16406);
    if ( v12 )
      *(_DWORD *)(a1 + 40 * *(_DWORD *)(a1 + 36) + 72) = SdbReadDWORDTag(a1, v12, 0);
    else
      *(_DWORD *)(a1 + 40 * *(_DWORD *)(a1 + 36) + 72) = 0;
    v13 = SdbFindFirstTag(a1, v7, 38913);
    v14 = a1 + 40 * *(_DWORD *)(a1 + 36);
    if ( !v13 )
    {
      *(_WORD *)(v14 + 44) = 0;
      return AslLogCallPrintf(1, "SdbpScanIndexes", 1048, "Index missing TAG_INDEX_BITS", a3);
    }
    *(_DWORD *)(v14 + 40) = v13;
    ++*(_DWORD *)(a1 + 36);
  }
  return result;
}

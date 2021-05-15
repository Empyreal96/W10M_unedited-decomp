// RtlpCopyRangeListEntry 
 
int __fastcall RtlpCopyRangeListEntry(int a1)
{
  int v2; // r0
  int v3; // r4
  int v5; // r3
  int v6; // r7
  int v7; // r0
  int v8; // r5
  int v9; // r0

  v2 = ExAllocateFromPagedLookasideList((int)&RtlpRangeListEntryLookasideList);
  v3 = v2;
  if ( !v2 )
    return v3;
  memmove(v2, a1, 0x28u);
  if ( (*(_BYTE *)(v3 + 25) & 0x10) != 0 )
    ++**(_DWORD **)(v3 + 16);
  if ( (*(_WORD *)(a1 + 26) & 1) == 0 )
    return v3;
  *(_DWORD *)(v3 + 16) = v3 + 16;
  *(_DWORD *)(v3 + 20) = v3 + 16;
  v5 = *(_DWORD *)(a1 + 16);
  v6 = v5 - 28;
  if ( a1 + 16 == v5 )
    return v3;
  v7 = ExAllocateFromPagedLookasideList((int)&RtlpRangeListEntryLookasideList);
  v8 = v7;
  if ( !v7 )
  {
    RtlpDeleteRangeListEntry(v3);
    return 0;
  }
  v9 = memmove(v7, v6, 0x28u);
  if ( (*(_BYTE *)(v8 + 25) & 0x10) != 0 )
    ++**(_DWORD **)(v8 + 16);
  return sub_80E7F8(v9);
}

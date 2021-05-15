// RtlpFreeRangeListEntry 
 
int __fastcall RtlpFreeRangeListEntry(int a1)
{
  _DWORD *v3; // r2

  if ( (*(_WORD *)(a1 + 26) & 1) == 0 && (*(_BYTE *)(a1 + 25) & 0x10) != 0 )
  {
    v3 = *(_DWORD **)(a1 + 16);
    if ( (*v3)-- == 1 )
      ExFreePoolWithTag(*(_DWORD *)(a1 + 16));
  }
  return ExFreeToPagedLookasideList((int)&RtlpRangeListEntryLookasideList, (_DWORD *)a1);
}

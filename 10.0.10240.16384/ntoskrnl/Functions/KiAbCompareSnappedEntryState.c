// KiAbCompareSnappedEntryState 
 
BOOL __fastcall KiAbCompareSnappedEntryState(int a1, _QWORD *a2)
{
  unsigned __int64 *v2; // r3
  unsigned __int64 v3; // kr00_8
  int v5; // [sp-18h] [bp-28h]

  __dmb(0xBu);
  v2 = (unsigned __int64 *)(a1 + 16);
  do
    v3 = __ldrexd(v2);
  while ( !v3 && __strexd(0i64, v2) );
  v5 = v3;
  __dmb(0xBu);
  return v5 < 0 && __PAIR64__(HIDWORD(v3), v3 & 0x7FFFFFFC) == *a2;
}

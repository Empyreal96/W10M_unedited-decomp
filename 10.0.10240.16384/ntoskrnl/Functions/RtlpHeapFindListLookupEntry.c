// RtlpHeapFindListLookupEntry 
 
int __fastcall RtlpHeapFindListLookupEntry(int a1, int a2, int a3, int a4, int a5)
{
  __int64 v5; // r4
  int v7; // r1

  v5 = *(_QWORD *)(a2 + 20);
  v7 = *(_DWORD *)(HIDWORD(v5) + 4);
  if ( HIDWORD(v5) == v7 || RtlpHeapListCompare(a1, v7, a5, a3) > 0 )
    return HIDWORD(v5);
  if ( RtlpHeapListCompare(a1, *(_DWORD *)HIDWORD(v5), a5, a3) <= 0 )
    return *(_DWORD *)HIDWORD(v5);
  return sub_528A54();
}

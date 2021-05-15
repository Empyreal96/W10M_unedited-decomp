// sub_80E76C 
 
void __fastcall sub_80E76C(int a1, int a2, __int64 *a3)
{
  int v3; // r4
  __int64 v4; // kr00_8

  v4 = *a3;
  if ( *(__int64 **)(*(_DWORD *)a3 + 4) == a3 && *(__int64 **)HIDWORD(v4) == a3 )
  {
    *(_DWORD *)HIDWORD(v4) = v4;
    *(_DWORD *)(v4 + 4) = HIDWORD(v4);
    RtlpFreeRangeListEntry(a1);
    --*(_DWORD *)(v3 + 12);
    ++*(_DWORD *)(v3 + 16);
    JUMPOUT(0x797856);
  }
  __fastfail(3u);
}

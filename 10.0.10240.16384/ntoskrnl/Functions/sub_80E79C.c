// sub_80E79C 
 
void __fastcall sub_80E79C(int a1, int a2, __int64 *a3)
{
  __int64 v3; // kr00_8

  v3 = *a3;
  if ( *(__int64 **)(*(_DWORD *)a3 + 4) == a3 && *(__int64 **)HIDWORD(v3) == a3 )
  {
    *(_DWORD *)HIDWORD(v3) = v3;
    *(_DWORD *)(v3 + 4) = HIDWORD(v3);
    RtlpDeleteRangeListEntry(a1);
    JUMPOUT(0x7978BC);
  }
  __fastfail(3u);
}

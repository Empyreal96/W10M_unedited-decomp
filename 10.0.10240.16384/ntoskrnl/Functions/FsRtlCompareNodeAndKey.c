// FsRtlCompareNodeAndKey 
 
int __fastcall FsRtlCompareNodeAndKey(int a1, unsigned __int64 a2, int a3)
{
  unsigned __int64 v4; // kr00_8
  int v6; // r0

  v4 = *(_QWORD *)(a1 + 32);
  if ( HIDWORD(v4) < HIDWORD(a2) )
    return -1;
  if ( HIDWORD(v4) > HIDWORD(a2) || (unsigned int)v4 > (unsigned int)a2 )
    return 1;
  if ( v4 < a2 )
    return -1;
  if ( (*(_DWORD *)(a1 + 40) & 2) != 0 )
    v6 = a1 + 52;
  else
    v6 = a1 + 44;
  return RtlCompareUnicodeString(v6, a3, 1);
}

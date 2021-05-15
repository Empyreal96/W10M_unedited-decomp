// CmpFreeSubordinatePost 
 
unsigned int __fastcall CmpFreeSubordinatePost(unsigned int result)
{
  __int64 *v1; // r2
  __int64 v2; // r0
  __int64 v3; // r0

  if ( *(_DWORD *)(result + 16) != result + 16 )
  {
    v1 = *(__int64 **)(result + 16);
    v2 = *v1;
    if ( *(__int64 **)(*(_DWORD *)v1 + 4) != v1 || *(__int64 **)HIDWORD(v2) != v1 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v2) = v2;
    *(_DWORD *)(v2 + 4) = HIDWORD(v2);
    v3 = *(v1 - 1);
    if ( *(__int64 **)(v3 + 4) != v1 - 1 || *(__int64 **)HIDWORD(v3) != v1 - 1 )
      sub_7DF05C();
    *(_DWORD *)HIDWORD(v3) = v3;
    *(_DWORD *)(v3 + 4) = HIDWORD(v3);
    result = CmpFreePostBlock((_DWORD *)v1 - 4);
  }
  return result;
}

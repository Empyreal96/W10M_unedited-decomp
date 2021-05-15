// sub_8DFAD0 
 
// local variable allocation has failed, the output may be wrong!
void sub_8DFAD0()
{
  int v0; // r4
  __int64 **v1; // r5
  int v2; // r8
  __int64 *v3; // r0
  __int64 v4; // r2
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED

  while ( *v1 != (__int64 *)v1 )
  {
    v3 = *v1;
    v4 = **v1;
    if ( (__int64 **)HIDWORD(v4) != v1 || *(__int64 **)(v4 + 4) != v3 )
      __fastfail(3u);
    *v1 = (__int64 *)v4;
    *(_DWORD *)(v4 + 4) = v1;
    FopFreeFontData(v3);
  }
  *(_QWORD *)&v5 = *(_QWORD *)v0;
  if ( *(_DWORD *)(*(_DWORD *)v0 + 4) == v0 && *v6 == v0 )
  {
    *v6 = v5;
    *(_DWORD *)(v5 + 4) = v6;
    BgpFwFreeMemory(v2);
    JUMPOUT(0x8DDF20);
  }
  __fastfail(3u);
}

// sub_50FE90 
 
void sub_50FE90()
{
  __int64 **v0; // r4
  __int64 *v1; // r0
  __int64 v2; // r2

  v1 = *v0;
  v2 = **v0;
  if ( (__int64 **)HIDWORD(v2) == v0 && *(__int64 **)(v2 + 4) == v1 )
  {
    *v0 = (__int64 *)v2;
    *(_DWORD *)(v2 + 4) = v0;
    RtlpFreeAtom(v1);
    JUMPOUT(0x42637E);
  }
  __fastfail(3u);
}

// sub_8119C0 
 
void sub_8119C0()
{
  int v0; // r4
  __int64 *v1; // r0
  __int64 v2; // kr00_8

  v1 = *(__int64 **)(v0 + 4);
  v2 = *v1;
  if ( *(_DWORD *)v1 == v0 && *(__int64 **)HIDWORD(v2) == v1 )
  {
    *(_DWORD *)(v0 + 4) = HIDWORD(v2);
    *(_DWORD *)HIDWORD(v2) = v0;
    PipFreeBindingId();
    JUMPOUT(0x7A1834);
  }
  __fastfail(3u);
}

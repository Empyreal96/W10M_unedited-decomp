// sub_525090 
 
void sub_525090()
{
  int v0; // r9
  __int64 v1; // r0

  v1 = *(_QWORD *)(v0 + 136);
  if ( *(_DWORD *)(v1 + 4) == v0 + 136 && *(_DWORD *)HIDWORD(v1) == v0 + 136 )
  {
    *(_DWORD *)HIDWORD(v1) = v1;
    *(_DWORD *)(v1 + 4) = HIDWORD(v1);
    JUMPOUT(0x45E972);
  }
  __fastfail(3u);
}

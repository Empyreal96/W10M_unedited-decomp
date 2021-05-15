// sub_522F04 
 
void __fastcall sub_522F04(int a1)
{
  __int64 v1; // kr00_8

  v1 = *(_QWORD *)(a1 + 144);
  if ( *(_DWORD *)(v1 + 4) == a1 + 144 && *(_DWORD *)HIDWORD(v1) == a1 + 144 )
    JUMPOUT(0x458862);
  __fastfail(3u);
}

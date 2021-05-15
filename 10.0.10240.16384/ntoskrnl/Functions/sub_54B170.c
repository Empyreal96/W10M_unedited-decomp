// sub_54B170 
 
void __fastcall sub_54B170(__int64 a1, _QWORD *a2)
{
  LODWORD(a1) = *(_DWORD *)HIDWORD(a1);
  *a2 = a1;
  if ( *(_DWORD *)(a1 + 4) != HIDWORD(a1) )
    __fastfail(3u);
  *(_DWORD *)(a1 + 4) = a2;
  *(_DWORD *)HIDWORD(a1) = a2;
  JUMPOUT(0x4D2628);
}

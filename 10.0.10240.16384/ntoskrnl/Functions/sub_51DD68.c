// sub_51DD68 
 
void __fastcall sub_51DD68(int a1)
{
  int v1; // r5
  int v2; // r7
  __int64 v3; // kr00_8

  v3 = *(_QWORD *)(a1 + 8);
  if ( *(_DWORD *)(v3 + 4) == a1 + 8 && *(_DWORD *)HIDWORD(v3) == a1 + 8 )
  {
    *(_DWORD *)HIDWORD(v3) = v3;
    *(_DWORD *)(v3 + 4) = HIDWORD(v3);
    *(_DWORD *)(a1 + 16) &= ~v2;
    --*(_DWORD *)(v1 + 52);
    JUMPOUT(0x44BE32);
  }
  __fastfail(3u);
}

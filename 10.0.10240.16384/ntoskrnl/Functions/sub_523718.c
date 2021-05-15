// sub_523718 
 
void __fastcall sub_523718(int a1)
{
  int v1; // r3
  __int64 v2; // kr00_8
  int v3; // r2
  int v4; // r6
  int v5; // r4

  v1 = *(_DWORD *)(a1 + 8);
  *(_BYTE *)(a1 + 46) = 0;
  v2 = *(_QWORD *)(a1 + 12);
  v3 = v1 + 100;
  v4 = *(char *)(a1 + 45);
  if ( *(_DWORD *)(v2 + 4) == a1 + 12 && *(_DWORD *)HIDWORD(v2) == a1 + 12 )
  {
    *(_DWORD *)HIDWORD(v2) = v2;
    *(_DWORD *)(v2 + 4) = HIDWORD(v2);
    if ( HIDWORD(v2) == (_DWORD)v2 )
    {
      v5 = v3 + 8 * v4;
      if ( *(_DWORD *)(a1 + 12) == v5 && *(_DWORD *)(a1 + 16) == v5 )
      {
        if ( v4 )
          *(_BYTE *)(v3 + 22) = 0;
        else
          *(_BYTE *)(v3 + 21) = 0;
      }
    }
    JUMPOUT(0x45A3FA);
  }
  __fastfail(3u);
}

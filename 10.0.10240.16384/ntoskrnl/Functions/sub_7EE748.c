// sub_7EE748 
 
void __fastcall sub_7EE748(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4
  int v6; // r2
  __int64 v7; // r0

  v6 = *(_DWORD *)(*(_DWORD *)(v5 + 2004) + 8 * a5 + 4) + 8;
  v7 = *(_QWORD *)v6;
  if ( *(_DWORD *)(*(_DWORD *)v6 + 4) == v6 && *(_DWORD *)HIDWORD(v7) == v6 )
  {
    *(_DWORD *)HIDWORD(v7) = v7;
    *(_DWORD *)(v7 + 4) = HIDWORD(v7);
    ExFreePoolWithTag(*(_DWORD *)(*(_DWORD *)(v5 + 2004) + 8 * a5 + 4));
    memmove(*(_DWORD *)(v5 + 2004) + 8 * a5, *(_DWORD *)(v5 + 2004) + 8 * a5 + 8, 8 * (*(_DWORD *)(v5 + 1992) - a5 - 1));
    --*(_DWORD *)(v5 + 1992);
    JUMPOUT(0x780496);
  }
  __fastfail(3u);
}

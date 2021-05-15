// RtlAddRange 
 
int __fastcall RtlAddRange(int a1, unsigned __int64 a2, unsigned __int64 a3, char a4, char a5, int a6, int a7)
{
  int v8; // r8
  int v9; // r5
  int v11; // r0
  int v12; // r5

  v8 = HIDWORD(a2);
  v9 = a2;
  if ( a3 < a2 )
    return -1073741811;
  v11 = ExAllocateFromPagedLookasideList((int)&RtlpRangeListEntryLookasideList);
  if ( !v11 )
    return -1073741823;
  *(_BYTE *)(v11 + 25) = 0;
  *(_WORD *)(v11 + 26) = 0;
  *(_DWORD *)v11 = v9;
  *(_DWORD *)(v11 + 20) = a7;
  *(_DWORD *)(v11 + 4) = v8;
  *(_DWORD *)(v11 + 8) = a3;
  *(_BYTE *)(v11 + 24) = a4;
  *(_DWORD *)(v11 + 12) = HIDWORD(a3);
  *(_DWORD *)(v11 + 16) = a6;
  if ( (a5 & 2) != 0 )
    *(_BYTE *)(v11 + 25) |= 1u;
  if ( (a5 & 0x10) != 0 )
    *(_BYTE *)(v11 + 25) |= 0x10u;
  v12 = RtlpAddRange(a1, v11);
  if ( v12 < 0 )
    return sub_80E48C();
  ++*(_DWORD *)(a1 + 12);
  ++*(_DWORD *)(a1 + 16);
  return v12;
}

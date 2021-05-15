// MiExpandPagedPool 
 
int __fastcall MiExpandPagedPool(int a1, unsigned int a2)
{
  int v4; // r6
  int v5; // r3
  unsigned int v6; // r5
  unsigned int v7; // r0
  unsigned int v8; // r9
  int v9; // r2
  unsigned int v10; // r10
  unsigned int v12; // r2
  int v13; // [sp+0h] [bp-30h]
  unsigned int v14[10]; // [sp+8h] [bp-28h] BYREF

  if ( (_UNKNOWN *)a1 == &unk_632CF4 )
  {
    MiFreeExcessSegments(1);
    v4 = 0;
    v5 = 14;
  }
  else if ( (int *)a1 == dword_634D34 )
  {
    MiFreeExcessSegments(1);
    v4 = 0;
    v5 = 6;
  }
  else
  {
    v4 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    v5 = 1;
  }
  v6 = (a2 + 1023) & 0xFFFFFC00;
  v13 = v5;
  if ( v6 < a2 || (v4 ? (v7 = MiObtainSessionVa(v6 >> 10)) : (v7 = MiObtainSystemVa(v6 >> 10, v5)), (v8 = v7) == 0) )
    JUMPOUT(0x52855A);
  v9 = (v7 >> 10) & 0x3FFFFC;
  v14[0] = v9 - 0x40000000;
  v10 = (v9 - *(_DWORD *)(a1 + 12) - 0x40000000) >> 2;
  if ( !MiSplitBitmapPages(v13, *(_DWORD *)(a1 + 8) + (v10 >> 3), (v10 & 7) + v6) )
    return sub_52852C();
  v12 = v10 + v6;
  if ( v10 + v6 > *(_DWORD *)(a1 + 4) )
  {
    if ( v12 > *(_DWORD *)(a1 + 16) )
      v12 = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(a1 + 4) = v12;
  }
  if ( !MiMakeZeroedPageTables(v14[0], v14[0] + 4 * v6 - 4, 0) )
    return sub_52852C();
  if ( v4 )
  {
    v14[1] = v4 + 8196;
    v14[0] = 512;
    RtlSetBits(v14, (v8 - dword_63389C) >> 22, v6 >> 10);
    *(_DWORD *)(v4 + 8308) += v6 >> 10;
  }
  if ( v6 != a2 )
    RtlClearBits((_BYTE *)(a1 + 4), v10 + a2, v6 - a2);
  return v10;
}

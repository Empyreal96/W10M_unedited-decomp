// FsRtlSplitBaseMcb 
 
int __fastcall FsRtlSplitBaseMcb(int a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned int v8; // r4
  int v9; // r1
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v13; // r3
  int v14; // r2
  int v15; // r0
  unsigned int v16[6]; // [sp+0h] [bp-18h] BYREF

  v16[0] = a4;
  if ( !FsRtlFindLargeIndex(a1, a3, (int *)v16) )
    return 0;
  v8 = v16[0];
  v9 = *(_DWORD *)(a1 + 12) + 8 * v16[0];
  if ( *(_DWORD *)(v9 + 4) == -1 )
    goto LABEL_31;
  if ( v16[0] )
    v10 = *(_DWORD *)(v9 - 8);
  else
    v10 = 0;
  if ( v10 == a3 )
  {
    if ( !v16[0] )
      goto LABEL_16;
    v11 = *(_DWORD *)(v9 - 4);
    if ( v11 == -1 || (v16[0] != 1 ? (v12 = *(_DWORD *)(v9 - 16)) : (v12 = 0), !(*(_DWORD *)(v9 - 8) + v11 - v12)) )
    {
      v8 = v16[0] - 1;
      goto LABEL_31;
    }
  }
  if ( v16[0] )
  {
    v13 = *(_DWORD *)(v9 - 8);
    goto LABEL_18;
  }
LABEL_16:
  v13 = 0;
LABEL_18:
  if ( v13 == a3 )
  {
    if ( FsRtlAddEntry((__int64 *)a1, v16[0], 1, v13) )
    {
      *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v8 + 4) = -1;
      *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v8) = a5 + a3;
      goto LABEL_30;
    }
    return 0;
  }
  if ( !FsRtlAddEntry((__int64 *)a1, v16[0], 2, v13) )
    return 0;
  *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v8 + 4) = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v8 + 20);
  *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v8) = a3;
  *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v8 + 12) = -1;
  *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v8 + 8) = a5 + a3;
  if ( v8 == -1 )
    v14 = 0;
  else
    v14 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v8);
  if ( v8 )
    v15 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v8 - 8);
  else
    v15 = 0;
  *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v8 + 20) += v14 - v15;
LABEL_31:
  for ( v8 += 2; v8 < *(_DWORD *)(a1 + 4); ++v8 )
  {
    *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v8) += a5;
LABEL_30:
    ;
  }
  return 1;
}

// RtlpAddToMergedRange 
 
int __fastcall RtlpAddToMergedRange(int a1, int a2, char a3)
{
  char v3; // r10
  int v4; // lr
  int v5; // r4
  int *v6; // r5
  unsigned __int64 v7; // r8
  _DWORD *v9; // r4
  int v10; // r2
  unsigned __int64 v11; // kr08_8
  int v12; // r2

  v3 = *(_BYTE *)(a2 + 25);
  v4 = a1 + 16;
  v5 = *(_DWORD *)(a1 + 16) - 28;
  v6 = 0;
  if ( a1 + 16 == *(_DWORD *)(a1 + 16) )
  {
LABEL_13:
    v9 = *(_DWORD **)(a1 + 20);
    v10 = a2 + 28;
    *(_DWORD *)(a2 + 28) = v4;
    *(_DWORD *)(a2 + 32) = v9;
    if ( *v9 != v4 )
      __fastfail(3u);
    *v9 = v10;
    *(_DWORD *)(a1 + 20) = v10;
  }
  else
  {
    do
    {
      v7 = *(_QWORD *)v5;
      if ( *(_QWORD *)v5 < *(_QWORD *)a2 )
        return sub_80D67C();
      if ( *(_QWORD *)a2 < v7 && *(_QWORD *)(a2 + 8) < v7 )
        JUMPOUT(0x80D68E);
      if ( (v3 & 1) == 0 || (*(_BYTE *)(v5 + 25) & 1) == 0 )
      {
        if ( (a3 & 1) == 0 )
          return -1073741182;
        *(_BYTE *)(v5 + 25) |= 2u;
        *(_BYTE *)(a2 + 25) |= 2u;
      }
      if ( !v6 && *(_QWORD *)v5 > *(_QWORD *)a2 )
        v6 = *(int **)(v5 + 32);
      v5 = *(_DWORD *)(v5 + 28) - 28;
    }
    while ( v4 != v5 + 28 );
    if ( !v6 )
      goto LABEL_13;
    v12 = *v6;
    *(_DWORD *)(a2 + 28) = *v6;
    *(_DWORD *)(a2 + 32) = v6;
    *(_DWORD *)(v12 + 4) = a2 + 28;
    *v6 = a2 + 28;
  }
  if ( *(_QWORD *)a2 < *(_QWORD *)a1 )
    *(_QWORD *)a1 = *(_QWORD *)a2;
  v11 = *(_QWORD *)(a2 + 8);
  if ( v11 > *(_QWORD *)(a1 + 8) )
    *(_QWORD *)(a1 + 8) = v11;
  if ( (*(_BYTE *)(a1 + 25) & 1) != 0 && (v3 & 1) == 0 )
    *(_BYTE *)(a1 + 25) &= 0xFEu;
  return 0;
}

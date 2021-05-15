// RtlDeleteOwnersRanges 
 
int __fastcall RtlDeleteOwnersRanges(int **a1, int a2)
{
  int v4; // r5
  int v5; // r0
  int v6; // r3
  int v7; // r6
  int v9; // r2
  _DWORD *v10; // r3
  _DWORD *v11; // lr

  v4 = 0;
LABEL_2:
  v5 = (int)(*a1 - 7);
  v6 = **a1;
  while ( 1 )
  {
    v7 = v6 - 28;
    if ( a1 == (int **)(v5 + 28) )
      return v4;
    if ( (*(_WORD *)(v5 + 26) & 1) != 0 )
    {
      v9 = *(_DWORD *)(v5 + 16) - 28;
      v10 = **(_DWORD ***)(v5 + 16);
      while ( 1 )
      {
        v11 = v10 - 7;
        if ( v5 + 16 == v9 + 28 )
          break;
        if ( *(_DWORD *)(v9 + 20) == a2 )
        {
          v4 = RtlpDeleteFromMergedRange(v9);
          if ( v4 < 0 )
            return v4;
          a1[3] = (int *)((char *)a1[3] - 1);
          a1[4] = (int *)((char *)a1[4] + 1);
          goto LABEL_2;
        }
        v10 = (_DWORD *)*v10;
        v9 = (int)v11;
      }
    }
    else if ( *(_DWORD *)(v5 + 20) == a2 )
    {
      return sub_80E76C();
    }
    v6 = *(_DWORD *)(v7 + 28);
    v5 = v7;
  }
}

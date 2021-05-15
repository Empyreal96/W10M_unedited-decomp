// RtlpAddRange 
 
int __fastcall RtlpAddRange(__int64 a1, int a2)
{
  int v2; // r4
  unsigned int v3; // r6
  unsigned int v4; // r10
  unsigned int v5; // lr
  unsigned int v6; // r7
  int v7; // r8
  unsigned __int64 v8; // kr08_8
  int *v10; // r1
  int v11; // r2
  int v12; // r2
  unsigned int v13; // [sp+0h] [bp-20h]

  v2 = HIDWORD(a1);
  v3 = *(_DWORD *)(HIDWORD(a1) + 12);
  v4 = *(_DWORD *)(HIDWORD(a1) + 8);
  v5 = *(_DWORD *)(HIDWORD(a1) + 4);
  *(_BYTE *)(HIDWORD(a1) + 25) &= 0xFDu;
  v6 = *(_DWORD *)HIDWORD(a1);
  v7 = 0;
  v13 = v3;
  if ( *(_DWORD *)a1 != (_DWORD)a1 && __PAIR64__(v5, v6) <= *(_QWORD *)(*(_DWORD *)(a1 + 4) - 20) )
  {
    for ( HIDWORD(a1) = *(_DWORD *)a1 - 28; (_DWORD)a1 != HIDWORD(a1) + 28; HIDWORD(a1) = *(_DWORD *)(HIDWORD(a1) + 28)
                                                                                        - 28 )
    {
      v8 = *(_QWORD *)HIDWORD(a1);
      if ( __PAIR64__(v3, v4) < *(_QWORD *)HIDWORD(a1) )
      {
        v10 = *(int **)(HIDWORD(a1) + 32);
        v11 = *v10;
        *(_DWORD *)(v2 + 28) = *v10;
        *(_DWORD *)(v2 + 32) = v10;
        *(_DWORD *)(v11 + 4) = v2 + 28;
        *v10 = v2 + 28;
        return v7;
      }
      if ( __PAIR64__(v5, v6) < v8 )
        return sub_80E498();
      if ( v8 >= __PAIR64__(v5, v6) || *(_QWORD *)(HIDWORD(a1) + 8) >= __PAIR64__(v5, v6) )
        return RtlpAddIntersectingRanges(a1, SHIDWORD(a1), v2, a2);
      v3 = v13;
    }
  }
  HIDWORD(a1) = *(_DWORD *)(a1 + 4);
  v12 = v2 + 28;
  *(_QWORD *)(v2 + 28) = a1;
  if ( *(_DWORD *)HIDWORD(a1) != (_DWORD)a1 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(a1) = v12;
  *(_DWORD *)(a1 + 4) = v12;
  return v7;
}

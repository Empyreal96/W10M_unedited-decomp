// RtlpCoalesceFreeBlocks 
 
int __fastcall RtlpCoalesceFreeBlocks(int a1, unsigned __int8 *a2, int *a3)
{
  unsigned __int8 *v3; // r8
  unsigned __int8 *v5; // r5
  unsigned int v7; // r0
  __int64 v9; // kr00_8
  int v10; // r2
  int v11; // r3
  unsigned __int8 *v12; // r4
  unsigned int v13; // r1
  _DWORD *v14; // r1
  unsigned int i; // r3
  _DWORD *v16; // r3
  unsigned int v17; // r3
  int v18; // r3
  char *v19; // r4
  char *v20; // r0
  __int64 v21; // kr08_8
  _DWORD *v22; // r1
  unsigned int j; // r3
  _DWORD *v24; // r3
  unsigned int v25; // r3
  int v26; // r3
  char *v27; // r5
  char *v28; // r0
  int v29; // r3

  v3 = a2;
  v5 = &a2[-8 * (*((unsigned __int16 *)a2 + 2) ^ *(unsigned __int16 *)(a1 + 84))];
  if ( v5 != a2 )
  {
    v7 = *(_DWORD *)(a1 + 76);
    if ( ((v5[2] ^ *(unsigned __int8 *)(a1 + 82) & (v7 >> 20)) & 1) == 0 )
    {
      if ( v7 )
      {
        *(_DWORD *)v5 ^= *(_DWORD *)(a1 + 80);
        if ( v5[3] != (v5[2] ^ v5[1] ^ *v5) )
          return sub_554174();
      }
      v9 = *((_QWORD *)v5 + 1);
      if ( *(_DWORD *)HIDWORD(v9) == *(_DWORD *)(v9 + 4) && *(unsigned __int8 **)HIDWORD(v9) == v5 + 8 )
      {
        v14 = *(_DWORD **)(a1 + 180);
        *(_DWORD *)(a1 + 116) -= *(unsigned __int16 *)v5;
        if ( v14 )
        {
          for ( i = v14[1]; ; i = v16[1] )
          {
            if ( *(unsigned __int16 *)v5 < i )
            {
              v17 = *(unsigned __int16 *)v5;
              goto LABEL_9;
            }
            v16 = (_DWORD *)*v14;
            if ( !*v14 )
              break;
            v14 = (_DWORD *)*v14;
          }
          v17 = v14[1] - 1;
LABEL_9:
          RtlpHeapRemoveListEntry(a1, v14, 1, (_DWORD *)v5 + 2, v17);
        }
        *(_DWORD *)HIDWORD(v9) = v9;
        *(_DWORD *)(v9 + 4) = HIDWORD(v9);
        if ( (v5[2] & 4) != 0 )
        {
          v18 = 8 * *(unsigned __int16 *)v5;
          v19 = (char *)(v18 - 16);
          if ( (v5[2] & 2) != 0 && (unsigned int)v19 > 4 )
            v19 = (char *)(v18 - 20);
          v20 = RtlCompareMemoryUlong((int *)v5 + 4, v19, -17891602);
          if ( v20 != v19 )
          {
            DbgPrint("HEAP: Free Heap block %p modified at %p after it was freed\n", v5, &v5[(_DWORD)v20 + 16]);
            if ( KdDebuggerEnabled )
              __debugbreak();
          }
        }
        v10 = *(unsigned __int16 *)v5;
        v5[2] = 0;
        v5[7] = 0;
        v3 = v5;
        v11 = *a3 + v10;
        *a3 = v11;
        *(_WORD *)v5 = v11;
        *(_WORD *)&v5[8 * *a3 + 4] = *(_WORD *)(a1 + 84) ^ *(_WORD *)a3;
      }
      else
      {
        RtlpLogHeapFailure(12, a1);
      }
    }
  }
  v12 = &v3[8 * *a3];
  if ( *(_DWORD *)(a1 + 76)
    && (unsigned int)(*(_DWORD *)(a1 + 80) ^ *(_DWORD *)v12) >> 24 != ((unsigned __int8)((unsigned __int16)(*(_WORD *)(a1 + 80) ^ *(_WORD *)v12) >> 8) ^ (unsigned __int8)(*(_BYTE *)(a1 + 80) ^ *v12) ^ (unsigned __int8)((unsigned int)(*(_DWORD *)(a1 + 80) ^ *(_DWORD *)v12) >> 16)) )
  {
    RtlpLogHeapFailure(3, a1);
  }
  while ( 1 )
  {
    v13 = *(_DWORD *)(a1 + 76);
    if ( ((v12[2] ^ *(unsigned __int8 *)(a1 + 82) & (v13 >> 20)) & 1) != 0 )
      return (int)v3;
    if ( v13 )
    {
      *(_DWORD *)v12 ^= *(_DWORD *)(a1 + 80);
      if ( v12[3] != (v12[2] ^ v12[1] ^ *v12) )
        RtlpAnalyzeHeapFailure(a1, v12);
    }
    v21 = *((_QWORD *)v12 + 1);
    if ( *(_DWORD *)HIDWORD(v21) == *(_DWORD *)(v21 + 4) && *(unsigned __int8 **)HIDWORD(v21) == v12 + 8 )
    {
      v22 = *(_DWORD **)(a1 + 180);
      *(_DWORD *)(a1 + 116) -= *(unsigned __int16 *)v12;
      if ( v22 )
      {
        for ( j = v22[1]; ; j = v24[1] )
        {
          if ( *(unsigned __int16 *)v12 < j )
          {
            v25 = *(unsigned __int16 *)v12;
            goto LABEL_45;
          }
          v24 = (_DWORD *)*v22;
          if ( !*v22 )
            break;
          v22 = (_DWORD *)*v22;
        }
        v25 = v22[1] - 1;
LABEL_45:
        RtlpHeapRemoveListEntry(a1, v22, 1, (_DWORD *)v12 + 2, v25);
      }
      *(_DWORD *)HIDWORD(v21) = v21;
      *(_DWORD *)(v21 + 4) = HIDWORD(v21);
      if ( (v12[2] & 4) != 0 )
      {
        v26 = 8 * *(unsigned __int16 *)v12;
        v27 = (char *)(v26 - 16);
        if ( (v12[2] & 2) != 0 && (unsigned int)v27 > 4 )
          v27 = (char *)(v26 - 20);
        v28 = RtlCompareMemoryUlong((int *)v12 + 4, v27, -17891602);
        if ( v28 != v27 )
        {
          DbgPrint("HEAP: Free Heap block %p modified at %p after it was freed\n", v12, &v28[(_DWORD)(v12 + 16)]);
          if ( KdDebuggerEnabled )
            __debugbreak();
        }
      }
      v3[2] = 0;
      v3[7] = 0;
      v29 = *a3 + *(unsigned __int16 *)v12;
      *a3 = v29;
      *(_WORD *)v3 = v29;
      *(_WORD *)&v3[8 * *a3 + 4] = *(_WORD *)(a1 + 84) ^ *(_WORD *)a3;
      return (int)v3;
    }
    RtlpLogHeapFailure(12, a1);
  }
}

// MiLogPageAccess 
 
int __fastcall MiLogPageAccess(int result, unsigned int a2)
{
  _DWORD *v2; // r8
  __int16 v4; // r9
  _DWORD *v5; // r1
  int *v6; // r5
  unsigned int v7; // r10
  int v8; // r0
  int v9; // r6
  int v10; // r0
  __int64 v11; // r0
  unsigned int v12; // r7
  int v13; // r3
  int **v14; // r1
  int **v15; // r2
  unsigned int v16; // r2
  unsigned int *v17; // r3
  int *v18; // [sp+0h] [bp-30h]
  int v19[10]; // [sp+8h] [bp-28h]

  v2 = *(_DWORD **)(result + 8);
  v19[0] = 0;
  v19[1] = 3;
  if ( v2 && (unsigned int)(v2[8] + 8) <= v2[9]
    || (result = (int)MiAllocateAccessLog(result), (v2 = (_DWORD *)result) != 0) )
  {
    if ( (a2 & 1) != 0 )
    {
      a2 &= 0xFFFFFFFE;
      v4 = 1;
    }
    else
    {
      v4 = 0;
    }
    v5 = (_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)a2 >> 12));
    if ( (v5[5] & 0x8000000) == 0 || (v5[2] & 0x400) == 0 )
    {
      v16 = (v4 << 9) & 0x200;
LABEL_21:
      v17 = (unsigned int *)v2[8];
      *v17 = v16;
      v17[1] = a2;
      v2[8] += 8;
      return result;
    }
    v6 = (int *)(v5[2] & 0xFFFFF800 | (2 * (v5[2] & 0x3FC)));
    v7 = v2[10];
    a2 = v5[1] | 0x80000000;
    if ( v2[11] > 1u )
    {
      v8 = 0;
      goto LABEL_14;
    }
    v9 = *v6;
    if ( (*(_WORD *)((v5[2] & 0xFFFFF800 | (2 * (v5[2] & 0x3FC))) + 0x12) & 2) == 0
      || (*(_DWORD *)(v9 + 28) & 0x4000000) == 0 )
    {
      v10 = MI_REFERENCE_CONTROL_AREA_FILE(*v6);
      v18 = *(int **)(v10 + 12);
      MI_DEREFERENCE_CONTROL_AREA_FILE(v9, v10);
      LODWORD(v11) = MiStartingOffset(v6, a2);
      v12 = *(_DWORD *)(v9 + 28);
      v7 -= 4;
      v13 = v19[(v12 >> 5) & 1];
      v6 = v18;
      a2 = (unsigned __int64)(v11 << v13) >> 32;
      v8 = ((unsigned __int16)((_DWORD)v11 << v13) ^ (unsigned __int16)(32 * v12)) & 0x400 ^ ((_DWORD)v11 << v13);
LABEL_14:
      v14 = (int **)v2[9];
      v15 = v14 + 1;
      if ( (unsigned int)(v14 + 1) > v7 )
        goto LABEL_18;
      do
      {
        if ( *v15 == v6 )
          break;
        ++v15;
      }
      while ( (unsigned int)v15 <= v7 );
      if ( (unsigned int)v15 > v7 )
      {
LABEL_18:
        v2[9] = v14 - 1;
        *v14 = v6;
        v15 = v14;
      }
      result = v8 & 0xFFFFFC00;
      v16 = ((unsigned int)(v2[10] - (_DWORD)v15) >> 2) & 0x1FF | ((v4 & 1) << 9) | result;
      goto LABEL_21;
    }
  }
  return result;
}

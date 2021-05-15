// PopAddPagesToCompressedPageSet 
 
int __fastcall PopAddPagesToCompressedPageSet(unsigned int a1, int a2, int *a3, int a4, char a5, int a6, int a7)
{
  int v7; // r4
  int v9; // r8
  int v10; // r7
  int v11; // r10
  __int64 v12; // kr00_8
  unsigned int v13; // r2
  unsigned int v14; // r3
  int v15; // r5
  unsigned int v16; // r1
  unsigned int v17; // r6
  int v18; // r4
  __int64 v19; // r0
  int result; // r0
  int v21; // [sp+0h] [bp-48h]
  int v22; // [sp+1Ch] [bp-2Ch]
  unsigned int v23; // [sp+24h] [bp-24h] BYREF
  int *v24; // [sp+28h] [bp-20h]

  v23 = a1;
  v24 = a3;
  v7 = a4;
  v22 = *(_DWORD *)(a2 + 12);
  v9 = 0;
  v10 = a6 << 12;
  if ( !v22 )
    goto LABEL_19;
  if ( !a5 )
  {
    v11 = a4;
    v12 = *(_QWORD *)(dword_61EF00 + 32) - *(_QWORD *)(dword_61EF00 + 48);
    v13 = *(_DWORD *)(a2 + 104);
    if ( v13 && (int)(100 * *(_DWORD *)(a2 + 108) / v13) <= dword_61EED4 )
    {
      v14 = *(_DWORD *)(dword_61EF00 + 4);
      if ( v12 >= v14 >> 1 )
      {
        if ( v12 >= (3 * v14) >> 2 )
          v9 = 3;
        else
          v9 = 2;
        ++*(_DWORD *)(a2 + 108);
        goto LABEL_14;
      }
    }
    else if ( v12 >= *(_DWORD *)(dword_61EF00 + 4) >> 1 )
    {
      v9 = 1;
      goto LABEL_14;
    }
    v9 = 0;
LABEL_14:
    *(_DWORD *)(a2 + 104) = v13 + 1;
    goto LABEL_15;
  }
  v11 = *(_DWORD *)a2;
  memmove(*(_DWORD *)a2, a4, a6 << 12);
LABEL_15:
  v15 = ReadTimeStampCounter();
  v17 = v16;
  v18 = RtlCompressBufferProgress(
          *((_WORD *)PopCompressMethodMap + v9),
          v11,
          v10,
          v22,
          v21,
          (int)&v23,
          *(_DWORD *)(a2 + 8),
          a7,
          v23);
  LODWORD(v19) = ReadTimeStampCounter();
  *(_QWORD *)(a2 + 24) = *(_QWORD *)(a2 + 24) - __PAIR64__(v17, v15) + v19;
  if ( v18 < 0 || v23 >= ((3584 * a6) & 0x1FFFFFFFu) )
  {
    v7 = v11;
  }
  else
  {
    v7 = v22;
    v10 = v23;
  }
LABEL_19:
  result = v7;
  *v24 = *(unsigned __int8 *)v24 | ((v10 & 0x3FFFFF | (v9 << 22)) << 8);
  return result;
}

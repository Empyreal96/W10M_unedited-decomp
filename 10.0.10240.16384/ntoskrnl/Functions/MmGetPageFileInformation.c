// MmGetPageFileInformation 
 
int __fastcall MmGetPageFileInformation(_DWORD *a1, unsigned int a2, int a3, unsigned int *a4)
{
  unsigned int *v4; // r5
  int v5; // r3
  unsigned int v6; // lr
  _DWORD *v7; // r2
  int v8; // r10
  unsigned int v9; // r4
  _DWORD *v10; // r6
  unsigned int v11; // r3
  unsigned int i; // r8
  unsigned int v13; // r1
  unsigned int *v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r0
  unsigned int v17; // r4
  unsigned int v18; // lr
  unsigned int v19; // r0
  unsigned int v20; // r3
  unsigned int v22; // [sp+0h] [bp-50h]
  unsigned __int16 v23; // [sp+0h] [bp-50h]
  unsigned int v26; // [sp+10h] [bp-40h]
  _DWORD *v27; // [sp+14h] [bp-3Ch]
  int v28; // [sp+1Ch] [bp-34h]
  int v29; // [sp+28h] [bp-28h]
  _DWORD *varg_r0; // [sp+58h] [bp+8h]
  unsigned int varg_r1; // [sp+5Ch] [bp+Ch]
  int varg_r2; // [sp+60h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v4 = a4;
  v5 = a3;
  v6 = a2;
  v7 = a1;
  v27 = a1;
  if ( v5 )
    v8 = 8;
  else
    v8 = 6;
  v9 = 0;
  *v4 = 0;
  v10 = a1;
  v11 = dword_64050C;
  v28 = dword_64050C;
  __dmb(0xBu);
  a1[1] = 0;
  for ( i = 0; i < v11; ++i )
  {
    if ( (*(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * i + 1800] + 96) & 0x10) == 0
      && (*(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * i + 1800] + 96) & 0x40) == 0 )
    {
      v10 = (_DWORD *)((char *)v7 + v9);
      v13 = v9 + v8 * 4;
      if ( v9 + v8 * 4 <= v9 || v13 > v6 )
      {
        *v4 = v13;
        return -1073741820;
      }
      v14 = *(unsigned int **)&MiSystemPartition[2 * i + 1800];
      v15 = *v14;
      v16 = v14[3];
      v22 = v14[4];
      v17 = v14[2];
      v18 = v14[1];
      while ( v16 >= v15 )
        ;
      v10[1] = v15;
      v10[2] = v15 - v16 - 2;
      v10[3] = v22;
      if ( a3 )
      {
        v10[6] = v17;
        v10[7] = v18;
      }
      v19 = *(unsigned __int16 *)(*(_DWORD *)&MiSystemPartition[2 * i + 1800] + 56);
      v23 = v19;
      LOWORD(v29) = *(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * i + 1800] + 56);
      HIWORD(v29) = v19 + 2;
      v10[4] = v29;
      v10[5] = &v10[v8];
      v26 = ((unsigned __int16)(v19 + 2) + 3) & 0xFFFFFFFC;
      v20 = v26 + v13;
      if ( v26 + v13 <= v13 || v20 > a2 )
      {
        *v4 = v20;
        return -1073741820;
      }
      v9 = v26 + v13;
      memmove((int)&v10[v8], *(_DWORD *)(*(_DWORD *)&MiSystemPartition[2 * i + 1800] + 60), v19);
      *((_WORD *)&v10[v8] + (v23 >> 1)) = 0;
      *v10 = v26 + v8 * 4;
      v7 = v27;
      v6 = a2;
    }
    v11 = v28;
  }
  *v10 = 0;
  *v4 = v9;
  return 0;
}

// RaspInitializeCompositeGlyphData 
 
int __fastcall RaspInitializeCompositeGlyphData(_DWORD *a1, int *a2, __int16 *a3, int a4, __int16 a5, unsigned __int16 a6, int a7, _WORD *a8, _DWORD *a9, int a10)
{
  int *v10; // r10
  int v11; // r5
  _BYTE *v14; // r0
  _BYTE *v15; // r4
  int result; // r0
  _BYTE *v17; // r5
  int v18; // r3
  _BYTE *v19; // r4
  int v20; // r9
  _WORD *v21; // lr
  __int16 *v22; // r6
  __int16 *v23; // r8
  __int16 v24; // r0
  int v25; // r4
  __int64 v26; // r2
  __int16 *v27; // r7
  int v28; // r2
  int v29; // r1
  unsigned int v30; // r2
  __int16 v31; // r3
  int v32; // r0
  int v33; // lr
  __int16 v34; // r9
  unsigned __int16 v35; // r5
  __int16 v36; // r3
  bool v37; // zf
  __int16 v38; // r3
  __int16 v39; // r2
  __int16 v40; // t1
  __int16 v41; // t1
  int v42; // [sp+0h] [bp-40h]
  __int16 v43; // [sp+4h] [bp-3Ch]
  __int16 v44; // [sp+8h] [bp-38h]
  _WORD *v46; // [sp+10h] [bp-30h]
  _BYTE *v47; // [sp+14h] [bp-2Ch]
  int v48; // [sp+18h] [bp-28h]
  __int16 v50; // [sp+20h] [bp-20h]

  v10 = a2;
  v11 = 9 * a4 + 2 * (a5 + 31);
  v14 = (_BYTE *)RaspAllocateMemory(v11 + a6, a10);
  v15 = v14;
  if ( !v14 )
    return -1073741670;
  memset(v14, 0, v11 + a6);
  *(_WORD *)v15 = a5;
  v17 = v15;
  v47 = v15;
  *(_DWORD *)(v15 + 2) = a3[1];
  *(_DWORD *)(v15 + 6) = a3[2];
  *(_DWORD *)(v15 + 10) = a3[3];
  v18 = a3[4];
  *((_WORD *)v15 + 11) = a6;
  *((_WORD *)v15 + 12) = a4;
  *(_DWORD *)(v15 + 14) = v18;
  *(_DWORD *)(v15 + 18) = *(_DWORD *)(v15 + 2);
  v19 = v15 + 46;
  *(_DWORD *)(v17 + 26) = v19;
  v20 = (int)&v19[2 * a5];
  if ( a6 )
  {
    *(_DWORD *)(v17 + 30) = v20;
    v20 += a6;
    FioFwReadBytesAtOffset(a1, a7, a6, *(_DWORD *)(v17 + 30));
  }
  v21 = *(_WORD **)(v17 + 26);
  v22 = (__int16 *)(a4 + v20);
  v23 = (__int16 *)(a4 + v20 + 4 * (a4 + 2));
  v43 = 0;
  v44 = 0;
  *(_DWORD *)(v17 + 34) = v20;
  *(_DWORD *)(v17 + 38) = a4 + v20;
  *(_DWORD *)(v17 + 42) = v23;
  v24 = 0;
  v46 = v21;
  while ( 1 )
  {
    v25 = *v10;
    if ( (int *)*v10 == v10 )
      break;
    v26 = *(_QWORD *)v25;
    if ( *(int **)(v25 + 4) != v10 || *(_DWORD *)(v26 + 4) != v25 )
      __fastfail(3u);
    *v10 = v26;
    *(_DWORD *)(v26 + 4) = v10;
    v27 = *(__int16 **)(v25 + 8);
    if ( (*(_WORD *)(v25 + 12) & 0x200) != 0 )
    {
      *a8 = *(_WORD *)(v25 + 14);
      *(_DWORD *)(v17 + 18) = *(_DWORD *)(v27 + 1);
    }
    LOWORD(v28) = 0;
    if ( *v27 > 0 )
    {
      v29 = 0;
      do
      {
        *v21++ = *(_WORD *)(*(_DWORD *)(v27 + 13) + 2 * v29) + v24;
        v28 = (unsigned __int16)(v28 + 1);
        v29 = v28;
      }
      while ( v28 < *v27 );
      v46 = v21;
    }
    v30 = (unsigned __int16)v27[12];
    v50 = v24 + v30;
    memmove(v20, *(_DWORD *)(v27 + 17), v30);
    v31 = *(_WORD *)(v25 + 12);
    v32 = 0x4000;
    v20 += (unsigned __int16)v27[12];
    v48 = v20;
    v42 = 0x4000;
    if ( (v31 & 8) != 0 )
    {
      v32 = *(__int16 *)(v25 + 20);
      v42 = v32;
    }
    else if ( (v31 & 0x40) != 0 )
    {
      v32 = *(__int16 *)(v25 + 20);
      v42 = *(__int16 *)(v25 + 22);
    }
    v33 = 0;
    if ( v27[12] )
    {
      v34 = v44;
      v35 = 0;
      do
      {
        *v22 = *(_DWORD *)(*(_DWORD *)(v27 + 19) + 4 * v33);
        *v23 = *(_DWORD *)(*(_DWORD *)(v27 + 21) + 4 * v33);
        *v22 = *v22 * (__int64)v32 / 0x4000;
        *v23 = *v23 * (__int64)v42 / 0x4000;
        if ( !v33 )
        {
          *v22 -= v34;
          *v23 -= v43;
          v36 = *(_WORD *)(v25 + 12);
          if ( (v36 & 2) != 0 )
          {
            v37 = (v36 & 1) == 0;
            v38 = *v22;
            if ( v37 )
            {
              *v22 = v38 + *(char *)(v25 + 16);
              v39 = *(char *)(v25 + 17);
            }
            else
            {
              *v22 = v38 + *(_WORD *)(v25 + 16);
              v39 = *(_WORD *)(v25 + 18);
            }
            *v23 += v39;
          }
        }
        v40 = *v22;
        v22 += 2;
        v34 += v40;
        v41 = *v23;
        v23 += 2;
        v43 += v41;
        v33 = ++v35;
      }
      while ( v35 < (unsigned int)(unsigned __int16)v27[12] );
      v17 = v47;
      v10 = a2;
      v44 = v34;
      v20 = v48;
    }
    RaspFreeMemory((int)v27, a10);
    RaspFreeMemory(v25, a10);
    v21 = v46;
    v24 = v50;
  }
  result = 0;
  *a9 = v17;
  return result;
}

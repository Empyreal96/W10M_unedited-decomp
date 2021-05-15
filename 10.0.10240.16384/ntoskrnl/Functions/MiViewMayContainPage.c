// MiViewMayContainPage 
 
int __fastcall MiViewMayContainPage(int a1, __int64 *a2, unsigned int a3, unsigned int a4, unsigned __int64 a5)
{
  unsigned int v5; // r7
  unsigned int v6; // r6
  int v8; // r1
  __int64 v10; // r0
  unsigned int v11; // r6
  unsigned int v12; // r5
  unsigned int v13; // r4
  unsigned int v14; // r10
  _DWORD *v15; // r4
  unsigned int v17; // r9
  _DWORD *v18; // r0
  unsigned __int64 v19; // r2
  bool v20; // cf
  unsigned int v21; // r2
  int v22; // r0
  int v23; // r4
  int v24; // r3
  unsigned __int64 v25; // kr18_8
  unsigned __int64 v26; // r0
  int v27; // r1
  unsigned int v28; // r2
  int v29; // [sp+0h] [bp-38h]
  unsigned int v32; // [sp+Ch] [bp-2Ch]

  v5 = *((_DWORD *)a2 + 2);
  v6 = a3;
  v8 = v5 & 3;
  v32 = 0;
  v29 = -1;
  if ( (v5 & 3) == 0 )
  {
    v11 = *((_DWORD *)a2 + 5);
    v12 = a2[2] & 0xFFFC0000;
    v13 = (__PAIR64__(v11, v12) + (((_DWORD)a2[2] & 0x1FFFFu) << 12)) >> 32;
    v14 = v12 + ((a2[2] & 0x1FFFF) << 12);
    if ( !v5 )
      return 0;
    goto LABEL_6;
  }
  if ( v8 == 1 )
  {
    v32 = a2[1] & 0xFFFFFFFE;
    if ( (*(_DWORD *)(a1 + 28) & 0x20) != 0 )
    {
      v11 = 0;
      v12 = 0;
      v14 = 0;
      v13 = 0;
    }
    else
    {
      v10 = MiStartingOffset(*((_DWORD *)a2 - 3), *((_DWORD *)a2 - 2), -1);
      v11 = HIDWORD(v10);
      v12 = v10;
      v13 = (v10 + (unsigned __int64)(unsigned int)((*((_DWORD *)a2 - 10) - *((_DWORD *)a2 - 11) + 1) << 12)) >> 32;
      v14 = v10 + ((*((_DWORD *)a2 - 10) - *((_DWORD *)a2 - 11) + 1) << 12);
    }
    v5 = *((_DWORD *)a2 - 11) << 12;
    goto LABEL_6;
  }
  if ( v8 == 2 )
  {
    v5 = a2[1] & 0xFFFFFFFD;
    if ( *((_DWORD *)a2 + 3) != -1 )
      v29 = *((_DWORD *)a2 + 3);
    v11 = *(a2 - 3) >> 20;
    v12 = *((_DWORD *)a2 - 6) << 12;
    v13 = ((*(a2 - 3) << 12) + (unsigned __int64)*((unsigned int *)a2 - 4)) >> 32;
    v14 = v12 + *((_DWORD *)a2 - 4);
    goto LABEL_6;
  }
  if ( v8 != 3 )
    return 0;
  v22 = *((_DWORD *)a2 + 4);
  v5 = a2[1] & 0xFFFFFFFC;
  v29 = v22;
  v14 = *((_DWORD *)a2 + 3) - v5 + 1;
  if ( (*(_DWORD *)(a1 + 28) & 0x20) == 0 )
  {
LABEL_44:
    v12 = 0;
    v11 = 0;
    v13 = 0;
LABEL_6:
    if ( (*(_DWORD *)(a1 + 28) & 0x20) != 0 )
    {
      v12 = 0;
      v11 = 0;
      v17 = v5 + 4096;
    }
    else
    {
      if ( a4 > v13 || a4 >= v13 && a3 >= v14 || a5 <= __PAIR64__(v11, v12) )
        return 0;
      if ( a4 >= v11 && (a4 > v11 || a3 >= v12) )
      {
        v19 = __PAIR64__(a4, a3) - __PAIR64__(v11, v12);
        v20 = __CFADD__(v12, a3 - v12);
        v12 = a3;
        v11 += HIDWORD(v19) + v20;
        v5 += v19;
      }
      if ( a5 > __PAIR64__(v13, v14) )
        v21 = v14 - v12;
      else
        v21 = a5 - v12;
      v17 = v21 + v5;
    }
    v18 = (_DWORD *)ExAllocatePoolWithTag(512, 32, 1633053005);
    v15 = v18;
    if ( !v18 )
      return (int)v15;
    v18[1] = v32;
    v18[2] = v5;
    v18[3] = v17;
    v18[5] = v11;
    v18[6] = v29;
    v18[4] = v12;
    v18[7] = a2[1] & 3;
    if ( !v32 || ObReferenceObjectSafeWithTag(v32, 1953261124) )
      return (int)v15;
    ExFreePoolWithTag(v15, 0);
    return 0;
  }
  v23 = a1 + 80;
  if ( v5 < dword_63389C
    || (v24 = *((unsigned __int8 *)&MiState[2423]
              + ((int)(((v5 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
        v24 != 1)
    && v24 != 11 )
  {
    v22 = -2;
    v29 = -2;
  }
  if ( a1 == -80 )
    return 0;
  while ( 1 )
  {
    v25 = MiStartingOffset(v23, *(_DWORD *)(v23 + 4), v22);
    LODWORD(v26) = MiEndingOffsetWithLock(v23);
    if ( __PAIR64__(a4, v6) >= v25 && __PAIR64__(a4, v6) < v26 )
      break;
    v23 = *(_DWORD *)(v23 + 8);
    if ( !v23 )
      return 0;
    v22 = v29;
  }
  v27 = *(_DWORD *)(v23 + 4);
  v28 = v27 + 4 * ((__int64)(__PAIR64__(a4, v6) - v25) >> 12);
  if ( v28 >= v27 + 4 * *(_DWORD *)(v23 + 28) )
    return 0;
  if ( (*(_WORD *)(v23 + 18) & 2) == 0 )
  {
    v5 += (int)(v28 - *(_DWORD *)(a1 + 84)) >> 2 << 12;
    goto LABEL_44;
  }
  return sub_51204C(v26);
}

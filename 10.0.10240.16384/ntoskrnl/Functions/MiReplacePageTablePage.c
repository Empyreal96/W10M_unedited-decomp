// MiReplacePageTablePage 
 
int __fastcall MiReplacePageTablePage(int **a1)
{
  int *v1; // r6
  int *v2; // lr
  int v3; // r4
  int v4; // r10
  int *v5; // r7
  int v6; // r0
  int v7; // r5
  int v8; // r9
  unsigned int v9; // r3
  int v10; // r3
  int v11; // r0
  int result; // r0
  unsigned __int8 *v13; // r1
  unsigned int v14; // r2
  unsigned int v15; // r0
  int v16; // r3
  int v17; // r9
  unsigned __int8 *v18; // r1
  unsigned int v19; // r2
  unsigned int *v20; // r2
  unsigned int v21; // r0
  unsigned int *v22; // r2
  int *v23; // r7
  unsigned int *v24; // r6
  unsigned int v25; // r3
  unsigned int v26; // t1
  unsigned int v27; // r4
  int v28; // r4
  unsigned __int8 *v29; // r3
  unsigned int v30; // r1
  unsigned int *v31; // r2
  unsigned int v32; // r5
  unsigned int *v33; // r4
  unsigned int v34; // r3
  unsigned int v35; // t1
  int v36; // r2
  unsigned int *v37; // r2
  unsigned int v38; // r2
  unsigned int *v39; // r2
  int v40; // [sp+0h] [bp-40h]
  int *v41; // [sp+4h] [bp-3Ch]
  BOOL v42; // [sp+8h] [bp-38h]
  int *v43; // [sp+Ch] [bp-34h]
  int *v44; // [sp+14h] [bp-2Ch]

  a1[7] = (int *)-1073741823;
  v2 = a1[2];
  v1 = a1[1];
  v44 = a1[4];
  v3 = MmPfnDatabase + 24 * (_DWORD)v2;
  v4 = MmPfnDatabase + 24 * (_DWORD)a1[3];
  v41 = *a1;
  v5 = *a1;
  v43 = a1[3];
  v6 = 0;
  v7 = 0;
  v40 = 0;
  v8 = 0;
  v42 = (*(_DWORD *)(v3 + 20) & 0xFFFFF) == (_DWORD)v2;
  while ( 1 )
  {
    v9 = *v5;
    if ( (*v5 & 2) != 0 )
    {
      v40 = v6 + 1;
      if ( v9 >> 12 == dword_6348F4 )
        ++v8;
LABEL_5:
      v10 = *v5++;
      *v1++ = v10;
      goto LABEL_6;
    }
    if ( (v9 & 0x400) != 0 || (v9 & 0x800) == 0 )
      goto LABEL_5;
    v11 = MiLockTransitionLeafPage(v5, v7 != 0, 1024);
    if ( v11 )
    {
      if ( (*(_BYTE *)(v11 + 18) & 0x20) != 0 )
        return sub_522354();
      ++v7;
      goto LABEL_5;
    }
LABEL_6:
    if ( ((unsigned __int16)v5 & 0xFFF) == 0 )
      break;
    v6 = v40;
  }
  v13 = (unsigned __int8 *)(v3 + 15);
  if ( v7 )
  {
    do
      v38 = __ldrex(v13);
    while ( __strex(v38 | 0x80, v13) );
    __dmb(0xBu);
    if ( v38 >> 7 )
      JUMPOUT(0x5223A8);
  }
  else
  {
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      JUMPOUT(0x522382);
  }
  v15 = *(_DWORD *)(v3 + 12) & 0x3FFFFFFF;
  if ( v42 )
  {
    v17 = v40;
    goto LABEL_19;
  }
  v16 = v7 - v8;
  v17 = v40;
  if ( *(unsigned __int16 *)(v3 + 12) != v16 + v40 + 1 )
LABEL_65:
    JUMPOUT(0x52242A);
LABEL_19:
  if ( *(_WORD *)(v3 + 16) != 1 || v15 >= 0x10000 )
    goto LABEL_65;
  v18 = (unsigned __int8 *)(v4 + 15);
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 | 0x80, v18) );
  __dmb(0xBu);
  if ( v19 >> 7 )
    JUMPOUT(0x5223CE);
  *(_DWORD *)(v4 + 12) = *(_DWORD *)(v4 + 12) & 0xC0000000 | v15 & 0x3FFFFFFF;
  __dmb(0xBu);
  v20 = (unsigned int *)(v4 + 12);
  do
    v21 = __ldrex(v20);
  while ( __strex(v21 & 0x7FFFFFFF, v20) );
  __dmb(0xBu);
  v22 = (unsigned int *)(v3 + 12);
  if ( v7 )
  {
    do
      result = __ldrex(v22);
    while ( __strex(result & 0x7FFFFFFF, v22) );
    v23 = v41;
    v33 = (unsigned int *)v41;
    do
    {
      v35 = *v33++;
      v34 = v35;
      if ( (v35 & 2) == 0 && (v34 & 0x400) == 0 && (v34 & 0x800) != 0 )
      {
        --v7;
        v36 = MmPfnDatabase + 24 * (v34 >> 12);
        *(_DWORD *)(v36 + 20) = *(_DWORD *)(v36 + 20) & 0xFFF00000 | (unsigned int)v43 & 0xFFFFF;
        __dmb(0xBu);
        if ( v7 )
        {
          v37 = (unsigned int *)(v36 + 12);
          do
            result = __ldrex(v37);
          while ( __strex(result & 0x7FFFFFFF, v37) );
        }
        else
        {
          v39 = (unsigned int *)(v36 + 12);
          do
            result = __ldrex(v39);
          while ( __strex(result & 0x7FFFFFFF, v39) );
        }
      }
    }
    while ( v7 );
  }
  else
  {
    do
      result = __ldrex(v22);
    while ( __strex(result & 0x7FFFFFFF, v22) );
    v23 = v41;
  }
  v24 = (unsigned int *)v23;
  if ( v17 )
  {
    do
    {
      v26 = *v24++;
      v25 = v26;
      if ( (v26 & 2) != 0 )
      {
        v27 = v25 >> 12;
        --v17;
        result = MI_IS_PFN(v25 >> 12);
        if ( result )
        {
          if ( (int *)v27 != v2 )
          {
            v28 = MmPfnDatabase + 24 * v27;
            v29 = (unsigned __int8 *)(v28 + 15);
            do
              v30 = __ldrex(v29);
            while ( __strex(v30 | 0x80, v29) );
            __dmb(0xBu);
            if ( v30 >> 7 )
              JUMPOUT(0x5223F6);
            if ( (int *)(*(_DWORD *)(v28 + 20) & 0xFFFFF) == v2 )
              *(_DWORD *)(v28 + 20) = *(_DWORD *)(v28 + 20) & 0xFFF00000 | (unsigned int)v43 & 0xFFFFF;
            __dmb(0xBu);
            v31 = (unsigned int *)(v28 + 12);
            do
              v32 = __ldrex(v31);
            while ( __strex(v32 & 0x7FFFFFFF, v31) );
          }
        }
      }
    }
    while ( v17 );
    v23 = v41;
  }
  if ( v42 )
    result = MiInsertTbFlushEntry(v44, v23, 1);
  a1[7] = 0;
  return result;
}

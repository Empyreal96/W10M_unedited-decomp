// -StCompactionFindEmptiest@-$ST_STORE@USM_TRAITS@@@@SAKPAU_ST_DATA_MGR@1@PAPAT_ST_REGION_STATE@1@KK@Z 
 
unsigned int __fastcall ST_STORE<SM_TRAITS>::StCompactionFindEmptiest(int a1, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r9
  unsigned int v5; // lr
  unsigned int v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r10
  _DWORD *v10; // r5
  unsigned int v11; // r7
  int v12; // r5
  __int64 v13; // kr00_8
  unsigned int v14; // r0
  unsigned int v15; // r1
  int v16; // r3
  _DWORD *v17; // lr
  int i; // r3
  unsigned int v19; // r2
  int v20; // r1
  int v21; // r3
  _WORD *v22; // r8
  unsigned int v23; // r2
  int v24; // r3
  _WORD **v25; // r4
  __int16 v27; // [sp+0h] [bp-38h] BYREF
  unsigned int v28; // [sp+4h] [bp-34h]
  unsigned int v29; // [sp+8h] [bp-30h]
  unsigned int v30; // [sp+Ch] [bp-2Ch]
  int v31; // [sp+10h] [bp-28h]
  unsigned int v32; // [sp+14h] [bp-24h]

  v4 = a2 + 4 * a3;
  v27 |= 0x1FFFu;
  v5 = a2;
  v7 = 0;
  if ( a2 > v4 )
    v8 = 0;
  else
    v8 = (unsigned int)(4 * a3 + 3) >> 2;
  v28 = a2;
  v29 = a4;
  v9 = a3;
  v30 = a2 + 4 * a3;
  v31 = a3;
  v10 = (_DWORD *)a2;
  if ( v8 )
  {
    do
    {
      ++v7;
      *v10++ = &v27;
    }
    while ( v7 < v8 );
  }
  v11 = 0;
  v12 = -1;
LABEL_7:
  while ( 1 )
  {
    if ( *(_BYTE *)(a1 + 72) )
    {
      v13 = *(_QWORD *)(a1 + 120);
      v14 = v12 + 1 < (unsigned int)v13 ? v12 + 1 : 0;
      v15 = v13 - 1;
      while ( 1 )
      {
        if ( v15 - v14 == -1 )
          goto LABEL_14;
        v17 = (_DWORD *)(HIDWORD(v13) + 4 * (v14 >> 5));
        for ( i = ~*v17 | ((1 << (v14 & 0x1F)) - 1); i == -1; i = ~*v17 )
        {
          if ( (unsigned int)++v17 > HIDWORD(v13) + 4 * (v15 >> 5) )
            goto LABEL_14;
        }
        v19 = __clz(__rbit(~i));
        v16 = v19 + 32 * (((int)v17 - HIDWORD(v13)) >> 2);
        v32 = v19;
        if ( v16 > v15 )
        {
LABEL_14:
          v16 = -1;
        }
        else if ( v16 != -1 )
        {
          break;
        }
        if ( !v14 )
          break;
        v20 = v12 + 2;
        if ( v12 + 2 > (unsigned int)v13 )
          v20 = v13;
        v15 = v20 - 1;
        v14 = 0;
      }
      v4 = v30;
      if ( v16 <= v12 )
        v16 = *(_DWORD *)(a1 + 84);
      v5 = v28;
      v9 = v31;
      v12 = v16;
    }
    else
    {
      ++v12;
    }
    if ( v12 == *(_DWORD *)(a1 + 84) )
      return v11;
    v21 = *(_DWORD *)(a1 + 304);
    v22 = (_WORD *)(v21 + 2 * v12);
    v23 = *v22 & 0x1FFF;
    if ( (*v22 & 0x1FFF) != 0 && v23 <= v29 )
    {
      v24 = *(_BYTE *)(a1 + 72) ? 0 : *(unsigned __int16 *)(v21 + 2 * v12) >> 13;
      if ( v12 != *(_DWORD *)(a1 + 12 * v24 + 392) )
      {
        v25 = (_WORD **)v5;
        if ( v5 < v4 )
        {
          while ( v23 >= (**v25 & 0x1FFFu) )
          {
            if ( (unsigned int)++v25 >= v4 )
              goto LABEL_7;
          }
          memmove((int)(v25 + 1), (int)v25, v4 - (_DWORD)v25 - 4);
          *v25 = v22;
          if ( v11 >= v9 || (++v11, v5 = v28, v11 >= v9) )
          {
            v5 = v28;
            v29 = (**(_WORD **)(v4 - 4) & 0x1FFF) - 1;
          }
        }
      }
    }
  }
}

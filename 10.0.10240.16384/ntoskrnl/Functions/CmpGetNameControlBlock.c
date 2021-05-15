// CmpGetNameControlBlock 
 
int __fastcall CmpGetNameControlBlock(unsigned __int16 *a1, _BYTE *a2)
{
  unsigned __int16 *v2; // r3
  unsigned int v4; // r1
  unsigned int v5; // r9
  unsigned __int16 *v6; // r7
  unsigned int v7; // r5
  unsigned int v8; // r6
  unsigned int v9; // r4
  unsigned int v10; // t1
  int v11; // r0
  unsigned int v12; // r10
  unsigned __int16 *v13; // r2
  unsigned int v14; // t1
  int v16; // r7
  int v17; // r4
  unsigned __int16 *v18; // r6
  unsigned int *v19; // r5
  _BYTE *v20; // r0
  _BYTE *v21; // r5
  unsigned int v22; // r4
  unsigned int v23; // r0
  _BYTE *v24; // r3
  int v25; // r3
  int v26; // r3
  int v27; // r2
  unsigned int v28; // r2
  unsigned int v29; // r7
  unsigned int v30; // r9
  char *v31; // r6
  int v32; // r8
  unsigned int v33; // r0
  unsigned int v35; // [sp+4h] [bp-2Ch]
  unsigned int v36; // [sp+8h] [bp-28h]
  int v37; // [sp+Ch] [bp-24h]

  v2 = a1;
  *a2 = 1;
  v4 = *a1;
  v5 = 0;
  v6 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  v35 = 0;
  v36 = v4;
  v7 = v4 >> 1;
  if ( v4 >> 1 )
  {
    v8 = v4 >> 1;
    do
    {
      v10 = *v6++;
      v9 = v10;
      if ( v10 != 92 )
      {
        if ( v9 >= 0x61 )
        {
          if ( v9 > 0x7A )
            v11 = RtlUpcaseUnicodeChar(v9);
          else
            v11 = v9 - 32;
        }
        else
        {
          v11 = v9;
        }
        if ( v11 != v9 )
          *a2 = 0;
        v5 = 37 * v5 + v11;
      }
      --v8;
    }
    while ( v8 );
    v2 = a1;
    v4 = v36;
    v35 = v5;
  }
  v12 = v4 >> 1;
  if ( v7 )
  {
    v13 = (unsigned __int16 *)*((_DWORD *)v2 + 1);
    do
    {
      v14 = *v13++;
      if ( v14 > 0xFF )
        return sub_8052E8();
      --v7;
    }
    while ( v7 );
  }
  CmpLockNameHashEntryExclusive(v5);
  v16 = ((unsigned __int16)(-30045 * (v5 ^ (v5 >> 9))) ^ (unsigned __int16)((101027 * (v5 ^ (v5 >> 9))) >> 9)) & 0x7FF;
  v17 = *(_DWORD *)(CmpNameCacheTable + 8 * v16 + 4);
  v37 = v16;
  if ( v17 )
  {
    v18 = a1;
    while ( 1 )
    {
      v19 = (unsigned int *)(v17 - 4);
      if ( v5 == *(_DWORD *)v17 )
      {
        v28 = *(unsigned __int16 *)(v17 + 8);
        if ( v12 == v28 )
        {
          if ( (*v19 & 1) != 0 )
          {
            if ( !CmpCompareCompressedName(v18, (unsigned __int8 *)(v17 + 10), v12, 2) )
              goto LABEL_35;
          }
          else
          {
            v29 = 0;
            v30 = v28 >> 1;
            v31 = (char *)*((_DWORD *)a1 + 1);
            if ( !(v28 >> 1) )
            {
LABEL_47:
              v5 = v35;
LABEL_35:
              if ( (*v19 & 0xFFFFFFFE) != -2 )
              {
                *v19 = *v19 & 1 ^ ((*v19 & 0xFFFFFFFE) + 2);
                CmpUnlockNameHashEntry(v5);
                return v17 - 4;
              }
              v21 = 0;
LABEL_26:
              CmpUnlockNameHashEntry(v5);
              return (int)v21;
            }
            v32 = (char *)v19 - v31 + 14;
            while ( 1 )
            {
              v33 = *(unsigned __int16 *)v31;
              if ( v33 >= 0x61 )
              {
                if ( v33 <= 0x7A )
                  v33 -= 32;
                else
                  v33 = RtlUpcaseUnicodeChar(v33);
              }
              if ( v33 != *(unsigned __int16 *)&v31[v32] )
                break;
              ++v29;
              v31 += 2;
              if ( v29 >= v30 )
                goto LABEL_47;
            }
            v18 = a1;
            v5 = v35;
          }
        }
      }
      v17 = *(_DWORD *)(v17 + 4);
      if ( !v17 )
      {
        v16 = v37;
        break;
      }
    }
  }
  v20 = (_BYTE *)ExAllocatePoolWithTag(1, v12 + 14, 1649298755);
  v21 = v20;
  if ( v20 )
  {
    memset(v20, 0, v12 + 14);
    v22 = 0;
    *(_DWORD *)v21 |= 1u;
    if ( v12 )
    {
      do
      {
        v23 = *(unsigned __int16 *)(*((_DWORD *)a1 + 1) + 2 * v22);
        if ( v23 >= 0x61 )
        {
          if ( v23 > 0x7A )
            LOBYTE(v23) = RtlUpcaseUnicodeChar(v23);
          else
            LOBYTE(v23) = v23 - 32;
        }
        v24 = &v21[v22++];
        v24[14] = v23;
      }
      while ( v22 < v12 );
    }
    v25 = *(_DWORD *)v21;
    *((_DWORD *)v21 + 1) = v5;
    *(_DWORD *)v21 = v25 & 1 | 2;
    v26 = CmpNameCacheTable;
    *((_WORD *)v21 + 6) = v12;
    v27 = v26 + 8 * v16;
    *((_DWORD *)v21 + 2) = *(_DWORD *)(v27 + 4);
    *(_DWORD *)(v27 + 4) = v21 + 4;
    goto LABEL_26;
  }
  CmpUnlockNameHashEntry(v5);
  return 0;
}

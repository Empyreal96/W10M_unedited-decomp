// MiReturnPageTablePageCommitment 
 
unsigned int __fastcall MiReturnPageTablePageCommitment(unsigned int a1, unsigned int a2, int a3, _DWORD *i, _DWORD *j, int a6, _BYTE *a7)
{
  int v7; // r6
  int v10; // r7
  int v12; // r9
  unsigned int v13; // r4
  int v14; // r5
  unsigned int v15; // r2
  _BYTE *v16; // r8
  int v17; // r7
  int v18; // r10
  _DWORD *v19; // r1
  _DWORD *v20; // r1
  int v21; // r0
  _DWORD *v22; // r2
  _DWORD *v23; // r3
  _DWORD **v24; // r3
  _DWORD *v25; // r2
  _DWORD *v26; // r3
  int v29; // [sp+8h] [bp-40h]
  unsigned int v30; // [sp+Ch] [bp-3Ch]
  int v31; // [sp+10h] [bp-38h]
  int v32; // [sp+14h] [bp-34h]
  int v33; // [sp+18h] [bp-30h]
  int v34; // [sp+1Ch] [bp-2Ch]
  int v36; // [sp+24h] [bp-24h]

  v7 = a3;
  v10 = __mrc(15, 0, 13, 0, 3);
  v36 = v10;
  v31 = 0;
  if ( (*(_DWORD *)(a6 + 28) & 0x8000) != 0 )
  {
    if ( (*(_DWORD *)(a6 + 28) & 7) == 5 )
      return sub_801830();
  }
  else if ( (*(_BYTE *)(a6 + 43) & 1) != 0 )
  {
    v31 = 1;
  }
  v33 = MiVadPureReserve(a6);
  v12 = 0;
  v13 = a1 >> 22;
  v14 = a2 >> 22;
  LOCK_PAGE_TABLE_COMMITMENT(v10 & 0xFFFFFFC0, v7);
  v29 = 0;
  LOBYTE(v15) = 0;
  v32 = -1069538888;
  v16 = a7;
  v17 = v31;
  v30 = 0;
  do
  {
    v18 = v13;
    v34 = v14;
    if ( *v16 )
    {
      v20 = i;
      if ( i )
      {
        while ( ((v20[4] >> 10) & 0x3FF) >> v15 == v13 )
        {
          if ( !MiVadPureReserve((int)v20) )
          {
            ++v13;
            *v16 = 0;
            break;
          }
          v22 = i;
          if ( *i )
          {
            v20 = (_DWORD *)*i;
            v23 = *(_DWORD **)(*i + 4);
            for ( i = (_DWORD *)*i; v23; i = v20 )
            {
              v20 = v23;
              v23 = (_DWORD *)v23[1];
            }
          }
          else
          {
            v20 = (_DWORD *)(i[2] & 0xFFFFFFFC);
            i = v20;
            if ( v20 )
            {
              do
              {
                if ( (_DWORD *)v20[1] == v22 )
                  break;
                v22 = v20;
                v20 = (_DWORD *)(v20[2] & 0xFFFFFFFC);
              }
              while ( v20 );
              i = v20;
            }
          }
          LOBYTE(v15) = v30;
          if ( !v20 )
            break;
        }
      }
    }
    else
    {
      ++v13;
    }
    if ( v16[1] )
    {
      v19 = j;
      if ( j )
      {
        while ( ((v19[3] >> 10) & 0x3FF) >> v30 == v14 )
        {
          if ( !MiVadPureReserve((int)v19) )
          {
            --v14;
            v16[1] = 0;
            break;
          }
          v24 = (_DWORD **)j[1];
          v25 = j;
          if ( v24 )
          {
            v19 = (_DWORD *)j[1];
            v26 = *v24;
            for ( j = v19; v26; j = v19 )
            {
              v19 = v26;
              v26 = (_DWORD *)*v26;
            }
          }
          else
          {
            v19 = (_DWORD *)(j[2] & 0xFFFFFFFC);
            j = v19;
            if ( v19 )
            {
              do
              {
                if ( (_DWORD *)*v19 == v25 )
                  break;
                v25 = v19;
                v19 = (_DWORD *)(v19[2] & 0xFFFFFFFC);
              }
              while ( v19 );
              j = v19;
            }
          }
          if ( !v19 )
            break;
        }
      }
    }
    else
    {
      --v14;
    }
    if ( (int)v13 > v14 )
      break;
    if ( (!v17 || v29) && !v33 )
      v12 += v14 - v13 + 1;
    do
    {
      if ( v33 )
      {
        v21 = *(_DWORD *)(v32 + 4);
        if ( ((*(char *)((v13 >> 3) + v21) >> (v13 & 7)) & 1) != 0 )
        {
          ++v12;
          *(_BYTE *)((v13 >> 3) + v21) &= ~(1 << (v13 & 7));
        }
      }
      else
      {
        *(_BYTE *)((v13 >> 3) + *(_DWORD *)(v32 + 4)) &= ~(1 << (v13 & 7));
      }
      ++v13;
    }
    while ( (int)v13 <= v14 );
    v7 = a3;
    v16 = a7;
    v14 = v34 >> 10;
    v15 = v30 + 10;
    *a7 >>= 1;
    v17 = v31;
    v13 = v18 >> 10;
    a7[1] >>= 1;
    ++v29;
    v30 = v15;
    v32 -= 8;
  }
  while ( v15 < 0xA );
  if ( v12 )
  {
    MEMORY[0xC0402100] -= v12;
    MiReturnFullProcessCommitment(v7, v12);
  }
  return UNLOCK_PAGE_TABLE_COMMITMENT(v36 & 0xFFFFFFC0, v7);
}

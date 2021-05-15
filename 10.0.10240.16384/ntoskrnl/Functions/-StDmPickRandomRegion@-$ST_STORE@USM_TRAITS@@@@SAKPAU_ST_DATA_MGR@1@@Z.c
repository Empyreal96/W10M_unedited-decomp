// -StDmPickRandomRegion@-$ST_STORE@USM_TRAITS@@@@SAKPAU_ST_DATA_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmPickRandomRegion(int a1)
{
  __int64 v2; // r0
  unsigned int v3; // r1
  unsigned int v4; // r0
  unsigned int v5; // r3
  signed int v6; // r1
  unsigned int i; // r8
  __int64 v8; // kr00_8
  unsigned int v9; // r5
  unsigned int v10; // r0
  unsigned int v11; // r3
  _DWORD *v12; // r7
  int j; // r3
  int v14; // r0
  unsigned int k; // r8
  signed int v16; // r1
  __int64 v17; // kr08_8
  unsigned int v18; // r5
  unsigned int v19; // r0
  unsigned int v20; // r3
  _DWORD *v21; // r7
  int l; // r3
  int v23; // r0
  __int64 v24; // kr10_8
  unsigned int v25; // r5
  int v26; // r3
  int *m; // r1
  int v28; // r3
  unsigned int v30; // [sp+0h] [bp-28h]

  if ( *(_DWORD *)(a1 + 128) )
  {
    LODWORD(v2) = ReadTimeStampCounter();
    v3 = v2 >> 4;
    v4 = *(_DWORD *)(a1 + 128);
    if ( !v4 )
      __brkdiv0();
    v5 = v3 % v4 + 1;
    v30 = v5;
    v6 = -1;
    for ( i = 0; i < v5; ++i )
    {
      if ( *(_BYTE *)(a1 + 72) )
      {
        v8 = *(_QWORD *)(a1 + 120);
        if ( v6 + 1 < (unsigned int)v8 )
          v9 = v6 + 1;
        else
          v9 = 0;
        v10 = v8 - 1;
        while ( 1 )
        {
          if ( v10 - v9 == -1 )
            goto LABEL_13;
          v12 = (_DWORD *)(HIDWORD(v8) + 4 * (v9 >> 5));
          for ( j = ~*v12 | ((1 << (v9 & 0x1F)) - 1); j == -1; j = ~*v12 )
          {
            if ( (unsigned int)++v12 > HIDWORD(v8) + 4 * (v10 >> 5) )
              goto LABEL_13;
          }
          v11 = __clz(__rbit(~j)) + 32 * (((int)v12 - HIDWORD(v8)) >> 2);
          if ( v11 > v10 )
          {
LABEL_13:
            v11 = -1;
          }
          else if ( v11 != -1 )
          {
            break;
          }
          if ( !v9 )
            break;
          v14 = v6 + 2;
          if ( v6 + 2 > (unsigned int)v8 )
            v14 = *(_DWORD *)(a1 + 120);
          v10 = v14 - 1;
          v9 = 0;
        }
        if ( (int)v11 <= v6 )
          v11 = *(_DWORD *)(a1 + 84);
        v6 = v11;
      }
      else
      {
        ++v6;
      }
      v5 = v30;
    }
    for ( k = 0; k < 7; ++k )
    {
      if ( !ST_STORE<SM_TRAITS>::StStagingRegionFind(a1, v6) )
        return v16;
      if ( *(_BYTE *)(a1 + 72) )
      {
        v17 = *(_QWORD *)(a1 + 120);
        if ( v16 + 1 < (unsigned int)v17 )
          v18 = v16 + 1;
        else
          v18 = 0;
        v19 = v17 - 1;
        while ( 1 )
        {
          if ( v19 - v18 == -1 )
            goto LABEL_38;
          v21 = (_DWORD *)(HIDWORD(v17) + 4 * (v18 >> 5));
          for ( l = ~*v21 | ((1 << (v18 & 0x1F)) - 1); l == -1; l = ~*v21 )
          {
            if ( (unsigned int)++v21 > HIDWORD(v17) + 4 * (v19 >> 5) )
              goto LABEL_38;
          }
          v20 = __clz(__rbit(~l)) + 32 * (((int)v21 - HIDWORD(v17)) >> 2);
          if ( v20 > v19 )
          {
LABEL_38:
            v20 = -1;
          }
          else if ( v20 != -1 )
          {
            break;
          }
          if ( !v18 )
            break;
          v23 = v16 + 2;
          if ( v16 + 2 > (unsigned int)v17 )
            v23 = *(_DWORD *)(a1 + 120);
          v19 = v23 - 1;
          v18 = 0;
        }
        if ( (int)v20 <= v16 )
          v20 = *(_DWORD *)(a1 + 84);
        v6 = v20;
      }
      else
      {
        v6 = v16 + 1;
      }
      if ( v6 == *(_DWORD *)(a1 + 84) )
      {
        if ( *(_BYTE *)(a1 + 72) )
        {
          v24 = *(_QWORD *)(a1 + 120);
          v25 = v24 - 1;
          if ( !(_DWORD)v24 )
            goto LABEL_62;
          v26 = *(_DWORD *)HIDWORD(v24);
          for ( m = *(int **)(a1 + 124); ; v26 = *m )
          {
            v28 = ~v26;
            if ( v28 != -1 )
              break;
            if ( (unsigned int)++m > HIDWORD(v24) + 4 * (v25 >> 5) )
              goto LABEL_62;
          }
          v6 = __clz(__rbit(~(_DWORD)v24)) + 32 * (((int)m - HIDWORD(v24)) >> 2);
          if ( v6 > v25 || v6 <= -1 )
LABEL_62:
            v6 = *(_DWORD *)(a1 + 84);
        }
        else
        {
          v6 = 0;
        }
      }
    }
  }
  return -1;
}

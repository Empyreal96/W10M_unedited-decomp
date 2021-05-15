// EtwpFillPerfectHashTable 
 
unsigned int __fastcall EtwpFillPerfectHashTable(int a1, unsigned int a2, char a3, unsigned int a4, int a5, _WORD *a6)
{
  unsigned int v6; // r2
  unsigned int v7; // r6
  int v8; // r4
  unsigned __int16 v9; // lr
  unsigned int result; // r0
  int v12; // r4
  int v13; // r3
  char v14; // r1
  unsigned __int16 v15; // r8
  int v16; // lr
  unsigned int v17; // r4
  int v18; // r2
  unsigned __int8 *v19; // r1
  unsigned int v20; // r1
  signed int v21; // r4
  signed int v22; // r10
  unsigned __int16 v23; // lr
  unsigned __int8 *v24; // r8
  unsigned int v25; // r2
  unsigned int v26; // r2
  unsigned __int16 v27; // r1
  int v28; // r4
  int v29; // lr
  unsigned int v30; // r1
  unsigned int v31; // [sp+0h] [bp-30h]

  v31 = a4;
  v6 = a4;
  v7 = (unsigned __int16)(a4 + 1);
  v8 = 0;
  v9 = 0;
  result = v7;
  *a6 = 0;
  do
  {
    v12 = a5 + 4 * v8;
    *(_WORD *)(v12 + 2) = -1;
    *(_BYTE *)v12 = -1;
    v8 = ++v9;
  }
  while ( v9 < 0x80u );
  v13 = 0;
  if ( a2 )
  {
    v14 = a3;
    v15 = 0;
    do
    {
      v16 = *(unsigned __int16 *)(a1 + 2 * v13);
      LOWORD(v17) = 0;
      v18 = v6 & __ROR4__(v16, v14);
      if ( *(unsigned __int16 *)(a5 + 4 * v18 + 2) != 0xFFFF )
      {
        do
        {
          v19 = (unsigned __int8 *)(a5 + 4 * v18);
          if ( *((unsigned __int16 *)v19 + 1) == v16 )
            break;
          v18 = *v19;
          v17 = (unsigned __int16)(v17 + 1);
          if ( v18 == 255 )
          {
            v18 = result;
            result = (unsigned __int16)(result + 1);
            *v19 = v18;
          }
          if ( v17 > (unsigned __int16)*a6 )
            *a6 = v17;
        }
        while ( *(unsigned __int16 *)(a5 + 4 * v18 + 2) != 0xFFFF );
        v14 = a3;
      }
      *(_WORD *)(a5 + 4 * v18 + 2) = v16;
      v6 = v31;
      v13 = ++v15;
    }
    while ( v15 < a2 );
  }
  v20 = 0;
  v21 = (unsigned __int16)(result - 1);
  v22 = v6 + 1;
  while ( v21 > v22 )
  {
    v23 = v20;
    if ( v20 >= v6 )
      break;
    v24 = (unsigned __int8 *)(a5 + 4 * v21);
    if ( *v24 == 255 )
    {
      do
      {
        if ( *(unsigned __int16 *)(a5 + 4 * v20 + 2) == 0xFFFF )
          break;
        v20 = ++v23;
      }
      while ( v23 < v6 );
      v23 = v20;
      if ( v20 >= v6 )
        break;
      *(_WORD *)(a5 + 4 * v20 + 2) = *((_WORD *)v24 + 1);
      v25 = 0;
      if ( result )
      {
        while ( *(unsigned __int8 *)(a5 + 4 * v25) != v21 )
        {
          v25 = (unsigned __int16)(v25 + 1);
          if ( v25 >= result )
            goto LABEL_25;
        }
        *(_BYTE *)(a5 + 4 * v25) = v20;
      }
LABEL_25:
      v6 = v31;
      *((_WORD *)v24 + 1) = -1;
      if ( v21 == result - 1 )
        result = (unsigned __int16)(result - 1);
    }
    v21 = (unsigned __int16)(v21 - 1);
    v20 = (unsigned __int16)(v23 + 1);
  }
  v26 = (unsigned __int16)(result - 1);
  while ( (int)v26 > v22 )
  {
    v27 = v7;
    if ( v7 >= v26 )
      break;
    do
    {
      if ( *(unsigned __int16 *)(a5 + 4 * v7 + 2) == 0xFFFF )
        break;
      v7 = ++v27;
    }
    while ( v27 < v26 );
    if ( v7 >= v26 )
      break;
    v28 = a5 + 4 * v26;
    v29 = a5 + 4 * v7;
    v30 = 0;
    *(_WORD *)(v29 + 2) = *(_WORD *)(v28 + 2);
    if ( result )
    {
      while ( *(unsigned __int8 *)(a5 + 4 * v30) != v26 )
      {
        v30 = (unsigned __int16)(v30 + 1);
        if ( v30 >= result )
          goto LABEL_39;
      }
      *(_BYTE *)(a5 + 4 * v30) = v7;
    }
LABEL_39:
    *(_BYTE *)v29 = *(_BYTE *)v28;
    result = (unsigned __int16)(result - 1);
    v26 = (unsigned __int16)(v26 - 1);
    v7 = (unsigned __int16)(v7 + 1);
  }
  return result;
}

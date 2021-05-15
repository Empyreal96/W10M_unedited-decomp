// RtlpLocateRelatedBlocks 
 
unsigned int __fastcall RtlpLocateRelatedBlocks(unsigned int result, unsigned int a2)
{
  _DWORD *i; // r2
  _DWORD *v4; // r1
  unsigned int v5; // r2
  __int16 *v6; // r1
  int *v7; // r4
  int *v8; // lr
  __int64 v9; // kr00_8
  unsigned int v10; // r6
  __int16 *v11; // r4
  int v12; // r7
  int v13; // r3
  unsigned int j; // r2
  int v15; // r3
  int v16; // r5
  int v17; // r3
  int v18; // r3
  unsigned __int16 *v19; // r5
  __int16 v20; // r3
  int v21; // r2
  int v22; // [sp+0h] [bp-18h]
  int v23; // [sp+0h] [bp-18h]
  int v24; // [sp+0h] [bp-18h]
  int v25; // [sp+0h] [bp-18h]
  int v26; // [sp+0h] [bp-18h]

  for ( i = *(_DWORD **)(result + 164); ; i = (_DWORD *)*i )
  {
    if ( i == (_DWORD *)(result + 164) )
    {
      v4 = (_DWORD *)(result + 156);
      v5 = *(_DWORD *)(result + 156);
      if ( v5 != result + 156 )
      {
        do
        {
          result = v5 & 0xFFFF0000;
          if ( (v5 & 0xFFFF0000) <= a2 && *(_DWORD *)(v5 + 20) + result > a2 )
            dword_618308 = 5;
          v5 = *(_DWORD *)v5;
        }
        while ( (_DWORD *)v5 != v4 );
      }
      return result;
    }
    if ( i[3] <= a2 && i[6] > a2 )
      break;
  }
  v6 = 0;
  v7 = (int *)i[10];
  v8 = 0;
  while ( v7 != i + 10 )
  {
    v9 = *((_QWORD *)v7 + 1);
    if ( HIDWORD(v9) + (int)v9 < a2 && HIDWORD(v9) + (int)v9 > (unsigned int)v6 )
      v6 = (__int16 *)(HIDWORD(v9) + v9);
    if ( (unsigned int)v9 > a2 && (!v8 || (unsigned int)v9 < v8[4]) )
      v8 = v7 - 2;
    v7 = (int *)*v7;
  }
  v10 = 0;
  if ( !v6 )
    v6 = (__int16 *)(i - 4);
  v11 = 0;
  if ( (unsigned int)v6 < a2 )
  {
    v12 = *(_DWORD *)(result + 76);
    do
    {
      v11 = v6;
      if ( v12 )
      {
        v12 = *(_DWORD *)(result + 76);
        v22 = *(_DWORD *)v6;
        if ( (v12 & *(_DWORD *)v6) != 0 )
          v22 = *(_DWORD *)(result + 80) ^ *(_DWORD *)v6;
        v13 = (unsigned __int16)v22;
      }
      else
      {
        v13 = (unsigned __int16)*v6;
      }
      if ( !v13 )
        break;
      v6 += 4 * v13;
    }
    while ( (unsigned int)v6 < a2 );
  }
  for ( j = (unsigned int)(v8 - 2); j > a2; j -= 8 * v15 )
  {
    v10 = j;
    v15 = *(unsigned __int16 *)(j + 4) ^ *(unsigned __int16 *)(result + 84);
    if ( !v15 )
      break;
  }
  unk_618320 = v11;
  unk_618324 = v10;
  if ( !v11 || !v10 )
    goto LABEL_71;
  if ( *(_DWORD *)(result + 76) )
  {
    v23 = *(_DWORD *)v11;
    if ( (*(_DWORD *)(result + 76) & *(_DWORD *)v11) != 0 )
      v23 = *(_DWORD *)(result + 80) ^ *(_DWORD *)v11;
    v16 = (unsigned __int16)v23;
  }
  else
  {
    v16 = (unsigned __int16)*v11;
  }
  if ( &v11[4 * v16] != (__int16 *)(v10 - 8 * (*(unsigned __int16 *)(result + 84) ^ *(unsigned __int16 *)(v10 + 4))) )
  {
    v17 = 4;
  }
  else
  {
LABEL_71:
    if ( *(_DWORD *)(result + 76) )
    {
      v24 = *(_DWORD *)v11;
      if ( (*(_DWORD *)(result + 76) & *(_DWORD *)v11) != 0 )
        v24 = *(_DWORD *)(result + 80) ^ *(_DWORD *)v11;
      v18 = (unsigned __int16)v24;
    }
    else
    {
      v18 = (unsigned __int16)*v11;
    }
    v19 = (unsigned __int16 *)&v11[4 * v18];
    if ( v10 )
      word_618330 = *(_WORD *)(result + 84) ^ *(_WORD *)(v10 + 4);
    if ( v11 )
    {
      if ( *(_DWORD *)(result + 76) )
      {
        v25 = *(_DWORD *)v11;
        if ( (*(_DWORD *)(result + 76) & *(_DWORD *)v11) != 0 )
          v25 = *(_DWORD *)(result + 80) ^ *(_DWORD *)v11;
        v20 = v25;
      }
      else
      {
        v20 = *v11;
      }
      word_618334 = v20;
    }
    if ( *(_DWORD *)(result + 76) )
    {
      v26 = *(_DWORD *)v19;
      if ( (*(_DWORD *)(result + 76) & *(_DWORD *)v19) != 0 )
        v26 = *(_DWORD *)(result + 80) ^ *(_DWORD *)v19;
      v21 = (unsigned __int16)v26;
    }
    else
    {
      v21 = *v19;
    }
    if ( (unsigned __int16)word_618330 == v21 )
    {
      if ( (unsigned __int16)word_618334 == (v19[2] ^ *(unsigned __int16 *)(result + 84)) )
        return result;
      v17 = 7;
    }
    else
    {
      v17 = 6;
    }
  }
  dword_618308 = v17;
  return result;
}

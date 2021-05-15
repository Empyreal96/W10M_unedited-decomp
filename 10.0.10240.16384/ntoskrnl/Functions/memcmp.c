// memcmp 
 
int __fastcall memcmp(unsigned int a1, unsigned int a2, int a3)
{
  bool v3; // cc
  int v4; // r3
  int v5; // t1
  int v6; // t1
  int v7; // r12
  int v8; // r3
  int result; // r0
  int v10; // r3
  int v11; // t1
  unsigned __int8 v12; // r12
  int v13; // t1
  int v14; // r3
  int v15; // r3
  int v16; // t1
  int v17; // r12
  int v18; // t1

  if ( a3 < 4 )
  {
LABEL_18:
    if ( !a3 )
      return 0;
    goto LABEL_19;
  }
  if ( ((a1 | a2) & 1) != 0 )
  {
    do
    {
LABEL_19:
      v16 = *(unsigned __int8 *)a1++;
      v15 = v16;
      v18 = *(unsigned __int8 *)a2++;
      v17 = v18;
      --a3;
    }
    while ( a3 && v15 == v17 );
    return v15 - v17;
  }
  if ( (((unsigned __int8)a1 | (unsigned __int8)a2) & 2) != 0 )
  {
    do
    {
      v3 = a3 < 2;
      a3 -= 2;
      if ( v3 )
      {
LABEL_17:
        a3 += 2;
        goto LABEL_18;
      }
      v11 = *(unsigned __int16 *)a1;
      a1 += 2;
      v10 = v11;
      v13 = *(unsigned __int16 *)a2;
      a2 += 2;
      v12 = v13;
      v14 = v10 - v13;
    }
    while ( !v14 );
    if ( (_BYTE)v14 )
      result = *(unsigned __int8 *)(a1 - 2) - v12;
    else
      result = v14 >> 8;
  }
  else
  {
    do
    {
      v3 = a3 < 4;
      a3 -= 4;
      if ( v3 )
      {
        a3 += 2;
        goto LABEL_17;
      }
      v5 = *(_DWORD *)a1;
      a1 += 4;
      v4 = v5;
      v6 = *(_DWORD *)a2;
      a2 += 4;
      v7 = v6 ^ v4;
    }
    while ( v6 == v4 );
    v8 = 4;
    if ( !(_BYTE)v7 )
    {
      v8 = 3;
      if ( (v7 & 0xFF00) == 0 )
      {
        v8 = 2;
        if ( (v7 & 0xFF0000) == 0 )
          v8 = 1;
      }
    }
    result = *(unsigned __int8 *)(a1 - v8) - *(unsigned __int8 *)(a2 - v8);
  }
  return result;
}

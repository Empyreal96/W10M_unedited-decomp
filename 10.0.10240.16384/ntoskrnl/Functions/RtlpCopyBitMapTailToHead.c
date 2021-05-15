// RtlpCopyBitMapTailToHead 
 
int __fastcall RtlpCopyBitMapTailToHead(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r7
  unsigned int v7; // r7
  unsigned int v8; // r6
  int result; // r0
  _DWORD *v10; // r5
  _DWORD *v11; // r4
  char v12; // lr
  int v13; // r3
  int *v14; // r4
  int v15; // r7
  int v16; // lr
  int v17; // t1
  int v18; // t1
  unsigned int v19; // r2

  v5 = a3 >> 3;
  if ( (a3 & 7) != 0 )
  {
    v7 = a4 & 0x1F;
    v8 = a4 >> 5;
    result = a3 & 0x1F;
    v10 = (_DWORD *)(*(_DWORD *)(a2 + 4) + 4 * ((a4 >> 5) + (a3 >> 5)));
    v11 = (_DWORD *)(*(_DWORD *)(a1 + 4) + 4 * (a4 >> 5));
    if ( (a4 & 0x1F) != 0 )
    {
      v12 = 32 - result;
      if ( v7 > 32 - result )
      {
        v10[1] = v10[1] & ~((1 << (v7 + result - 32)) - 1) | ((*v11 & (unsigned int)(((1 << (v7 + result - 32)) - 1) << v12)) >> v12);
        v13 = *v10 & ((1 << result) - 1) | ((*v11 & ((1 << v12) - 1)) << result);
      }
      else
      {
        v13 = ((*v11 & ((1 << v7) - 1)) << result) | *v10 & ~(((1 << v7) - 1) << result);
      }
      *v10 = v13;
    }
    v14 = v11 - 1;
    if ( v8 )
    {
      v15 = (1 << (32 - result)) - 1;
      v16 = (1 << result) - 1;
      do
      {
        v17 = *v14--;
        *v10 = *v10 & ~v16 | ((v17 & (unsigned int)~v15) >> (32 - result));
        v18 = *--v10;
        *v10 = v18 & v16 | ((v14[1] & v15) << result);
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    v19 = a4 >> 3;
    result = a4 & 7;
    if ( (a4 & 7) != 0 )
    {
      result = sub_515BFC(result, a1, v19);
    }
    else if ( v19 )
    {
      result = memmove(*(_DWORD *)(a2 + 4) + v5, *(_DWORD *)(a1 + 4), v19);
    }
  }
  return result;
}

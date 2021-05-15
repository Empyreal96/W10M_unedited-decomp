// RtlCopyBitMap 
 
unsigned int *__fastcall RtlCopyBitMap(unsigned int *result, _DWORD *a2, unsigned int a3)
{
  unsigned int *v3; // r8
  unsigned int v4; // r4
  int v5; // r3
  unsigned int *v6; // r6
  bool v7; // zf
  unsigned int v8; // r5
  int v9; // r4
  int v10; // r5
  int v11; // r7
  int v12; // lr
  unsigned int v13; // r8
  int v14; // t1
  char v15; // r7

  v3 = result;
  v4 = *a2 - a3;
  if ( *result <= v4 )
    v4 = *result;
  if ( v4 )
  {
    v5 = a2[1];
    v6 = (unsigned int *)result[1];
    result = (unsigned int *)(v5 + 4 * (a3 >> 5));
    if ( v6 > result || result > &v6[(v4 - 1) >> 5] )
    {
      if ( (a3 & 7) != 0 )
      {
        v10 = a3 & 0x1F;
        if ( v4 >= 0x20 )
        {
          v11 = (1 << (32 - v10)) - 1;
          v12 = (1 << v10) - 1;
          v13 = v4 >> 5;
          do
          {
            v4 -= 32;
            *result = *result & v12 | ((*v6 & v11) << v10);
            ++result;
            v14 = *v6++;
            *result = *result & ~v12 | ((v14 & (unsigned int)~v11) >> (32 - v10));
            --v13;
          }
          while ( v13 );
        }
        if ( v4 )
        {
          v15 = 32 - v10;
          if ( v4 > 32 - v10 )
          {
            *result = *result & ((1 << v10) - 1) | ((*v6 & ((1 << v15) - 1)) << v10);
            result[1] = result[1] & ~((1 << (v10 + v4 - 32)) - 1) | ((*v6 & (((1 << (v10 + v4 - 32)) - 1) << v15)) >> v15);
          }
          else
          {
            *result = ((((1 << v4) - 1) & *v6) << v10) | *result & ~(((1 << v4) - 1) << v10);
          }
        }
      }
      else
      {
        v8 = v4 >> 3;
        v7 = v4 >> 3 == 0;
        v9 = v4 & 7;
        if ( !v7 )
          result = (unsigned int *)memmove(v5 + (a3 >> 3), v3[1], v8);
        if ( v9 )
          result = (unsigned int *)sub_515B14(result);
      }
    }
    else
    {
      result = (unsigned int *)RtlpCopyBitMapTailToHead(v3, a2, a3, v4);
    }
  }
  return result;
}

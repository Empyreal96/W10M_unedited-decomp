// RtlSidHashLookup 
 
unsigned __int16 **__fastcall RtlSidHashLookup(unsigned int *a1, unsigned __int16 *a2)
{
  unsigned int v2; // lr
  int v4; // r3
  int v5; // r7
  int v6; // r10
  int v7; // r0
  unsigned int v8; // r2
  unsigned int i; // r8
  unsigned int v10; // r6
  int v11; // r4
  unsigned __int16 **v12; // r5
  unsigned int v13; // r1
  unsigned __int16 *v14; // t1
  int v16; // r9
  unsigned int v17; // r4
  int v18; // r6
  unsigned __int16 *v19; // r1
  int v21; // [sp+4h] [bp-24h]
  char v22; // [sp+8h] [bp-20h]

  v2 = (unsigned int)a2;
  if ( !a2 || !a1 )
    return 0;
  v4 = *((unsigned __int8 *)a2 + 1);
  v5 = *a2;
  v6 = 0;
  v7 = v4 + 2;
  v8 = LOBYTE(a2[2 * v4 + 2]);
  v21 = v4 + 2;
  for ( i = a1[(v8 >> 4) + 18] & a1[(v8 & 0xF) + 2]; i; i >>= 8 )
  {
    v16 = (unsigned __int8)i;
    if ( (_BYTE)i )
    {
      v17 = a1[1];
      do
      {
        v18 = v6 + *((unsigned __int8 *)SidHashByteToIndexLookupTable + v16);
        v19 = *(unsigned __int16 **)(v17 + 8 * v18);
        v22 = *((_BYTE *)SidHashByteToIndexLookupTable + v16);
        if ( *v19 == v5 )
        {
          if ( !memcmp(v2, (unsigned int)v19, 4 * v7) )
            return (unsigned __int16 **)(v17 + 8 * v18);
          v2 = (unsigned int)a2;
          v7 = v21;
        }
        v16 = (unsigned __int8)((1 << v22) ^ v16);
      }
      while ( v16 );
    }
    v6 = (unsigned __int8)(v6 + 8);
  }
  v10 = *a1;
  if ( *a1 <= 0x20 )
    return 0;
  v11 = 32;
  if ( v10 <= 0x20 )
    return 0;
  v12 = (unsigned __int16 **)(a1[1] + 256);
  while ( 1 )
  {
    v14 = *v12;
    v12 += 2;
    v13 = (unsigned int)v14;
    if ( *v14 == v5 && !memcmp(v2, v13, 4 * v7) )
      break;
    if ( ++v11 >= v10 )
      return 0;
    v2 = (unsigned int)a2;
    v7 = v21;
  }
  return v12 - 2;
}

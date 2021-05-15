// EtwpCheckPoolTagFilters 
 
int __fastcall EtwpCheckPoolTagFilters(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  unsigned int v5; // r6
  unsigned __int16 *v6; // r5
  int v7; // t1
  unsigned int v8; // r2
  int v9; // r1
  int v10; // r0
  int v12; // [sp+0h] [bp-18h] BYREF
  int v13[5]; // [sp+4h] [bp-14h] BYREF

  v12 = a2;
  v13[0] = a3;
  v13[1] = a4;
  v4 = 0;
  v5 = EtwpPoolTagFilter[10 * a1];
  if ( EtwpPoolTagFilter[10 * a1] )
  {
    v12 = a2;
    v6 = &EtwpPoolTagFilter[10 * a1];
    do
    {
      v7 = *((_DWORD *)v6 + 1);
      v6 += 2;
      v8 = 0;
      v9 = 0;
      v13[0] = v7;
      while ( 1 )
      {
        v10 = *((unsigned __int8 *)v13 + v9);
        if ( v10 == 42 )
          return 1;
        if ( v10 != 63 && (v8 != 3 || (*((_BYTE *)&v12 + v9) & 0x7F) != v10) && *((unsigned __int8 *)&v12 + v9) != v10 )
          break;
        ++v8;
        ++v9;
        if ( v8 >= 4 )
          return 1;
      }
      ++v4;
    }
    while ( v4 < v5 );
  }
  return 0;
}

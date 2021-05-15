// PfpRpRehashIfNeeded 
 
BOOL __fastcall PfpRpRehashIfNeeded(unsigned int a1, unsigned int *a2, int a3, int a4)
{
  unsigned int v5; // r4
  int v7; // r0
  unsigned int v8; // r3
  unsigned int v9; // r0
  char v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r3
  unsigned int *v13; // r6
  int v14; // r2
  unsigned int v15; // r1
  int v16; // lr
  int v17; // r7
  _DWORD *v18; // r6
  int v19; // r2
  unsigned int v20; // r2
  char v21; // r3
  int v23[8]; // [sp+0h] [bp-20h] BYREF

  v23[0] = a3;
  v23[1] = a4;
  v5 = a3;
  v7 = *(_DWORD *)(a1 + 4) >> 5;
  if ( *(_DWORD *)a1 >= (unsigned int)(2 * v7) && RtlULongLongToULong(2 * v7, 0, v23) >= 0 )
  {
    v8 = v23[0];
    if ( !v23[0] )
      v8 = 64;
    if ( v8 <= v5 )
    {
      v9 = *a2;
      if ( ((v5 - 1) & v5) != 0 )
      {
        v10 = -1;
        while ( v5 )
        {
          v5 >>= 1;
          ++v10;
        }
        v5 = 1 << v10;
      }
      if ( v5 > 0x4000000 )
        v5 = 0x4000000;
      v11 = 0;
      if ( v9 > v9 + 4 * v5 )
        v12 = 0;
      else
        v12 = (4 * v5 + 3) >> 2;
      v13 = (unsigned int *)*a2;
      if ( v12 )
      {
        do
        {
          ++v11;
          *v13++ = a1 | 1;
        }
        while ( v11 < v12 );
      }
      v14 = *(_DWORD *)(a1 + 4);
      v15 = 0;
      v16 = -1 << (v14 & 0x1F);
      if ( (v14 & 0xFFFFFFE0) != 0 )
      {
        do
        {
          v17 = *(_DWORD *)(a1 + 8);
          while ( 1 )
          {
            v18 = *(_DWORD **)(v17 + 4 * v15);
            if ( ((unsigned __int8)v18 & 1) != 0 )
              break;
            *(_DWORD *)(v17 + 4 * v15) = *v18;
            v23[0] = v18[1] & v16;
            v19 = (37 * (37 * (37 * (LOBYTE(v23[0]) + 11623883) + BYTE1(v23[0])) + BYTE2(v23[0])) + HIBYTE(v23[0])) & (v5 - 1);
            *v18 = *(_DWORD *)(v9 + 4 * v19);
            *(_DWORD *)(v9 + 4 * v19) = v18;
          }
          ++v15;
        }
        while ( v15 < *(_DWORD *)(a1 + 4) >> 5 );
      }
      v21 = *(_QWORD *)(a1 + 4);
      v20 = *(_DWORD *)(a1 + 8);
      *(_DWORD *)(a1 + 8) = v9;
      *(_DWORD *)(a1 + 4) = v21 & 0x1F | (32 * v5);
      *a2 = v20;
    }
  }
  return (*(_DWORD *)(a1 + 4) & 0xFFFFFFE0) != 0;
}

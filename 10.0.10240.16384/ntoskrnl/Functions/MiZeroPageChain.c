// MiZeroPageChain 
 
_DWORD *__fastcall MiZeroPageChain(int a1, int a2, unsigned int a3)
{
  int *v3; // r4
  unsigned int v4; // r6
  int v5; // r5
  unsigned int v7; // r3
  unsigned int v8; // r10
  int v9; // r2
  int v10; // r3
  int v11; // r5
  _DWORD *result; // r0
  unsigned int v13; // r4
  _DWORD *v14; // r0
  unsigned int v15; // r5
  int v16; // r0
  int v17; // [sp+0h] [bp-B8h] BYREF
  char v18; // [sp+4h] [bp-B4h]
  char v19; // [sp+5h] [bp-B3h]
  int v20; // [sp+8h] [bp-B0h]
  int v21; // [sp+Ch] [bp-ACh]
  int v22; // [sp+10h] [bp-A8h]
  int v23; // [sp+14h] [bp-A4h]

  v3 = *(int **)(a1 + 3256);
  v4 = a3;
  v5 = *v3;
  v7 = (unsigned int)*v3 >> 13;
  if ( a3 > v7 )
  {
    v21 = 0;
    v19 = 0;
    v23 = 0;
    v18 = 0;
    v17 = 0;
    v22 = 0;
    v20 = 33;
    MiInsertTbFlushEntry(&v17, (_DWORD)&v3[v7] << 10, 256 - v7);
    MiFlushTbList(&v17);
    v7 = 256;
  }
  v8 = v7 - v4;
  v9 = v5 & 0x1FFF ^ ((v7 - v4) << 13);
  if ( (unsigned int)(v3 + 0x10000000) > 0x3FFFFF )
  {
    *v3 = v9;
  }
  else
  {
    v10 = *v3;
    v11 = 0;
    __dmb(0xBu);
    *v3 = v9;
    if ( (v10 & 2) == 0 && (v9 & 2) != 0 )
      v11 = 1;
    if ( (unsigned int)v3 >= 0xC0300000 )
      return (_DWORD *)sub_51C754();
    if ( v11 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  v13 = (unsigned int)&v3[v8];
  v14 = (_DWORD *)MiMapPagesToZero(v13, a2, 0);
  result = KeZeroPages(v14, v4 << 12);
  if ( v4 )
  {
    v15 = v13 + 0x40000000;
    do
    {
      if ( v15 > 0x3FFFFF )
      {
        *(_DWORD *)v13 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v13 = 0;
        if ( v13 >= 0xC0300000 && v13 <= 0xC0300FFF )
        {
          v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          result = (_DWORD *)MiArmWriteConvertedHardwarePde(v16, v16 + 4 * (v13 & 0xFFF), 0);
        }
      }
      v13 += 4;
      v15 += 4;
      --v4;
    }
    while ( v4 );
  }
  return result;
}

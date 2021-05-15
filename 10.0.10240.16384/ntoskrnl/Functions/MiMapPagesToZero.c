// MiMapPagesToZero 
 
int __fastcall MiMapPagesToZero(unsigned int a1, int *a2, int a3)
{
  int v3; // lr
  int *v4; // r6
  unsigned int v5; // r4
  int *v6; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r3
  unsigned int v12; // r2
  int v13; // r3
  int v14; // r5
  int v15; // r0
  int *v17; // [sp+4h] [bp-2Ch]
  unsigned int v18; // [sp+Ch] [bp-24h]

  v3 = a3;
  v4 = a2;
  v5 = a1;
  if ( a3 == 1 )
    v6 = a2 + 6144;
  else
    v6 = 0;
  v17 = v6;
  v18 = a1 << 10;
  do
  {
    if ( (*((_BYTE *)v4 + 18) & 0xC0) == 192 )
      return sub_51C7AC(MmProtectToPteMask);
    v8 = 4;
    v9 = *((unsigned __int8 *)v4 + 18) >> 6;
    if ( v9 )
    {
      if ( v9 == 2 )
        v8 = 28;
    }
    else
    {
      v8 = 12;
    }
    v10 = 2048;
    if ( v5 > (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 || v5 < 0xC0000000 )
    {
      if ( v5 < 0xC0300000 || v5 > dword_633898 )
      {
        if ( v5 + 0x40000000 > 0x3FFFFF
          || v5 << 10 < dword_63389C
          || (v11 = *((unsigned __int8 *)&MiState[2423]
                    + ((int)(((v5 >> 10) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
              v11 != 1)
          && v11 != 11 )
        {
          v10 = 0;
        }
      }
    }
    else
    {
      v10 = 2080;
    }
    v12 = (v10 | MmProtectToPteMask[v8] & 0xFED | ((((int)v4 - MmPfnDatabase) / 24) << 12) | 0x12) & 0xFFFFF1FF;
    if ( v5 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v5 = v12;
    }
    else
    {
      v13 = *(_DWORD *)v5;
      v14 = 0;
      __dmb(0xBu);
      if ( (v13 & 2) == 0 )
        v14 = 1;
      *(_DWORD *)v5 = v12;
      if ( v5 >= 0xC0300000 && v5 <= 0xC0300FFF )
      {
        v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v15, v15 + 4 * (v5 & 0xFFF), v12);
        v3 = a3;
      }
      if ( v14 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    v5 += 4;
    if ( v3 == 1 )
      v4 += 6;
    else
      v4 = (int *)*v4;
  }
  while ( v4 != v17 );
  return v18;
}

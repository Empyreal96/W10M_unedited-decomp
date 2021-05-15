// MmUnmapReservedMapping 
 
unsigned int __fastcall MmUnmapReservedMapping(unsigned int a1, int a2, int a3)
{
  int v3; // r8
  unsigned int v5; // r6
  int v6; // r0
  unsigned int v7; // r5
  int v8; // r1
  unsigned int v9; // r7
  unsigned int v10; // r4
  unsigned int v11; // r10
  int v12; // t1
  _DWORD *v13; // r4
  unsigned int v14; // r5
  int v15; // r0
  unsigned int result; // r0
  int v17; // [sp+8h] [bp-C0h]
  int v18; // [sp+10h] [bp-B8h] BYREF
  char v19; // [sp+14h] [bp-B4h]
  char v20; // [sp+15h] [bp-B3h]
  int v21; // [sp+18h] [bp-B0h]
  int v22; // [sp+1Ch] [bp-ACh]
  int v23; // [sp+20h] [bp-A8h]
  int v24; // [sp+24h] [bp-A4h]

  v17 = a3;
  v3 = a3;
  v5 = a1;
  if ( (*(_WORD *)(a3 + 6) & 0x200) != 0 )
    v5 = a1 - MiRetardMdl(a3);
  v6 = MiValidateReservedMapping(v5, a2);
  v7 = ((v5 >> 10) & 0x3FFFFC) - 0x40000000;
  v8 = ((v5 >> 10) & 0x3FFFFC) - 1073741832;
  v9 = (*(_DWORD *)(v3 + 20)
      + (((unsigned __int16)*(_DWORD *)(v3 + 24) + (unsigned __int16)*(_DWORD *)(v3 + 16)) & 0xFFFu)
      + 4095) >> 12;
  if ( v9 > v6 - 2 )
    KeBugCheckEx(218, 266, v5, v6, v9);
  v10 = v7 + 4 * (v6 - 2);
  v22 = 0;
  v23 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 33;
  v11 = v7 + 4 * v9;
  v24 = 0;
  if ( v7 < v11 )
  {
    do
    {
      if ( (*(_DWORD *)v7 & 2) == 0 )
        KeBugCheckEx(218, 267, v5, a2, v9);
      MiInsertTbFlushEntry((int)&v18, v7 << 10, 1, 0);
      v7 += 4;
    }
    while ( v7 < v11 );
    v8 = ((v5 >> 10) & 0x3FFFFC) - 1073741832;
  }
  while ( v7 < v10 )
  {
    v12 = *(_DWORD *)v7;
    v7 += 4;
    if ( v12 )
      KeBugCheckEx(218, 268, v5, a2, v9);
  }
  v13 = (_DWORD *)(v8 + 8);
  if ( v9 )
  {
    v14 = v8 + 1070596104;
    do
    {
      if ( v14 + 3145728 > 0x3FFFFF )
      {
        *v13 = 0;
      }
      else
      {
        __dmb(0xBu);
        *v13 = 0;
        if ( v14 <= 0xFFF )
        {
          v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v15, (_DWORD *)(v15 + 4 * ((unsigned __int16)v13 & 0xFFF)), 0);
        }
      }
      ++v13;
      v14 += 4;
      --v9;
    }
    while ( v9 );
    v3 = v17;
  }
  result = MiFlushTbList((unsigned int)&v18, v8);
  *(_WORD *)(v3 + 6) &= 0xFFDEu;
  return result;
}

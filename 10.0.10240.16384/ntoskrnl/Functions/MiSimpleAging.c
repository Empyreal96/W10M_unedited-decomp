// MiSimpleAging 
 
unsigned int __fastcall MiSimpleAging(unsigned int result)
{
  int v1; // r5
  unsigned int v2; // r4
  _DWORD *v3; // r8
  int v4; // r7
  int v5; // r7
  int v6; // r6
  int v7; // r1
  int v8; // r0
  int v9; // r4
  int v10; // r0
  _DWORD *v11; // r2
  int v12; // [sp+8h] [bp-B8h] BYREF
  char v13; // [sp+Ch] [bp-B4h]
  char v14; // [sp+Dh] [bp-B3h]
  int v15; // [sp+10h] [bp-B0h]
  int v16; // [sp+14h] [bp-ACh]
  int v17; // [sp+18h] [bp-A8h]
  int v18; // [sp+1Ch] [bp-A4h]

  v1 = result;
  v2 = *(_DWORD *)(result + 60);
  if ( (*(_BYTE *)(result + 112) & 0x40) != 0 && v2 >= 4 * (*(_DWORD *)(result + 68) / 5u) )
  {
    v3 = *(_DWORD **)(result + 92);
    v4 = v3[1];
    result = v3[16] + v3[15];
    if ( v4 + result >= 4 * (v2 / 5) && v2 - v4 - result < 0x400 )
    {
      if ( result > 0x100 )
        v5 = result >> 5;
      else
        v5 = 8;
      v16 = 0;
      v17 = 0;
      v13 = 0;
      v14 = 0;
      v15 = 33;
      v6 = 1;
      v18 = 0;
      v12 = MiTbFlushType(v1);
      while ( v5 )
      {
        v8 = MiRotateHeadWsle(v3, v6);
        if ( v8 == 0xFFFFF )
        {
          if ( !v6 )
            break;
          --v6;
        }
        else
        {
          --v5;
          v9 = v3[9] * v8;
          v10 = v3[63];
          v11 = (_DWORD *)(((*(_DWORD *)(v9 + v10) >> 10) & 0x3FFFFC) - 0x40000000);
          MiClearPteAccessed(
            v1,
            MmPfnDatabase + 24 * (*v11 >> 12),
            (unsigned int)v11,
            (_DWORD *)(v9 + v10),
            (int)&v12,
            dword_634484);
        }
      }
      result = MiFlushTbList((unsigned int)&v12, v7);
    }
  }
  return result;
}

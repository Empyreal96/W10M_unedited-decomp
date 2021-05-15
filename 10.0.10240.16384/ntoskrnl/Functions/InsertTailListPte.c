// InsertTailListPte 
 
unsigned int __fastcall InsertTailListPte(unsigned int result, int *a2)
{
  _DWORD *v2; // r5
  int v4; // r9
  int v5; // r2
  int *v6; // r1
  int v7; // r2
  int v8; // r1
  int v9; // r2
  int v10; // r4
  int *v11; // r2
  int v12; // r0
  int v13; // r0
  int v14; // [sp+0h] [bp-20h]

  v2 = (_DWORD *)result;
  v4 = *(_DWORD *)(result + 4) >> 12;
  v14 = (result >> 10) & 0x3FFFFC;
  v5 = (v14 - *(_DWORD *)(result + 8) - 0x40000000) >> 2 << 12;
  if ( (unsigned int)(a2 + 0x10000000) > 0x3FFFFF )
  {
    *a2 = v5;
  }
  else
  {
    __dmb(0xBu);
    *a2 = v5;
    if ( (unsigned int)(a2 + 267649024) <= 0xFFF )
      return sub_54D1A0();
  }
  v6 = a2 + 1;
  v7 = v4 << 12;
  if ( (unsigned int)(a2 + 268435457) > 0x3FFFFF )
  {
    *v6 = v7;
  }
  else
  {
    __dmb(0xBu);
    *v6 = v7;
    if ( (unsigned int)(a2 + 267649025) <= 0xFFF )
    {
      v12 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      result = MiArmWriteConvertedHardwarePde(v12, (_DWORD *)(v12 + 4 * ((unsigned __int16)v6 & 0xFFF)), v7);
    }
  }
  v8 = v2[2];
  v9 = ((int)a2 - v8) >> 2;
  if ( v4 == (v14 - v8 - 0x40000000) >> 2 )
  {
    v10 = v9 << 12;
    *v2 = *v2 & 0xFFF | (v9 << 12);
  }
  else
  {
    v10 = v9 << 12;
    v11 = (int *)(v8 + 4 * v4);
    if ( (unsigned int)(v11 + 0x10000000) > 0x3FFFFF )
    {
      *v11 = v10;
    }
    else
    {
      __dmb(0xBu);
      *v11 = v10;
      if ( (unsigned int)(v11 + 267649024) <= 0xFFF )
      {
        v13 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        result = MiArmWriteConvertedHardwarePde(v13, (_DWORD *)(v13 + 4 * ((unsigned __int16)v11 & 0xFFF)), v10);
      }
    }
  }
  v2[1] = v2[1] & 0xFFF | v10;
  return result;
}

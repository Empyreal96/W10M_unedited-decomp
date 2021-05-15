// RemoveListEntryPte 
 
int __fastcall RemoveListEntryPte(unsigned int a1, _DWORD *a2)
{
  _DWORD *v3; // r5
  int v4; // r2
  int v5; // lr
  int v6; // r0
  _DWORD *v7; // r2
  int result; // r0
  int v9; // r1
  int v10; // r2
  int *v11; // r1
  int v12; // r4
  int v13; // r3
  int v14; // r5
  int v15; // r0

  v3 = (_DWORD *)a1;
  v4 = a2[1] >> 12;
  v5 = (a1 >> 10) & 0x3FFFFC;
  v6 = *(_DWORD *)(a1 + 8);
  if ( v4 == (v5 - v6 - 0x40000000) >> 2 )
    v7 = v3;
  else
    v7 = (_DWORD *)(v6 + 4 * v4);
  result = 2;
  if ( (unsigned int)v7 >= 0xC0000000 )
    return sub_5531C4(2);
  *v7 = *a2;
  v9 = v3[2];
  v10 = *a2 >> 12;
  if ( v10 != (v5 - v9 - 0x40000000) >> 2 )
    v3 = (_DWORD *)(v9 + 4 * v10);
  v11 = v3 + 1;
  v12 = a2[1];
  if ( (unsigned int)(v3 + 268435457) > 0x3FFFFF )
  {
    *v11 = v12;
  }
  else
  {
    v13 = *v11;
    v14 = 0;
    __dmb(0xBu);
    *v11 = v12;
    if ( (v13 & 2) == 0 && (v12 & 2) != 0 )
      v14 = 1;
    if ( (unsigned int)(v11 + 267649024) <= 0xFFF )
    {
      v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      result = MiArmWriteConvertedHardwarePde(v15, (_DWORD *)(v15 + 4 * ((unsigned __int16)v11 & 0xFFF)), v12);
    }
    if ( v14 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  return result;
}

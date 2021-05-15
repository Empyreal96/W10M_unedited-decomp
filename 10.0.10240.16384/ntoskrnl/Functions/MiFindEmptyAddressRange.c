// MiFindEmptyAddressRange 
 
int __fastcall MiFindEmptyAddressRange(unsigned int a1, int a2, unsigned int a3, char a4, int *a5, _DWORD *a6)
{
  unsigned int v6; // r8
  int v9; // r7
  _DWORD *v10; // lr
  unsigned int v11; // r9
  unsigned int v12; // r3
  int result; // r0
  unsigned int v14; // r7
  unsigned int v15; // r2
  int v16; // r8
  unsigned int v17; // r0
  int v18; // r1
  int v19; // r2
  unsigned int v20; // r3
  int v21; // r2
  unsigned int v22; // r3
  unsigned int v23; // r4
  int v24; // r3
  unsigned int v25; // [sp+8h] [bp-40h]
  unsigned int v26; // [sp+Ch] [bp-3Ch]
  int v28; // [sp+18h] [bp-30h]
  unsigned int v29[10]; // [sp+20h] [bp-28h] BYREF

  v6 = a3;
  v9 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v10 = a6;
  v28 = v9;
  *a6 = 1;
  if ( (a4 & 2) == 0 )
    JUMPOUT(0x802392);
  v11 = MEMORY[0xC0402110];
  v12 = MEMORY[0xC0402136];
  v25 = MEMORY[0xC0402110];
  v26 = MEMORY[0xC0402136];
  if ( !MEMORY[0xC0402110] )
    return sub_80238C();
  if ( a2 != 4096 )
  {
    if ( a2 == 0x10000 )
      v14 = (a1 + 0xFFFF) >> 16;
    else
      v14 = HIWORD(a1);
    while ( 1 )
    {
      v29[1] = MEMORY[0xC040212C];
      v29[0] = MEMORY[0xC0402114];
      if ( v6 != MmHighestUserAddress - 0x10000 )
        break;
      v15 = MEMORY[0xC0402104];
      if ( v14 != 1 && v14 >= MEMORY[0xC040210C] )
        v15 = MEMORY[0xC0402108];
      v16 = MEMORY[0xC040212C] + 1069547520;
      v22 = v15 + 8 * v16;
      if ( v22 < v25 || v22 >= v26 )
      {
        v15 = v25;
        *v10 = 0;
      }
      if ( a2 == 0x10000 )
        v17 = RtlFindClearBits(v29, v14, v15);
      else
        v17 = MiFindClearBitsAligned(v29, v14, v15);
      if ( v17 != -1 )
      {
        v19 = v25;
        v20 = v17 + 8 * v16;
        if ( v20 >= v25 )
        {
          v19 = v26;
          if ( v20 < v26 )
          {
            v21 = (v17 + 8 * MEMORY[0xC040212C]) << 16;
            result = 0;
            *a5 = v21;
            return result;
          }
        }
      }
      if ( MiExpandVadBitMap(v14, v18, v19, v20) != 1 )
        return -1073741801;
      v10 = a6;
      v6 = a3;
    }
    v11 = v25;
    v12 = v26;
    v9 = v28;
  }
  *v10 = 0;
  if ( v6 > v12 << 16 )
    v6 = v12 << 16;
  v23 = MEMORY[0xC0402130];
  if ( MEMORY[0xC0402130] > v6 )
  {
    if ( (*(_DWORD *)(v9 + 188) & 0x2000000) == 0 || (v24 = 0x3FFFFFFF, v6 <= 0x3FFFFFFF) )
      v24 = 0xFFFFFF;
    v23 = v24 & MEMORY[0xC0402130];
    if ( (v24 & MEMORY[0xC0402130]) == 0 || v23 > v6 )
      v23 = 0x10000;
    if ( v23 < MEMORY[0xC0402130] )
      v23 = v11 << 16;
  }
  result = MiFindEmptyAddressRangeInTree(v9 + 636, a1, a2, v23, v6, a5);
  if ( result < 0 && v11 << 16 < v23 )
    result = MiFindEmptyAddressRangeInTree(v9 + 636, a1, a2, v11 << 16, v6, a5);
  return result;
}

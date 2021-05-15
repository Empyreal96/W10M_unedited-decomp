// IoSetDumpRange 
 
int __fastcall IoSetDumpRange(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int v4; // r7
  unsigned int v5; // r5
  int v7; // r0
  unsigned int v8; // r2
  int v9; // r4
  int v10; // r1
  unsigned int v11; // lr
  unsigned int v12; // t1
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r8
  unsigned int v16; // t1
  int v17; // r8
  int v18; // r0
  __int64 v20[5]; // [sp+8h] [bp-28h] BYREF

  v4 = a3;
  v5 = a2;
  if ( a4 == 1 )
  {
    MmGetPhysicalAddress((int)v20, a2, a3, 1);
    v7 = IopAddPageToPageMap(a1[2], a1[3], v20[0] >> 12, v4, (a1[4] & 1) != 0);
LABEL_20:
    v9 = v7;
    goto LABEL_30;
  }
  if ( a4 != 2 )
  {
    v17 = 1;
    if ( !a3 )
      return 0;
    v9 = -1073741789;
    do
    {
      if ( MiIsAddressValid(v5, 0, a3, a4) )
      {
        MmGetPhysicalAddress((int)v20, v5, a3, a4);
        v18 = IopAddPageToPageMap(a1[2], a1[3], v20[0] >> 12, 1, (a1[4] & 1) != 0);
        if ( v18 == -1073741789 )
          return v9;
        if ( v18 < 0 )
          v17 = 0;
      }
      v5 += 4096;
      --v4;
    }
    while ( v4 );
    if ( v17 == 1 )
      return 0;
    v9 = -1073741503;
LABEL_30:
    if ( v9 != -1073741503 )
      return v9;
    goto LABEL_31;
  }
  v8 = 0;
  v9 = -1073741503;
  if ( *(_DWORD *)MmPhysicalMemoryBlock )
  {
    v10 = MmPhysicalMemoryBlock;
    do
    {
      v12 = *(_DWORD *)(v10 + 8);
      v10 += 8;
      v11 = v12;
      if ( v12 > v5 )
        break;
      if ( *(_DWORD *)(v10 + 4) + v11 > v5 )
      {
        if ( v4 > *(_DWORD *)(MmPhysicalMemoryBlock + 8 * v8 + 8)
                + *(_DWORD *)(MmPhysicalMemoryBlock + 8 * v8 + 12)
                - v5 )
          break;
LABEL_19:
        v7 = IopAddPageToPageMap(a1[2], a1[3], v5, v4, (a1[4] & 1) != 0);
        goto LABEL_20;
      }
      ++v8;
    }
    while ( v8 < *(_DWORD *)MmPhysicalMemoryBlock );
  }
  if ( SpecialMemoryRanges )
  {
    v13 = 0;
    if ( *(_DWORD *)SpecialMemoryRanges )
    {
      v14 = SpecialMemoryRanges;
      do
      {
        v16 = *(_DWORD *)(v14 + 8);
        v14 += 8;
        v15 = v16;
        if ( v16 > v5 )
          break;
        if ( *(_DWORD *)(v14 + 4) + v15 > v5 )
        {
          if ( v4 > *(_DWORD *)(SpecialMemoryRanges + 8 * v13 + 8)
                  + *(_DWORD *)(SpecialMemoryRanges + 8 * v13 + 12)
                  - v5 )
            break;
          goto LABEL_19;
        }
        ++v13;
      }
      while ( v13 < *(_DWORD *)SpecialMemoryRanges );
    }
  }
LABEL_31:
  if ( (a1[4] & 1) != 0 )
    return 0;
  return v9;
}

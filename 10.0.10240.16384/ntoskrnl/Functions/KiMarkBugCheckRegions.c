// KiMarkBugCheckRegions 
 
int *__fastcall KiMarkBugCheckRegions(int a1, int a2, int a3, int a4)
{
  int *result; // r0
  int v6; // r8
  int v7; // r1
  int *v8; // r4
  int v9; // r1
  int v10; // r8
  unsigned int v11; // r9
  unsigned int v12; // r5
  unsigned int i; // r7
  int v14; // r5
  int v15; // r1
  int v16; // r8
  int v17; // r1
  int v18; // r1
  unsigned int v19; // r5
  unsigned int j; // r4
  int v21; // r0
  unsigned int v22; // r5
  unsigned int k; // r4
  int v24; // r0
  int v25; // r1
  unsigned int v26; // [sp+4h] [bp-34h]
  int v27; // [sp+8h] [bp-30h]
  int *v28; // [sp+Ch] [bp-2Ch] BYREF
  int v29; // [sp+10h] [bp-28h]
  int v30; // [sp+14h] [bp-24h]
  int v31[8]; // [sp+18h] [bp-20h] BYREF

  result = &KdpBreakpointChangeCount;
  v6 = a3;
  v7 = KdpBreakpointChangeCount;
  v29 = a3;
  __dmb(0xBu);
  if ( v7 )
    result = (int *)IoAddTriageDumpDataBlock((int)&KdpBreakpointChangeCount, 4);
  v8 = &dword_618DA8;
  v9 = *(_DWORD *)&algn_618DB4[4] | *(_DWORD *)&algn_618DB4[8];
  if ( *(_QWORD *)&algn_618DB4[4] )
  {
    KiMismatchSummary = *(_QWORD *)&algn_618DB4[4];
    result = (int *)IoAddTriageDumpDataBlock((int)&KiMismatchSummary, 8);
  }
  v30 = -1073741824;
  if ( a4 == 257 && dword_618DB0 )
  {
    v10 = dword_618DA8;
    v11 = 0;
    v26 = 0;
    v27 = dword_618DA8;
    do
    {
      result = (int *)MmIsAddressValid(v10 & 0xFFFFF000, v9);
      if ( result )
      {
        v12 = ((v10 & 0xFFFFF000) >> 10) & 0x3FFFFC;
        for ( i = 0; i < 2; ++i )
        {
          if ( i )
          {
            result = (int *)((((v12 - 1073741821) >> 10) & 0x3FFFFC) - 0x40000000);
          }
          else
          {
            result = (int *)(v12 - 0x40000000);
            if ( (*(_DWORD *)((((v12 - 0x40000000) >> 10) & 0x3FFFFC) + v30) & 0x400) != 0 )
              result = 0;
          }
          if ( result )
            result = (int *)IoAddTriageDumpDataBlock((int)result, 4);
        }
        v8 = &dword_618DA8;
        v11 = v26;
        v10 = v27;
      }
      v11 += 4096;
      v10 += 4096;
      v26 = v11;
      v27 = v10;
    }
    while ( v11 < dword_618DB0 );
    v6 = v29;
    dword_618DB0 = 4096;
  }
  v14 = 2;
  do
  {
    v15 = v8[2];
    if ( v15 )
      result = (int *)IoAddTriageDumpDataBlock(*v8, v15);
    ++v8;
    --v14;
  }
  while ( v14 );
  if ( v6 )
  {
    v16 = v6 & 0xFFFFF000;
    v30 = v16;
    IoAddTriageDumpDataBlock(v16, 4096);
    IoAddTriageDumpDataBlock(v16 + 4096, 4096);
    if ( MmIsAddressValid(v16 & 0xFFFFF000, v17) )
    {
      v19 = ((v16 & 0xFFFFF000) >> 10) & 0x3FFFFC;
      for ( j = 0; j < 2; ++j )
      {
        if ( j )
        {
          v21 = (((v19 - 1073741821) >> 10) & 0x3FFFFC) - 0x40000000;
        }
        else
        {
          v21 = v19 - 0x40000000;
          if ( (*(_DWORD *)((((v19 - 0x40000000) >> 10) & 0x3FFFFC) - 0x40000000) & 0x400) != 0 )
            v21 = 0;
        }
        if ( v21 )
          IoAddTriageDumpDataBlock(v21, 4);
      }
      v16 = v30;
    }
    if ( MmIsAddressValid((v16 + 4096) & 0xFFFFF000, v18) )
    {
      v22 = (((v16 + 4096) & 0xFFFFF000) >> 10) & 0x3FFFFC;
      for ( k = 0; k < 2; ++k )
      {
        if ( k )
        {
          v24 = (((v22 - 1073741821) >> 10) & 0x3FFFFC) - 0x40000000;
        }
        else
        {
          v24 = v22 - 0x40000000;
          if ( (*(_DWORD *)((((v22 - 0x40000000) >> 10) & 0x3FFFFC) - 0x40000000) & 0x400) != 0 )
            v24 = 0;
        }
        if ( v24 )
          IoAddTriageDumpDataBlock(v24, 4);
      }
    }
    MmQueryApiSetSchema(&v28, v31);
    result = (int *)MmIsAddressValid(v28, v25);
    if ( result )
    {
      result = v28;
      if ( v29 == *v28 )
        result = (int *)IoAddTriageDumpDataBlock((int)v28, 4);
    }
  }
  return result;
}

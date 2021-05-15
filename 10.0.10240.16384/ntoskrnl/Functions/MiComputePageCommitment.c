// MiComputePageCommitment 
 
int __fastcall MiComputePageCommitment(unsigned int a1, unsigned int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // lr
  char v6; // r7
  unsigned int v7; // r6
  unsigned int v8; // r9
  int v9; // r4
  int v10; // t1
  unsigned int v11; // r1
  int v13; // r0
  int v14; // r2
  unsigned int v15; // r1
  int v16; // r0
  int v17; // [sp+8h] [bp-28h]
  int v18; // [sp+Ch] [bp-24h] BYREF
  int v19; // [sp+10h] [bp-20h]

  v5 = a4;
  v19 = a4;
  v6 = 0;
  v17 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v7 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v8 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  if ( *(int *)(a3 + 32) >= 0 )
  {
    v9 = 0;
  }
  else
  {
    v6 = 2;
    v9 = ((int)(v8 - v7) >> 2) + 1;
  }
  if ( a5 )
    *a5 = 0;
  if ( v7 > v8 )
    return v9;
  do
  {
    v7 = MiGetNextPageTable(v7, v8, 0, v5, 1, &v18);
    if ( !v7 )
      break;
    do
    {
      v10 = *(_DWORD *)v7;
      v7 += 4;
      v18 = v10;
      if ( v10 )
      {
        if ( MiIsPteDecommittedPage(&v18) )
          return sub_53E6F0();
        v6 &= 0xFEu;
        if ( (v6 & 2) != 0 )
        {
          v13 = v6 & 1;
          if ( (v6 & 1) != 0 )
            --v9;
        }
        else
        {
          v13 = v6 & 1;
          if ( (v6 & 1) == 0 )
            ++v9;
        }
        if ( a5 && MEMORY[0xC0402140] && !v13 )
        {
          if ( (v11 & 2) != 0 )
          {
            v14 = MmPfnDatabase + 24 * (v11 >> 12);
            if ( (*(_DWORD *)(v14 + 20) & 0x8000000) == 0 || *(int *)(v14 + 4) >= 0 )
              continue;
          }
          else
          {
            if ( (v11 & 0x400) == 0 )
              continue;
            if ( (v11 & 0xFFFFE000) == -8192 )
              continue;
            v15 = (v11 & 0x1FC | (v11 >> 2) & 0x3FFFFE00) - 0x40000000;
            if ( v15 >= dword_640484 && v15 < dword_640488 )
              continue;
          }
          v16 = MiLocateCloneAddress(v17);
          if ( v16 && MEMORY[0xC0402140] > *(_QWORD *)(v16 + 40) )
            ++*a5;
        }
      }
    }
    while ( v7 <= v8 && (v7 & 0xFFF) != 0 );
    v5 = v19;
  }
  while ( v7 <= v8 );
  return v9;
}

// MmGrowKernelStackEx 
 
int __fastcall MmGrowKernelStackEx(int a1, int a2)
{
  unsigned int v4; // r5
  int v6; // r4
  int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r6
  int v10; // r9
  int v11; // r8
  unsigned int v12; // r0
  unsigned int v13; // r0

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(v4 + 0x28) - (*(_DWORD *)(*(_DWORD *)(v4 + 0x20) + 4) & 0xFFFFFFFE) < 0xF000 )
    return sub_5231F4();
  v6 = 0;
  v7 = KfRaiseIrql(2);
  v8 = ((*(_DWORD *)(v4 + 36) >> 10) & 0x3FFFFC) - 0x40000000;
  v9 = (((unsigned int)(a1 - a2) >> 10) & 0x3FFFFC) - 0x40000000;
  v10 = v7;
  if ( v9 < v8 )
  {
    if ( v9 < ((*(_DWORD *)(*(_DWORD *)(v4 + 32) + 4) >> 10) & 0x3FFFFCu) - 0x40000000 )
    {
      v6 = -1073741571;
      ++dword_634850;
    }
    else
    {
      v11 = ((int)(v8 - v9 - 4) >> 2) + 1;
      if ( MiChargeResident(MiSystemPartition, v11, 0) )
      {
        do
          v12 = __ldrex(dword_634A04);
        while ( __strex(v12 + v11, dword_634A04) );
        if ( MiAllocateKernelStackPages(
               v9,
               v11,
               v4 | 1,
               *(_DWORD *)(MmPfnDatabase
                         + 24 * (*(_DWORD *)(((*(_DWORD *)(v4 + 40) >> 10) & 0x3FFFFC) - 1073741828) >> 12)
                         + 20) >> 28) )
        {
          *(_DWORD *)(v4 + 36) = v9 << 10;
        }
        else
        {
          MiReturnResidentAvailable(v11);
          do
            v13 = __ldrex(&dword_634A04[3]);
          while ( __strex(v13 + v11, &dword_634A04[3]) );
          v6 = -1073741670;
        }
      }
      else
      {
        v6 = -1073741801;
      }
    }
  }
  KfLowerIrql(v10);
  return v6;
}

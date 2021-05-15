// MmAddPrivateDataToCrashDump 
 
int __fastcall MmAddPrivateDataToCrashDump(int (__fastcall **a1)(_DWORD, unsigned int, int, int), char a2)
{
  int v2; // r5
  int v5; // r0
  int v6; // r8
  void **v7; // r10
  int v8; // t1
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int *v12; // r4
  int v13; // r0
  int v15; // [sp+0h] [bp-20h]

  v2 = 0;
  if ( (a2 & 1) != 0 )
  {
    v5 = MmAddRangeToCrashDump(a1, MmPfnDatabase, 24 * (dword_633850 + 1));
    if ( v5 < 0 )
      v2 = v5;
  }
  if ( (a2 & 2) != 0 )
  {
    v6 = KeNumberProcessors_0;
    if ( KeNumberProcessors_0 )
    {
      v7 = &KiProcessorBlock;
      do
      {
        v8 = (int)*v7++;
        v15 = *(_DWORD *)(*(_DWORD *)(v8 + 4) + 116);
        if ( (*a1)(a1, *(_DWORD *)(v15 + 24) >> 12, 1, 2) < 0 )
        {
          v9 = (*a1)(a1, *(_DWORD *)(v15 + 32), 4, 0);
          if ( v9 < 0 )
            v2 = v9;
        }
        --v6;
      }
      while ( v6 );
    }
  }
  if ( (a2 & 4) != 0 )
  {
    v10 = MmAddRangeToCrashDump(a1, PsNtosImageBase, PsNtosImageEnd - PsNtosImageBase);
    if ( v10 < 0 )
      v2 = v10;
  }
  if ( (a2 & 8) != 0 )
  {
    v11 = MmAddRangeToCrashDump(a1, PsHalImageBase, PsHalImageEnd - PsHalImageBase);
    if ( v11 < 0 )
      v2 = v11;
  }
  if ( (a2 & 0x10) != 0 )
  {
    v12 = (int *)dword_634D28;
    while ( v12 != &dword_634D28 )
    {
      v13 = MmAddRangeToCrashDump(a1, (unsigned int)(v12 - 24), 8448);
      v12 = (int *)*v12;
      if ( v13 < 0 )
        v2 = v13;
    }
  }
  return v2;
}

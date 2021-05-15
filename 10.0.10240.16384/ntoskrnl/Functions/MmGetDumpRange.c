// MmGetDumpRange 
 
int __fastcall MmGetDumpRange(int result, int a2, char a3)
{
  int (__fastcall **v4)(_DWORD, unsigned int, int, int); // r5
  int v5; // r7
  void **v6; // r9
  int v7; // t1
  int v8; // r10
  int v9; // r2
  unsigned int i; // r7
  int v11; // r8
  unsigned int v12; // r1
  unsigned int v13; // r7
  unsigned int v14; // r8

  v4 = (int (__fastcall **)(_DWORD, unsigned int, int, int))result;
  if ( a2 )
  {
    v9 = MmPhysicalMemoryBlock;
    for ( i = 0; i < *(_DWORD *)MmPhysicalMemoryBlock; ++i )
    {
      result = (*v4)(v4, *(_DWORD *)(v9 + 8 * i + 8), *(_DWORD *)(v9 + 8 * i + 12), 2);
      v9 = MmPhysicalMemoryBlock;
    }
  }
  else
  {
    v5 = KeNumberProcessors_0;
    if ( KeNumberProcessors_0 )
    {
      v6 = &KiProcessorBlock;
      do
      {
        v7 = (int)*v6++;
        v8 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 116);
        if ( (*v4)(v4, *(_DWORD *)(v8 + 24) >> 12, 1, 2) < 0 )
          (*v4)(v4, *(_DWORD *)(v8 + 32), 4, 0);
        --v5;
      }
      while ( v5 );
    }
    MmAddRangeToCrashDump(v4, dword_63389C, -dword_63389C);
    if ( (a3 & 1) != 0 && (KiBugCheckActive & 3) != 0 )
      MmAddRangeToCrashDump(v4, 0, MmUserProbeAddress);
    (*v4)(v4, ((unsigned int)__mrc(15, 0, 2, 0, 0) >> 12) & 0xFFFFC, 4, 2);
    if ( (a3 & 2) != 0 )
    {
      MiAddPhysicalPagesToCrashDump((int)v4);
      MmRemoveSystemCacheFromDump(v4);
    }
    result = MiRemoveFreePoolMemoryFromDump(v4);
  }
  v11 = dword_640088;
  if ( dword_640088 == 0xFFFFF )
  {
    v12 = MmPfnDatabase;
  }
  else
  {
    do
    {
      result = v4[1](v4, v11, 1, 2);
      v12 = MmPfnDatabase;
      v11 = *(_DWORD *)(MmPfnDatabase + 24 * v11);
    }
    while ( v11 != 0xFFFFF );
  }
  if ( byte_634428 == 1 )
  {
    v13 = v12;
    v14 = v12 + 24 * dword_640504;
    if ( v12 <= v14 )
    {
      do
      {
        if ( (*(_BYTE *)(v13 + 19) & 0x40) != 0 )
        {
          result = v4[1](v4, (int)(v13 - v12) / 24, 1, 2);
          v12 = MmPfnDatabase;
        }
        v13 += 24;
      }
      while ( v13 <= v14 );
    }
  }
  return result;
}

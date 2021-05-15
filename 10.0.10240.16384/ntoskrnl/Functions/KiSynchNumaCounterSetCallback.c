// KiSynchNumaCounterSetCallback 
 
int __fastcall KiSynchNumaCounterSetCallback(int a1, int a2)
{
  int v2; // r6
  int v3; // r3
  unsigned int v4; // r5
  unsigned int v5; // r2
  void **v6; // r10
  int v7; // t1
  unsigned int v8; // r9
  int v9; // r8
  unsigned int v10; // r2
  int v11; // r3
  int v12; // r4
  _DWORD *v13; // r1
  int result; // r0
  char v15[8]; // [sp+10h] [bp-1C0h] BYREF
  int v16; // [sp+18h] [bp-1B8h]
  int v17; // [sp+20h] [bp-1B0h]
  int v18; // [sp+24h] [bp-1ACh]
  _DWORD v19[46]; // [sp+28h] [bp-1A8h] BYREF
  _DWORD v20[46]; // [sp+E0h] [bp-F0h] BYREF
  unsigned __int16 v21[28]; // [sp+198h] [bp-38h] BYREF

  if ( !a1 )
  {
    EtwReferenceSpinLockCounters();
    return 0;
  }
  if ( a1 == 1 )
  {
    EtwDereferenceSpinLockCounters();
    return 0;
  }
  if ( a1 != 2 && a1 != 3 )
    return 0;
  v2 = *(_DWORD *)(a2 + 20);
  memset(v19, 0, sizeof(v19));
  v4 = 0;
  v5 = (unsigned __int16)KeNumberNodes;
  if ( KeNumberNodes )
  {
    v6 = &KeNodeBlock;
    do
    {
      v7 = (int)*v6++;
      v3 = v7;
      v8 = *(_DWORD *)(v7 + 260);
      if ( v8 )
      {
        memset(v20, 0, sizeof(v20));
        v9 = 0;
        while ( v8 )
        {
          v10 = __clz(__rbit(v8));
          v8 &= ~(1 << v10);
          v11 = (int)*(&KiProcessorBlock + v10);
          v16 = v10;
          v12 = v11 + 3712;
          KiAddSynchCounters(v20, (_DWORD *)(v11 + 3712));
          KiAddSynchCounters(v19, v13);
          RtlStringCbPrintfW(v21, 0x16u, (int)L"%u,%u", v4);
          RtlInitUnicodeString((unsigned int)v15, v21);
          v17 = v12;
          v18 = 184;
          result = PcwAddInstance(v2, (int)v15, v16, 1);
          if ( result < 0 )
            return result;
          ++v9;
        }
        RtlStringCbPrintfW(v21, 0x16u, (int)L"%u,_Total", v4);
        RtlInitUnicodeString((unsigned int)v15, v21);
        result = PcwAddInstance(v2, (int)v15, KeMaximumProcessors + v4, 1);
        if ( result < 0 )
          return result;
        v5 = (unsigned __int16)KeNumberNodes;
      }
      ++v4;
    }
    while ( v4 < v5 );
  }
  RtlStringCbPrintfW(v21, 0x16u, (int)L"_Total", v3);
  RtlInitUnicodeString((unsigned int)v15, v21);
  return PcwAddInstance(v2, (int)v15, (unsigned __int16)KeNumberNodes + KeMaximumProcessors, 1);
}

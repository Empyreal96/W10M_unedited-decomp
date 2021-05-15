// IopLiveDumpMarkRequiredDumpData 
 
int __fastcall IopLiveDumpMarkRequiredDumpData(int a1, int (__fastcall *a2)(_DWORD, unsigned int, int, int))
{
  int result; // r0
  unsigned int v4; // r5
  int v5; // r1
  unsigned int v6; // r5
  unsigned int v7; // r1
  int (__fastcall *v8[8])(_DWORD, unsigned int, int, int); // [sp+8h] [bp-20h] BYREF

  v8[2] = (int (__fastcall *)(_DWORD, unsigned int, int, int))(a1 + 220);
  v8[3] = a2;
  v8[0] = (int (__fastcall *)(_DWORD, unsigned int, int, int))IoSetDumpRange;
  v8[1] = 0;
  v8[4] = (int (__fastcall *)(_DWORD, unsigned int, int, int))1;
  result = MmAddRangeToCrashDump(v8, (unsigned int)&KdDebuggerDataBlock, 864);
  if ( result >= 0 )
  {
    result = MmAddRangeToCrashDump(v8, (unsigned int)&KiProcessorBlock, 4 * KeNumberProcessors_0);
    if ( result >= 0 )
    {
      result = IopLiveDumpMarkLoadedModuleList(v8);
      if ( result >= 0 )
      {
        v4 = dword_681D78[0];
        while ( v4 )
        {
          v5 = __clz(__rbit(v4));
          v4 &= ~(1 << v5);
          result = IopLiveDumpMarkProcessorData(v8, v5);
          if ( result < 0 )
            return result;
        }
        result = MmAddPrivateDataToCrashDump(v8, 2);
        if ( result >= 0 )
        {
          result = MmAddRangeToCrashDump(v8, 0xFFFF9000, 1800);
          if ( result >= 0 )
          {
            result = MmAddPrivateDataToCrashDump(v8, 4);
            if ( result >= 0 )
            {
              result = MmAddPrivateDataToCrashDump(v8, 8);
              if ( result >= 0 && *(_DWORD *)a1 == 351 && *(_DWORD *)(a1 + 4) == 2 )
              {
                v6 = *(_DWORD *)(a1 + 8);
                result = MmAddRangeToCrashDump(v8, v6, 32);
                if ( result >= 0 )
                {
                  result = IopLiveDumpMarkDeviceNode(v8, *(_DWORD *)(v6 + 28));
                  if ( result >= 0 )
                  {
                    v7 = *(_DWORD *)(a1 + 16);
                    if ( v7 )
                      result = IopLiveDumpMarkDeviceNode(v8, v7);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}

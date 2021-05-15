// IopLiveDumpMarkProcessorData 
 
int __fastcall IopLiveDumpMarkProcessorData(int (__fastcall **a1)(_DWORD, unsigned int, int, int), int a2)
{
  int v3; // r5
  int result; // r0

  v3 = (int)*(&KiProcessorBlock + a2);
  result = MmAddRangeToCrashDump(a1, v3 - 1408, 19968);
  if ( result >= 0 )
  {
    result = MmAddRangeToCrashDump(a1, *(_DWORD *)(v3 + 4), 1104);
    if ( result >= 0 )
    {
      result = MmAddRangeToCrashDump(a1, *(_DWORD *)(*(_DWORD *)(v3 + 4) + 116), 888);
      if ( result >= 0 )
      {
        result = MmAddRangeToCrashDump(a1, *(_DWORD *)(v3 + 1304), 416);
        if ( result >= 0 )
        {
          result = MmAddRangeToCrashDump(a1, *(_DWORD *)(*(_DWORD *)(v3 + 1304) + 56), 0x2000);
          if ( result >= 0 )
            result = MmAddRangeToCrashDump(a1, *(_DWORD *)(*(_DWORD *)(v3 + 1304) + 64) - 4096, 0x2000);
        }
      }
    }
  }
  return result;
}

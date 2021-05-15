// IopLiveDumpMarkLoadedModuleList 
 
int __fastcall IopLiveDumpMarkLoadedModuleList(int (__fastcall **a1)(_DWORD, unsigned int, int, int))
{
  int result; // r0
  unsigned int i; // r4

  result = MmAddRangeToCrashDump(a1, (unsigned int)&PsLoadedModuleList, 8);
  if ( result >= 0 )
  {
    for ( i = PsLoadedModuleList; (int *)i != &PsLoadedModuleList; i = *(_DWORD *)i )
    {
      result = MmAddRangeToCrashDump(a1, i, 92);
      if ( result < 0 )
        break;
      result = MmAddRangeToCrashDump(a1, *(_DWORD *)(i + 48), *(unsigned __int16 *)(i + 44));
      if ( result < 0 )
        break;
      result = MmAddRangeToCrashDump(a1, *(_DWORD *)(i + 40), *(unsigned __int16 *)(i + 36));
      if ( result < 0 )
        break;
      result = MmAddRangeToCrashDump(a1, *(_DWORD *)(i + 20), 32);
      if ( result < 0 )
        break;
      result = MmAddRangeToCrashDump(a1, *(_DWORD *)(i + 24), 4096);
      if ( result < 0 )
        break;
    }
  }
  return result;
}

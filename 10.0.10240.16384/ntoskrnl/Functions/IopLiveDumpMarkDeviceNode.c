// IopLiveDumpMarkDeviceNode 
 
int __fastcall IopLiveDumpMarkDeviceNode(int (__fastcall **a1)(_DWORD, unsigned int, int, int), unsigned int a2)
{
  int result; // r0

  result = MmAddRangeToCrashDump(a1, a2, 44);
  if ( result >= 0 )
  {
    result = MmAddRangeToCrashDump(a1, *(_DWORD *)(a2 + 24), *(unsigned __int16 *)(a2 + 20) + 2);
    if ( result >= 0 )
      result = MmAddRangeToCrashDump(a1, *(_DWORD *)(a2 + 32), *(unsigned __int16 *)(a2 + 28) + 2);
  }
  return result;
}

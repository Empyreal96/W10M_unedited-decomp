// MiReplaceWorkingSetEntryIfNecessary 
 
int __fastcall MiReplaceWorkingSetEntryIfNecessary(int a1, int a2)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 92);
  if ( a2 == 1 || (*(_BYTE *)(a1 + 112) & 0x40) != 0 && *(_DWORD *)(a1 + 52) >= *(_DWORD *)(a1 + 68) )
  {
    if ( *(_DWORD *)(result + 36) == 16 )
    {
      MiReplaceWorkingSetEntryLarge(a1, a2);
      result = MiSimpleAging(a1);
    }
    else
    {
      result = MiReplaceWorkingSetEntrySmall(a1, a2);
    }
  }
  return result;
}

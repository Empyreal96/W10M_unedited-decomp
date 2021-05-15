// MmNotifyProcessInSwapTrigger 
 
int __fastcall MmNotifyProcessInSwapTrigger(int result)
{
  if ( (*(_BYTE *)(result + 607) & 0xC0) == 128 && dword_634CA0 && *(_DWORD *)dword_634CA0 > 5u )
  {
    result = TlgKeywordOn(dword_634CA0, 8i64);
    if ( result )
      result = sub_50EDCC();
  }
  return result;
}

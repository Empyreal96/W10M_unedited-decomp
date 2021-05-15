// KeFreeInterrupt 
 
int __fastcall KeFreeInterrupt(_DWORD *a1)
{
  return RtlpInterlockedPushEntrySList((unsigned __int64 *)(a1[44] + 3368), a1);
}

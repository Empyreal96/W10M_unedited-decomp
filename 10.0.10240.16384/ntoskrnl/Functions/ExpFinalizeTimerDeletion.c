// ExpFinalizeTimerDeletion 
 
int __fastcall ExpFinalizeTimerDeletion(int a1)
{
  if ( bswap32(__ROR4__(KiWaitNever ^ *(_DWORD *)(a1 + 88), -(char)KiWaitNever) ^ a1) != KiWaitAlways )
    return sub_555A60();
  *(_BYTE *)(a1 + 96) = ~ExpTimerFreedCookie;
  return ExFreePoolWithTag(a1, 1834252357);
}

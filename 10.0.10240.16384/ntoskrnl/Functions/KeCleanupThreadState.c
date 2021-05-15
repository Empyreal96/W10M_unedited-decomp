// KeCleanupThreadState 
 
int __fastcall KeCleanupThreadState(int a1)
{
  int result; // r0

  result = KiAbCleanupThreadState();
  if ( *(_WORD *)(a1 + 808) )
    result = KeFlushQueuedDpcs();
  return result;
}

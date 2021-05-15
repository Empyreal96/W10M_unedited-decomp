// KiEntropyQueueDpc 
 
int __fastcall KiEntropyQueueDpc(int result)
{
  if ( KiEntropyTimingRoutine )
    result = KiInsertQueueDpc(result + 2684);
  return result;
}

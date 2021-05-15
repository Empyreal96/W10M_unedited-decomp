// PspJobCycleTimeNotificationDpcRoutine 
 
int __fastcall PspJobCycleTimeNotificationDpcRoutine(int a1, unsigned int a2)
{
  int result; // r0

  result = ObReferenceObjectSafeWithTag(a2);
  if ( result )
  {
    result = PspRequestDeferredJobNotification(a2, 0x20000);
    if ( !result )
      result = ObfDereferenceObjectWithTag(a2);
  }
  return result;
}

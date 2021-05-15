// VerifierExFreePoolWithTag 
 
unsigned int __fastcall VerifierExFreePoolWithTag(unsigned int a1, int a2)
{
  VfFreePoolNotification(a1, 0);
  VfIrpDatabaseCheckExFreePool(a1);
  if ( (MiFlags & 2) != 0 )
    return ExFreePoolWithTag(a1);
  ExFreePoolSanityChecks(a1);
  return pXdvExFreePoolWithTag(a1, a2);
}

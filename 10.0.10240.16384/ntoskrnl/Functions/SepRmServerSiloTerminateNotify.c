// SepRmServerSiloTerminateNotify 
 
int __fastcall SepRmServerSiloTerminateNotify(int a1, int *a2)
{
  int result; // r0

  if ( a2 )
    result = SepRmCleanupRmLsaState(a2);
  return result;
}

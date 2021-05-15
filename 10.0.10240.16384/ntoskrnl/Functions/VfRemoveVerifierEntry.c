// VfRemoveVerifierEntry 
 
int __fastcall VfRemoveVerifierEntry(int a1)
{
  int result; // r0

  if ( ViVerifierDriverAddedThunkListHead )
    result = VfSuspectDriversRemove(a1);
  else
    result = -1073741637;
  return result;
}

// SepRmCleanupRmLsaState 
 
int __fastcall SepRmCleanupRmLsaState(int *a1)
{
  int result; // r0

  if ( a1[1] )
  {
    ZwClose();
    a1[1] = 0;
  }
  if ( a1[3] )
  {
    ZwClose();
    a1[3] = 0;
  }
  result = *a1;
  if ( *a1 )
  {
    result = ZwClose();
    *a1 = 0;
  }
  return result;
}

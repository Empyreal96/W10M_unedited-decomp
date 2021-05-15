// MmValidateUserCallTarget 
 
int MmValidateUserCallTarget()
{
  unsigned int v0; // r2
  int result; // r0

  if ( MiIsProcessCfgEnabled() )
    result = MiValidateUserCallTarget(v0, (_DWORD *)0xC040214C);
  else
    result = 1;
  return result;
}

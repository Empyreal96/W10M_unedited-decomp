// VfQueryThreadContext 
 
int __fastcall VfQueryThreadContext(int a1, int a2)
{
  int v3; // r1
  int result; // r0

  if ( ViVerifierEnabled && ViIsContextIdValid(3, a2) )
    result = ViQueryObjectContext(a1, 3, v3);
  else
    result = 0;
  return result;
}

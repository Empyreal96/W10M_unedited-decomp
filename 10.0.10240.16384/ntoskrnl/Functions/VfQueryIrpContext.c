// VfQueryIrpContext 
 
int __fastcall VfQueryIrpContext(int a1, int a2)
{
  int v3; // r1
  int result; // r0

  if ( ViVerifierEnabled && ViIsContextIdValid(2, a2) )
    result = ViQueryObjectContext(a1, 2, v3);
  else
    result = 0;
  return result;
}

// ViCreateProcessCallback 
 
int __fastcall ViCreateProcessCallback(int a1, int a2)
{
  int result; // r0

  result = a2;
  if ( ViVerifierEnabled )
    result = sub_526A4C(a2);
  return result;
}

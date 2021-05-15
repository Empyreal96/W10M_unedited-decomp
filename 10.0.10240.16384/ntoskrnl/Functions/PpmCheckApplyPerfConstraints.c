// PpmCheckApplyPerfConstraints 
 
int __fastcall PpmCheckApplyPerfConstraints(int a1)
{
  int result; // r0

  if ( a1 )
    result = PpmCheckCustomRun(2);
  else
    result = PpmCheckCustomRun(1);
  return result;
}

// CmReleaseLoadKeyContext 
 
int __fastcall CmReleaseLoadKeyContext(int a1, int a2)
{
  int result; // r0

  if ( a2 < 0 )
    result = sub_7C2F40();
  else
    result = CmpDereferenceKeyControlBlock(a1);
  return result;
}

// ExpWnfValidatePubSubPreconditions 
 
int __fastcall ExpWnfValidatePubSubPreconditions(int a1, unsigned int *a2, unsigned int a3, int a4, int a5)
{
  int result; // r0
  unsigned int v9; // r0

  if ( a5 || (result = ExpWnfCheckCallerAccess(a2[2], a1), result >= 0) )
  {
    v9 = a2[1];
    if ( v9 )
    {
      result = sub_7C4640(v9, a1);
    }
    else if ( a3 > *a2 )
    {
      result = -1073741811;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

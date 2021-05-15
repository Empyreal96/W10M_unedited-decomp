// PopFxRequestCommon 
 
int __fastcall PopFxRequestCommon(int a1)
{
  int result; // r0

  if ( a1 == 1 )
    result = PopFxAcpiForwardRequestCommon(1);
  else
    result = -1073741637;
  return result;
}

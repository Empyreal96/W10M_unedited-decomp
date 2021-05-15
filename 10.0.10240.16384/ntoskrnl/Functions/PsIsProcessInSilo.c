// PsIsProcessInSilo 
 
int __fastcall PsIsProcessInSilo(int a1, int a2)
{
  int result; // r0

  if ( a2 )
    result = sub_52F460();
  else
    result = 1;
  return result;
}

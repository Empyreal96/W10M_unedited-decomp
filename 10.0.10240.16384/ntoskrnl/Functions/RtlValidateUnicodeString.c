// RtlValidateUnicodeString 
 
int __fastcall RtlValidateUnicodeString(int a1, int a2)
{
  int result; // r0

  if ( a1 )
    result = -1073741811;
  else
    result = sub_4DAE74(a2);
  return result;
}

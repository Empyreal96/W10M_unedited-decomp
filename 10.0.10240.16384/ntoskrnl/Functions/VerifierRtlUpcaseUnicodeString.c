// VerifierRtlUpcaseUnicodeString 
 
int __fastcall VerifierRtlUpcaseUnicodeString(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int var10[6]; // [sp+0h] [bp-10h] BYREF

  var10[1] = a4;
  result = pXdvRtlUpcaseUnicodeString(a1, a2);
  var10[0] = result;
  if ( result >= 0 )
  {
    if ( a3 )
    {
      ViRtlReplaceStringBuffer(a1, var10, var10[5]);
      result = var10[0];
    }
  }
  return result;
}

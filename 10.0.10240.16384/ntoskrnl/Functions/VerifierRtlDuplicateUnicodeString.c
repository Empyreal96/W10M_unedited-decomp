// VerifierRtlDuplicateUnicodeString 
 
int __fastcall VerifierRtlDuplicateUnicodeString(int a1, int a2, int a3)
{
  int result; // r0
  int var8[4]; // [sp+0h] [bp-8h] BYREF

  result = pXdvRtlDuplicateUnicodeString(a1);
  var8[0] = result;
  if ( result >= 0 )
  {
    ViRtlReplaceStringBuffer(a3, var8, var8[3]);
    result = var8[0];
  }
  return result;
}

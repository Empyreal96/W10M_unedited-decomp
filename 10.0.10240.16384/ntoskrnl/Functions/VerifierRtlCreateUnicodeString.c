// VerifierRtlCreateUnicodeString 
 
int __fastcall VerifierRtlCreateUnicodeString(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int var10[6]; // [sp+0h] [bp-10h] BYREF

  var10[0] = a3;
  var10[1] = a4;
  v5 = pXdvRtlCreateUnicodeString(a1, a2);
  if ( v5 )
  {
    var10[0] = 0;
    ViRtlReplaceStringBuffer(a1, var10, var10[5]);
    if ( var10[0] < 0 )
      v5 = 0;
  }
  return v5;
}

// GetHangulT 
 
int __fastcall GetHangulT(int a1)
{
  unsigned int v1; // r3
  __int16 v2; // r2
  int result; // r0

  v1 = (int)((unsigned __int64)(2454267027i64 * (a1 - 44032)) >> 32) >> 4;
  v2 = a1 + 21504 - 28 * (v1 + (v1 >> 31));
  if ( v2 )
    result = (unsigned __int16)(v2 + 4519);
  else
    result = 0;
  return result;
}

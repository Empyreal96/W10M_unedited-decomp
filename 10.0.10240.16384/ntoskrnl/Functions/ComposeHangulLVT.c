// ComposeHangulLVT 
 
int __fastcall ComposeHangulLVT(int a1, int a2)
{
  int v2; // r5
  int result; // r0

  v2 = a2 - 4519;
  if ( (unsigned int)(a2 - 4520) <= 0x1A && IsHangulLV(a1) )
    result = v2 + a1;
  else
    result = 0;
  return result;
}

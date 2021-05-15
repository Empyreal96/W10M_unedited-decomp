// ComposeHangulLV 
 
int __fastcall ComposeHangulLV(int a1, int a2)
{
  unsigned int v2; // r0
  int result; // r0

  v2 = a1 - 4352;
  if ( v2 > 0x12 || (unsigned int)(a2 - 4449) > 0x14 )
    result = 0;
  else
    result = 28 * (21 * v2 + a2 - 4449) + 44032;
  return result;
}

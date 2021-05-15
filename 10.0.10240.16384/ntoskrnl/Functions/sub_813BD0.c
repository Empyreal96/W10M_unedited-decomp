// sub_813BD0 
 
void sub_813BD0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  int v8; // r7
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  if ( BiGetAliasedIdentifier(v8, a5, (char *)va) < 0 )
    JUMPOUT(0x7A6592);
  JUMPOUT(0x7A656A);
}

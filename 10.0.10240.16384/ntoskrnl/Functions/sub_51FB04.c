// sub_51FB04 
 
void sub_51FB04(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r5
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( a1 == 3 )
  {
    if ( off_617B18(v4, (int *)va) < 0 )
      JUMPOUT(0x450F24);
    JUMPOUT(0x450F3E);
  }
  JUMPOUT(0x450F26);
}

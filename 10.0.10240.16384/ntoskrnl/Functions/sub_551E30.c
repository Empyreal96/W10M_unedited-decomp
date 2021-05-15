// sub_551E30 
 
void sub_551E30(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r5
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  SmFpCleanup((int)va);
  if ( v6 )
    ExFreePoolWithTag(v6);
  JUMPOUT(0x4F0544);
}

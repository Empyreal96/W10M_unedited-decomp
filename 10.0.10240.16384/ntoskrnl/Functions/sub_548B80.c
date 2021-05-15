// sub_548B80 
 
void sub_548B80(int a1, int a2, int a3, int a4, ...)
{
  unsigned int v4; // r4
  int v5; // r5
  unsigned int *v6; // r7
  unsigned int v7; // r5
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  v7 = v5 + a1;
  if ( v7 < v4 )
  {
    if ( RtlFindNextForwardRunClearCapped(v6, v7, 0xFFFFFFFF, (unsigned int *)va) )
      JUMPOUT(0x4C8EAE);
    JUMPOUT(0x4C8ECA);
  }
  JUMPOUT(0x4C8ECE);
}

// sub_7C93C4 
 
void sub_7C93C4(int a1, int a2, int a3, int a4, ...)
{
  unsigned int *v4; // r6
  unsigned int v5; // r2
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  KeDelayExecutionThread(0, 0, (unsigned int *)va);
  __dmb(0xBu);
  do
    v5 = __ldrex(v4);
  while ( __strex(1u, v4) );
  JUMPOUT(0x6CF078);
}

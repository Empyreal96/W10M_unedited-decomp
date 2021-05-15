// sub_975EF4 
 
void sub_975EF4(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r5
  int v7; // r8
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  if ( FioFwReadUlongAtOffset(*(_DWORD **)(v6 + 8), v7, (unsigned int *)va) < 0 )
    JUMPOUT(0x97554E);
  JUMPOUT(0x97550C);
}

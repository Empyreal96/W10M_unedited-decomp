// sub_806CDC 
 
void sub_806CDC(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  _DWORD *v6; // r8
  unsigned int v7; // r9
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  if ( a4 == 5 )
  {
    v6[11] = 1;
  }
  else if ( a4 > 10 && (a4 <= 13 || a4 == 16) && (a4 != 16 || v7 <= 1) && v6[8] > v6[9] )
  {
    KeDelayExecutionThread(0, 0, (unsigned int *)va);
    v6[9] += v6[7];
    if ( (v6[10] & 4) == 0 )
      JUMPOUT(0x7576C8);
  }
  JUMPOUT(0x75774A);
}

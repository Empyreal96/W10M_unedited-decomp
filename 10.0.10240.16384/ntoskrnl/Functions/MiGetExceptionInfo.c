// MiGetExceptionInfo 
 
int __fastcall MiGetExceptionInfo(int **a1, _DWORD *a2, _DWORD *a3)
{
  int *v3; // r0
  int v4; // r4

  *a2 = 0;
  v3 = *a1;
  v4 = *v3;
  if ( (*v3 == -1073741819 || v4 == -2147483647 || v4 == -1073741818) && (unsigned int)v3[4] > 1 )
  {
    *a2 = 1;
    *a3 = v3[6];
  }
  return 1;
}

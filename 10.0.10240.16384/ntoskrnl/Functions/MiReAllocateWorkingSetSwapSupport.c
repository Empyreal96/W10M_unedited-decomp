// MiReAllocateWorkingSetSwapSupport 
 
int *__fastcall MiReAllocateWorkingSetSwapSupport(int *a1)
{
  int *v2; // r0
  int *v3; // r4
  int v4; // r0

  v2 = (int *)MiAllocateWorkingSetSwapSupport(a1[2]);
  v3 = v2;
  if ( v2 )
  {
    v4 = *v2;
    v3[2] = a1[2];
    v3[3] = a1[3];
    memmove(v4, *a1, 8 * a1[2]);
  }
  return v3;
}

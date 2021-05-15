// PspUnlockJobsAndProcessExclusive 
 
int *__fastcall PspUnlockJobsAndProcessExclusive(int *result, int a2, int a3)
{
  int v3; // r6
  unsigned __int8 *v6; // r4
  int v7; // t1
  __int16 v8; // r3

  v3 = *result;
  if ( *result )
  {
    v6 = (unsigned __int8 *)&result[2 * v3];
    do
    {
      v7 = *v6;
      v6 -= 8;
      if ( v7 )
        result = (int *)PspUnlockJobChain(*((_DWORD *)v6 + 1), 0);
      else
        result = (int *)ExReleaseResourceLite(*((_DWORD *)v6 + 1) + 32);
      --v3;
    }
    while ( v3 );
  }
  if ( a2 )
    return (int *)sub_7C1B28();
  v8 = *(_WORD *)(a3 + 310) + 1;
  *(_WORD *)(a3 + 310) = v8;
  if ( !v8 && *(_DWORD *)(a3 + 100) != a3 + 100 )
    result = (int *)KiCheckForKernelApcDelivery((int)result);
  return result;
}

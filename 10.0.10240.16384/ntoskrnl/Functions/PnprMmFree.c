// PnprMmFree 
 
unsigned int __fastcall PnprMmFree(unsigned int *a1)
{
  unsigned int result; // r0
  __int64 v3; // r2

  while ( 1 )
  {
    result = *a1;
    if ( (unsigned int *)*a1 == a1 )
      break;
    v3 = *(_QWORD *)result;
    if ( *(unsigned int **)(result + 4) != a1 || *(_DWORD *)(v3 + 4) != result )
      __fastfail(3u);
    *a1 = v3;
    *(_DWORD *)(v3 + 4) = a1;
    ExFreePoolWithTag(result);
  }
  return result;
}

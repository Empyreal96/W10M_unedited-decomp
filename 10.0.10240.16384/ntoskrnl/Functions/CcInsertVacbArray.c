// CcInsertVacbArray 
 
int **__fastcall CcInsertVacbArray(_DWORD *a1)
{
  int **result; // r0
  unsigned int v2; // r1
  int *v3; // r2

  if ( (unsigned int)CcVacbArraysAllocated > 1 )
    KeBugCheckEx(52, 394, -1073740768);
  if ( *(_DWORD *)CcVacbArrays )
    return (int **)sub_50ED04(a1, CcVacbArrays + 4, 0);
  *(_DWORD *)CcVacbArrays = a1;
  *a1 = 0;
  v2 = 0;
  v3 = a1 + 6;
  do
  {
    if ( *(v3 - 2) )
    {
      result = (int **)dword_63259C;
      *v3 = (int)&CcVacbFreeHighPriorityList;
      v3[1] = (int)result;
      if ( *result != &CcVacbFreeHighPriorityList )
        __fastfail(3u);
      *result = v3;
      dword_63259C = (int)v3;
      ++CcNumberOfFreeHighPriorityVacbs;
    }
    else
    {
      result = (int **)dword_632594;
      *v3 = (int)&CcVacbFreeList;
      v3[1] = (int)result;
      if ( *result != &CcVacbFreeList )
        __fastfail(3u);
      *result = v3;
      dword_632594 = (int)v3;
      ++CcNumberOfFreeVacbs;
    }
    ++v2;
    v3 += 6;
  }
  while ( v2 < 0x1554 );
  return result;
}

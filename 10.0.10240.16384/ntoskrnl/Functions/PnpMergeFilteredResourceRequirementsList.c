// PnpMergeFilteredResourceRequirementsList 
 
int __fastcall PnpMergeFilteredResourceRequirementsList(int *a1, _DWORD *a2, _DWORD *a3)
{
  unsigned int *v4; // r5
  int v7; // r8
  int v8; // r0
  int *v9; // r6
  int v10; // r2
  int v11; // r3
  int v13; // r0
  int v14; // r4

  v4 = (unsigned int *)a1;
  *a3 = 0;
  if ( !a1 || !a1[7] )
    return sub_81973C();
  if ( a2 && a2[7] )
  {
    v7 = *a2 + *a1 - 32;
    v8 = ExAllocatePoolWithTag(1, v7, 1970499664);
    v9 = (int *)v8;
    if ( v8 )
    {
      memmove(v8, (int)v4, *v4);
      memmove((int)v9 + *v4, (int)(a2 + 8), v7 - *v4);
      v10 = v9[7];
      *v9 = v7;
      v11 = a2[7];
      *a3 = v9;
      v9[7] = v11 + v10;
      return 0;
    }
  }
  else
  {
    v13 = ExAllocatePoolWithTag(1, *a1, 1970499664);
    v14 = v13;
    if ( v13 )
    {
      memmove(v13, (int)a1, *a1);
      *a3 = v14;
      return 0;
    }
  }
  return -1073741670;
}

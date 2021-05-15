// EtwpUpdatePidFilterData 
 
int __fastcall EtwpUpdatePidFilterData(int a1, int *a2, int a3)
{
  int v3; // r4
  unsigned int v6; // r6
  unsigned int *v7; // r0

  v3 = 0;
  if ( a3 )
  {
    ExFreePoolWithTag(*(_DWORD *)(a1 + 4));
    *(_DWORD *)(a1 + 4) = 0;
  }
  else
  {
    v6 = (unsigned int)a2[2] >> 2;
    if ( v6 <= 8 )
    {
      v7 = *(unsigned int **)(a1 + 4);
      if ( !v7 )
      {
        v7 = (unsigned int *)ExAllocatePoolWithTag(1, 36, 1182233669);
        if ( !v7 )
          return -1073741801;
        *(_DWORD *)(a1 + 4) = v7;
      }
      *v7 = v6;
      memmove((int)(v7 + 1), *a2, 4 * v6);
      return v3;
    }
    v3 = -1073741811;
  }
  return v3;
}

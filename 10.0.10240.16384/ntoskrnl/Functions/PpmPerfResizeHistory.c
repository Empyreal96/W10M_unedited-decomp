// PpmPerfResizeHistory 
 
int __fastcall PpmPerfResizeHistory(int a1)
{
  int v2; // r7
  unsigned int v3; // r5
  unsigned int *v5; // r0
  unsigned int *v6; // r4

  v2 = 0;
  v3 = *((unsigned __int8 *)&PpmCurrentProfile[44 * dword_61EC0C + 14] + *(unsigned __int8 *)(a1 + 2986));
  if ( *(_DWORD *)(a1 + 3216) )
    return sub_81A854();
  if ( v3 > 1 )
  {
    v5 = (unsigned int *)ExAllocatePoolWithTag(512, 8 * v3 + 28, 1884115024);
    v6 = v5;
    if ( v5 )
    {
      memset(v5, 0, 8 * v3 + 28);
      *v6 = v3;
      *(_DWORD *)(a1 + 3216) = v6;
      PpmPerfResetHistory((_DWORD *)a1);
    }
    else
    {
      v2 = -1073741670;
    }
  }
  return v2;
}

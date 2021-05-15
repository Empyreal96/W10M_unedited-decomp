// IopAppendLegacyVeto 
 
int __fastcall IopAppendLegacyVeto(int a1, unsigned __int16 *a2)
{
  unsigned int v4; // r8
  int v5; // r0
  int v6; // r6
  int *v7; // r5
  int v8; // r1
  int *v9; // r3
  int result; // r0

  v4 = *(_DWORD *)(a1 + 4) + *a2 + 2;
  v5 = ExAllocatePoolWithTag(512, v4, 1869181008);
  v6 = v5;
  if ( v5 )
  {
    v7 = *(int **)a1;
    v8 = **(_DWORD **)a1;
    if ( v8 )
    {
      memmove(v5, v8, *(_DWORD *)(a1 + 4));
      ExFreePoolWithTag(*v7);
    }
    memmove(v6 + 2 * (*(_DWORD *)(a1 + 4) >> 1), *((_DWORD *)a2 + 1), *a2);
    *(_WORD *)(v6 + 2 * (v4 >> 1) - 2) = 0;
    v9 = *(int **)a1;
    *(_DWORD *)(a1 + 4) = v4;
    result = 1;
    *v9 = v6;
  }
  else
  {
    result = 0;
    **(_DWORD **)(a1 + 12) = -1073741670;
  }
  return result;
}

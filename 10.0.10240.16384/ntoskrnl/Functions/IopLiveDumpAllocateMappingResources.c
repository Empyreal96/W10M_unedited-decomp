// IopLiveDumpAllocateMappingResources 
 
int __fastcall IopLiveDumpAllocateMappingResources(int a1)
{
  unsigned int v2; // r6
  _BYTE *v3; // r0
  int v4; // r4
  int v6; // r7
  int *v7; // r8
  int v8; // r0
  int v9; // r0

  v2 = KeNumberProcessors_0;
  v3 = (_BYTE *)ExAllocatePoolWithTag(512, 8 * KeNumberProcessors_0, 1886217292);
  *(_DWORD *)(a1 + 312) = v3;
  if ( v3 )
  {
    memset(v3, 0, 8 * v2);
    v4 = 0;
    v6 = 0;
    *(_DWORD *)(a1 + 308) = v2;
    if ( !v2 )
      return v4;
    while ( 1 )
    {
      v7 = (int *)(*(_DWORD *)(a1 + 312) + 8 * v6);
      v8 = MmAllocateDumpHibernateResources(0x10000);
      *v7 = v8;
      if ( !v8 )
        break;
      v9 = IoAllocateMdl(v8, 0x10000, 0, 0, 0);
      v7[1] = v9;
      if ( !v9 )
        break;
      if ( ++v6 >= v2 )
        return v4;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 308) = 0;
  }
  v4 = -1073741670;
  IopLiveDumpFreeMappingResources(a1);
  return v4;
}

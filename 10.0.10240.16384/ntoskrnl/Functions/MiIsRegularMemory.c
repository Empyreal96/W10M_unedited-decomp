// MiIsRegularMemory 
 
int __fastcall MiIsRegularMemory(int a1, unsigned int a2)
{
  unsigned int v3; // r2
  _DWORD *v5; // r2
  _DWORD *v6; // r1
  unsigned int v7; // r0
  int v8; // r3

  if ( !MxLastMemoryDescriptorChecked
    || (v3 = *(_DWORD *)(MxLastMemoryDescriptorChecked + 12), a2 < v3)
    || a2 >= *(_DWORD *)(MxLastMemoryDescriptorChecked + 16) + v3 )
  {
    v5 = *(_DWORD **)(a1 + 24);
    v6 = (_DWORD *)(a1 + 24);
    while ( 1 )
    {
      if ( v5 == v6 )
        return 0;
      v7 = v5[3];
      if ( a2 < v7 )
        return 0;
      if ( a2 < v5[4] + v7 )
        break;
      v5 = (_DWORD *)*v5;
    }
    v8 = v5[2];
    if ( v8 == 31 || v8 == 30 || v8 == 32 || v8 == 6 || v8 == 23 || v8 == 3 || v8 == 22 )
      return 0;
    MxLastMemoryDescriptorChecked = (int)v5;
  }
  return 1;
}

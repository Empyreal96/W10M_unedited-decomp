// MiRevertRelocatedImagePfn 
 
int __fastcall MiRevertRelocatedImagePfn(int a1, int a2, unsigned int a3)
{
  _DWORD *v6; // r5
  int v7; // r2
  int v8; // r0
  int v9; // r4

  v6 = **(_DWORD ***)(a2 + 56);
  if ( !v6 || a3 >= v6[6] )
    return -1;
  v7 = *(_DWORD *)(*v6 + 4 * a3) ? 5 : 1;
  if ( v7 != 5 )
    return -1;
  v8 = ExAllocatePoolWithTag(1, 4096, 1749642573);
  v9 = v8;
  if ( !v8 )
    return 0;
  memmove(v8, a1, 0x1000u);
  MiPerformFixups(v9, a2, a3, -v6[5], 0, 0);
  return v9;
}

// VfAllocateDomainCommonBuffer 
 
int __fastcall VfAllocateDomainCommonBuffer(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, int a9)
{
  int v13; // r5
  int v14; // r4
  int (__fastcall *v15)(int, int, int, int, int, int, int, _DWORD *, int); // r0

  v13 = ExAllocatePoolWithTag(512, 16);
  if ( !v13 )
    return -1073741670;
  v15 = (int (__fastcall *)(int, int, int, int, int, int, int, _DWORD *, int))ViGetRealDmaOperation(a1, 116);
  v14 = v15(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( v14 < 0 )
  {
    ExFreePoolWithTag(v13);
  }
  else
  {
    *(_DWORD *)(v13 + 8) = *a8;
    *(_DWORD *)(v13 + 12) = a8[1];
    ViHalTrackDomainCommonBuffer(v13);
  }
  return v14;
}

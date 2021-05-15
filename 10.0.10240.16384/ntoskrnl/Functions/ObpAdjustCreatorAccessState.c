// ObpAdjustCreatorAccessState 
 
int __fastcall ObpAdjustCreatorAccessState(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v9; // r2
  int v10; // r4

  v5 = a1[4];
  if ( (v5 & 0x2000000) != 0 )
    a1[4] = v5 & 0xFDFFFFFF | 0x10000000;
  if ( (a1[4] & 0xF0000000) != 0 )
    RtlMapGenericMask(a1 + 4, a3 + 52);
  if ( (a1[4] & 0x1000000) != 0 )
    return sub_7E5A94();
  v9 = a1[5] | a1[4];
  a1[4] = 0;
  a1[5] = v9;
  a1[5] = (*(_DWORD *)(a3 + 68) | 0x1000000) & v9;
  v10 = ObpReferenceSecurityDescriptor(a4 - 24);
  a1[5] &= ~SeComputeCreatorDeniedRights(a1 + 7, (int)a1, a1[5], v10);
  if ( v10 )
    ObDereferenceSecurityDescriptor(v10, 1);
  return 0;
}

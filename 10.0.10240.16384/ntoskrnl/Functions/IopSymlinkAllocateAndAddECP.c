// IopSymlinkAllocateAndAddECP 
 
int __fastcall IopSymlinkAllocateAndAddECP(int a1, _DWORD *a2, int a3, int a4)
{
  int v5; // r4
  int v7; // r3
  int result; // r0
  int v9; // r0
  int v10[8]; // [sp+8h] [bp-20h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v5 = 0;
  *a2 = 0;
  v7 = *(_DWORD *)(a1 + 8);
  v10[0] = 0;
  if ( (v7 & 0x80) != 0 )
  {
    v5 = *(_DWORD *)(a1 + 60);
    v10[0] = v5;
  }
  if ( FsRtlAllocateExtraCreateParameterFromLookasideList(
         IopSymlinkECPGuid,
         a3 + 20,
         0,
         IopSymlinkCleanupECP,
         &IopSymlinkInfoLookasideList,
         a2) < 0 )
    return sub_7DD654();
  if ( !v5 )
  {
    v9 = FsRtlAllocateExtraCreateParameterList(0, v10);
    v5 = v10[0];
    if ( v9 < 0 )
      return sub_7DD654();
    IoSetIrpExtraCreateParameter(a1, v10[0]);
  }
  result = FsRtlInsertExtraCreateParameter(v5, *a2);
  if ( result < 0 )
    return sub_7DD654();
  return result;
}

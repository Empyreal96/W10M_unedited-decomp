// IopSymlinkPropagateToExtensionIfNeeded 
 
int __fastcall IopSymlinkPropagateToExtensionIfNeeded(int a1, int a2, unsigned __int16 *a3)
{
  _WORD *v3; // r4
  int v6; // r0
  int v7; // r5
  int v9; // r0
  int v10; // r8
  int v11[6]; // [sp+18h] [bp-18h] BYREF

  v3 = 0;
  v11[0] = 0;
  if ( !a2 || (IopSymlinkRemoveECP(a2, (int)v11), (v3 = (_WORD *)v11[0]) == 0) )
  {
    v6 = *(_DWORD *)(a1 + 32);
    if ( v6 )
    {
      v9 = IopGetFileObjectExtension(v6, 5, 0);
      v10 = v9;
      if ( v9 )
      {
        v7 = FsRtlAllocateExtraCreateParameterFromLookasideList(
               IopSymlinkECPGuid,
               (unsigned __int16)(*(_WORD *)(v9 + 12) + *a3 + 2) + 20,
               0,
               (int)IopSymlinkCleanupECP,
               (int)&IopSymlinkInfoLookasideList,
               v11);
        if ( v7 < 0 )
        {
          v3 = (_WORD *)v11[0];
          goto LABEL_5;
        }
        v3 = (_WORD *)v11[0];
        IopSymlinkInitializeSymlinkInfo(
          v11[0],
          *a3 + *(_WORD *)(v10 + 12) + 22,
          *((_DWORD *)a3 + 1),
          *a3,
          0,
          *(_DWORD *)(v10 + 16),
          *(_WORD *)(v10 + 12),
          *(_WORD *)(v10 + 4),
          *(_WORD *)(v10 + 2),
          0);
        *v3 = *(_WORD *)v10 - *(_WORD *)(v10 + 12) + v3[6];
        goto LABEL_9;
      }
    }
LABEL_4:
    v7 = 0;
    goto LABEL_5;
  }
  if ( (*(_WORD *)(v11[0] + 2) & 1) == 0 )
    goto LABEL_4;
LABEL_9:
  v7 = IopSymlinkSetFoExtension(a1, (unsigned int)v3);
  if ( v7 >= 0 )
  {
    IopSymlinkFreeRelatedMountPointChain(v3);
    return v7;
  }
LABEL_5:
  if ( v3 )
  {
    IopSymlinkFreeRelatedMountPointChain(v3);
    FsRtlFreeExtraCreateParameter(v3);
  }
  return v7;
}

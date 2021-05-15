// PnpRestoreResourcesInternal 
 
int __fastcall PnpRestoreResourcesInternal(int a1)
{
  int *v1; // r1
  int v3; // r5
  int v4; // r4
  int v5; // r4
  int *v6; // r4
  _DWORD *v8[2]; // [sp+0h] [bp-40h] BYREF
  int v9[10]; // [sp+8h] [bp-38h] BYREF
  char v10[16]; // [sp+30h] [bp-10h] BYREF

  v1 = *(int **)(a1 + 284);
  if ( !v1 )
    return 0;
  v4 = PnpCmResourcesToIoResources(a1, v1, 0);
  if ( !v4 )
    return -1073741670;
  memset(v9, 0, sizeof(v9));
  v9[0] = *(_DWORD *)(a1 + 16);
  v9[2] = 4;
  v9[5] = v4;
  v3 = IopResourceRequirementsListToReqList(v9, (unsigned int *)&v9[6]);
  if ( v3 >= 0 && (v5 = v9[6]) != 0 )
  {
    IopRearrangeReqList(v9[6]);
    if ( *(_DWORD *)(v5 + 16) )
    {
      v3 = PnpFindBestConfiguration((int)v9, 1, (int)v8);
      PnpFreeResourceRequirementsForAssignTable((unsigned int)v9, (unsigned int)v10);
      if ( v3 >= 0 )
        v3 = IopCommitConfiguration(v8);
      if ( v9[7] )
        ExFreePoolWithTag(v9[7]);
      if ( v9[8] )
        ExFreePoolWithTag(v9[8]);
      v6 = *(int **)(a1 + 284);
      PnpDetermineResourceListSize(v6);
      IopWriteAllocatedResourcesToRegistry(a1, (int)v6);
    }
    else
    {
      PnpFreeResourceRequirementsForAssignTable((unsigned int)v9, (unsigned int)v10);
      v3 = -1073741438;
    }
  }
  else
  {
    ExFreePoolWithTag(v9[5]);
  }
  return v3;
}

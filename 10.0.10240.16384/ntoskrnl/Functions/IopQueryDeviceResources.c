// IopQueryDeviceResources 
 
int __fastcall IopQueryDeviceResources(int a1, int a2, int *a3, unsigned int *a4)
{
  int *v8; // r9
  int v9; // r0
  int *v10; // r3
  int v11; // r5
  unsigned int *v12; // r4
  int v14; // r4
  int v15; // r1
  int v16; // r0
  int v17; // r0
  unsigned int v18; // r8
  unsigned int v19; // r8
  int v20[2]; // [sp+10h] [bp-58h] BYREF
  int v21[2]; // [sp+18h] [bp-50h] BYREF
  char v22[72]; // [sp+20h] [bp-48h] BYREF

  *a3 = 0;
  *a4 = 0;
  memset(v22, 0, 40);
  v8 = *(int **)(*(_DWORD *)(a1 + 176) + 20);
  if ( !a2 )
  {
    if ( (v8[67] & 1) == 0 )
    {
      v22[1] = 10;
      v22[0] = 27;
      v11 = IopSynchronousCall(a1, (int)v22, -1073741637, 0, a3);
      if ( v11 == -1073741637 )
      {
        *a3 = 0;
        v11 = 0;
      }
      if ( v11 >= 0 )
        *a4 = PnpDetermineResourceListSize(*a3);
      return v11;
    }
    v11 = PnpGetDeviceResourcesFromRegistry(a1, 0, 7, a3, a4);
    if ( v11 == -1073741772 )
      return 0;
    return v11;
  }
  v9 = PnpGetDeviceResourcesFromRegistry(a1, 0, 2, a3, v21);
  if ( v9 != -1073741772 )
  {
    if ( *a3 )
    {
      v12 = (unsigned int *)PnpCmResourcesToIoResources(v9, *a3, 0);
      ExFreePoolWithTag(*a3);
      if ( !v12 )
      {
        *a3 = 0;
        *a4 = 0;
        return -1073741670;
      }
      *a3 = (int)v12;
      *a4 = *v12;
    }
    else
    {
      v12 = 0;
    }
LABEL_10:
    if ( IopFilterResourceRequirementsCall(a1, v12, v21) < 0 )
    {
      *a3 = (int)v12;
      if ( v12 )
        *a4 = *v12;
      else
        *a4 = 0;
      return 0;
    }
    v14 = v21[0];
    if ( !v21[0] )
    {
      *a4 = 0;
      *a3 = 0;
LABEL_23:
      if ( CmOpenDeviceRegKey(PiPnpRtlCtx, v8[6], 19, 0, 131097, 1u, (int)v21, 0) >= 0 )
      {
        v20[0] = 2752552;
        v20[1] = (int)L"FilteredConfigVector";
        ZwSetValueKey();
        ZwClose();
      }
      return 0;
    }
    v15 = *(_DWORD *)v21[0];
    *a4 = *(_DWORD *)v21[0];
    v16 = ExAllocatePoolWithTag(1, v15, 538996816);
    *a3 = v16;
    if ( v16 )
    {
      memmove(v16, v14, *a4);
      ExFreePoolWithTag(v14);
      goto LABEL_23;
    }
    ExFreePoolWithTag(v14);
    return -1073741670;
  }
  if ( PnpGetDeviceResourcesFromRegistry(a1, 1, 1, v20, v21) != -1073741772 )
  {
    v12 = (unsigned int *)v20[0];
    goto LABEL_9;
  }
  if ( (v8[67] & 1) != 0 )
  {
    v11 = PnpGetDeviceResourcesFromRegistry(a1, 1, 2, v20, v21);
    if ( v11 == -1073741772 )
    {
      v11 = 0;
      v12 = 0;
      goto LABEL_8;
    }
LABEL_52:
    v12 = (unsigned int *)v20[0];
LABEL_8:
    if ( v11 >= 0 )
    {
LABEL_9:
      if ( PnpGetDeviceResourcesFromRegistry(a1, 0, 4, v20, v21) >= 0 )
      {
        v18 = v20[0];
        if ( !v20[0] || !*(_DWORD *)v20[0] || *(_DWORD *)(v20[0] + 4) != 5 )
        {
          v11 = PnpFilterResourceRequirementsList(v12, v20[0], v21, v20);
          if ( v18 )
            ExFreePoolWithTag(v18);
          if ( v11 < 0 )
          {
            if ( v12 )
              ExFreePoolWithTag((unsigned int)v12);
            return v11;
          }
          if ( (v8[67] & 1) != 0 || v20[0] && v12[7] <= 1 )
          {
            if ( v12 )
              ExFreePoolWithTag((unsigned int)v12);
            v12 = (unsigned int *)v21[0];
          }
          else
          {
            v19 = v21[0];
            v11 = PnpMergeFilteredResourceRequirementsList(v21[0], v12, v20);
            if ( v12 )
              ExFreePoolWithTag((unsigned int)v12);
            if ( v19 )
              ExFreePoolWithTag(v19);
            if ( v11 < 0 )
              return v11;
            v12 = (unsigned int *)v20[0];
          }
        }
      }
      goto LABEL_10;
    }
    return v11;
  }
  v10 = (int *)v8[74];
  if ( !v10 )
  {
    v11 = PpIrpQueryResourceRequirements(a1, v20);
    if ( v11 == -1073741637 )
    {
      v12 = 0;
      v11 = 0;
      goto LABEL_8;
    }
    goto LABEL_52;
  }
  v17 = ExAllocatePoolWithTag(1, *v10, 538996816);
  v12 = (unsigned int *)v17;
  if ( v17 )
  {
    memmove(v17, v8[74], *(_DWORD *)v8[74]);
    goto LABEL_9;
  }
  return sub_7E1340();
}

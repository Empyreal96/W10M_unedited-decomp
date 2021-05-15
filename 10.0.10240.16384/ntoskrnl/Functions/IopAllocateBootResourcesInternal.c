// IopAllocateBootResourcesInternal 
 
int __fastcall IopAllocateBootResourcesInternal(int a1, int a2, int a3)
{
  _BYTE *v6; // r0
  int v7; // r4
  unsigned int v8; // r6
  int v9; // r5
  unsigned int v10; // r0
  int result; // r0
  int v12[16]; // [sp+0h] [bp-40h] BYREF

  v6 = memset(v12, 0, 40);
  if ( a2 )
    v7 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 20);
  else
    v7 = 0;
  v8 = PnpCmResourcesToIoResources(v6, a3, 1);
  if ( v8 )
  {
    v12[2] = a1;
    v12[5] = v8;
    v12[0] = a2;
    v9 = IopResourceRequirementsListToReqList(v12, &v12[6]);
    if ( v9 >= 0 )
    {
      if ( !v12[6] )
        goto LABEL_15;
      v9 = IopBootAllocation();
      if ( v9 >= 0 )
      {
        PipSetDevNodeFlags(v7, 128);
        PnpBuildCmResourceList(v12, 0);
        v9 = v12[9];
        if ( v12[9] >= 0 )
        {
          if ( *(_DWORD *)(v7 + 360) )
          {
            if ( v12[7] )
            {
              ExFreePoolWithTag(v12[7]);
              v12[7] = 0;
            }
          }
          else
          {
            *(_DWORD *)(v7 + 360) = v12[7];
          }
          v10 = *(_DWORD *)(v7 + 364);
          if ( v10 )
          {
            ExFreePoolWithTag(v10);
            *(_DWORD *)(v7 + 364) = 0;
          }
          v9 = 0;
          *(_DWORD *)(v7 + 364) = v12[8];
        }
      }
    }
  }
  else
  {
    v9 = -1073741823;
  }
  if ( v12[6] )
    IopFreeReqList(v12[6]);
LABEL_15:
  if ( v8 )
    ExFreePoolWithTag(v8);
  if ( v9 >= 0 )
    result = v9;
  else
    result = sub_80DD44();
  return result;
}

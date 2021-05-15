// PnpReallocateResources 
 
int __fastcall PnpReallocateResources(_DWORD *a1)
{
  unsigned int v2; // r2
  int v3; // r7
  int v4; // r0
  int v5; // r8
  int v6; // r5
  int v7; // r2
  int result; // r0
  unsigned int v9; // r1
  __int16 v10; // r3
  int v11; // [sp+8h] [bp-50h] BYREF
  _DWORD *v12[2]; // [sp+10h] [bp-48h] BYREF
  int v13[10]; // [sp+18h] [bp-40h] BYREF
  char v14[24]; // [sp+40h] [bp-18h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  KeWaitForSingleObject((unsigned int)&PpRegistrySemaphore, 4, 0, 0, 0);
  v3 = a1[67];
  if ( (v3 & 0x400) == 0 )
    goto LABEL_17;
  PipClearDevNodeFlags((int)a1, 256);
  if ( (a1[67] & 0x800) != 0 )
  {
    memset(v13, 0, sizeof(v13));
    v13[0] = a1[4];
    v13[5] = 0;
    v13[2] = 4;
    v13[1] |= 0x280u;
    v4 = PnpGetResourceRequirementsForAssignTable((unsigned int)v13, (unsigned int)v14, &v11);
    v5 = v11;
    v6 = v4;
    if ( !v11 )
      goto LABEL_15;
    if ( a1[71] )
      PnpReleaseResourcesInternal(a1);
    v6 = PnpFindBestConfiguration((int)v13, v5, (int)v12);
    if ( v6 < 0 || (v6 = IopCommitConfiguration(v12), v6 < 0) )
    {
      if ( PnpRestoreResourcesInternal(a1) < 0 )
      {
        v7 = 14;
        goto LABEL_12;
      }
    }
    else
    {
      PipClearDevNodeFlags((int)a1, 3072);
      PnpBuildCmResourceLists((int)v13, (unsigned int)v14, 1);
      v6 = PnpStartDeviceNode((int)a1, 1, 1);
      if ( v6 < 0 )
      {
        v7 = 12;
LABEL_12:
        PnpRequestDeviceRemoval((int)a1, 0, v7);
        goto LABEL_13;
      }
    }
LABEL_13:
    PnpFreeResourceRequirementsForAssignTable((unsigned int)v13, (unsigned int)v14);
    goto LABEL_15;
  }
  v6 = PnpRebalance((int)a1, 0, 0, 0);
LABEL_15:
  if ( v6 < 0 )
  {
    PipClearDevNodeFlags((int)a1, 256);
    PipSetDevNodeFlags((int)a1, v3 & 0x100);
  }
LABEL_17:
  result = KeReleaseSemaphore((int)&PpRegistrySemaphore, 0, 1);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}

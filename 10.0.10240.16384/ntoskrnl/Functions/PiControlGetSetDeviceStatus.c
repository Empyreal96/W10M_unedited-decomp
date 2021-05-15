// PiControlGetSetDeviceStatus 
 
int __fastcall PiControlGetSetDeviceStatus(int a1, unsigned __int16 *a2, unsigned int a3, char a4)
{
  _DWORD *v4; // r6
  unsigned int v6; // r2
  int v7; // r5
  int v8; // r7
  unsigned int v9; // r9
  int v10; // r1
  int v11; // r4
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int *v15; // r8
  BOOL v17; // r5
  int v18; // r3
  int v19; // r0
  int *v20; // r2
  char *v21; // r3
  int v22[2]; // [sp+8h] [bp-40h] BYREF
  __int16 v23[2]; // [sp+10h] [bp-38h] BYREF
  int v24; // [sp+14h] [bp-34h] BYREF
  char v25[48]; // [sp+18h] [bp-30h] BYREF

  v4 = a2;
  v6 = *a2;
  v7 = a4;
  v8 = 0;
  v23[1] = v6;
  v23[0] = v6;
  v22[0] = 0;
  v9 = 0;
  if ( !v6 || v6 > 0x190 || (v6 & 1) != 0 )
    return -1073741811;
  v11 = PiControlMakeUserModeCallersCopy(&v24, *((_DWORD *)a2 + 1), v6, 2, a4, 1);
  if ( v11 >= 0 )
  {
    PpDevNodeLockTree(0, v10);
    v12 = PnpDeviceObjectFromDeviceInstance((int)v23);
    v15 = (int *)v12;
    if ( v7 )
      return sub_7C6C58();
    if ( v12 )
      v8 = *(_DWORD *)(*(_DWORD *)(v12 + 176) + 20);
    PpDevNodeUnlockTree(0, v13, v14);
    if ( v8 )
    {
      if ( v8 == IopRootDeviceNode && v4[2] )
      {
        v11 = -1073741790;
      }
      else
      {
        v17 = (v4[5] & 1) == 0;
        v18 = v4[2];
        if ( v18 )
        {
          if ( v18 == 2 )
          {
            KeInitializeEvent((int)v25, 0, 0);
            v11 = PnpRequestDeviceAction(v15, 1, 0, 0, (int)v25, (int)v22);
          }
          else
          {
            if ( v18 != 1 )
            {
              v11 = -1073741808;
              goto LABEL_13;
            }
            if ( (v4[5] & 1) != 0 )
            {
              v19 = ExAllocatePoolWithTag(1, a3, 1433431632);
              v9 = v19;
              if ( !v19 )
              {
                v11 = -1073741670;
                goto LABEL_13;
              }
              memmove(v19, (int)v4, a3);
            }
            else
            {
              KeInitializeEvent((int)v25, 0, 0);
            }
            if ( v17 )
              v20 = v22;
            else
              v20 = 0;
            if ( v17 )
              v21 = v25;
            else
              v21 = 0;
            if ( !v17 )
              v4 = (_DWORD *)v9;
            v11 = PnpRequestDeviceAction(v15, 15, 0, (int)v4, (int)v21, (int)v20);
            if ( !v17 )
              goto LABEL_13;
          }
          if ( v11 >= 0 )
          {
            v11 = KeWaitForSingleObject((unsigned int)v25, 0, 0, 0, 0);
            if ( !v11 )
              v11 = v22[0];
          }
          goto LABEL_13;
        }
        PiControlGetUserFlagsFromDeviceNode(v8, v4 + 3);
        v11 = 0;
        v4[4] = *(_DWORD *)(v8 + 276);
        v4[6] = *(_DWORD *)(v8 + 280);
      }
    }
    else
    {
      v11 = -1073741810;
    }
LABEL_13:
    if ( v15 )
      ObfDereferenceObject((int)v15);
    if ( v11 < 0 )
    {
      if ( v9 )
        ExFreePoolWithTag(v9);
    }
  }
  return v11;
}

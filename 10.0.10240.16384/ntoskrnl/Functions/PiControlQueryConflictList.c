// PiControlQueryConflictList 
 
int __fastcall PiControlQueryConflictList(int a1, _DWORD *a2, int a3, char a4)
{
  int v5; // r7
  _DWORD *v6; // r1
  unsigned int v7; // r4
  unsigned int v8; // r3
  unsigned int v9; // r6
  int v10; // r8
  int v11; // r4
  unsigned int v12; // r9
  int v13; // r4
  _BYTE *v14; // r0
  int v15; // r1
  int v16; // r0
  int v17; // r2
  int v18; // r2
  int v19; // r0
  unsigned int v21; // [sp+8h] [bp-30h] BYREF
  __int16 v22[2]; // [sp+10h] [bp-28h] BYREF
  unsigned int v23[9]; // [sp+14h] [bp-24h] BYREF

  v5 = a4;
  if ( !a2[4] || a2[5] < 0x20u )
    return -1073741789;
  v6 = (_DWORD *)a2[2];
  if ( !v6 )
    return -1073741811;
  v7 = a2[3];
  if ( v7 < 0x24 )
    return -1073741811;
  if ( *v6 != 1 )
    return -1073741811;
  if ( v6[4] != 1 )
    return -1073741811;
  v8 = *(unsigned __int16 *)a2;
  v22[1] = v8;
  v22[0] = v8;
  if ( !v8 || v8 > 0x190 || (v8 & 1) != 0 )
    return -1073741811;
  v21 = 0;
  v23[0] = 0;
  v9 = 0;
  v10 = 0;
  v11 = PiControlMakeUserModeCallersCopy((int *)&v21, (int)v6, v7, 1, v5, 1);
  v12 = v21;
  if ( v11 >= 0 )
  {
    v13 = a2[5];
    if ( !v13 )
      goto LABEL_17;
    if ( !v5 )
    {
      v9 = a2[4];
      goto LABEL_17;
    }
    v14 = (_BYTE *)ExAllocatePoolWithQuotaTag(9u, a2[5], 538996816);
    v9 = (unsigned int)v14;
    if ( v14 )
    {
      memset(v14, 0, v13);
LABEL_17:
      v11 = PiControlMakeUserModeCallersCopy((int *)v23, a2[1], *(unsigned __int16 *)a2, 2, v5, 1);
      if ( v11 >= 0 )
      {
        v11 = -1073741810;
        PpDevNodeLockTree(1, v15);
        v16 = PnpDeviceObjectFromDeviceInstance((int)v22);
        v10 = v16;
        if ( v16 )
        {
          v17 = *(_DWORD *)(*(_DWORD *)(v16 + 176) + 20);
          if ( v17 )
          {
            if ( v17 != IopRootDeviceNode )
            {
              v18 = *(_DWORD *)(v17 + 172);
              if ( v18 != 787 && v18 != 788 )
              {
                v11 = IopQueryConflictList(v16, v12, v18, v9, a2[5]);
                v19 = PiControlMakeUserModeCallersCopy(a2 + 4, v9, a2[5], 1, v5, 0);
                if ( v19 < 0 )
                  v11 = v19;
              }
            }
          }
        }
        PpDevNodeUnlockTree(1);
      }
      goto LABEL_26;
    }
    v11 = -1073741670;
  }
LABEL_26:
  if ( v5 )
  {
    if ( v12 )
      ExFreePoolWithTag(v12);
    if ( v9 )
      ExFreePoolWithTag(v9);
    if ( v23[0] )
      ExFreePoolWithTag(v23[0]);
  }
  if ( v10 )
    ObfDereferenceObject(v10);
  a2[7] = v11;
  return v11;
}

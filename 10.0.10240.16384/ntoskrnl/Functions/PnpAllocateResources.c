// PnpAllocateResources 
 
int __fastcall PnpAllocateResources(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // r10
  unsigned int v5; // r6
  unsigned int v7; // r5
  _DWORD *v8; // r5
  int v9; // r7
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  int v14; // r1
  int v15; // r9
  _DWORD *v16; // r2
  int v17; // r3
  _DWORD *v18; // r2
  unsigned int v19; // r4
  int v20; // r3
  int v21; // r3
  unsigned int v22; // r7
  _DWORD *v23; // r4
  int v24; // r9
  int v25; // r0
  unsigned int v26; // r3
  unsigned int v27; // r2
  unsigned int i; // r4
  unsigned int v29; // r2
  int v30; // r3
  int v31; // [sp+8h] [bp-60h] BYREF
  int v32; // [sp+Ch] [bp-5Ch]
  _DWORD *v33; // [sp+10h] [bp-58h]
  int v34; // [sp+14h] [bp-54h]
  char v35[8]; // [sp+18h] [bp-50h] BYREF
  char v36[72]; // [sp+20h] [bp-48h] BYREF

  v4 = a3;
  v32 = a3;
  v33 = a4;
  v5 = a2;
  v34 = a2;
  if ( a4 )
    *a4 = 0;
  if ( !a3 )
  {
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 308);
    KeWaitForSingleObject((unsigned int)&PpRegistrySemaphore, 4, 0, 0, 0);
  }
  v8 = (_DWORD *)(v5 + 40 * a1);
  v31 = a1;
  v9 = PnpGetResourceRequirementsForAssignTable(v5, v8, &v31);
  if ( v9 < 0 )
    goto LABEL_6;
  v14 = 0;
  v15 = 1;
  if ( !IopBootConfigsReserved )
  {
    v29 = v5;
    if ( v5 < (unsigned int)v8 )
    {
      while ( *(int *)(v29 + 36) < 0 || *(_DWORD *)(v29 + 20) )
      {
        v29 += 40;
        if ( v29 >= (unsigned int)v8 )
          goto LABEL_68;
      }
      v14 = 1;
    }
LABEL_68:
    if ( (_DWORD *)v29 != v8 )
      return sub_7E10E8();
    if ( v14 )
      goto LABEL_48;
  }
  v16 = (_DWORD *)v5;
  if ( v5 < (unsigned int)v8 )
  {
    while ( 1 )
    {
      v17 = *v16 ? *(_DWORD *)(*(_DWORD *)(*v16 + 176) + 20) : 0;
      if ( (*(_DWORD *)(v17 + 268) & 0x40) != 0 && v16[5] )
        break;
      v16 += 10;
      if ( v16 >= v8 )
        goto LABEL_19;
    }
    v15 = 0;
  }
LABEL_19:
  if ( v16 == v8 || (v18 = (_DWORD *)v5, v5 >= (unsigned int)v8) )
  {
    v19 = v31;
  }
  else
  {
    v19 = v31;
    do
    {
      if ( *v18 )
        v20 = *(_DWORD *)(*(_DWORD *)(*v18 + 176) + 20);
      else
        v20 = 0;
      if ( (*(_DWORD *)(v20 + 268) & 0x40) == 0 || !v18[5] )
      {
        v21 = v18[1];
        if ( (v21 & 0x20) == 0 )
        {
          v18[1] = v21 | 0x20;
          v18[9] = -1073741267;
          --v19;
        }
      }
      v18 += 10;
    }
    while ( v18 < v8 );
  }
  if ( !v19 )
  {
    v9 = -1073741823;
    goto LABEL_48;
  }
  if ( v19 != a1 )
  {
    v22 = v5;
    while ( v22 < (unsigned int)v8 )
    {
      if ( (*(_DWORD *)(v22 + 4) & 0x20) != 0 )
      {
        memmove((int)v36, v22, 0x28u);
        memmove(v22, (int)(v8 - 10), 0x28u);
        memmove((int)(v8 - 10), (int)v36, 0x28u);
        v8 -= 10;
      }
      else
      {
        v22 += 40;
      }
    }
  }
  if ( v19 > 1 )
  {
    v26 = 0;
    v27 = v5;
    do
    {
      *(_DWORD *)(v27 + 16) = v26++;
      v27 += 40;
    }
    while ( v26 < v19 );
    qsort(v5, v19, 0x28u, (int (__fastcall *)(unsigned int, _BYTE *))PnpCompareResourceRequestPriority);
  }
  if ( v15 )
    v9 = PnpFindBestConfiguration(v5, v19, v35);
  else
    v9 = -1073741823;
  if ( v9 >= 0 )
  {
    v9 = IopCommitConfiguration(v35);
    for ( i = v5; i < (unsigned int)v8; i += 40 )
    {
      if ( v9 < 0 )
        *(_DWORD *)(i + 36) = -1073741800;
      else
        PnpBuildCmResourceLists(i, i + 40, 0);
    }
    goto LABEL_47;
  }
  v31 = 0;
  v23 = (_DWORD *)v5;
  if ( v5 >= (unsigned int)v8 )
    goto LABEL_47;
  while ( 1 )
  {
    if ( *v23 )
      v24 = *(_DWORD *)(*(_DWORD *)(*v23 + 176) + 20);
    else
      v24 = 0;
    v25 = PnpFindBestConfiguration(v23, 1, v35);
    v9 = v25;
    if ( v25 >= 0 )
    {
      v31 = 1;
      v9 = IopCommitConfiguration(v35);
      if ( v9 < 0 )
        goto LABEL_84;
      PnpBuildCmResourceLists(v23, v23 + 10, 0);
      goto LABEL_44;
    }
    if ( v25 == -1073741670 )
      goto LABEL_45;
    if ( v31 || (*(_DWORD *)(v5 + 4) & 0x80) != 0 )
    {
      v23[1] |= 0x20u;
      v23[9] = -1073741267;
      goto LABEL_44;
    }
    PipSetDevNodeFlags(v24, 0x40000);
    v9 = PnpRebalance(v24, v23, 1, 0);
    PipClearDevNodeFlags(v24, 0x40000);
    if ( v9 >= 0 )
      break;
    if ( v9 != -1073739512 )
    {
LABEL_84:
      v23[9] = -1073741800;
      goto LABEL_44;
    }
    v23[9] = -1073739512;
LABEL_44:
    v23 += 10;
    if ( v23 >= v8 )
      goto LABEL_45;
  }
  if ( v33 )
    *v33 = 1;
  v23 += 10;
LABEL_45:
  if ( v23 < v8 )
  {
    do
    {
      if ( v9 == -1073741670 )
      {
        v23[9] = -1073741670;
      }
      else
      {
        v30 = v23[1];
        v23[9] = -1073741267;
        v23[1] = v30 | 0x20;
      }
      v23 += 10;
    }
    while ( v23 < v8 );
    v5 = v34;
  }
  v4 = v32;
LABEL_47:
  IopReleaseFilteredBootResources(v5, v8);
LABEL_48:
  PnpFreeResourceRequirementsForAssignTable(v5, v8);
LABEL_6:
  if ( !v4 )
  {
    v10 = KeReleaseSemaphore((int)&PpRegistrySemaphore, 0, 1);
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(_WORD *)(v11 + 0x134) + 1;
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
      KiCheckForKernelApcDelivery(v10);
  }
  return v9;
}

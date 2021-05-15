// IopEnumerateEnvironmentVariablesTrEE 
 
int __fastcall IopEnumerateEnvironmentVariablesTrEE(int a1, int a2, int a3, _DWORD *a4, unsigned int *a5)
{
  int v6; // r4
  int v7; // r6
  _DWORD *v8; // r5
  unsigned int *v9; // r8
  int v10; // r0
  int v11; // r3
  int v12; // r0
  int v13; // r3
  unsigned int v14; // r7
  int v15; // r0
  int v16; // r3
  int v17; // r0
  int v18; // r3
  _DWORD *v19; // r10
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r0
  int v27; // r3
  _DWORD *v28; // r4
  unsigned int v29; // r10
  int v30; // r2
  int v31; // r3
  int v32; // r4
  unsigned int *v33; // r2
  unsigned int v34; // r3
  unsigned int v35; // r6
  int v36; // r1
  int v37; // r2
  int v38; // r3
  _DWORD *v40; // [sp+18h] [bp-48h]
  int v41; // [sp+1Ch] [bp-44h]
  _DWORD *v42; // [sp+20h] [bp-40h]
  BOOL v43; // [sp+24h] [bp-3Ch]
  _DWORD *v44; // [sp+28h] [bp-38h]
  _DWORD *v45; // [sp+2Ch] [bp-34h]
  int v46; // [sp+2Ch] [bp-34h]
  unsigned int v49; // [sp+38h] [bp-28h]
  _DWORD *v50; // [sp+3Ch] [bp-24h]
  _DWORD v51[8]; // [sp+40h] [bp-20h] BYREF

  v43 = a3 == 2;
  if ( a3 != 1 && a3 != 2 )
    return -1073741811;
  v7 = 0;
  v8 = 0;
  v45 = 0;
  v40 = 0;
  v41 = 0;
  v9 = 0;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v11 = 40;
    else
      v11 = 32;
    v10 = ExAllocatePoolWithTagPriority(1, 0x214u, 538996553, v11);
  }
  else
  {
    v10 = ExAllocatePoolWithTag(1, 532, 538996553);
  }
  v42 = (_DWORD *)v10;
  if ( v10 )
  {
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v13 = 40;
      else
        v13 = 32;
      v12 = ExAllocatePoolWithTagPriority(1, 0x21Cu, 538996553, v13);
    }
    else
    {
      v12 = ExAllocatePoolWithTag(1, 540, 538996553);
    }
    v14 = v12;
    if ( !v12 )
      goto LABEL_19;
    if ( !v43 )
      goto LABEL_35;
    if ( ViVerifierDriverAddedThunkListHead )
    {
      v16 = (MmVerifierData & 0x10) != 0 ? 40 : 32;
      v15 = ExAllocatePoolWithTagPriority(1, 0x214u, 538996553, v16);
    }
    else
    {
      v15 = ExAllocatePoolWithTag(1, 532, 538996553);
    }
    v8 = (_DWORD *)v15;
    v40 = (_DWORD *)v15;
    if ( v15
      && ((v7 = 272, v41 = 272, ViVerifierDriverAddedThunkListHead) ? ((MmVerifierData & 0x10) != 0 ? (v18 = 40) : (v18 = 32),
                                                                       v17 = ExAllocatePoolWithTagPriority(
                                                                               1,
                                                                               0x110u,
                                                                               538996553,
                                                                               v18)) : (v17 = ExAllocatePoolWithTag(
                                                                                                1,
                                                                                                272,
                                                                                                538996553)),
          (v9 = (unsigned int *)v17) != 0) )
    {
LABEL_35:
      v49 = (unsigned int)a4 + *a5;
      *a5 = 0;
      memset((_BYTE *)v14, 0, 540);
      v19 = a4;
      v50 = a4;
      v44 = a4;
      while ( 1 )
      {
        v20 = *(_DWORD *)(v14 + 8);
        v21 = *(_DWORD *)(v14 + 12);
        v22 = *(_DWORD *)(v14 + 16);
        *v42 = *(_DWORD *)(v14 + 4);
        v42[1] = v20;
        v42[2] = v21;
        v42[3] = v22;
        memmove((int)(v42 + 4), v14 + 24, *(_DWORD *)(v14 + 20));
        *((_WORD *)v42 + (*(_DWORD *)(v14 + 20) >> 1) + 8) = 0;
        v6 = IopIssueTrEERequest(1, a1, a2, (int)v42, 532, v14, 540, 0x18u, v51);
        if ( v6 < 0 )
          break;
        if ( *(_DWORD *)v14 == -2147483634 )
        {
          v6 = 0;
          break;
        }
        if ( *(int *)v14 < 0 )
        {
          v6 = IopEfiStatusToNTSTATUS(*(_DWORD *)v14);
          break;
        }
        if ( v43 )
        {
          v23 = *(_DWORD *)(v14 + 8);
          v24 = *(_DWORD *)(v14 + 12);
          v25 = *(_DWORD *)(v14 + 16);
          *v8 = *(_DWORD *)(v14 + 4);
          v8[1] = v23;
          v8[2] = v24;
          v8[3] = v25;
          memmove((int)(v8 + 4), v14 + 24, *(_DWORD *)(v14 + 20));
          while ( 1 )
          {
            v6 = IopIssueTrEERequest(0, a1, a2, (int)v8, 532, (int)v9, v7, 0xCu, v51);
            if ( v6 < 0 )
              goto LABEL_71;
            if ( *v9 == -2147483643 )
            {
              if ( a4 )
              {
                v7 = v9[2] + 16;
                v41 = v7;
                ExFreePoolWithTag((unsigned int)v9);
                if ( ViVerifierDriverAddedThunkListHead )
                {
                  if ( (MmVerifierData & 0x10) != 0 )
                    v27 = 40;
                  else
                    v27 = 32;
                  v26 = ExAllocatePoolWithTagPriority(1, v7, 538996553, v27);
                }
                else
                {
                  v26 = ExAllocatePoolWithTag(1, v7, 538996553);
                }
                v9 = (unsigned int *)v26;
                if ( !v26 )
                {
                  v6 = -1073741670;
                  goto LABEL_71;
                }
                v6 = -1073741789;
              }
            }
            else if ( (*v9 & 0x80000000) != 0 )
            {
              v6 = IopEfiStatusToNTSTATUS(*v9);
LABEL_56:
              if ( v6 < 0 )
                goto LABEL_71;
              v28 = v44;
              v46 = ((unsigned int)v44 + *(_DWORD *)(v14 + 20) + 35) & 0xFFFFFFFC;
              v29 = (v9[2] + v46 + 3) & 0xFFFFFFFC;
              if ( v29 > v49 )
                a4 = 0;
              if ( a4 )
              {
                v30 = *(_DWORD *)(v14 + 8);
                v31 = *(_DWORD *)(v14 + 12);
                v32 = *(_DWORD *)(v14 + 16);
                v44[4] = *(_DWORD *)(v14 + 4);
                v44[5] = v30;
                v44[6] = v31;
                v44[7] = v32;
                v28 = v44;
                memmove((int)(v44 + 8), v14 + 24, *(_DWORD *)(v14 + 20));
                v44[1] = v46 - (_DWORD)v44;
                memmove(v46, (int)(v9 + 3), v9[2]);
                v8 = v40;
                v44[2] = v9[2];
                v44[3] = v9[1];
                *v44 = v29 - (_DWORD)v44;
              }
              v33 = a5;
              v44 = (_DWORD *)v29;
              v45 = v28;
              v34 = *a5 - (_DWORD)v28 + v29;
              v19 = v50;
              goto LABEL_67;
            }
            if ( v6 != -1073741789 )
              goto LABEL_56;
          }
        }
        v35 = ((unsigned int)v19 + *(_DWORD *)(v14 + 20) + 23) & 0xFFFFFFFC;
        if ( v35 > v49 )
          a4 = 0;
        if ( a4 )
        {
          v36 = *(_DWORD *)(v14 + 8);
          v37 = *(_DWORD *)(v14 + 12);
          v38 = *(_DWORD *)(v14 + 16);
          v19[1] = *(_DWORD *)(v14 + 4);
          v19[2] = v36;
          v19[3] = v37;
          v19[4] = v38;
          memmove((int)(v19 + 5), v14 + 24, *(_DWORD *)(v14 + 20));
          *v19 = v35 - (_DWORD)v19;
        }
        v33 = a5;
        v8 = v40;
        v45 = v19;
        v50 = (_DWORD *)v35;
        v34 = *a5 - (_DWORD)v19 + v35;
        v19 = (_DWORD *)v35;
LABEL_67:
        v7 = v41;
        *v33 = v34;
      }
LABEL_71:
      if ( v45 && a4 )
        *v45 = 0;
    }
    else
    {
LABEL_19:
      v6 = -1073741670;
    }
    ExFreePoolWithTag((unsigned int)v42);
    if ( v14 )
      ExFreePoolWithTag(v14);
    if ( v8 )
      ExFreePoolWithTag((unsigned int)v8);
    if ( v9 )
      ExFreePoolWithTag((unsigned int)v9);
  }
  else
  {
    v6 = -1073741670;
  }
  if ( !a4 )
    v6 = -1073741789;
  return v6;
}

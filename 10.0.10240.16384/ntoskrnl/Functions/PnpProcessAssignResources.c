// PnpProcessAssignResources 
 
int __fastcall PnpProcessAssignResources(int a1, int a2, int a3)
{
  int v5; // r4
  int v6; // r7
  _BYTE *v7; // r0
  _DWORD *v8; // r9
  int v9; // r5
  _BYTE *v11; // r0
  _BYTE *v12; // r8
  _BYTE *v13; // r6
  _DWORD *v14; // r7
  int v15; // r10
  int v16; // r4
  int v17; // r0
  _DWORD *v18; // r7
  int v19; // r3
  _DWORD *v20; // r4
  int v21; // r2
  int v22; // r6
  int v23; // r1
  unsigned int v24; // r2
  unsigned __int8 v25; // r6
  unsigned int v26; // r1
  int v27; // r0
  int v28; // r1
  _DWORD *v29; // [sp+0h] [bp-30h]
  int v30; // [sp+4h] [bp-2Ch]
  unsigned int v31; // [sp+8h] [bp-28h]
  int v33; // [sp+Ch] [bp-24h]

  v5 = IopNumberDeviceNodes + 2;
  v6 = 0;
  v30 = 0;
  v7 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * (IopNumberDeviceNodes + 2), 896560720);
  v8 = v7;
  v29 = v7;
  if ( v7 )
  {
    memset(v7, 0, 4 * v5);
    *v8 = a2;
    PnpProcessAssignResourcesWorker(a1, v8);
    v9 = v8[1];
    if ( v9 )
    {
      v11 = (_BYTE *)ExAllocatePoolWithTag(1, 40 * v9, 913337936);
      v12 = v11;
      v31 = (unsigned int)v11;
      if ( v11 )
      {
        memset(v11, 0, 40 * v9);
        v13 = v12;
        v14 = v8;
        v15 = v9;
        do
        {
          v16 = v14[2];
          memset(v13, 0, 40);
          *(_DWORD *)v13 = v16;
          *((_DWORD *)v13 + 5) = 0;
          *((_DWORD *)v13 + 2) = 4;
          v13 += 40;
          ++v14;
          --v15;
        }
        while ( v15 );
        v17 = PnpAssignResourcesToDevices(v9, v31, a3);
        v18 = (_DWORD *)v31;
        while ( 1 )
        {
          if ( !*v18 )
            return sub_7CBE90(v17);
          v19 = *v18;
          v20 = *(_DWORD **)(*(_DWORD *)(*v18 + 176) + 20);
          v21 = v18[9];
          if ( v21 >= 0 )
          {
            v30 = 1;
            if ( v18[7] )
            {
              v22 = KeAbPreAcquire((unsigned int)&PiResourceListLock, 0, 0);
              v23 = KfRaiseIrql(1);
              v33 = v23;
              do
                v24 = __ldrex((unsigned __int8 *)&PiResourceListLock);
              while ( __strex(v24 & 0xFE, (unsigned __int8 *)&PiResourceListLock) );
              __dmb(0xBu);
              if ( (v24 & 1) == 0 )
              {
                ExpAcquireFastMutexContended((int)&PiResourceListLock, v22);
                v23 = v33;
              }
              if ( v22 )
                *(_BYTE *)(v22 + 14) |= 1u;
              dword_630824 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              dword_63083C = v23;
              v20[71] = v18[7];
              v20[72] = v18[8];
              dword_630824 = 0;
              v25 = dword_63083C;
              __dmb(0xBu);
              do
                v26 = __ldrex(&PiResourceListLock);
              while ( !v26 && __strex(1u, &PiResourceListLock) );
              if ( v26 )
                ExpReleaseFastMutexContended(&PiResourceListLock, v26);
              KfLowerIrql(v25);
              KeAbPostRelease((unsigned int)&PiResourceListLock);
            }
            else
            {
              PipSetDevNodeFlags((int)v20, 256);
            }
            PipSetDevNodeState(v20, 772);
            v17 = PipClearDevNodeUserFlags((int)v20, 4);
            goto LABEL_15;
          }
          if ( v21 == -1073741686 )
          {
            v28 = 17;
            goto LABEL_42;
          }
          if ( v21 == -1073741438 )
            break;
          if ( v21 != -1073741267 )
          {
            if ( v21 == -1073739512 || v21 == -1073479627 )
            {
              v28 = 35;
            }
            else
            {
              if ( v21 != -1073479626 )
              {
                v27 = *(_DWORD *)(*(_DWORD *)(v19 + 176) + 20);
                if ( v21 == -1073479625 )
                  v28 = 36;
                else
                  v28 = 12;
                goto LABEL_43;
              }
              v28 = 33;
            }
LABEL_42:
            v27 = *(_DWORD *)(*(_DWORD *)(v19 + 176) + 20);
LABEL_43:
            v17 = PipSetDevNodeProblem(v27, v28, v21);
          }
LABEL_15:
          v18 += 10;
          if ( !--v9 )
          {
            v8 = v29;
            ExFreePoolWithTag(v31);
            v6 = v30;
            goto LABEL_3;
          }
        }
        v28 = 34;
        goto LABEL_42;
      }
    }
LABEL_3:
    ExFreePoolWithTag((unsigned int)v8);
  }
  return v6;
}

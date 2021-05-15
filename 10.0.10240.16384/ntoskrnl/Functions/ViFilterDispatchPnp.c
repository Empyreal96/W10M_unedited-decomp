// ViFilterDispatchPnp 
 
int __fastcall ViFilterDispatchPnp(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r2
  int v7; // r3
  int v8; // r0
  int v9; // r4
  int *v10; // lr
  _DWORD *v11; // r8
  int v12; // r3
  int *v13; // r6
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r4
  int *v18; // lr
  int v19; // r2
  int v20; // r3
  int v21; // r4
  int (__fastcall *v22)(int, int); // r3
  int *v23; // r5
  int v24; // r0
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int *v28; // lr
  int v29; // r1
  int v30; // r2
  int v31; // r3
  int *v32; // r5
  int v33; // r0
  int v34; // r1
  int v35; // r2
  int v36; // r3
  int *v37; // lr
  int v38; // r1
  int v39; // r2
  int v40; // r3
  int v41; // r2
  int *v42; // r5
  int v43; // r0
  int v44; // r1
  int v45; // r2
  int v46; // r3
  int *v47; // lr
  int v48; // r1
  int v49; // r2
  int v50; // r3
  int v51; // r2
  int v53[8]; // [sp+8h] [bp-20h] BYREF

  v53[0] = a3;
  v53[1] = a4;
  v5 = a1[10];
  v53[0] = v5;
  v7 = *(_DWORD *)(v5 + 64);
  __dmb(0xBu);
  while ( (v7 & 1) == 0 )
  {
    __dmb(0xAu);
    __yield();
    v7 = *(_DWORD *)(v5 + 64);
    __dmb(0xBu);
  }
  v8 = IoAcquireRemoveLockEx((_BYTE *)(v53[0] + 16), a2, (int)byte_901D79, 1, 24);
  v9 = v8;
  if ( v8 >= 0 )
  {
    v10 = *(int **)(a2 + 96);
    v11 = *(_DWORD **)(v53[0] + 4);
    v12 = *((unsigned __int8 *)v10 + 1);
    if ( *((_BYTE *)v10 + 1) )
    {
      if ( v12 == 2 )
      {
        v32 = v10 - 10;
        v33 = *v10;
        v34 = v10[1];
        v35 = v10[2];
        v36 = v10[3];
        v37 = v10 + 4;
        *v32 = v33;
        v32[1] = v34;
        v32[2] = v35;
        v32[3] = v36;
        v38 = v37[1];
        v39 = v37[2];
        v40 = v37[3];
        v32[4] = *v37;
        v32[5] = v38;
        v32[6] = v39;
        v32[7] = v40;
        *((_BYTE *)v32 + 3) = 0;
        KeInitializeEvent(v53[0] + 40, 0, 0);
        v41 = *(_DWORD *)(a2 + 96);
        *(_DWORD *)(v41 - 8) = ViFilterRemoveNotificationCompletion;
        *(_DWORD *)(v41 - 4) = v53;
        *(_BYTE *)(v41 - 37) = -32;
        v9 = IofCallDriver((int)v11, a2);
        if ( v9 == 259 )
        {
          KeWaitForSingleObject(v53[0] + 40, 0, 0, 0, 0);
          v9 = *(_DWORD *)(a2 + 24);
        }
        IoReleaseRemoveLockAndWaitEx(v53[0] + 16, a2, 24);
        IoDetachDevice(v11);
        IoDeleteDevice(a1);
        goto LABEL_6;
      }
      if ( v12 == 22 )
      {
        v23 = v10 - 10;
        v24 = *v10;
        v25 = v10[1];
        v26 = v10[2];
        v27 = v10[3];
        v28 = v10 + 4;
        *v23 = v24;
        v23[1] = v25;
        v23[2] = v26;
        v23[3] = v27;
        v29 = v28[1];
        v30 = v28[2];
        v31 = v28[3];
        v23[4] = *v28;
        v23[5] = v29;
        v23[6] = v30;
        v23[7] = v31;
        *((_BYTE *)v23 + 3) = 0;
        v22 = ViFilterDeviceUsageNotificationCompletion;
      }
      else
      {
        v13 = v10 - 10;
        v14 = *v10;
        v15 = v10[1];
        v16 = v10[2];
        v17 = v10[3];
        v18 = v10 + 4;
        *v13 = v14;
        v13[1] = v15;
        v13[2] = v16;
        v13[3] = v17;
        v19 = v18[1];
        v20 = v18[2];
        v21 = v18[3];
        v13[4] = *v18;
        v13[5] = v19;
        v13[6] = v20;
        v13[7] = v21;
        *((_BYTE *)v13 + 3) = 0;
        v22 = (int (__fastcall *)(int, int))ViFilterGenericCompletionRoutine;
      }
    }
    else
    {
      v42 = v10 - 10;
      v43 = *v10;
      v44 = v10[1];
      v45 = v10[2];
      v46 = v10[3];
      v47 = v10 + 4;
      *v42 = v43;
      v42[1] = v44;
      v42[2] = v45;
      v42[3] = v46;
      v48 = v47[1];
      v49 = v47[2];
      v50 = v47[3];
      v42[4] = *v47;
      v42[5] = v48;
      v42[6] = v49;
      v42[7] = v50;
      *((_BYTE *)v42 + 3) = 0;
      v22 = (int (__fastcall *)(int, int))ViFilterStartCompletionRoutine;
    }
    v51 = *(_DWORD *)(a2 + 96);
    *(_DWORD *)(v51 - 8) = v22;
    *(_DWORD *)(v51 - 4) = v53;
    *(_BYTE *)(v51 - 37) = -32;
    return IofCallDriver((int)v11, a2);
  }
  *(_DWORD *)(a2 + 24) = v8;
LABEL_6:
  IofCompleteRequest(a2, 0);
  return v9;
}

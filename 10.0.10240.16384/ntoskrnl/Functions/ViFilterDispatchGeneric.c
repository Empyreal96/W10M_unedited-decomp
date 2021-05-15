// ViFilterDispatchGeneric 
 
int __fastcall ViFilterDispatchGeneric(int a1, int a2)
{
  int v2; // r2
  int v4; // r3
  int v5; // r4
  int *v6; // r5
  int *v7; // r6
  int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r2
  int v17; // r2
  int v18; // r3
  unsigned int v19; // r4
  int v20; // r0
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int *v24; // r0
  int v26; // [sp+0h] [bp-38h]
  int v27; // [sp+8h] [bp-30h] BYREF
  int v28; // [sp+Ch] [bp-2Ch] BYREF
  char v29[8]; // [sp+10h] [bp-28h] BYREF
  _DWORD v30[2]; // [sp+18h] [bp-20h] BYREF
  int v31; // [sp+20h] [bp-18h]

  v2 = *(_DWORD *)(a1 + 40);
  v27 = v2;
  v4 = *(_DWORD *)(v2 + 64);
  __dmb(0xBu);
  while ( (v4 & 1) == 0 )
  {
    __dmb(0xAu);
    __yield();
    v4 = *(_DWORD *)(v2 + 64);
    __dmb(0xBu);
  }
  v5 = IoAcquireRemoveLockEx((_BYTE *)(v27 + 16), a2, (int)byte_901D79, 1, 24);
  if ( v5 < 0 )
  {
LABEL_12:
    *(_DWORD *)(a2 + 24) = v5;
    IofCompleteRequest(a2, 0);
    return v5;
  }
  v6 = *(int **)(a2 + 96);
  v7 = v6 - 10;
  v8 = *v6;
  v9 = v6[1];
  v10 = v6[2];
  v11 = v6[3];
  v6 += 4;
  *v7 = v8;
  v7[1] = v9;
  v7[2] = v10;
  v7[3] = v11;
  v12 = *v6;
  v13 = v6[1];
  v14 = v6[2];
  v15 = v6[3];
  v7[4] = *v6;
  v7[5] = v13;
  v7[6] = v14;
  v7[7] = v15;
  *((_BYTE *)v7 + 3) = 0;
  v16 = *(_DWORD *)(a2 + 96);
  *(_DWORD *)(v16 - 8) = ViFilterGenericCompletionRoutine;
  *(_DWORD *)(v16 - 4) = &v27;
  *(_BYTE *)(v16 - 37) = -32;
  v19 = KeGetCurrentIrql(v12);
  if ( v19 > 2 )
    return IofCallDriver(*(_DWORD *)(v27 + 4), a2);
  v20 = RtlpGetStackLimits((int)&v28, (int)v29, v17, v18);
  if ( !v20 )
    return IofCallDriver(*(_DWORD *)(v27 + 4), a2);
  v24 = KeGetCurrentStackPointer(v20, v21, v22, v23, v26);
  if ( (unsigned int)v24 - v28 >= 0xC00 )
    return IofCallDriver(*(_DWORD *)(v27 + 4), a2);
  v30[0] = *(_DWORD *)(v27 + 4);
  v30[1] = a2;
  v31 = -1;
  v5 = KeExpandKernelStackAndCalloutEx((int)ViFilterIoCallDriverWithExpandStack, (int)v30, 3072, v19 <= 1, 0);
  if ( v5 < 0 )
  {
    if ( v31 == -1 )
      IoReleaseRemoveLockEx(v27 + 16, a2, 24);
    goto LABEL_12;
  }
  return v31;
}

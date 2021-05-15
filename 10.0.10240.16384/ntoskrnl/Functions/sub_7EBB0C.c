// sub_7EBB0C 
 
void __fastcall sub_7EBB0C(int a1, int a2, int a3, int a4, unsigned int *a5)
{
  int v5; // r4
  int v6; // r5
  int v7; // r0
  unsigned int v8; // r3
  unsigned int *v9; // r2
  unsigned int v10; // r0
  unsigned int *v11; // r3
  unsigned int *v12; // r5
  unsigned int v13; // r1
  unsigned int v14; // r2
  unsigned int v15; // r3
  unsigned int *v16; // r4
  unsigned int v17; // r3
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r0
  unsigned int *v23; // r3
  int v24; // r0
  int v25; // r4
  unsigned int v26; // r2
  unsigned int *v27; // r2
  unsigned int v28; // r1

  v7 = PiSwMakePdoInactive(v6);
  if ( (*(_DWORD *)(v5 + 4) & 8) == 0 )
    PiSwUnassociateDeviceObject(v7);
  v8 = a5[1];
  if ( (v8 & 2) == 0 )
LABEL_23:
    JUMPOUT(0x765F2C);
  a5[1] = v8 & 0xFFFFFFFD;
  PiSwBusRelationRemove(a5);
  v9 = a5;
  if ( !a5[12] )
  {
LABEL_21:
    if ( !v9[15] )
    {
      RtlDeleteElementGenericTableAvl((int)&PiSwDeviceInstanceTable, (int)&a5, (int)v9, 0);
      PiSwDeviceDereference(a5);
    }
    goto LABEL_23;
  }
  v10 = a5[11];
  if ( v10 )
  {
    ExFreePoolWithTag(v10);
    v11 = a5;
    a5[10] = 0;
    v11[11] = 0;
    v9 = a5;
  }
  PiSwPnPInfoFree(v9 + 4);
  v12 = a5 + 4;
  v13 = *(_DWORD *)(a5[12] + 8);
  v14 = *(_DWORD *)(a5[12] + 12);
  v15 = *(_DWORD *)(a5[12] + 16);
  v16 = (unsigned int *)(a5[12] + 20);
  a5[4] = *(_DWORD *)(a5[12] + 4);
  v12[1] = v13;
  v12[2] = v14;
  v12[3] = v15;
  v12 += 4;
  v17 = v16[1];
  *v12 = *v16;
  v12[1] = v17;
  memset((_BYTE *)(a5[12] + 4), 0, 24);
  v18 = a5;
  v19 = a5[20];
  if ( v19 )
  {
    ExFreePoolWithTag(v19);
    v18 = a5;
  }
  v18[20] = *(_DWORD *)(v18[12] + 28);
  *(_DWORD *)(a5[12] + 28) = 0;
  v20 = a5;
  v21 = a5[22];
  if ( v21 )
  {
    PnpFreeDevPropertyArray(a5[23], v21);
    v20 = a5;
  }
  v20[23] = *(_DWORD *)(v20[12] + 36);
  a5[22] = *(_DWORD *)(a5[12] + 32);
  *(_DWORD *)(a5[12] + 36) = 0;
  *(_DWORD *)(a5[12] + 32) = 0;
  PiSwFreeInterfaceList((int *)a5 + 25);
  v22 = PiSwBusRelationAdd(*(unsigned __int16 **)a5[12]);
  v23 = a5;
  if ( v22 < 0 )
  {
    v26 = a5[19];
    if ( !v26 )
    {
LABEL_20:
      PiSwQueuedCreateInfoFree(v23[12]);
      a5[12] = 0;
      v9 = a5;
      goto LABEL_21;
    }
    __dmb(0xBu);
    v27 = (unsigned int *)(v26 + 56);
    do
      v28 = __ldrex(v27);
    while ( __strex(0, v27) );
    __dmb(0xBu);
    if ( v28 )
    {
      *(_DWORD *)(a5[19] + 28) = 0;
      *(_DWORD *)(a5[19] + 24) = v22;
      IofCompleteRequest(a5[19], 0);
      a5[19] = 0;
    }
  }
  else
  {
    v24 = PnpDeviceObjectFromDeviceInstance(a5[15]);
    v25 = v24;
    if ( v24 )
    {
      IoInvalidateDeviceRelations(v24, 5);
      ObfDereferenceObject(v25);
    }
  }
  v23 = a5;
  goto LABEL_20;
}

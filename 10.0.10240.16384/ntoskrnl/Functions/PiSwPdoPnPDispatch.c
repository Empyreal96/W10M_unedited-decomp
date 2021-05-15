// PiSwPdoPnPDispatch 
 
int __fastcall PiSwPdoPnPDispatch(int a1, _DWORD *a2)
{
  _DWORD *v3; // r5
  int v5; // r4
  int v6; // r8
  int v8; // r2
  int v9; // r3
  _DWORD *v10; // r0
  int v11; // r3
  unsigned __int16 *v12; // r0
  unsigned int v13; // r1
  int v14; // r0
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r2
  int v19; // r3
  _DWORD *v20; // r2
  _DWORD *v21; // r3
  int v22; // r3
  int v23; // r1
  int v24; // r1
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // r2
  int v29; // r3
  _DWORD *v30; // r0
  int v31; // r1
  int v32; // r0
  int v33; // r2
  int v34; // r3
  int v35; // r3
  int v36; // r2
  int v37; // r3
  int v38; // r2
  int v39; // r3
  int v40; // r3
  int v41; // r0
  unsigned int v42; // r1
  int v43; // r3
  unsigned int v44; // r3
  int v45; // r2
  int v46; // r3
  int v47; // r3
  _DWORD *v48; // r0
  _DWORD *v49; // r4

  v3 = *(_DWORD **)(a1 + 40);
  v5 = a2[6];
  v6 = a2[24];
  if ( (v3[1] & 0x10) != 0 )
    return sub_7E0964();
  switch ( *(_BYTE *)(v6 + 1) )
  {
    case 0:
      v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v37 = *(__int16 *)(v36 + 0x134) - 1;
      *(_WORD *)(v36 + 308) = v37;
      ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v36, v37);
      if ( (v3[1] & 1) != 0 )
        goto LABEL_19;
      v5 = PiSwDeviceInterfacesUpdateState(*v3, 1);
      if ( v5 < 0 )
        PiSwDeviceInterfacesUpdateState(*v3, 0);
      else
        v3[1] |= 1u;
      goto LABEL_13;
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
      goto LABEL_27;
    case 2:
      v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v39 = *(__int16 *)(v38 + 0x134) - 1;
      *(_WORD *)(v38 + 308) = v39;
      ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v38, v39);
      v40 = v3[1] | 2;
      v3[1] = v40;
      PiSwProcessRemove(a1, (v40 & 8) != 0);
      if ( (v3[1] & 8) == 0 )
        PiSwDestroyDeviceObject(a1);
      goto LABEL_53;
    case 7:
      if ( *(_DWORD *)(v6 + 8) != 4 )
        goto LABEL_14;
      v48 = (_DWORD *)ExAllocatePoolWithTag(1, 8, 1466986064);
      v49 = v48;
      if ( !v48 )
        goto LABEL_59;
      *v48 = 1;
      v48[1] = a1;
      ObfReferenceObject(a1);
      a2[7] = v49;
      goto LABEL_27;
    case 9:
      v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v19 = *(__int16 *)(v18 + 0x134) - 1;
      *(_WORD *)(v18 + 308) = v19;
      ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v18, v19);
      if ( !*v3 )
        goto LABEL_60;
      v20 = *(_DWORD **)(v6 + 8);
      v21 = v20 + 6;
      v20[4] = 0;
      v20[5] = 1;
      do
        *v21++ = 4;
      while ( v21 != v20 + 11 );
      v22 = v20[1];
      v20[11] = 0;
      v20[12] = 0;
      v20[1] = v22 | 0x240;
      v23 = (v22 | 0x240) ^ (((unsigned __int8)v22 | 0x40) ^ (unsigned __int8)(16 * ((*(_DWORD *)(*v3 + 36) & 1) != 0))) & 0x10;
      v20[1] = v23;
      v24 = v23 ^ ((unsigned __int8)v23 ^ (unsigned __int8)(((*(_DWORD *)(*v3 + 36) & 2) != 0) << 7)) & 0x80;
      v20[1] = v24;
      v25 = v24 ^ (v24 ^ (((*(_DWORD *)(*v3 + 36) & 4) != 0) << 17)) & 0x20000;
      v20[1] = v25;
      v20[1] = ((unsigned __int16)v25 ^ (((*(_DWORD *)(*v3 + 36) & 8) == 0) << 8)) & 0x100 ^ v25;
      goto LABEL_19;
    case 0xC:
      v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v27 = *(__int16 *)(v26 + 0x134) - 1;
      *(_WORD *)(v26 + 308) = v27;
      ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v26, v27);
      v28 = *v3;
      if ( !*v3 )
        goto LABEL_60;
      v29 = *(_DWORD *)(v6 + 8);
      if ( v29 )
      {
        if ( v29 != 1 )
          goto LABEL_13;
        v12 = *(unsigned __int16 **)(v28 + 32);
      }
      else
      {
        v12 = *(unsigned __int16 **)(v28 + 28);
      }
      if ( !v12 )
        goto LABEL_13;
      v13 = 0x7FFFFFFF;
      goto LABEL_11;
    case 0x13:
      v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v9 = *(__int16 *)(v8 + 0x134) - 1;
      *(_WORD *)(v8 + 308) = v9;
      ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v8, v9);
      v10 = (_DWORD *)*v3;
      if ( !*v3 )
        goto LABEL_60;
      v11 = *(_DWORD *)(v6 + 8);
      switch ( v11 )
      {
        case 0:
          v12 = (unsigned __int16 *)v10[2];
LABEL_10:
          v13 = 200;
LABEL_11:
          v14 = PnpAllocatePWSTR(v12, v13, 1466986064, a2 + 7);
          goto LABEL_12;
        case 1:
          v32 = v10[4];
          if ( v32 )
          {
            v14 = PnpAllocateMultiSZ(v32, 0x7FFFFFFF);
            goto LABEL_12;
          }
          break;
        case 2:
          v14 = PiSwDeviceMakeCompatibleIds();
          goto LABEL_12;
        case 3:
          v12 = (unsigned __int16 *)v10[3];
          goto LABEL_10;
        default:
          if ( v11 == 5 && v10[6] )
          {
            v31 = ExAllocatePoolWithTag(1, 78, 1466986064);
            a2[7] = v31;
            if ( v31 )
            {
              v14 = PnpStringFromGuid(*(_DWORD *)(*v3 + 24), v31);
LABEL_12:
              v5 = v14;
              break;
            }
            v5 = -1073741670;
          }
          break;
      }
LABEL_13:
      v15 = ExReleaseResourceLite((int)&PiSwLockObj);
      v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v17 = (__int16)(*(_WORD *)(v16 + 0x134) + 1);
      *(_WORD *)(v16 + 308) = v17;
      if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
        KiCheckForKernelApcDelivery(v15);
LABEL_14:
      a2[6] = v5;
      IofCompleteRequest((int)a2, 0);
      return v5;
    case 0x14:
      v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v34 = *(__int16 *)(v33 + 0x134) - 1;
      *(_WORD *)(v33 + 308) = v34;
      ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v33, v34);
      if ( *v3 )
      {
        v35 = a2[7];
        if ( (*(_DWORD *)(*v3 + 36) & 4) != 0 )
          v44 = v35 | 2;
        else
          v44 = v35 & 0xFFFFFFFD;
        a2[7] = v44;
LABEL_19:
        v5 = 0;
      }
      else
      {
LABEL_60:
        v5 = -1073741810;
      }
      goto LABEL_13;
    case 0x15:
      v30 = (_DWORD *)ExAllocatePoolWithTag(1, 24, 1466986064);
      if ( v30 )
      {
        *v30 = 114361122;
        v30[1] = 1290763744;
        v30[2] = 2098800014;
        v30[3] = -498961394;
        v30[4] = 15;
        v30[5] = 0;
        a2[7] = v30;
LABEL_27:
        v5 = 0;
      }
      else
      {
LABEL_59:
        v5 = -1073741670;
      }
      goto LABEL_14;
    case 0x16:
      if ( !*(_BYTE *)(v6 + 8) )
        goto LABEL_27;
      v5 = -1073741637;
      goto LABEL_14;
    case 0x17:
      v45 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v46 = *(__int16 *)(v45 + 0x134) - 1;
      *(_WORD *)(v45 + 308) = v46;
      ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v45, v46);
      v47 = v3[1] | 4;
      v3[1] = v47;
      PiSwProcessRemove(a1, (v47 & 8) != 0);
LABEL_53:
      v41 = ExReleaseResourceLite((int)&PiSwLockObj);
      v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v43 = (__int16)(*(_WORD *)(v42 + 0x134) + 1);
      *(_WORD *)(v42 + 308) = v43;
      if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
        KiCheckForKernelApcDelivery(v41);
      goto LABEL_27;
    case 0x19:
      PiSwCompleteCreate(a1);
      goto LABEL_27;
    default:
      goto LABEL_14;
  }
}

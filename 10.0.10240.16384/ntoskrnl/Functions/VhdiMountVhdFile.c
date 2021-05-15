// VhdiMountVhdFile 
 
int __fastcall VhdiMountVhdFile(unsigned __int16 *a1)
{
  int v2; // r4
  unsigned __int16 *v3; // r9
  unsigned int v4; // r7
  _DWORD *v5; // r0
  unsigned int v6; // r6
  _DWORD *v7; // r5
  int v8; // r0
  unsigned __int16 *v9; // r4
  unsigned int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  unsigned __int16 *v14; // r7
  int v15; // r4
  int v16; // r0
  unsigned __int16 *v18[2]; // [sp+20h] [bp-148h] BYREF
  char v19; // [sp+28h] [bp-140h] BYREF
  char v20; // [sp+29h] [bp-13Fh]
  char v21; // [sp+2Ah] [bp-13Eh]
  int v22; // [sp+2Ch] [bp-13Ch]
  int *v23; // [sp+30h] [bp-138h] BYREF
  int **v24; // [sp+34h] [bp-134h]
  int v25; // [sp+38h] [bp-130h] BYREF
  int v26; // [sp+40h] [bp-128h]
  int v27; // [sp+48h] [bp-120h]
  int v28; // [sp+4Ch] [bp-11Ch]
  char *v29; // [sp+50h] [bp-118h]
  int v30; // [sp+54h] [bp-114h]
  int v31; // [sp+58h] [bp-110h]
  int v32; // [sp+5Ch] [bp-10Ch]
  char v33[8]; // [sp+60h] [bp-108h] BYREF
  char v34[8]; // [sp+68h] [bp-100h] BYREF
  int v35[6]; // [sp+70h] [bp-F8h] BYREF
  _DWORD v36[22]; // [sp+88h] [bp-E0h] BYREF
  int v37[34]; // [sp+E0h] [bp-88h] BYREF

  v18[0] = 0;
  v25 = 0;
  if ( !a1 )
  {
    v2 = -1073741811;
    goto LABEL_3;
  }
  memset(v36, 0, 84);
  v2 = IoGetDeviceInterfaces((int)&GUID_DEVINTERFACE_SURFACE_VIRTUAL_DRIVE, 0, 0, v18);
  if ( v2 < 0 )
    goto LABEL_3;
  v3 = v18[0];
  if ( !*v18[0] )
  {
    v2 = -1073741275;
    goto LABEL_3;
  }
  RtlInitUnicodeString((unsigned int)v34, v18[0]);
  v2 = IoGetDeviceObjectPointer((int)v34, 0x10000000, &v25, (int *)v18);
  if ( v2 < 0 )
    goto LABEL_3;
  v4 = 2 * (wcslen(a1) + 1);
  v5 = (_DWORD *)ExAllocatePoolWithTag(512, v4 + 32, 1113876566);
  v6 = (unsigned int)v5;
  if ( !v5 )
    goto LABEL_9;
  *v5 = 1;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  v5[4] = 0;
  v5[5] = 0;
  v5[6] = 32;
  v5[7] = v4;
  memmove((int)(v5 + 8), (int)a1, v4);
  v7 = (_DWORD *)ExAllocatePoolWithTag(512, v4 + 540, 1113876566);
  if ( !v7 )
  {
LABEL_9:
    v2 = -1073741801;
    goto LABEL_3;
  }
  v19 = 1;
  v20 = 0;
  v21 = 4;
  v22 = 0;
  v24 = &v23;
  v23 = (int *)&v23;
  v8 = IoBuildDeviceIoControlRequest(2971948, (int)v18[0], v6, v4 + 32, (int)v7, v4 + 540);
  if ( !v8 )
    goto LABEL_12;
  v2 = IofCallDriver((int)v18[0], v8);
  if ( v2 == 259 )
  {
    KeWaitForSingleObject((unsigned int)&v19, 0, 0, 0, 0);
    v2 = v26;
  }
  if ( v2 < 0 )
    goto LABEL_3;
  v9 = (unsigned __int16 *)((char *)v7 + v7[5]);
  if ( *v9 == 92 && v9[1] == 92 && v9[2] == 46 && v9[3] == 92 )
  {
    v9[1] = 63;
    v9[2] = 63;
  }
  v10 = wcslen(a1);
  wcscat_s(v9, v10 + 257, (char *)a1);
  RtlInitUnicodeString((unsigned int)v33, v9);
  v27 = 24;
  v28 = 0;
  v30 = 512;
  v29 = v33;
  v31 = 0;
  v32 = 0;
  memset(v37, 0, 104);
  v37[0] = 0;
  v37[1] = 5506944;
  strcpy((char *)&v37[2], "VIRTDSK");
  v36[0] = 775214672;
  v36[1] = 1120557081;
  v36[2] = 148090500;
  v36[3] = 98941443;
  v36[9] = 84;
  v36[10] = 4;
  v36[13] = 2;
  v11 = v7[1];
  v12 = v7[2];
  v13 = v7[3];
  v36[4] = *v7;
  v36[5] = v11;
  v36[6] = v12;
  v36[7] = v13;
  v36[8] = v7[4];
  memmove((int)&v37[4], (int)v36, 0x54u);
  v2 = ZwCreateFile();
  if ( v2 < 0 )
    goto LABEL_3;
  v2 = ObReferenceObjectByHandle(dword_65358C, -1072693248, 0, 0, (int)v18, 0);
  if ( v2 < 0 )
    goto LABEL_3;
  v14 = v18[0];
  v15 = IoGetRelatedDeviceObject((_DWORD *)v18[0]);
  memset(v35, 0, sizeof(v35));
  v35[0] = 1;
  v19 = 1;
  v20 = 0;
  v21 = 4;
  v22 = 0;
  v24 = &v23;
  v23 = (int *)&v23;
  v16 = IoBuildDeviceIoControlRequest(2955548, v15, (int)v35, 24, 0, 0);
  if ( !v16 )
  {
LABEL_12:
    v2 = -1073741670;
    goto LABEL_3;
  }
  *(_DWORD *)(*(_DWORD *)(v16 + 96) - 12) = v14;
  v2 = IofCallDriver(v15, v16);
  if ( v2 == 259 )
  {
    KeWaitForSingleObject((unsigned int)&v19, 0, 0, 0, 0);
    v2 = v26;
  }
  if ( v2 < 0 )
LABEL_3:
    KeBugCheckEx(303, 5, v2, 0, 0);
  ExFreePoolWithTag(v6);
  ExFreePoolWithTag((unsigned int)v7);
  if ( v14 )
    ObfDereferenceObjectWithTag((int)v14);
  if ( v25 )
    ObfDereferenceObjectWithTag(v25);
  ExFreePoolWithTag((unsigned int)v3);
  return v2;
}

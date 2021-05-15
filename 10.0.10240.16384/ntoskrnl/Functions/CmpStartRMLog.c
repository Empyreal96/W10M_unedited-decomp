// CmpStartRMLog 
 
int __fastcall CmpStartRMLog(_DWORD *a1, _DWORD *a2)
{
  int v2; // r7
  int v3; // r6
  unsigned int v6; // r10
  int v7; // r2
  int v8; // r3
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r4
  _DWORD *v13; // r8
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  _DWORD *v17; // r4
  int v18; // r1
  int v19; // r2
  int v20; // r3
  _DWORD *v21; // r3
  _DWORD *v22; // r4
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r7
  int v27; // r0
  unsigned int v28; // r4
  int v29; // r0
  int v30; // r0
  int v31; // r3
  int v32; // r1
  int v33; // r0
  int v34; // r0
  int v35; // r0
  int v36; // r1
  int v37; // r0
  unsigned int v38; // r1
  __int16 v39; // r3
  _DWORD *v41; // [sp+4h] [bp-ACh]
  _DWORD *v42; // [sp+8h] [bp-A8h]
  _DWORD *v43; // [sp+Ch] [bp-A4h]
  char v44[4]; // [sp+18h] [bp-98h] BYREF
  unsigned int v45; // [sp+1Ch] [bp-94h] BYREF
  int v46; // [sp+20h] [bp-90h] BYREF
  int v47; // [sp+28h] [bp-88h] BYREF
  int v48; // [sp+2Ch] [bp-84h]
  int v49; // [sp+30h] [bp-80h] BYREF
  int v50; // [sp+34h] [bp-7Ch]
  int v51; // [sp+38h] [bp-78h] BYREF
  int v52; // [sp+3Ch] [bp-74h]
  int v53; // [sp+40h] [bp-70h] BYREF
  int v54; // [sp+44h] [bp-6Ch] BYREF
  int v55; // [sp+48h] [bp-68h]
  char v56[4]; // [sp+4Ch] [bp-64h] BYREF
  char v57[4]; // [sp+50h] [bp-60h] BYREF
  int *v58; // [sp+54h] [bp-5Ch] BYREF
  int v59; // [sp+58h] [bp-58h] BYREF
  int v60[2]; // [sp+60h] [bp-50h] BYREF
  int v61[2]; // [sp+68h] [bp-48h] BYREF
  int v62[2]; // [sp+70h] [bp-40h] BYREF
  char v63[8]; // [sp+78h] [bp-38h] BYREF
  char v64[8]; // [sp+80h] [bp-30h] BYREF
  char v65[40]; // [sp+88h] [bp-28h] BYREF

  v51 = 0;
  v49 = 0;
  v59 = 0;
  v46 = 0;
  v2 = 0;
  v3 = 0;
  v55 = 1;
  v52 = 0;
  v50 = 0;
  v6 = 0;
  v45 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(__int16 *)(v7 + 0x134) - 1;
  *(_WORD *)(v7 + 308) = v8;
  ExAcquireResourceExclusiveLite(a1[20], 1, v7, v8);
  if ( (a1[15] & 1) != 0 )
  {
    v9 = ExReleaseResourceLite(a1[20]);
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(_WORD *)(v10 + 0x134) + 1;
    *(_WORD *)(v10 + 308) = v11;
    if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery(v9);
    return 0;
  }
  v13 = (_DWORD *)ExAllocatePoolWithTag(1, 120, 538987843);
  if ( !v13 )
  {
    v14 = ExReleaseResourceLite(a1[20]);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery(v14);
    return -1073741670;
  }
  a1[15] |= 2u;
  a1[18] = 0;
  a1[19] = -1;
  if ( a1 == (_DWORD *)CmRmSystem )
  {
    v53 = (int)&CmpLogPath;
    if ( a2 )
    {
      v17 = (_DWORD *)(*((_DWORD *)off_60E8A4 + 8) + 128);
      v18 = a2[1];
      v19 = a2[2];
      v20 = a2[3];
      *v17 = *a2;
      v17[1] = v18;
      v17[2] = v19;
      v17[3] = v20;
    }
    v12 = RtlStringFromGUIDEx(*((_DWORD *)off_60E8A4 + 8) + 128, (int)&v49, 1);
    if ( v12 < 0 )
    {
      v3 = v50;
      v6 = 0;
      goto LABEL_62;
    }
    a1[10] = 5242880;
    a1[11] = 0;
    v21 = off_60E8A4;
    goto LABEL_24;
  }
  v12 = CmpQueryNameString(*(_DWORD *)(a1[12] + 1776), (unsigned __int16 *)&v51);
  if ( v12 >= 0 )
  {
    v53 = (int)&v51;
    if ( a2 )
    {
      v22 = (_DWORD *)(*(_DWORD *)(a1[12] + 32) + 128);
      v23 = a2[1];
      v24 = a2[2];
      v25 = a2[3];
      *v22 = *a2;
      v22[1] = v23;
      v22[2] = v24;
      v22[3] = v25;
    }
    v12 = RtlStringFromGUIDEx(*(_DWORD *)(a1[12] + 32) + 128, (int)&v49, 1);
    if ( v12 >= 0 )
    {
      v2 = v52;
      a1[10] = 0x100000;
      a1[11] = 0;
      v21 = (_DWORD *)a1[12];
LABEL_24:
      v12 = CmpQueryFileSecurityDescriptor(v21[444], (int *)&v45);
      if ( v12 < 0 )
      {
        v3 = v50;
        v6 = 0;
        goto LABEL_62;
      }
      v6 = v45;
      v26 = v53;
      v43 = a1 + 13;
      v42 = a1 + 9;
      v41 = a1 + 10;
      while ( 1 )
      {
        v12 = CmpStartCLFSLog(v26, &v49);
        if ( v12 < 0 )
          goto LABEL_54;
        v53 = 120;
        v27 = ExAllocatePoolWithTag(1, 120, 538987843);
        v28 = v27;
        if ( v27 )
        {
          ClfsGetLogFileInformation(a1[13], v27, &v53);
          ExFreePoolWithTag(v28);
        }
        v54 = 120;
        v12 = ClfsGetLogFileInformation(a1[13], v13, &v54);
        a1[18] = v13[18];
        a1[19] = v13[19];
        if ( v12 < 0 )
        {
LABEL_54:
          if ( v46 )
            ClfsTerminateReadLog();
          if ( v12 >= 0 )
          {
            a1[15] = a1[15] & 0xFFFFFFFC | 1;
          }
          else if ( a1[14] )
          {
            a1[14] = 0;
          }
          break;
        }
        if ( ClfsReadRestartArea(a1[14], &v58, &v59, v63, &v46, v41, v42, v43) == 1075445772 || !v58 )
        {
          v47 = v13[18];
          v48 = v13[19];
          goto LABEL_42;
        }
        v47 = *v58;
        v48 = v58[1];
        if ( !ClfsLsnEqual(v63, &v47) )
          goto LABEL_42;
        v45 = 0;
        v29 = a1[14];
        v61[0] = v47;
        v61[1] = v48;
        v44[0] = 0;
        if ( ClfsReadLogRecord(v29, v61, 3, v56, v57, v44, v65, v64) >= 0 )
        {
          v44[0] = 1;
          v30 = ClfsReadNextLogRecord(v45, v56, v57, v44, 0, v65, v64, v60, &v45);
          if ( v30 == -1073741807 )
          {
            v47 = v13[22];
            v31 = v13[23];
          }
          else
          {
            if ( v30 < 0 )
              goto LABEL_39;
            v47 = v60[0];
            v31 = v60[1];
          }
          v48 = v31;
        }
LABEL_39:
        if ( v45 )
          ClfsTerminateReadLog();
LABEL_42:
        if ( v46 )
        {
          ClfsTerminateReadLog();
          v46 = 0;
        }
        if ( !ClfsLsnEqual(&v47, v13 + 22) && (a1[15] & 4) != 0 )
        {
          CmpRmRecover(a1, v32, v47, v48);
          a1[15] &= 0xFFFFFFFB;
        }
        v33 = a1[14];
        v62[0] = v13[22];
        v62[1] = v13[23];
        v34 = ClfsWriteRestartArea(v33, v62, 8, 0, 0, &v54, 0);
        v12 = v34;
        if ( !v55 || v34 != -1072037859 && a1[9] <= 0xAu )
          goto LABEL_54;
        v55 = 0;
        if ( v46 )
        {
          ClfsTerminateReadLog();
          v46 = 0;
        }
        ClfsDeleteLogByPointer(a1[13]);
        ClfsDeleteMarshallingArea(a1[14]);
        v35 = a1[13];
        a1[14] = 0;
        ClfsCloseLogFileObject(v35, v36);
        v43 = a1 + 13;
        v42 = a1 + 9;
        v41 = a1 + 10;
        a1[13] = 0;
        a1[9] = 0;
      }
    }
    v3 = v50;
  }
  v2 = v52;
LABEL_62:
  v37 = ExReleaseResourceLite(a1[20]);
  v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v39 = *(_WORD *)(v38 + 0x134) + 1;
  *(_WORD *)(v38 + 308) = v39;
  if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 && !*(_WORD *)(v38 + 310) )
    KiCheckForKernelApcDelivery(v37);
  if ( v2 )
    RtlFreeAnsiString(&v51);
  if ( v3 )
    RtlFreeAnsiString(&v49);
  ExFreePoolWithTag((unsigned int)v13);
  if ( v6 )
    ExFreePoolWithTag(v6);
  return v12;
}

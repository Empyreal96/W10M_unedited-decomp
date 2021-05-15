// NtQueryKey 
 
int __fastcall NtQueryKey(int a1, int a2, _BYTE *a3, unsigned int a4, _DWORD *a5)
{
  int v7; // lr
  __int64 v8; // r0
  int v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  int v15; // r6
  int (__fastcall *v16)(int, _DWORD *, int, int, int, _DWORD, _BYTE); // r5
  char v17; // r3
  unsigned int v18; // r4
  unsigned int v19; // r1
  unsigned int v20; // r1
  int v21; // r3
  int v22; // r5
  int v23; // r2
  _DWORD *v24; // r2
  int v25; // r6
  int v26; // r5
  int v27; // r2
  int v28; // r0
  int v29; // r3
  _DWORD *v30; // r10
  int v31; // r0
  int v32; // r10
  unsigned int v33; // r1
  __int16 v34; // r3
  unsigned int v35; // r1
  unsigned int v36; // r1
  __int16 v37; // r3
  _DWORD *v39; // [sp+4h] [bp-94h]
  __int16 v40; // [sp+8h] [bp-90h]
  int v41; // [sp+Ch] [bp-8Ch]
  int v42; // [sp+Ch] [bp-8Ch]
  _DWORD *v43; // [sp+10h] [bp-88h] BYREF
  _DWORD *v44; // [sp+14h] [bp-84h]
  int v45; // [sp+18h] [bp-80h] BYREF
  _BYTE *v46; // [sp+1Ch] [bp-7Ch]
  unsigned int v47; // [sp+20h] [bp-78h]
  int v48; // [sp+24h] [bp-74h]
  int v49; // [sp+28h] [bp-70h] BYREF
  _DWORD *v50; // [sp+2Ch] [bp-6Ch] BYREF
  int v51; // [sp+30h] [bp-68h]
  int v52; // [sp+34h] [bp-64h]
  _DWORD v53[2]; // [sp+38h] [bp-60h] BYREF
  _DWORD v54[2]; // [sp+40h] [bp-58h] BYREF
  int v55; // [sp+48h] [bp-50h] BYREF
  _DWORD v56[7]; // [sp+4Ch] [bp-4Ch] BYREF
  _DWORD _68[18]; // [sp+68h] [bp-30h] BYREF

  _68[14] = a1;
  _68[16] = a3;
  v47 = a4;
  _68[17] = a4;
  v46 = a3;
  _68[15] = a2;
  v43 = (_DWORD *)a1;
  v54[0] = a3;
  v44 = a5;
  v50 = a5;
  v55 = 0;
  memset(v56, 0, sizeof(v56));
  v45 = 0;
  v49 = 0;
  _68[0] = 0;
  _68[1] = 0;
  _68[2] = 0;
  _68[3] = 0;
  v7 = 0;
  v41 = 0;
  v51 = 0;
  if ( CmpTraceRoutine )
  {
    LODWORD(v8) = _68;
    HIDWORD(v8) = 0x20000;
    EtwGetKernelTraceTimestamp(v8);
    v7 = 0;
  }
  v9 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v9 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v10 = CmpShutdownRundown & 0xFFFFFFFE;
  v11 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v12 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v12 == v10 && __strex(v11, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v12 == v10 )
  {
    v48 = 1;
    LOBYTE(v40) = 1;
  }
  else
  {
    v12 = ExfAcquireRundownProtection(&CmpShutdownRundown);
    v48 = v12;
    LOBYTE(v40) = v12;
    if ( !v12 )
    {
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = *(_WORD *)(v13 + 0x134) + 1;
      *(_WORD *)(v13 + 308) = v14;
      if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
        KiCheckForKernelApcDelivery(0);
      v15 = -1073741431;
      goto LABEL_85;
    }
    v7 = 0;
  }
  if ( !a2 || a2 == 1 || a2 == 2 || a2 == 3 || a2 == 4 || a2 == 5 || a2 == 6 || a2 == 7 || a2 == 8 )
  {
    v22 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    HIBYTE(v40) = v22;
    if ( v22 == 1 )
    {
      if ( a2 == 3 )
      {
LABEL_44:
        v23 = 4;
      }
      else
      {
        switch ( a2 )
        {
          case 0:
          case 1:
          case 2:
          case 4:
            v23 = 8;
            break;
          default:
            goto LABEL_44;
        }
      }
      ProbeForWrite((unsigned int)v46, v47, v23);
      v24 = a5;
      if ( (unsigned int)a5 >= MmUserProbeAddress )
        v24 = (_DWORD *)MmUserProbeAddress;
      *v24 = *v24;
    }
    v25 = a2 != 3 && a2 != 7;
    v15 = ObReferenceObjectByHandle(a1, v25, (int)CmKeyObjectType, v22, (int)&v50, (int)v54);
    v26 = (int)v50;
    v43 = v50;
    if ( v15 >= 0 )
    {
      v27 = *v50;
      if ( *v50 == 1803104306 )
      {
        if ( CmpTraceRoutine )
        {
          v41 = v50[1];
          v51 = v41;
        }
        if ( a2 == 3 || a2 == 7 )
        {
          if ( !v54[1] )
          {
            v15 = -1073741790;
            goto LABEL_84;
          }
LABEL_67:
          v53[1] = v53;
          v53[0] = v53;
          v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v29 = *(__int16 *)(v28 + 0x134);
          *(_WORD *)(v28 + 0x134) = v29 - 1;
          if ( CmpCallBackCount )
          {
            v28 = ExIsResourceAcquiredSharedLite(
                    (int)&CmpRegistryLock,
                    (int)&CmpCallBackCount,
                    v29 - 1,
                    CmpCallBackCount);
            v30 = v44;
            if ( !v28 )
            {
              v55 = v26;
              v56[0] = a2;
              v56[1] = v46;
              v56[2] = v47;
              v56[3] = v44;
              v28 = CmpCallCallBacks(7, &v55, 1, 22, v26, v53);
              v15 = v28;
            }
          }
          else
          {
            v30 = v44;
          }
          if ( v15 < 0 )
          {
            v32 = v45;
            if ( v15 == -1073740541 )
              v15 = 0;
          }
          else
          {
            v31 = CmKeyBodyRemapToVirtualForEnum((int)&v43, &v49);
            v26 = (int)v43;
            if ( v31 < 0 )
            {
              v32 = v49;
            }
            else
            {
              v39 = v30;
              v32 = v49;
              v31 = CmQueryKey(v43, v49, a2, v46, v47, v39, v40);
            }
            v28 = CmPostCallbackNotification(22, v26, v31, &v55, v53);
            v15 = v28;
          }
          v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v34 = *(_WORD *)(v33 + 0x134) + 1;
          *(_WORD *)(v33 + 308) = v34;
          if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
            KiCheckForKernelApcDelivery(v28);
          if ( v32 )
            ObfDereferenceObject(v32);
          goto LABEL_84;
        }
        if ( a2 != 4 )
          goto LABEL_67;
      }
      else if ( a2 != 4 )
      {
        v15 = -1073741816;
LABEL_84:
        ObfDereferenceObject(v26);
        goto LABEL_85;
      }
      if ( v27 != 1803104306 )
      {
        *v44 = 40;
        if ( v47 >= 0x28 )
        {
          memset(v46, 0, 40);
          *((_DWORD *)v46 + 5) = *(_DWORD *)(*(_DWORD *)(v26 + 4) + 52);
        }
        else
        {
          v15 = -1073741789;
          v52 = -1073741789;
        }
        goto LABEL_84;
      }
      goto LABEL_67;
    }
LABEL_85:
    if ( CmpTraceRoutine )
      CmpTraceRoutine(13, _68, v15, a2, v41, 0);
    if ( v48 )
    {
      __pld(&CmpShutdownRundown);
      v12 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v35 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v35 == v12 && __strex(v12 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v35 != v12 )
        v12 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v37 = *(_WORD *)(v36 + 0x134) + 1;
      *(_WORD *)(v36 + 308) = v37;
      if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
        goto LABEL_96;
    }
    return v15;
  }
  v16 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD, _BYTE))CmpTraceRoutine;
  if ( CmpTraceRoutine && a1 )
  {
    v17 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v12 = ObReferenceObjectByHandle(a1, 0, (int)CmKeyObjectType, v17, (int)&v45, 0);
    if ( v12 < 0 )
    {
      v16 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD, _BYTE))CmpTraceRoutine;
      v7 = 0;
    }
    else
    {
      v42 = *(_DWORD *)(v45 + 4);
      v12 = ObfDereferenceObject(v45);
      v16 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD, _BYTE))CmpTraceRoutine;
      v7 = v42;
    }
  }
  v15 = -1073741811;
  if ( v16 )
    v12 = v16(13, _68, -1073741811, a2, v7, 0, v40);
  __pld(&CmpShutdownRundown);
  v18 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v19 == v18 && __strex(v18 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v19 != v18 )
    v12 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = (__int16)(*(_WORD *)(v20 + 0x134) + 1);
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
LABEL_96:
    KiCheckForKernelApcDelivery(v12);
  return v15;
}

// EtwpEnableGuid 
 
int __fastcall EtwpEnableGuid(int a1, char a2)
{
  int v2; // r6
  int v3; // r4
  _DWORD *v5; // r9
  int v6; // r8
  int v7; // r8
  int v8; // r5
  int v9; // r0
  _DWORD *v10; // r10
  int v11; // r0
  int v12; // r3
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v18; // r0
  int v19; // r5
  int v21; // r8
  __int16 v22; // r2
  __int64 v23; // kr08_8
  int v24; // r4
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // r1
  int v29; // r2
  int v30; // r3
  _DWORD *v31; // r4
  _DWORD *v32; // r3
  int v33; // r5
  int *v34; // r6
  int v35; // r5
  unsigned int v36; // r0
  unsigned int v37; // t1
  int *v38; // r5
  int v39; // r6
  unsigned int v40; // r0
  int v41; // r0
  int v42; // r0
  int v43; // r0
  unsigned __int8 v44; // r1
  int v45; // r2
  int v46; // r10
  int v47; // r3
  int v48; // r4
  int v49; // r6
  _DWORD *v50; // r9
  int v51; // r5
  int v52; // r4
  int v53; // r8
  int v54; // r0
  int v55; // r3
  int v56; // r2
  int *v57; // r5
  __int64 v58; // kr10_8
  _DWORD *v59; // r4
  unsigned int v60; // r0
  unsigned int v61; // r1
  int v62; // r0
  int v63; // r3
  _DWORD *v64; // r0
  unsigned int v65; // r4
  unsigned int v66; // r1
  int v67; // r4
  int v68; // r2
  int v69; // r3
  unsigned int v70; // r2
  unsigned int v71; // kr04_4
  unsigned int *v72; // r2
  unsigned int v73; // r0
  int v74; // r0
  int v75; // r2
  int v76; // r3
  char v77[4]; // [sp+10h] [bp-B0h] BYREF
  int v78; // [sp+14h] [bp-ACh]
  _DWORD *v79; // [sp+18h] [bp-A8h] BYREF
  _DWORD *v80; // [sp+1Ch] [bp-A4h] BYREF
  char v81[4]; // [sp+20h] [bp-A0h] BYREF
  _DWORD *v82; // [sp+24h] [bp-9Ch] BYREF
  int v83; // [sp+28h] [bp-98h]
  _DWORD *v84; // [sp+2Ch] [bp-94h] BYREF
  int v85; // [sp+30h] [bp-90h]
  _DWORD *v86; // [sp+34h] [bp-8Ch]
  int v87; // [sp+38h] [bp-88h]
  int v88; // [sp+3Ch] [bp-84h]
  int v89; // [sp+40h] [bp-80h] BYREF
  _DWORD *v90; // [sp+44h] [bp-7Ch]
  int v91; // [sp+48h] [bp-78h]
  _DWORD *v92; // [sp+4Ch] [bp-74h]
  int v93; // [sp+50h] [bp-70h]
  _DWORD *v94; // [sp+54h] [bp-6Ch]
  int v95[6]; // [sp+58h] [bp-68h] BYREF
  unsigned __int64 v96; // [sp+70h] [bp-50h] BYREF
  int v97; // [sp+78h] [bp-48h]
  int v98; // [sp+7Ch] [bp-44h]
  char v99[56]; // [sp+88h] [bp-38h] BYREF

  v89 = 0;
  v86 = 0;
  v79 = 0;
  v93 = a1 + 40;
  v2 = a1 + 72;
  v87 = 0;
  v88 = 0;
  v91 = 0;
  v85 = 0;
  v77[0] = 0;
  v3 = a2;
  v5 = 0;
  if ( (*(_DWORD *)(a1 + 80) & 0x20) != 0 )
    v6 = 2;
  else
    v6 = 0;
  v78 = v6;
  memset(v95, 0, sizeof(v95));
  memset(v99, 0, 20);
  v7 = 0;
  v8 = 0;
  v80 = 0;
  v82 = 0;
  v9 = EtwpValidateEnableNotification(a1, v3, v99, &v84, v95);
  v10 = v84;
  if ( v9 < 0 )
    goto LABEL_138;
  v11 = *(_DWORD *)v2;
  v12 = *(_DWORD *)(a1 + 116);
  v83 = *(_DWORD *)v2;
  if ( v12 )
  {
    v70 = *(_DWORD *)(a1 + 124);
    v98 = *(_DWORD *)(a1 + 132);
    v97 = *(_DWORD *)(a1 + 128);
    v71 = *(_DWORD *)(a1 + 120);
    v96 = __PAIR64__(v70, v71) + (unsigned int)a1;
  }
  else
  {
    v98 = 0;
  }
  v13 = v78;
  if ( !v78 )
  {
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v14 + 308);
    v15 = EtwpEnableDisableSpecialGuids(a1 + 40, *(unsigned __int16 *)(v2 + 6), v11, *(_DWORD *)(v2 + 16), &v96, v81);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
    if ( !v81[0] )
    {
      v13 = v78;
      goto LABEL_11;
    }
LABEL_138:
    JUMPOUT(0x807B86);
  }
LABEL_11:
  if ( !*(_WORD *)(v2 + 6) || *(_WORD *)(v2 + 6) == 2 )
  {
    v24 = -1073741790;
    goto LABEL_87;
  }
  *(_DWORD *)(a1 + 36) = PsGetCurrentThreadProcessId();
  v18 = EtwpFindGuidEntryByGuid(a1 + 40, v13);
  v19 = (unsigned __int8)v99[18];
  v5 = (_DWORD *)v18;
  v90 = (_DWORD *)v18;
  if ( v18 )
  {
    v21 = v83;
  }
  else
  {
    if ( v99[18] )
      return sub_807B80();
    v21 = v83;
    if ( v83 != 1 )
      return sub_807B80();
    v5 = (_DWORD *)EtwpAddGuidEntry(a1 + 40, v13);
    v90 = v5;
    if ( !v5 )
      JUMPOUT(0x807B84);
  }
  KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  v88 = 1;
  if ( v10 && (v10[152] & 0x40) != 0 )
  {
    v24 = -1073741162;
    goto LABEL_34;
  }
  if ( v13 == 2 )
  {
    v24 = EtwpAcquireTokenAccessInformation(v10);
    if ( v24 )
      goto LABEL_34;
  }
  *(_DWORD *)(a1 + 112) = v21;
  v22 = *(_WORD *)(v2 + 6);
  *(_WORD *)(a1 + 104) = v22;
  *(_BYTE *)(a1 + 106) = *(_BYTE *)(v2 + 4);
  *(_DWORD *)(a1 + 108) = *(_DWORD *)(v2 + 16);
  v23 = *(_QWORD *)(v2 + 16);
  if ( v19 )
  {
    *(_WORD *)(a1 + 104) = v22 & 0x7FFF;
    *(_BYTE *)(a1 + 107) = 1;
  }
  if ( !*(_QWORD *)(v2 + 16) )
  {
    *(_DWORD *)(v2 + 16) = -1;
    *(_DWORD *)(v2 + 20) = -1;
  }
  if ( !*(_BYTE *)(v2 + 4) )
    *(_BYTE *)(v2 + 4) = -1;
  if ( v21 == 2 || v19 )
  {
LABEL_32:
    v31 = v5 + 7;
    v32 = (_DWORD *)v5[7];
    v92 = v5 + 7;
    if ( v32 == v5 + 7 )
    {
      v24 = 0;
      goto LABEL_34;
    }
    if ( *(_BYTE *)(a1 + 12) )
    {
      v24 = EtwpCreateUmReplyObject(v5, &v89, &v79);
      if ( v24 < 0 )
      {
        v33 = (int)v79;
        goto LABEL_35;
      }
      v31 = v5 + 7;
      v86 = v79;
      *(_DWORD *)(a1 + 24) = v79;
    }
    v41 = EtwpBuildNotificationPacket((int)v5, a1, 255, &v82);
    v8 = (int)v82;
    if ( v41 < 0 )
    {
      v24 = -1073741801;
      goto LABEL_89;
    }
    v42 = v82[1];
    v79 = v82;
    v43 = EtwpAllocDataBlock(v42, v82, &v80);
    v7 = (int)v80;
    if ( v43 < 0 )
    {
      v24 = -1073741801;
    }
    else
    {
      v44 = 0;
      v45 = 0;
      v46 = 0;
      v82 = v80;
      do
      {
        if ( v5[8 * v45 + 22] )
          v46 = (unsigned __int8)((1 << v45) | v46);
        v45 = ++v44;
      }
      while ( v44 < 8u );
      v47 = v5[7];
      v91 = v46;
      v10 = v84;
      v94 = (_DWORD *)v47;
      if ( (_DWORD *)v47 != v31 )
      {
        v48 = v78;
        v49 = (int)v79;
        v50 = v94;
        while ( 1 )
        {
          if ( v48 )
            v51 = (int)(v50 - 2);
          else
            v51 = (int)v50;
          v50 = (_DWORD *)*v50;
          if ( !EtwpIsRegEntryAllowed(v51, v10, v99, a1, v95, v48) )
            goto LABEL_79;
          v84 = (_DWORD *)v49;
          if ( v99[18] )
            goto LABEL_76;
          if ( v83 == 2 )
            break;
          if ( v48 )
            v52 = *(unsigned __int8 *)(v51 + 52);
          else
            v52 = *(unsigned __int8 *)(v51 + 51);
          v53 = v78;
          EtwpUpdateRegEntryEnableMask(v51, v85, v78);
          v54 = EtwpCalculateUpdateNotification(v51, v85, v52, v91, v53, v83, &v80);
          v7 = (int)v80;
          if ( v54 )
          {
            if ( v80 )
            {
              v84 = v80;
              if ( v80 != v82 )
              {
                EtwpUnreferenceDataBlock(v82);
                v82 = (_DWORD *)v7;
              }
            }
            else
            {
              v7 = (int)v82;
              v80 = v82;
            }
            if ( v83 == 1 )
              goto LABEL_74;
            goto LABEL_76;
          }
LABEL_126:
          v48 = v78;
LABEL_79:
          if ( v50 == v92 )
          {
            v5 = v90;
            v8 = (int)v79;
            goto LABEL_81;
          }
        }
        if ( !EtwpIsCaptureStateAllowed(v51, a1, v95) )
          goto LABEL_79;
LABEL_74:
        v55 = *(unsigned __int8 *)(v51 + 50);
        if ( (v55 & 8) != 0 || (v55 & 0x20) != 0 )
        {
          if ( (v55 & 1) != 0 )
          {
            v67 = 0;
            if ( (v55 & 0x10) == 0 )
              goto LABEL_108;
            v74 = MmGetSessionById(*(_DWORD *)(v51 + 28), 1, (v55 & 1) != 0, v55);
            v67 = v74;
            if ( !v74 )
              goto LABEL_76;
            if ( MmAttachSession(v74, (int)&v96, v75, v76) >= 0 )
            {
LABEL_108:
              EtwpProviderArrivalCallback((int)v10, 0, v51, v55);
              if ( !v67 )
                goto LABEL_76;
              MmDetachSession(v67, (int)&v96, v68, v69);
            }
            MmQuitNextSession(v67);
          }
          else
          {
            v59 = (_DWORD *)(*(_DWORD *)(v51 + 40) + 172);
            __pld(v59);
            v60 = *v59 & 0xFFFFFFFE;
            do
              v61 = __ldrex(v59);
            while ( v61 == v60 && __strex(v60 + 2, v59) );
            __dmb(0xBu);
            if ( v61 == v60 )
              v62 = 1;
            else
              v62 = ExfAcquireRundownProtection(v59);
            if ( v62 )
            {
              KiStackAttachProcess(*(_DWORD *)(v51 + 40), 0, (int)&v96);
              EtwpProviderArrivalCallback((int)v10, 1, v51, v63);
              KiUnstackDetachProcess((unsigned int)&v96, 0);
              v64 = (_DWORD *)(*(_DWORD *)(v51 + 40) + 172);
              __pld(v64);
              v65 = *v64 & 0xFFFFFFFE;
              __dmb(0xBu);
              do
                v66 = __ldrex(v64);
              while ( v66 == v65 && __strex(v65 - 2, v64) );
              if ( v66 != v65 )
                ExfReleaseRundownProtection((unsigned __int8 *)v64);
            }
          }
        }
LABEL_76:
        if ( EtwpSendDataBlock(v51, v84) >= 0 )
        {
          v48 = v78;
          if ( (*(_BYTE *)(v51 + 50) & 2) != 0 )
            ++v87;
          goto LABEL_79;
        }
        goto LABEL_126;
      }
LABEL_81:
      v56 = v89;
      v24 = 0;
      *(_DWORD *)(a1 + 20) = v87;
      *(_QWORD *)(a1 + 24) = v56;
      if ( !v10 )
        goto LABEL_87;
      if ( v83 == 1 )
      {
        v57 = ETW_EVENT_PROVIDER_ENABLED;
LABEL_84:
        v58 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
        if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)v57) )
          EtwpEventWriteTemplateSessAndProv(v58, HIDWORD(v58), v57);
        v8 = (int)v79;
        goto LABEL_87;
      }
      if ( !v83 )
      {
        v57 = ETW_EVENT_PROVIDER_DISABLED;
        goto LABEL_84;
      }
    }
LABEL_87:
    if ( v7 )
      EtwpUnreferenceDataBlock(v7);
LABEL_89:
    if ( v8 )
      EtwpUnreferenceDataBlock(v8);
    v33 = (int)v86;
    if ( v88 != 1 )
      goto LABEL_36;
    goto LABEL_35;
  }
  v24 = EtwpUpdateGuidEnableInfo(v5, a1, v23, HIDWORD(v23), v95, v77);
  if ( v24 >= 0 )
  {
    v25 = v5[15];
    v26 = v5[16];
    v27 = v5[17];
    *(_DWORD *)v2 = v5[14];
    *(_DWORD *)(v2 + 4) = v25;
    *(_DWORD *)(v2 + 8) = v26;
    *(_DWORD *)(v2 + 12) = v27;
    v28 = v5[19];
    v29 = v5[20];
    v30 = v5[21];
    *(_DWORD *)(v2 + 16) = v5[18];
    *(_DWORD *)(v2 + 20) = v28;
    *(_DWORD *)(v2 + 24) = v29;
    *(_DWORD *)(v2 + 28) = v30;
    if ( (*(_DWORD *)(v2 + 8) & 4) == 0 )
      goto LABEL_31;
    __dmb(0xBu);
    v72 = v10 + 152;
    do
      v73 = __ldrex(v72);
    while ( __strex(v73 | 0x2000, v72) );
    __dmb(0xBu);
    if ( (v73 & 0x2000) != 0 )
    {
LABEL_31:
      v85 = (unsigned __int8)v77[0];
    }
    else
    {
      EtwpReferenceStackLookasideList();
      v85 = (unsigned __int8)v77[0];
    }
    goto LABEL_32;
  }
LABEL_34:
  v33 = 0;
LABEL_35:
  KeReleaseMutex((int)&EtwpNotificationMutex);
LABEL_36:
  if ( v10 )
    EtwpReleaseLoggerContext(v10, 0);
  if ( v33 )
    ObfDereferenceObject(v33);
  if ( v5 )
    EtwpUnreferenceGuidEntry((int)v5);
  v34 = v95;
  v35 = 3;
  do
  {
    v37 = *v34++;
    v36 = v37;
    if ( v37 )
      ExFreePoolWithTag(v36);
    --v35;
  }
  while ( v35 );
  v38 = v95;
  v39 = 2;
  do
  {
    v40 = v38[3];
    if ( v40 )
      ExFreePoolWithTag(v40);
    ++v38;
    --v39;
  }
  while ( v39 );
  if ( v95[5] )
    ExFreePoolWithTag(v95[5]);
  return v24;
}

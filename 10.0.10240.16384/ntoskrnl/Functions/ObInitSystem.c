// ObInitSystem 
 
int ObInitSystem()
{
  int v1; // r3
  _DWORD *v2; // r0
  _DWORD *v3; // r2
  int v4; // r3
  int v5; // r4
  void **v6; // r5
  _DWORD *v7; // t1
  char *v8; // r5
  unsigned int i; // r4
  int *v10; // r4
  int v11; // r6
  int v12; // r0
  int v13; // r6
  int v14; // r0
  int v15; // r4
  bool v16; // nf
  unsigned int v17; // r0
  int v18; // r0
  int v19; // r7
  _BYTE *v20; // r4
  unsigned int v21; // r1
  int v22; // r1
  int v23; // r2
  int v24; // r5
  unsigned int v25; // r2
  unsigned __int8 *v26; // r7
  int v27; // r0
  int v28; // r4
  unsigned int v29; // r2
  int v30; // r2
  unsigned int *v31; // r4
  int v32; // r1
  unsigned int v33; // r0
  unsigned int v34; // r2
  int v35; // r0
  unsigned int v36; // r4
  int v37; // r3
  int v38; // [sp+10h] [bp-238h]
  int v39; // [sp+30h] [bp-218h]
  int v40; // [sp+34h] [bp-214h] BYREF
  int v41; // [sp+38h] [bp-210h] BYREF
  int v42; // [sp+3Ch] [bp-20Ch] BYREF
  char v43[8]; // [sp+40h] [bp-208h] BYREF
  int v44; // [sp+48h] [bp-200h] BYREF
  int v45; // [sp+4Ch] [bp-1FCh]
  char v46; // [sp+5Ah] [bp-1EEh]
  char v47; // [sp+5Bh] [bp-1EDh]
  int v48; // [sp+5Ch] [bp-1ECh]
  int v49[22]; // [sp+60h] [bp-1E8h] BYREF
  int v50[6]; // [sp+B8h] [bp-190h] BYREF
  char v51[8]; // [sp+D0h] [bp-178h] BYREF
  void *v52; // [sp+D8h] [bp-170h]
  char v53[8]; // [sp+E0h] [bp-168h] BYREF
  char v54[8]; // [sp+E8h] [bp-160h] BYREF
  char v55[8]; // [sp+F0h] [bp-158h] BYREF
  char v56[24]; // [sp+F8h] [bp-150h] BYREF
  char v57[24]; // [sp+110h] [bp-138h] BYREF
  unsigned __int8 v58[288]; // [sp+128h] [bp-120h] BYREF

  if ( (_BYTE)dword_681280 )
    return sub_965FA4();
  v1 = InitializationPhase;
  if ( !InitializationPhase )
  {
    ObHeaderCookie = ExGenRandom(0);
    ExInitializeSystemLookasideList(
      (int)&ObpCreateInfoLookasideList,
      512,
      44,
      1766023759,
      32,
      (int)&ExSystemLookasideListHead);
    v2 = ExInitializeSystemLookasideList(
           (int)&ObpNameBufferLookasideList,
           1,
           248,
           1833853519,
           16,
           (int)&ExSystemLookasideListHead);
    v3 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
    v3[713] = &ObpCreateInfoLookasideList;
    v3[712] = &ObpCreateInfoLookasideList;
    v3[715] = &ObpNameBufferLookasideList;
    v3[714] = &ObpNameBufferLookasideList;
    ObpRemoveObjectList = 0;
    ObpRemoveObjectWait = 0;
    if ( ObpInitSecurityDescriptorCache(v2) < 0 )
      return 0;
    ObpDefaultObject = 0;
    byte_61FAB1 = 0;
    byte_61FAB2 = 4;
    dword_61FAB4 = 1;
    dword_61FABC = (int)&dword_61FAB8;
    dword_61FAB8 = (int)&dword_61FAB8;
    ObpKernelHandleTable = ExCreateHandleTable(0, 1);
    v4 = __mrc(15, 0, 13, 0, 3);
    *(_DWORD *)(*(_DWORD *)((v4 & 0xFFFFFFC0) + 0x74) + 336) = ObpKernelHandleTable;
    if ( !ObpKernelHandleTable )
      return 0;
    dword_61FAD8 = (int)ObpProcessRemoveObjectQueue;
    dword_61FADC = 0;
    ObpRemoveObjectWorkItem = 0;
    ObpRemoveObjectDpc = 19;
    byte_61FAE1 = 1;
    word_61FAE2 = 0;
    dword_61FAEC = (int)ObpProcessRemoveObjectDpcWorker;
    dword_61FAF0 = 0;
    dword_61FAFC = 0;
    dword_61FAE8 = 0;
    ObpInitInfoBlockOffsets();
    dword_6820EC = MmBadPointer;
    memset(v49, 0, sizeof(v49));
    LOWORD(v49[0]) = 88;
    v49[2] = 256;
    v49[9] = 512;
    RtlInitUnicodeString((unsigned int)v53, L"Type");
    v49[7] = 983041;
    v49[3] = 0x20000;
    v49[4] = 0x20000;
    v49[5] = 0x20000;
    v49[6] = 983041;
    v49[11] = 144;
    BYTE2(v49[0]) |= 0x24u;
    if ( ObCreateObjectType() < 0 )
      return 0;
    v49[9] = 1;
    RtlInitUnicodeString((unsigned int)v51, L"Directory");
    v49[11] = 172;
    v49[7] = 983055;
    BYTE2(v49[0]) |= 1u;
    v49[3] = 131075;
    v49[4] = 131084;
    v49[5] = 131075;
    v49[6] = 983055;
    BYTE2(v49[0]) = BYTE2(v49[0]) & 0xD3 | 0xC;
    v49[14] = (int)ObpCloseDirectoryObject;
    v49[15] = (int)ObpDeleteDirectoryObject;
    if ( ObCreateObjectType() < 0 )
      return 0;
    v49[14] = 0;
    *(_DWORD *)(ObpDirectoryObjectType + 68) &= 0xFFEFFFFF;
    RtlInitUnicodeString((unsigned int)v55, L"SymbolicLink");
    v49[11] = 24;
    v49[9] = 1;
    v49[7] = 0xFFFFF;
    BYTE2(v49[0]) |= 1u;
    v49[3] = 131073;
    v49[4] = 0x20000;
    v49[5] = 131073;
    v49[6] = 983041;
    v49[15] = (int)ObpDeleteSymbolicLink;
    v49[16] = (int)ObpParseSymbolicLink;
    BYTE2(v49[0]) &= 0xF7u;
    if ( ObCreateObjectType() < 0 )
      return 0;
    *(_DWORD *)(ObpSymbolicLinkObjectType + 68) &= 0xFFEFFFFF;
    ObpInitializeNamespaceTable();
    ObpInitStackTrace();
    v1 = InitializationPhase;
  }
  if ( v1 != 1 )
    return 1;
  memset(v50, 0, sizeof(v50));
  LOWORD(v50[0]) = 1;
  HIWORD(v50[0]) |= 1u;
  v50[1] = (int)ObInitServerSilo;
  v50[2] = (int)AlpcMessageDeleteProcedure;
  PsRegisterMonitorServerSilo(0, L"NTOS_OB", (unsigned __int16 *)v50, (unsigned int *)&ObSiloMonitor);
  PsStartMonitorServerSilo((_DWORD *)ObSiloMonitor);
  v5 = 0;
  if ( KeNumberProcessors_0 )
  {
    v6 = &KiProcessorBlock;
    do
    {
      v7 = *v6++;
      if ( ObInitializeProcessor(v7) < 0 )
        return 0;
    }
    while ( ++v5 < (unsigned int)KeNumberProcessors_0 );
  }
  v8 = (char *)&ObpWaitBlockLookaside;
  for ( i = 24; i < 0x50; i += 14 )
  {
    ExInitializeNPagedLookasideList((int)v8, 0, 0, 512);
    v8 += 128;
  }
  if ( ObpAuditBaseDirectories || ObpAuditBaseObjects )
  {
    v20 = (_BYTE *)SeWorldSid;
    v21 = 4 * (*(unsigned __int8 *)(SeWorldSid + 1) + 7);
    if ( v21 >= 0xFA
      || RtlCreateAcl((int)v58, v21, 2) < 0
      || RtlAddAuditAccessAce(v58, v22, 1610612736, v20) < 0
      || RtlGetAce(v58, 0, (int)&v41) < 0 )
    {
      return 0;
    }
    v23 = v41;
    if ( ObpAuditBaseDirectories )
      *(_BYTE *)(v41 + 1) |= 0xAu;
    if ( ObpAuditBaseObjects )
      *(_BYTE *)(v23 + 1) |= 9u;
    if ( RtlCreateSecurityDescriptor(v56, 1) < 0
      || RtlSetDaclSecurityDescriptor((int)v56, 1, SePublicDefaultUnrestrictedDacl, 0) < 0
      || RtlSetSaclSecurityDescriptor((int)v56, 1, (int)v58, 0) < 0 )
    {
      return 0;
    }
  }
  RtlInitUnicodeString((unsigned int)v54, L"\\");
  if ( NtCreateDirectoryObject() < 0 )
    return 0;
  v12 = ObReferenceObjectByHandle(v39, 0, ObpDirectoryObjectType, 0, (int)&v42, 0);
  ObpRootDirectoryObject = v42;
  if ( v12 < 0 )
    return 0;
  if ( NtClose() < 0 )
    return 0;
  if ( RtlCreateSecurityDescriptor(v57, 1) < 0 )
    return 0;
  v13 = *(unsigned __int8 *)(SeLocalSystemSid + 1)
      + *(unsigned __int8 *)(SeWorldSid + 1)
      + *(unsigned __int8 *)(SeAliasAdminsSid + 1)
      + 17;
  v14 = ExAllocatePoolWithTag(1, 4 * v13, 1818452292);
  v15 = v14;
  if ( !v14 )
    return 0;
  v16 = RtlCreateAcl(v14, 4 * v13, 2) < 0;
  v17 = v15;
  if ( v16
    || (v16 = RtlAddAccessAllowedAce(v15, 2, 131075, SeWorldSid) < 0, v17 = v15, v16)
    || (v16 = RtlAddAccessAllowedAce(v15, 2, 983055, SeAliasAdminsSid) < 0, v17 = v15, v16) )
  {
LABEL_61:
    ExFreePoolWithTag(v17);
    return 0;
  }
  if ( RtlAddAccessAllowedAce(v15, 2, 983055, SeLocalSystemSid) < 0
    || RtlSetDaclSecurityDescriptor((int)v57, 1, v15, 0) < 0 )
  {
    v17 = v15;
    goto LABEL_61;
  }
  RtlInitUnicodeString((unsigned int)v43, L"\\KernelObjects");
  if ( NtCreateDirectoryObject() < 0 )
    return 0;
  if ( NtClose() < 0 )
    return 0;
  RtlInitUnicodeString((unsigned int)v43, L"\\ObjectTypes");
  if ( NtCreateDirectoryObject() < 0 )
    return 0;
  v18 = ObReferenceObjectByHandle(v38, 0, ObpDirectoryObjectType, 0, (int)&v40, 0);
  ObpTypeDirectoryObject = v40;
  if ( v18 < 0 || NtClose() < 0 )
    return 0;
  v11 = 0;
  v24 = ObpTypeDirectoryObject;
  v45 = 0;
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v25 + 308);
  v26 = (unsigned __int8 *)(v24 + 148);
  v27 = KeAbPreAcquire(v24 + 148, 0, 0);
  v28 = v27;
  do
    v29 = __ldrex(v26);
  while ( __strex(v29 | 1, v26) );
  __dmb(0xBu);
  if ( (v29 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v24 + 148), v27, v24 + 148);
  if ( v28 )
    *(_BYTE *)(v28 + 14) |= 1u;
  v48 = -859041228;
  ObfReferenceObjectWithTag(v24);
  v46 = 1;
  v47 = 1;
  v44 = v24;
  v19 = ObpTypeObjectType;
  v10 = *(int **)ObpTypeObjectType;
  if ( *(_DWORD *)ObpTypeObjectType != ObpTypeObjectType )
  {
    while ( 1 )
    {
      v30 = (int)((*((_BYTE *)v10 + 30) & 2) != 0 ? (int *)((char *)v10
                                                          - ObpInfoMaskToOffset[*((_BYTE *)v10 + 30) & 3]
                                                          + 16) : 0);
      if ( v30
        && !*(_DWORD *)v30
        && !ObpLookupDirectoryEntry(ObpTypeDirectoryObject, (unsigned __int16 *)(v30 + 4), 64, 0, (int)&v44)
        && !ObpInsertDirectoryEntry(ObpTypeDirectoryObject, (int)(v10 + 10), (int)&v44) )
      {
        return 0;
      }
      v10 = (int *)*v10;
      if ( v10 == (int *)v19 )
      {
        v11 = v45;
        if ( !v46 )
          goto LABEL_27;
        v24 = v44;
        break;
      }
    }
  }
  v31 = (unsigned int *)(v24 + 148);
  __pld((void *)(v24 + 148));
  v32 = *(_DWORD *)(v24 + 148);
  if ( (v32 & 0xFFFFFFF0) <= 0x10 )
    v33 = 0;
  else
    v33 = v32 - 16;
  if ( (v32 & 2) != 0 )
    goto LABEL_79;
  __dmb(0xBu);
  do
    v34 = __ldrex(v31);
  while ( v34 == v32 && __strex(v33, v31) );
  if ( v34 != v32 )
LABEL_79:
    ExfReleasePushLock((_DWORD *)(v24 + 148), v32);
  KeAbPostRelease(v24 + 148);
  v35 = ObfDereferenceObjectWithTag(v24);
  v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v37 = (__int16)(*(_WORD *)(v36 + 0x134) + 1);
  *(_WORD *)(v36 + 308) = v37;
  if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
    KiCheckForKernelApcDelivery(v35);
LABEL_27:
  if ( v11 )
    ObfDereferenceObjectWithTag(v11);
  v52 = &ObpLUIDDeviceMapsEnabled;
  return ObpCreateDosDevicesDirectory() >= 0;
}

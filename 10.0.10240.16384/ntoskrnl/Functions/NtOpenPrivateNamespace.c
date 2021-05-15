// NtOpenPrivateNamespace 
 
int __fastcall NtOpenPrivateNamespace(unsigned int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r9
  int v6; // r5
  _DWORD *v7; // r1
  int v8; // r3
  int v9; // r8
  int v10; // r4
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r6
  unsigned int v14; // r1
  int v15; // r6
  int v16; // r1
  int v17; // r0
  unsigned int v18; // r6
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int v22; // r6
  unsigned int v23; // r6
  int v24; // r1
  int v25; // r0
  unsigned int v26; // lr
  int v27; // r0
  unsigned int v28; // r4
  __int16 v29; // r3
  char v31; // [sp+10h] [bp-38h]
  unsigned int v32; // [sp+1Ch] [bp-2Ch] BYREF
  int v33; // [sp+20h] [bp-28h]
  _DWORD _24[15]; // [sp+24h] [bp-24h] BYREF

  _24[13] = a3;
  _24[14] = a4;
  v33 = a2;
  _24[12] = a2;
  v5 = (_DWORD *)a1;
  _24[11] = a1;
  _24[0] = 0;
  v31 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = 0;
  if ( v31 )
  {
    v7 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v7 = (_DWORD *)MmUserProbeAddress;
    *v7 = *v7;
    if ( a3 )
    {
      if ( (a3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v6 = *(_DWORD *)(a3 + 12);
    }
  }
  else if ( a3 )
  {
    v6 = *(_DWORD *)(a3 + 12);
  }
  if ( v31 )
    v8 = 3570;
  else
    v8 = 69618;
  v9 = v6 & v8;
  v10 = ObpCaptureBoundaryDescriptor(a4, &v32);
  if ( v10 >= 0 )
  {
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v11 + 308);
    v12 = KeAbPreAcquire((unsigned int)&dword_620C08, 0, 0);
    v13 = v12;
    do
      v14 = __ldrex((unsigned __int8 *)&dword_620C08);
    while ( __strex(v14 | 1, (unsigned __int8 *)&dword_620C08) );
    __dmb(0xBu);
    if ( (v14 & 1) != 0 )
      v12 = ExfAcquirePushLockExclusiveEx(&dword_620C08, v12, (unsigned int)&dword_620C08);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    v15 = ObpLookupNamespaceEntry(v12, v32);
    ExFreePoolWithTag(v32);
    if ( !v15 )
    {
      __pld(&dword_620C08);
      v17 = dword_620C08;
      if ( (dword_620C08 & 0xFFFFFFF0) <= 0x10 )
        v18 = 0;
      else
        v18 = dword_620C08 - 16;
      if ( (dword_620C08 & 2) == 0 )
      {
        __dmb(0xBu);
        do
          v16 = __ldrex((unsigned int *)&dword_620C08);
        while ( v16 == v17 && __strex(v18, (unsigned int *)&dword_620C08) );
        goto LABEL_29;
      }
      goto LABEL_30;
    }
    v22 = *(_DWORD *)(v15 + 8);
    if ( !v22 )
    {
      __pld(&dword_620C08);
      v17 = dword_620C08;
      if ( (dword_620C08 & 0xFFFFFFF0) <= 0x10 )
        v23 = 0;
      else
        v23 = dword_620C08 - 16;
      if ( (dword_620C08 & 2) == 0 )
      {
        __dmb(0xBu);
        do
          v16 = __ldrex((unsigned int *)&dword_620C08);
        while ( v16 == v17 && __strex(v23, (unsigned int *)&dword_620C08) );
LABEL_29:
        if ( v16 == v17 )
          goto LABEL_31;
      }
LABEL_30:
      ExfReleasePushLock(&dword_620C08, v16);
LABEL_31:
      v19 = KeAbPostRelease((unsigned int)&dword_620C08);
      v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v21 = *(_WORD *)(v20 + 0x134) + 1;
      *(_WORD *)(v20 + 308) = v21;
      if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
        KiCheckForKernelApcDelivery(v19);
      return -1073741766;
    }
    ObfReferenceObject(v22);
    __pld(&dword_620C08);
    v25 = dword_620C08;
    if ( (dword_620C08 & 0xFFFFFFF0) <= 0x10 )
      v26 = 0;
    else
      v26 = dword_620C08 - 16;
    if ( (dword_620C08 & 2) != 0 )
      goto LABEL_53;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)&dword_620C08);
    while ( v24 == v25 && __strex(v26, (unsigned int *)&dword_620C08) );
    if ( v24 != v25 )
LABEL_53:
      ExfReleasePushLock(&dword_620C08, v24);
    v27 = KeAbPostRelease((unsigned int)&dword_620C08);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = *(_WORD *)(v28 + 0x134) + 1;
    *(_WORD *)(v28 + 308) = v29;
    if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
      KiCheckForKernelApcDelivery(v27);
    v10 = ObOpenObjectByPointer(v22, v9, 0, v33, ObpDirectoryObjectType, v31, _24);
    v33 = v10;
    ObfDereferenceObject(v22);
    *v5 = _24[0];
  }
  return v10;
}

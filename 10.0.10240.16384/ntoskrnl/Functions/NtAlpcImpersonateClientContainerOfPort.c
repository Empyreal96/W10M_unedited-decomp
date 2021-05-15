// NtAlpcImpersonateClientContainerOfPort 
 
int __fastcall NtAlpcImpersonateClientContainerOfPort(int a1, int *a2)
{
  unsigned int v3; // r2
  int v4; // r4
  int v5; // r0
  int v6; // r5
  _DWORD *v7; // r6
  int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int *v12; // r8
  int v13; // r3
  _DWORD *v14; // r4
  int v15; // r9
  unsigned int *v16; // r8
  unsigned int v17; // r1
  unsigned int *v18; // r2
  unsigned int v19; // r0
  int v20; // r0
  int v21; // r10
  unsigned int *v22; // r9
  unsigned int v23; // r1
  unsigned int *v24; // r2
  unsigned int v25; // r0
  int v26; // r10
  unsigned int *v27; // r9
  unsigned int v28; // r1
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int v31; // r0
  int v32; // r4
  int v33; // r0
  unsigned int v34; // r1
  __int16 v35; // r3
  _DWORD *v37[2]; // [sp+8h] [bp-40h] BYREF
  _DWORD v38[4]; // [sp+10h] [bp-38h] BYREF
  int v39; // [sp+20h] [bp-28h]
  int v40; // [sp+24h] [bp-24h]

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v5 = ObReferenceObjectByHandle(a1, 0x20000, AlpcPortObjectType, v4, (int)v37, 0);
  v6 = v5;
  v7 = v37[0];
  if ( v5 < 0 )
    goto LABEL_67;
  if ( (v37[0][61] & 6) != 6 || *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != v7[3] )
    goto LABEL_66;
  if ( v4 )
  {
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      a2 = (int *)MmUserProbeAddress;
    memmove((int)v38, (int)a2, 0x18u);
  }
  else
  {
    v8 = *a2;
    v9 = a2[1];
    v10 = a2[2];
    v11 = a2[3];
    v12 = a2 + 4;
    v38[0] = v8;
    v38[1] = v9;
    v38[2] = v10;
    v38[3] = v11;
    v13 = v12[1];
    v39 = *v12;
    v40 = v13;
  }
  v5 = AlpcpLookupMessage((int)v7, v39, v40, v37);
  v6 = v5;
  if ( v5 >= 0 )
  {
    v14 = v37[0];
    if ( (v37[0][5] & 0x80) != 0 )
    {
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v37[0]);
      v15 = 0;
      if ( (*(_BYTE *)(v14 - 4) & 1) != 0 )
      {
        v15 = 0x10000 - *((__int16 *)v14 - 7);
        *((_BYTE *)v14 - 16) &= 0xFEu;
        *((_WORD *)v14 - 7) = 0;
      }
      v16 = v14 - 1;
      __dmb(0xBu);
      do
        v17 = __ldrex(v16);
      while ( __strex(v17 - 1, v16) );
      if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
        ExfTryToWakePushLock(v14 - 1);
      v5 = KeAbPostRelease((unsigned int)(v14 - 1));
      if ( v15 > 0 )
      {
        __dmb(0xBu);
        v18 = v14 - 3;
        do
        {
          v19 = __ldrex(v18);
          v5 = v19 - v15;
        }
        while ( __strex(v5, v18) );
        __dmb(0xBu);
        if ( v5 <= 0 )
        {
          if ( v5 )
            KeBugCheckEx(24, 0, (int)v14, 40, v5);
          v5 = AlpcpDestroyBlob((int)v14);
        }
      }
      v6 = -1073740029;
      goto LABEL_67;
    }
    v20 = v37[0][4];
    if ( v20 )
    {
      PsImpersonateContainerOfThread(v20);
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v14);
      v21 = 0;
      if ( (*(_BYTE *)(v14 - 4) & 1) != 0 )
      {
        v21 = 0x10000 - *((__int16 *)v14 - 7);
        *((_BYTE *)v14 - 16) &= 0xFEu;
        *((_WORD *)v14 - 7) = 0;
      }
      v22 = v14 - 1;
      __dmb(0xBu);
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 - 1, v22) );
      if ( (v23 & 2) != 0 && (v23 & 4) == 0 )
        ExfTryToWakePushLock(v14 - 1);
      v5 = KeAbPostRelease((unsigned int)(v14 - 1));
      if ( v21 > 0 )
      {
        __dmb(0xBu);
        v24 = v14 - 3;
        do
        {
          v25 = __ldrex(v24);
          v5 = v25 - v21;
        }
        while ( __strex(v5, v24) );
        __dmb(0xBu);
        if ( v5 <= 0 )
        {
          if ( v5 )
            KeBugCheckEx(24, 0, (int)v14, 40, v5);
          v5 = AlpcpDestroyBlob((int)v14);
        }
      }
      goto LABEL_67;
    }
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v37[0]);
    v26 = 0;
    if ( (*(_BYTE *)(v14 - 4) & 1) != 0 )
    {
      v26 = 0x10000 - *((__int16 *)v14 - 7);
      *((_BYTE *)v14 - 16) &= 0xFEu;
      *((_WORD *)v14 - 7) = 0;
    }
    v27 = v14 - 1;
    __dmb(0xBu);
    do
      v28 = __ldrex(v27);
    while ( __strex(v28 - 1, v27) );
    if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
      ExfTryToWakePushLock(v14 - 1);
    KeAbPostRelease((unsigned int)(v14 - 1));
    if ( v26 > 0 )
    {
      __dmb(0xBu);
      v29 = v14 - 3;
      do
      {
        v30 = __ldrex(v29);
        v31 = v30 - v26;
      }
      while ( __strex(v31, v29) );
      __dmb(0xBu);
      if ( v31 <= 0 )
      {
        if ( v31 )
          KeBugCheckEx(24, 0, (int)v14, 40, v31);
        AlpcpDestroyBlob((int)v14);
      }
    }
    v5 = AlpcpReferenceConnectedPort((int)v7);
    v32 = v5;
    if ( v5 )
    {
      v33 = *(_DWORD *)(v5 + 12);
      if ( (v33 & 1) == 0 && v33 )
        PsImpersonateContainerOfProcess(v33);
      v5 = ObfDereferenceObject(v32);
      goto LABEL_67;
    }
LABEL_66:
    v6 = -1073741790;
  }
LABEL_67:
  if ( v7 )
    v5 = ObfDereferenceObject((int)v7);
  v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v35 = *(_WORD *)(v34 + 0x134) + 1;
  *(_WORD *)(v34 + 308) = v35;
  if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
    KiCheckForKernelApcDelivery(v5);
  return v6;
}

// IoRegisterPlugPlayNotification 
 
int __fastcall IoRegisterPlugPlayNotification(int a1, int a2, void **a3, int a4, int a5, int a6, unsigned __int16 *a7)
{
  int v10; // r4
  int v11; // r0
  _DWORD *v12; // r5
  int v14; // r0
  void **v15; // r6
  int v16; // r1
  int v17; // r2
  int v18; // r3
  unsigned __int16 *v19; // r7
  unsigned __int16 *i; // r5
  int v21; // r0
  int v22; // r0
  int v23; // r9
  int v24; // r0
  int v25; // r7
  int v26; // r1
  unsigned int v27; // r2
  _DWORD *v28; // r1
  unsigned __int8 v29; // r7
  unsigned int v30; // r1
  void *v31; // r2
  void *v32; // r3
  void *v33; // r4
  int v34; // r5
  unsigned __int16 *v35; // r1
  unsigned int v36; // r2
  char *v37; // r2
  char **v38; // r1
  unsigned __int8 v39; // r5
  unsigned int v40; // r1
  int v41; // r0
  int v42; // r0
  int v43; // r7
  int v44; // r9
  unsigned int v45; // r2
  void ***v46; // r1
  unsigned __int8 v47; // r7
  unsigned int v48; // r1
  unsigned __int16 *v49[2]; // [sp+8h] [bp-58h] BYREF
  int v50[2]; // [sp+10h] [bp-50h] BYREF
  __int16 v51[2]; // [sp+18h] [bp-48h] BYREF
  int v52; // [sp+1Ch] [bp-44h]
  int v53; // [sp+20h] [bp-40h]
  int v54; // [sp+24h] [bp-3Ch]
  int v55; // [sp+28h] [bp-38h]
  void *v56; // [sp+2Ch] [bp-34h]
  int v57; // [sp+30h] [bp-30h]
  int v58; // [sp+34h] [bp-2Ch]
  int v59; // [sp+38h] [bp-28h]
  int *v60; // [sp+3Ch] [bp-24h]

  *(_DWORD *)a7 = 0;
  v50[0] = a2;
  v49[0] = a7;
  v10 = ObReferenceObjectByPointer(a4, 0, IoDriverObjectType, 0);
  if ( v10 < 0 )
    return v10;
  if ( a1 != 3 )
  {
    if ( a1 == 2 )
    {
      v14 = ExAllocatePoolWithTag(1, 60, 1148218960);
      v15 = (void **)v14;
      if ( v14 )
      {
        v10 = PnpInitializeNotifyEntry(v14, 2, a5, a6, a4, &PnpDeviceClassNotifyLock);
        if ( v10 < 0 )
          goto LABEL_11;
        v31 = a3[1];
        v32 = a3[2];
        v33 = a3[3];
        v15[11] = *a3;
        v15[12] = v31;
        v15[13] = v32;
        v15[14] = v33;
        v10 = PnpDeferNotification(v15);
        if ( v10 >= 0 )
        {
          v34 = KeAbPreAcquire((unsigned int)&PnpDeviceClassNotifyLock, 0, 0);
          v35 = (unsigned __int16 *)KfRaiseIrql(1);
          v49[0] = v35;
          do
            v36 = __ldrex((unsigned __int8 *)&PnpDeviceClassNotifyLock);
          while ( __strex(v36 & 0xFE, (unsigned __int8 *)&PnpDeviceClassNotifyLock) );
          __dmb(0xBu);
          if ( (v36 & 1) == 0 )
          {
            ExpAcquireFastMutexContended((int)&PnpDeviceClassNotifyLock, v34);
            v35 = v49[0];
          }
          if ( v34 )
            *(_BYTE *)(v34 + 14) |= 1u;
          dword_630D04 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          dword_630D1C = (int)v35;
          v37 = (char *)&PnpDeviceClassNotifyList
              + 8 * (((unsigned int)v15[11] + (int)v15[13] + (_DWORD)v15[14] + (unsigned int)v15[12]) % 0xD);
          v38 = (char **)*((_DWORD *)v37 + 1);
          *v15 = v37;
          v15[1] = v38;
          if ( *v38 != v37 )
            __fastfail(3u);
          *v38 = (char *)v15;
          dword_630D04 = 0;
          v39 = dword_630D1C;
          *((_DWORD *)v37 + 1) = v15;
          __dmb(0xBu);
          do
            v40 = __ldrex((unsigned int *)&PnpDeviceClassNotifyLock);
          while ( !v40 && __strex(1u, (unsigned int *)&PnpDeviceClassNotifyLock) );
          if ( v40 )
            ExpReleaseFastMutexContended((unsigned int *)&PnpDeviceClassNotifyLock, v40);
          KfLowerIrql(v39);
          KeAbPostRelease((unsigned int)&PnpDeviceClassNotifyLock);
          if ( (v50[0] & 1) != 0 )
          {
            v51[0] = 1;
            v51[1] = 40;
            v52 = -885374972;
            v53 = 298862320;
            v54 = 1610649520;
            v55 = 1057297303;
            v16 = (int)v15[12];
            v17 = (int)v15[13];
            v18 = (int)v15[14];
            v56 = v15[11];
            v57 = v16;
            v58 = v17;
            v59 = v18;
            v10 = IopGetDeviceInterfaces((int)(v15 + 11), 0, 0, 0, v49, 0);
            if ( v10 < 0 )
              goto LABEL_11;
            v19 = v49[0];
            for ( i = v49[0]; *i; i += (LOWORD(v50[0]) >> 1) + 1 )
            {
              RtlInitUnicodeString((unsigned int)v50, i);
              v60 = v50;
              if ( v15[3] != *(void **)PsGetServerSiloGlobals(-1) )
              {
                v41 = IopGetSessionIdFromSymbolicName(v60);
                if ( v41 != -1 && v15[3] != (void *)v41 )
                  continue;
              }
              PnpNotifyDriverCallback(v15, (int)v51, (int *)v49);
            }
            ExFreePoolWithTag((unsigned int)v19);
          }
          *(_DWORD *)a7 = v15;
          goto LABEL_20;
        }
LABEL_64:
        ExFreePoolWithTag((unsigned int)v15);
        goto LABEL_20;
      }
    }
    else
    {
      if ( a1 != 1 )
      {
        v10 = -1073741585;
        goto LABEL_11;
      }
      v21 = ExAllocatePoolWithTag(1, 44, 963669584);
      v15 = (void **)v21;
      if ( v21 )
      {
        v10 = PnpInitializeNotifyEntry(v21, 1, a5, a6, a4, &PnpHwProfileNotifyLock);
        if ( v10 < 0 )
          goto LABEL_11;
        v42 = PnpDeferNotification(v15);
        v10 = v42;
        if ( v42 >= 0 )
        {
          v43 = KeAbPreAcquire((unsigned int)&PnpHwProfileNotifyLock, 0, 0);
          v44 = KfRaiseIrql(1);
          do
            v45 = __ldrex((unsigned __int8 *)&PnpHwProfileNotifyLock);
          while ( __strex(v45 & 0xFE, (unsigned __int8 *)&PnpHwProfileNotifyLock) );
          __dmb(0xBu);
          if ( (v45 & 1) == 0 )
            ExpAcquireFastMutexContended((int)&PnpHwProfileNotifyLock, v43);
          if ( v43 )
            *(_BYTE *)(v43 + 14) |= 1u;
          dword_630D44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v46 = (void ***)off_9209FC;
          dword_630D5C = v44;
          *v15 = &PnpProfileNotifyList;
          v15[1] = v46;
          if ( *v46 != &PnpProfileNotifyList )
            __fastfail(3u);
          *v46 = v15;
          dword_630D44 = 0;
          v47 = dword_630D5C;
          off_9209FC = v15;
          __dmb(0xBu);
          do
            v48 = __ldrex((unsigned int *)&PnpHwProfileNotifyLock);
          while ( !v48 && __strex(1u, (unsigned int *)&PnpHwProfileNotifyLock) );
          if ( v48 )
            ExpReleaseFastMutexContended((unsigned int *)&PnpHwProfileNotifyLock, v48);
          KfLowerIrql(v47);
          KeAbPostRelease((unsigned int)&PnpHwProfileNotifyLock);
          *(_DWORD *)v49[0] = v15;
LABEL_20:
          if ( v10 >= 0 )
            return v10;
          goto LABEL_11;
        }
        goto LABEL_64;
      }
    }
    v10 = -1073741670;
    goto LABEL_11;
  }
  v10 = PnpGetRelatedTargetDevice((int)a3, v50);
  if ( v10 >= 0 )
  {
    v11 = ExAllocatePoolWithTag(1, 52, 1131441744);
    v12 = (_DWORD *)v11;
    if ( !v11 )
      return sub_7F19A8();
    v10 = PnpInitializeNotifyEntry(v11, 3, a5, a6, a4, &PnpTargetDeviceNotifyLock);
    if ( v10 < 0 )
    {
      ExFreePoolWithTag((unsigned int)v12);
      v22 = *(_DWORD *)(v50[0] + 16);
    }
    else
    {
      v23 = v50[0];
      v12[11] = a3;
      v12[12] = *(_DWORD *)(v23 + 16);
      v24 = PnpDeferNotification(v12);
      v10 = v24;
      if ( v24 >= 0 )
      {
        v25 = KeAbPreAcquire((unsigned int)&PnpTargetDeviceNotifyLock, 0, 0);
        v26 = KfRaiseIrql(1);
        v50[0] = v26;
        do
          v27 = __ldrex((unsigned __int8 *)&PnpTargetDeviceNotifyLock);
        while ( __strex(v27 & 0xFE, (unsigned __int8 *)&PnpTargetDeviceNotifyLock) );
        __dmb(0xBu);
        if ( (v27 & 1) == 0 )
        {
          ExpAcquireFastMutexContended((int)&PnpTargetDeviceNotifyLock, v25);
          v26 = v50[0];
        }
        if ( v25 )
          *(_BYTE *)(v25 + 14) |= 1u;
        dword_630D24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        dword_630D3C = v26;
        v28 = *(_DWORD **)(v23 + 324);
        *v12 = v23 + 320;
        v12[1] = v28;
        if ( *v28 != v23 + 320 )
          __fastfail(3u);
        *v28 = v12;
        *(_DWORD *)(v23 + 324) = v12;
        dword_630D24 = 0;
        v29 = dword_630D3C;
        __dmb(0xBu);
        do
          v30 = __ldrex((unsigned int *)&PnpTargetDeviceNotifyLock);
        while ( !v30 && __strex(1u, (unsigned int *)&PnpTargetDeviceNotifyLock) );
        if ( v30 )
          ExpReleaseFastMutexContended((unsigned int *)&PnpTargetDeviceNotifyLock, v30);
        KfLowerIrql(v29);
        KeAbPostRelease((unsigned int)&PnpTargetDeviceNotifyLock);
        *(_DWORD *)v49[0] = v12;
        goto LABEL_20;
      }
      ExFreePoolWithTag((unsigned int)v12);
      v22 = *(_DWORD *)(v23 + 16);
    }
    ObfDereferenceObject(v22);
    goto LABEL_20;
  }
LABEL_11:
  ObfDereferenceObject(a4);
  return v10;
}

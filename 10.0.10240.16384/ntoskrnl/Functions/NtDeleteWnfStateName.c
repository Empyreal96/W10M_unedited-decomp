// NtDeleteWnfStateName 
 
int __fastcall NtDeleteWnfStateName(int a1)
{
  int v1; // r3
  int v2; // r9
  int v3; // r8
  int v4; // r6
  unsigned int *v5; // r0
  int v6; // r5
  int v7; // r1
  int v8; // r4
  int v9; // lr
  BOOL v10; // r10
  int v11; // r4
  int v12; // r2
  int v13; // r1
  int v14; // r1
  int v15; // r4
  unsigned int *v16; // r0
  unsigned int v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // r4
  unsigned int v20; // r1
  unsigned int v21; // r4
  unsigned int v22; // r1
  unsigned int v23; // r1
  __int16 v24; // r3
  int v26; // [sp+20h] [bp-60h] BYREF
  int v27; // [sp+24h] [bp-5Ch] BYREF
  int v28; // [sp+28h] [bp-58h] BYREF
  int v29; // [sp+2Ch] [bp-54h]
  unsigned int *v30; // [sp+30h] [bp-50h]
  int v31; // [sp+34h] [bp-4Ch]
  int v32; // [sp+38h] [bp-48h]
  unsigned int *v33; // [sp+3Ch] [bp-44h]
  _BYTE v34[8]; // [sp+40h] [bp-40h] BYREF
  __int64 v35; // [sp+48h] [bp-38h] BYREF
  _BYTE v36[48]; // [sp+50h] [bp-30h] BYREF

  v1 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v1 & 0xFFFFFFC0) + 0x134);
  v2 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v29 = v2;
  v31 = 0;
  v32 = 0;
  v27 = 0;
  v3 = 0;
  v28 = 0;
  v4 = 0;
  v26 = 0;
  v5 = (unsigned int *)ExpCaptureWnfStateName(a1, &v35, v2);
  v6 = (int)v5;
  v33 = v5;
  if ( (int)v5 >= 0 )
  {
    v7 = HIDWORD(v35);
    v8 = v35;
    v5 = (unsigned int *)(((unsigned int)v35 >> 4) & 3);
    v30 = v5;
    v9 = v35 >> 6;
    v32 = v9;
    if ( !v5 )
    {
      v6 = -1073741811;
      goto LABEL_42;
    }
    v10 = v2 == 0;
    if ( v5 != (unsigned int *)3 )
    {
      if ( v2 )
      {
        v5 = (unsigned int *)ExpWnfLookupPermanentName(v35);
        v6 = (int)v5;
        if ( (int)v5 < 0 )
          goto LABEL_42;
        v11 = *(_DWORD *)(v27 + 8);
        SeCaptureSubjectContext(v36);
        SeAccessCheck(v11, (int)v36, 0, 0x10000, 0, 0, (int)ExpWnfNotificationMapping, 1, (int)v34, (int)&v27);
        v5 = (unsigned int *)SeReleaseSubjectContext(v36);
        v6 = v27;
        if ( v27 < 0 )
          goto LABEL_42;
        v10 = 1;
        v7 = HIDWORD(v35);
        v8 = v35;
      }
      v5 = (unsigned int *)ExpWnfDeletePermanentName(v8, v7);
      v6 = (int)v5;
      if ( (int)v5 < 0 )
        goto LABEL_42;
      v31 = 1;
      v5 = v30;
      LOBYTE(v9) = v32;
    }
    v12 = v29;
    if ( v29 )
      v13 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    else
      v13 = PsInitialSystemProcess;
    v27 = v13;
    if ( v5 == (unsigned int *)3 )
    {
      v5 = (unsigned int *)ExpWnfResolveScopeInstance(&v28, v13, 0, v9 & 0xF, 0, v12 == 0);
      v6 = (int)v5;
      v3 = v28;
      if ( (int)v5 < 0 )
        goto LABEL_42;
    }
    else
    {
      v6 = 0;
      v5 = (unsigned int *)ExpWnfEnumerateScopeInstances(v9 & 0xF, 0);
      v3 = (int)v5;
    }
    if ( v3 )
    {
      while ( 1 )
      {
        v5 = (unsigned int *)ExpWnfLookupNameInstance(v3, v14, v8, HIDWORD(v35), &v26);
        v6 = (int)v5;
        v4 = v26;
        if ( (int)v5 >= 0 )
        {
          if ( !v10 )
          {
            v15 = *(_DWORD *)(v26 + 44);
            SeCaptureSubjectContext(v36);
            SeAccessCheck(v15, (int)v36, 0, 0x10000, 0, 0, (int)ExpWnfNotificationMapping, 1, (int)v34, (int)&v28);
            v5 = (unsigned int *)SeReleaseSubjectContext(v36);
            v6 = v28;
            if ( v28 < 0 )
              goto LABEL_42;
            v10 = 1;
          }
          if ( v30 == (unsigned int *)3 && *(_DWORD *)(v4 + 84) != v27 )
          {
            v6 = -1073741790;
            goto LABEL_42;
          }
          ExpWnfNotifyNameSubscribers(v4, 16, 1, v29 != 0);
          v5 = (unsigned int *)ExpWnfDeleteNameInstance(v3, v4, 1);
          if ( v5 )
          {
            v4 = 0;
            v26 = 0;
          }
          else
          {
            v6 = -1073741772;
          }
        }
        if ( v30 == (unsigned int *)3 )
          break;
        if ( v4 )
        {
          v16 = (unsigned int *)(v4 + 4);
          __pld((void *)(v4 + 4));
          v17 = *(_DWORD *)(v4 + 4) & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v18 = __ldrex(v16);
          while ( v18 == v17 && __strex(v17 - 2, v16) );
          if ( v18 != v17 )
            ExfReleaseRundownProtection((unsigned __int8 *)v16);
          v4 = 0;
          v26 = 0;
        }
        v5 = (unsigned int *)ExpWnfEnumerateScopeInstances(v32 & 0xF, v3);
        v3 = (int)v5;
        if ( !v5 )
          break;
        v8 = v35;
      }
    }
    if ( (v35 & 0x400) != 0 )
      v5 = (unsigned int *)ExpWnfDeletePermanentStateData(0);
  }
LABEL_42:
  if ( v31 )
    v6 = 0;
  if ( v4 )
  {
    v5 = (unsigned int *)(v4 + 4);
    __pld((void *)(v4 + 4));
    v19 = *(_DWORD *)(v4 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v20 = __ldrex(v5);
    while ( v20 == v19 && __strex(v19 - 2, v5) );
    if ( v20 != v19 )
      v5 = (unsigned int *)ExfReleaseRundownProtection((unsigned __int8 *)v5);
  }
  if ( v3 )
  {
    v5 = (unsigned int *)(v3 + 4);
    __pld((void *)(v3 + 4));
    v21 = *(_DWORD *)(v3 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v22 = __ldrex(v5);
    while ( v22 == v21 && __strex(v21 - 2, v5) );
    if ( v22 != v21 )
      v5 = (unsigned int *)ExfReleaseRundownProtection((unsigned __int8 *)v5);
  }
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = *(_WORD *)(v23 + 0x134) + 1;
  *(_WORD *)(v23 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    KiCheckForKernelApcDelivery((int)v5);
  return v6;
}

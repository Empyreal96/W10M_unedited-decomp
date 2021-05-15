// vDbgPrintExWithPrefixInternal 
 
int __fastcall vDbgPrintExWithPrefixInternal(int a1, int a2, int a3, int a4, int a5)
{
  _BYTE *v6; // r6
  int v7; // r0
  unsigned int v8; // r5
  unsigned int v9; // r8
  _BYTE *v10; // r3
  char *v11; // r0
  void **v12; // r8
  unsigned int v13; // r9
  int v14; // r0
  unsigned int v15; // r2
  unsigned int v16; // r1
  void **v17; // r6
  unsigned int *v18; // r0
  unsigned int v19; // r4
  unsigned int v20; // r2
  unsigned int v21; // r1
  unsigned int v22; // r1
  unsigned int v23; // r2
  unsigned int *v24; // r0
  unsigned int v25; // r4
  unsigned int v26; // r2
  unsigned int v27; // r1
  int v28; // r0
  unsigned int v29; // r2
  unsigned int v30; // r1
  unsigned int v31; // r1
  unsigned int v32; // r2
  unsigned int *v33; // r0
  unsigned int v34; // r4
  unsigned int v35; // r2
  unsigned int v36; // r1
  _BYTE v38[128]; // [sp-80h] [bp-C8h] BYREF
  int v39; // [sp+0h] [bp-48h]
  int v40; // [sp+4h] [bp-44h]
  void (__fastcall *v41)(__int16 *, int, int); // [sp+8h] [bp-40h]
  _BYTE *v42; // [sp+Ch] [bp-3Ch]
  int v43; // [sp+10h] [bp-38h]
  int v44; // [sp+18h] [bp-30h]
  __int16 v45; // [sp+20h] [bp-28h] BYREF
  _BYTE *v46; // [sp+24h] [bp-24h]
  int varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]

  v44 = a4;
  varg_r3 = a4;
  v40 = a3;
  varg_r2 = a3;
  v39 = a2;
  varg_r1 = a2;
  varg_r0 = a1;
  if ( NtQueryDebugFilterState(a2, a3) )
  {
    v6 = 0;
    v7 = 0;
    v43 = 0;
    v8 = 0;
    while ( v8 < 0x200 )
    {
      v6 = v38;
      v42 = v38;
      v8 += 128;
      v41 = (void (__fastcall *)(__int16 *, int, int))v8;
      v9 = (unsigned int)strlen(a1);
      if ( v9 > v8 - 1 )
        v9 = v8 - 1;
      memmove((int)v38, a1, v9);
      v7 = RtlStringCbVPrintfA(&v38[v9], v8 - v9, v44, a5);
      v43 = v7;
      if ( v7 >= 0 )
        goto LABEL_11;
      if ( v7 != -2147483643 )
        break;
    }
    if ( v7 < 0 && v7 == -2147483643 )
    {
      v10 = &v6[v8];
      *(v10 - 2) = 10;
      *(v10 - 1) = 0;
      v11 = (char *)(v8 - 1);
    }
    else
    {
LABEL_11:
      v11 = strlen((unsigned int)v6);
    }
    v46 = v6;
    v45 = (__int16)v11;
    if ( (KiBugCheckActive & 3) == 0 && RtlpDebugPrintCallbacksActive == 1 )
    {
      v12 = 0;
      v13 = KeGetCurrentIrql(v11);
      v42 = (_BYTE *)v13;
      if ( v13 < 0xC )
        KfRaiseIrql(12);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&RtlpDebugPrintCallbackLock);
      }
      else
      {
        v14 = RtlpDebugPrintCallbackLock & 0x7FFFFFFF;
        v15 = (RtlpDebugPrintCallbackLock & 0x7FFFFFFF) + 1;
        do
          v16 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
        while ( v16 == v14 && __strex(v15, (unsigned int *)&RtlpDebugPrintCallbackLock) );
        __dmb(0xBu);
        if ( v16 != v14 )
          ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&RtlpDebugPrintCallbackLock);
      }
      v17 = (void **)RtlpDebugPrintCallbackList;
      if ( RtlpDebugPrintCallbackList != &RtlpDebugPrintCallbackList )
      {
        do
        {
          v18 = (unsigned int *)(v17 - 2);
          __pld(v17 - 2);
          v19 = (unsigned int)*(v17 - 2) & 0xFFFFFFFE;
          v20 = v19 + 2;
          do
            v21 = __ldrex(v18);
          while ( v21 == v19 && __strex(v20, v18) );
          __dmb(0xBu);
          if ( v21 == v19 || ExfAcquireRundownProtection(v18, v21, v20) )
          {
            if ( (dword_682604 & 0x10000) != 0 )
            {
              ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&RtlpDebugPrintCallbackLock);
            }
            else
            {
              __dmb(0xBu);
              do
                v22 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
              while ( __strex(v22 & 0xBFFFFFFF, (unsigned int *)&RtlpDebugPrintCallbackLock) );
              __dmb(0xBu);
              do
                v23 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
              while ( __strex(v23 - 1, (unsigned int *)&RtlpDebugPrintCallbackLock) );
            }
            v41 = (void (__fastcall *)(__int16 *, int, int))*(v17 - 1);
            if ( v12 )
            {
              v24 = (unsigned int *)(v12 + 1);
              __pld(v12 + 1);
              v25 = (unsigned int)v12[1] & 0xFFFFFFFE;
              __dmb(0xBu);
              v26 = v25 - 2;
              do
                v27 = __ldrex(v24);
              while ( v27 == v25 && __strex(v26, v24) );
              if ( v27 != v25 )
                ExfReleaseRundownProtection(v24, v27, v26);
            }
            v12 = v17 - 3;
            v41(&v45, v39, v40);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&RtlpDebugPrintCallbackLock);
            }
            else
            {
              v28 = RtlpDebugPrintCallbackLock & 0x7FFFFFFF;
              v29 = (RtlpDebugPrintCallbackLock & 0x7FFFFFFF) + 1;
              do
                v30 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
              while ( v30 == v28 && __strex(v29, (unsigned int *)&RtlpDebugPrintCallbackLock) );
              __dmb(0xBu);
              if ( v30 != v28 )
                ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&RtlpDebugPrintCallbackLock);
            }
          }
          v17 = (void **)*v17;
        }
        while ( v17 != &RtlpDebugPrintCallbackList );
        v13 = (unsigned int)v42;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&RtlpDebugPrintCallbackLock);
      }
      else
      {
        __dmb(0xBu);
        do
          v31 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
        while ( __strex(v31 & 0xBFFFFFFF, (unsigned int *)&RtlpDebugPrintCallbackLock) );
        __dmb(0xBu);
        do
          v32 = __ldrex((unsigned int *)&RtlpDebugPrintCallbackLock);
        while ( __strex(v32 - 1, (unsigned int *)&RtlpDebugPrintCallbackLock) );
      }
      if ( v12 )
      {
        v33 = (unsigned int *)(v12 + 1);
        __pld(v12 + 1);
        v34 = (unsigned int)v12[1] & 0xFFFFFFFE;
        __dmb(0xBu);
        v35 = v34 - 2;
        do
          v36 = __ldrex(v33);
        while ( v36 == v34 && __strex(v35, v33) );
        if ( v36 != v34 )
          ExfReleaseRundownProtection(v33, v36, v35);
      }
      if ( v13 < 0xC )
        KfLowerIrql(v13);
    }
    DbgBreakPointWithStatusEnd();
  }
  return 0;
}

// ObCheckObjectAccess 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ObCheckObjectAccess(int a1, int *a2, int a3, char a4, int *a5)
{
  int v5; // r8
  int v7; // r6
  int v9; // r0
  int result; // r0
  int v11; // r4
  unsigned int v12; // r1
  int v13; // r0
  _DWORD *v14; // r9
  int v15; // r5
  int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r3
  _DWORD *v21; // r6
  _DWORD *v22; // r4
  unsigned int i; // r2
  unsigned int v24; // r1
  unsigned int v25; // r2
  int v26; // r0
  unsigned int v27; // r1
  int v28; // r3
  unsigned __int8 *v29; // r8
  unsigned int v30; // r7
  int v31; // r0
  int v32; // r9
  unsigned int v33; // r2
  unsigned int v34; // r1
  int v35; // r1 OVERLAPPED
  _DWORD *v36; // r2 OVERLAPPED
  unsigned int v37; // r1
  int v38; // r0
  __int16 v39; // r3
  unsigned int v40; // r1
  int v41; // r0
  int v42; // r3
  char v43[4]; // [sp+18h] [bp-30h] BYREF
  int v44; // [sp+1Ch] [bp-2Ch] BYREF
  _DWORD *v45; // [sp+20h] [bp-28h] BYREF
  int v46[9]; // [sp+24h] [bp-24h] BYREF

  v46[0] = 0;
  v5 = a4;
  v7 = ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  v44 = 0;
  v45 = 0;
  v9 = ObpGetObjectSecurity(a1, &v44, v43, a4);
  if ( v9 < 0 )
    return sub_7FC318();
  v11 = v44;
  if ( v44 )
  {
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v12 + 308);
    ExAcquireResourceSharedLite(*(_DWORD *)(a2[9] + 48), 1);
    if ( a2[7] )
    {
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v25 + 308);
      ExAcquireResourceSharedLite(*(_DWORD *)(a2[7] + 48), 1);
    }
    v13 = SeAccessCheck(v11, (int)(a2 + 7), 1, a2[4], a2[5], (int)&v45, v7 + 52, v5, (int)v46, (int)a5);
    v14 = v45;
    v15 = v13;
    if ( v45 )
    {
      SeAppendPrivileges((int)a2, v45);
      ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v14);
    }
    if ( v15 )
    {
      v16 = v46[0];
      a2[5] |= v46[0];
      a2[4] &= ~(v16 | 0x2000000);
    }
    if ( v5 )
      SeOpenObjectAuditAlarmWithTransaction(v7 + 8, a1, 0, v11, a2, 0);
    v17 = ExReleaseResourceLite(*(_DWORD *)(a2[9] + 48));
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery(v17);
    v20 = a2[7];
    if ( v20 )
    {
      v26 = ExReleaseResourceLite(*(_DWORD *)(v20 + 48));
      v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v28 = (__int16)(*(_WORD *)(v27 + 0x134) + 1);
      *(_WORD *)(v27 + 308) = v28;
      if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
        KiCheckForKernelApcDelivery(v26);
    }
    if ( v43[0] )
    {
      ExFreePoolWithTag(v11);
      result = v15;
    }
    else
    {
      v21 = (_DWORD *)(v11 - 16);
      v22 = (_DWORD *)(v11 - 8);
      __pld(v22);
      for ( i = *v22; (int)(i - 1) > 0; i = v24 )
      {
        __dmb(0xBu);
        do
          v24 = __ldrex(v22);
        while ( v24 == i && __strex(i - 1, v22) );
        if ( v24 == i )
          goto LABEL_22;
      }
      if ( i != 1 )
        __fastfail(0xEu);
      v29 = (unsigned __int8 *)&ObsSecurityDescriptorCache[3 * (v21[3] % 0x101u)];
      v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v30 + 308);
      v31 = KeAbPreAcquire((unsigned int)v29, 0, 0);
      v32 = v31;
      do
        v33 = __ldrex(v29);
      while ( __strex(v33 | 1, v29) );
      __dmb(0xBu);
      if ( (v33 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v29, v31, (unsigned int)v29);
      if ( v32 )
        *(_BYTE *)(v32 + 14) |= 1u;
      __dmb(0xBu);
      do
        v34 = __ldrex(v22);
      while ( __strex(v34 - 1, v22) );
      if ( (int)(v34 - 1) > 0 )
      {
        __dmb(0xBu);
        do
          v40 = __ldrex((unsigned int *)v29);
        while ( __strex(v40 - 1, (unsigned int *)v29) );
        if ( (v40 & 2) != 0 && (v40 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v29);
        v41 = KeAbPostRelease((unsigned int)v29);
        v42 = (__int16)(*(_WORD *)(v30 + 308) + 1);
        *(_WORD *)(v30 + 308) = v42;
        if ( !v42 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
          KiCheckForKernelApcDelivery(v41);
      }
      else
      {
        if ( v34 != 1 )
          __fastfail(0xEu);
        __dmb(0xBu);
        *(_QWORD *)&v35 = *(_QWORD *)v21;
        if ( *(_DWORD **)(*v21 + 4) != v21 || (_DWORD *)*v36 != v21 )
          __fastfail(3u);
        *v36 = v35;
        *(_DWORD *)(v35 + 4) = v36;
        __dmb(0xBu);
        do
          v37 = __ldrex((unsigned int *)v29);
        while ( __strex(v37 - 1, (unsigned int *)v29) );
        if ( (v37 & 2) != 0 && (v37 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v29);
        v38 = KeAbPostRelease((unsigned int)v29);
        v39 = *(_WORD *)(v30 + 308) + 1;
        *(_WORD *)(v30 + 308) = v39;
        if ( !v39 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
          KiCheckForKernelApcDelivery(v38);
        ExFreePoolWithTag((unsigned int)v21);
      }
LABEL_22:
      result = v15;
    }
  }
  else
  {
    a2[5] |= a2[4];
    a2[4] = 0;
    *a5 = v9;
    result = 1;
  }
  return result;
}

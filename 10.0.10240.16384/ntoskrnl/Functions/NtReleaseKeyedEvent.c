// NtReleaseKeyedEvent 
 
int __fastcall NtReleaseKeyedEvent(int a1, unsigned int a2, _DWORD *a3, int *a4)
{
  int *v4; // r6
  unsigned int v5; // r5
  int v6; // r10
  unsigned int v8; // r4
  int v9; // r1
  int v10; // r2
  unsigned __int8 *v11; // r5
  _DWORD **v12; // r8
  int v13; // r0
  int v14; // r9
  unsigned int v15; // r2
  _DWORD *i; // r2
  _DWORD *v17; // r9
  _DWORD *v18; // r0
  _DWORD *v19; // r1
  _DWORD *v20; // r2
  _DWORD *v21; // r1
  unsigned int v22; // r1
  int v23; // r0
  int v24; // r0
  int v25; // r3
  __int16 v26; // r3
  int v27; // r8
  int v28; // r0
  int v29; // r6
  unsigned int v30; // r2
  unsigned int v31; // r2
  int v32; // r0
  _DWORD *v33; // r1
  unsigned int v34; // r1
  int v35; // r0
  __int16 v36; // r3
  int v38; // [sp+10h] [bp-48h]
  char v40; // [sp+18h] [bp-40h]
  int v42; // [sp+20h] [bp-38h]
  int v43; // [sp+28h] [bp-30h] BYREF
  _DWORD _30[14]; // [sp+30h] [bp-28h] BYREF
  _DWORD *varg_r2; // [sp+68h] [bp+10h]
  int *varg_r3; // [sp+6Ch] [bp+14h]

  varg_r2 = a3;
  v4 = a4;
  varg_r3 = a4;
  LOBYTE(varg_r2) = (_BYTE)a3;
  v5 = a2;
  _30[13] = a2;
  _30[12] = a1;
  v6 = 0;
  v38 = 0;
  if ( (a2 & 1) != 0 )
    return -1073741585;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v43 = v8;
  v9 = *(char *)(v8 + 0x15A);
  v40 = *(_BYTE *)(v8 + 0x15A);
  if ( a4 )
  {
    if ( *(_BYTE *)(v8 + 0x15A) && ((unsigned int)(a4 + 2) > MmUserProbeAddress || a4 + 2 < a4) )
      *(_BYTE *)MmUserProbeAddress = 0;
    _30[0] = *a4;
    _30[1] = a4[1];
    v4 = _30;
    varg_r3 = _30;
  }
  if ( !a1 )
  {
    v10 = ExpCritSecOutOfMemoryEvent;
    v42 = ExpCritSecOutOfMemoryEvent;
LABEL_12:
    *(_DWORD *)(v8 + 964) |= 8u;
    v43 = *(_DWORD *)(v8 + 116);
    v11 = (unsigned __int8 *)(v10 + 12 * ((v5 >> 5) & 0x3F));
    v12 = (_DWORD **)(v11 + 4);
    --*(_WORD *)(v8 + 308);
    v13 = KeAbPreAcquire((unsigned int)v11, 0, 0);
    v14 = v13;
    do
      v15 = __ldrex(v11);
    while ( __strex(v15 | 1, v11) );
    __dmb(0xBu);
    if ( (v15 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v11, v13, (unsigned int)v11);
    if ( v14 )
      *(_BYTE *)(v14 + 14) |= 1u;
    for ( i = *v12; ; i = (_DWORD *)*i )
    {
      if ( i == v12 )
      {
        v38 = *(_DWORD *)(v8 + 860);
        *(_DWORD *)(v8 + 860) = a2 | 1;
        v20 = (_DWORD *)(v8 + 840);
        v21 = *v12;
        *(_DWORD *)(v8 + 840) = *v12;
        *(_DWORD *)(v8 + 844) = v12;
        if ( (_DWORD **)v21[1] != v12 )
          __fastfail(3u);
        v21[1] = v20;
        *v12 = v20;
        v17 = 0;
        goto LABEL_31;
      }
      v17 = i - 210;
      if ( i[5] == a2 )
      {
        v12 = (_DWORD **)(v11 + 4);
        if ( *(i - 126) == v43 )
          break;
      }
    }
    v18 = (_DWORD *)*i;
    v19 = (_DWORD *)i[1];
    if ( *(_DWORD **)(*i + 4) != i || (_DWORD *)*v19 != i )
      __fastfail(3u);
    *v19 = v18;
    v18[1] = v19;
    i[1] = i;
    *i = i;
LABEL_31:
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v11);
    while ( __strex(v22 - 1, (unsigned int *)v11) );
    if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v11);
    v23 = KeAbPostRelease((unsigned int)v11);
    if ( v17 )
    {
      v24 = KeReleaseSemaphore((int)(v17 + 221), 1, 1);
      v25 = (__int16)(*(_WORD *)(v8 + 308) + 1);
      *(_WORD *)(v8 + 308) = v25;
      if ( !v25 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
        KiCheckForKernelApcDelivery(v24);
    }
    else
    {
      v26 = *(_WORD *)(v8 + 308) + 1;
      *(_WORD *)(v8 + 308) = v26;
      if ( !v26 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
        KiCheckForKernelApcDelivery(v23);
      v6 = KeWaitForSingleObject(v8 + 884, 21, v40, a3, v4);
      if ( v6 )
      {
        v27 = 1;
        --*(_WORD *)(v8 + 308);
        v28 = KeAbPreAcquire((unsigned int)v11, 0, 0);
        v29 = v28;
        do
          v30 = __ldrex(v11);
        while ( __strex(v30 | 1, v11) );
        __dmb(0xBu);
        if ( (v30 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v11, v28, (unsigned int)v11);
        if ( v29 )
          *(_BYTE *)(v29 + 14) |= 1u;
        v31 = v8 + 840;
        if ( *(_DWORD *)(v8 + 840) != v8 + 840 )
        {
          v32 = *(_DWORD *)v31;
          v33 = *(_DWORD **)(v8 + 844);
          if ( *(_DWORD *)(*(_DWORD *)v31 + 4) != v31 || *v33 != v31 )
            __fastfail(3u);
          *v33 = v32;
          *(_DWORD *)(v32 + 4) = v33;
          *(_DWORD *)(v8 + 844) = v8 + 840;
          *(_DWORD *)v31 = v31;
          v27 = 0;
        }
        __dmb(0xBu);
        do
          v34 = __ldrex((unsigned int *)v11);
        while ( __strex(v34 - 1, (unsigned int *)v11) );
        if ( (v34 & 2) != 0 && (v34 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v11);
        v35 = KeAbPostRelease((unsigned int)v11);
        v36 = *(_WORD *)(v8 + 308) + 1;
        *(_WORD *)(v8 + 308) = v36;
        if ( !v36 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
          KiCheckForKernelApcDelivery(v35);
        if ( v27 )
          v6 = KeWaitForSingleObject(v8 + 884, 21, 0, 0, 0);
      }
      *(_DWORD *)(v8 + 860) = v38;
    }
    *(_DWORD *)(v8 + 964) &= 0xFFFFFFF7;
    if ( a1 )
      ObfDereferenceObject(v42);
    return v6;
  }
  v6 = ObReferenceObjectByHandle(a1, 2, ExpKeyedEventObjectType, v9, &v43);
  v10 = v43;
  v42 = v43;
  if ( v6 >= 0 )
    goto LABEL_12;
  return v6;
}

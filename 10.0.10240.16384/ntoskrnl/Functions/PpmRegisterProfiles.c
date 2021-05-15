// PpmRegisterProfiles 
 
int __fastcall PpmRegisterProfiles(unsigned int a1, int a2)
{
  int v2; // r6
  int v5; // r9
  unsigned int v6; // r5
  int v7; // r4
  int v8; // r7
  _BYTE *v9; // r0
  int v10; // r10
  int v11; // lr
  unsigned int v12; // r5
  unsigned int v13; // r7
  unsigned int v14; // r6
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r4
  int v19; // lr
  unsigned int v20; // r2
  int v21; // r0
  int v22; // r5
  unsigned int v23; // r2
  int v24; // r3
  unsigned __int8 v25; // r6
  _DWORD *v26; // r5
  int v27; // r3
  int v28; // r1
  unsigned int v29; // r0
  unsigned int v30; // r2
  int v31; // r0
  unsigned int v32; // r1
  int v33; // r3
  int v34; // [sp+0h] [bp-30h] BYREF
  int v35; // [sp+4h] [bp-2Ch]
  unsigned int v36; // [sp+8h] [bp-28h] BYREF
  int v37; // [sp+Ch] [bp-24h]
  int v38; // [sp+10h] [bp-20h]

  v2 = a2;
  v38 = a2;
  if ( a1 > 0x1F )
    return sub_816570();
  v5 = RtlULongLongToULong(424 * a1, (424 * (unsigned __int64)a1) >> 32, &v36);
  v37 = v5;
  if ( v5 >= 0 )
  {
    v6 = 0;
    v7 = (v36 + 1) & 0xFFFFFFFE;
    v8 = v7;
    if ( a1 )
    {
      while ( 1 )
      {
        v5 = RtlStringCbLengthW(*(_DWORD *)(v2 + 16 * v6 + 4), 0x7FFFFFFFu, &v34);
        v37 = v5;
        if ( v5 < 0 )
          break;
        v7 += v34 + 2;
        v6 = (unsigned __int8)(v6 + 1);
        if ( v6 >= a1 )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      v9 = (_BYTE *)ExAllocatePoolWithTag(512, v7, 1716342864);
      v10 = (int)v9;
      if ( v9 )
      {
        memset(v9, 0, v7);
        v11 = v10 + v8;
        v12 = 0;
        v35 = v10 + v8;
        if ( a1 )
        {
          v36 = 0;
          do
          {
            v13 = v2 + 16 * v12;
            v14 = v10 + 424 * v12;
            v15 = *(_DWORD *)(*(_DWORD *)v13 + 4);
            v16 = *(_DWORD *)(*(_DWORD *)v13 + 8);
            v17 = *(_DWORD *)(*(_DWORD *)v13 + 12);
            *(_DWORD *)(v14 + 8) = **(_DWORD **)v13;
            *(_DWORD *)(v14 + 12) = v15;
            *(_DWORD *)(v14 + 16) = v16;
            *(_DWORD *)(v14 + 20) = v17;
            LOBYTE(v17) = *(_BYTE *)(v13 + 8);
            *(_DWORD *)v14 = v11;
            *(_BYTE *)(v14 + 28) = v17;
            *(_DWORD *)(v14 + 408) = -1;
            *(_DWORD *)(v14 + 412) = -1;
            v12 = (unsigned __int8)(v36 + 1);
            *(_BYTE *)(v14 + 4) = v12;
            RtlStringCchLengthW(*(unsigned __int16 **)(v13 + 4), 0x7FFFFFFFu, &v34);
            v18 = v34;
            RtlStringCchCopyW(*(_WORD **)v14, v34 + 1, *(_DWORD *)(v13 + 4));
            v19 = v35;
            *(_DWORD *)(v13 + 12) = v14;
            v11 = v19 + 2 * (v18 + 1);
            v2 = v38;
            v35 = v11;
            v36 = v12;
          }
          while ( v12 < a1 );
          v5 = v37;
        }
        PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
        v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v20 + 308);
        v21 = KeAbPreAcquire((unsigned int)&PpmIdlePolicyLock, 0, 0);
        v22 = v21;
        do
          v23 = __ldrex((unsigned __int8 *)&PpmIdlePolicyLock);
        while ( __strex(v23 | 1, (unsigned __int8 *)&PpmIdlePolicyLock) );
        __dmb(0xBu);
        if ( (v23 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&PpmIdlePolicyLock, v21, (unsigned int)&PpmIdlePolicyLock);
        if ( v22 )
          *(_BYTE *)(v22 + 14) |= 1u;
        dword_61E89C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        PpmProfiles = v10;
        PpmProfileCount = a1;
        v24 = 0;
        if ( a1 )
        {
          v25 = 0;
          do
          {
            v26 = (_DWORD *)(v10 + 424 * v24);
            memmove((int)(v26 + 8), (int)dword_61DBC0, 0xB0u);
            memmove((int)(v26 + 52), (int)&dword_61DC70, 0xB0u);
            v27 = 2;
            do
            {
              v26[8] = 0;
              v26[9] = 0;
              v26[52] = 0;
              v26[53] = 0;
              v26 += 2;
              --v27;
            }
            while ( v27 );
            v24 = ++v25;
          }
          while ( v25 < a1 );
        }
        PpmEventTraceProfiles(0);
        dword_61E89C = 0;
        __pld(&PpmIdlePolicyLock);
        v28 = PpmIdlePolicyLock;
        if ( (PpmIdlePolicyLock & 0xFFFFFFF0) > 0x10 )
          v29 = PpmIdlePolicyLock - 16;
        else
          v29 = 0;
        if ( (PpmIdlePolicyLock & 2) != 0 )
          goto LABEL_36;
        __dmb(0xBu);
        do
          v30 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
        while ( v30 == v28 && __strex(v29, (unsigned int *)&PpmIdlePolicyLock) );
        if ( v30 != v28 )
LABEL_36:
          ExfReleasePushLock(&PpmIdlePolicyLock, v28);
        v31 = KeAbPostRelease((unsigned int)&PpmIdlePolicyLock);
        v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v33 = (__int16)(*(_WORD *)(v32 + 0x134) + 1);
        *(_WORD *)(v32 + 308) = v33;
        if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
          KiCheckForKernelApcDelivery(v31);
        PpmReleaseLock(&PpmPerfPolicyLock);
        PpmProfileStatus |= 1u;
      }
      else
      {
        v5 = -1073741670;
      }
    }
  }
  return v5;
}

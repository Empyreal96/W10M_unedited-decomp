// NtSetSystemEnvironmentValue 
 
int __fastcall NtSetSystemEnvironmentValue(int *a1, int *a2, int a3)
{
  unsigned int v3; // r3
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r9
  int v7; // r4
  unsigned int v8; // r3
  int *v9; // r0
  unsigned int v10; // r3
  int v11; // r8
  int v12; // r4
  int v13; // r3
  int v14; // r1
  int v15; // r2
  int v16; // r4
  int v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r9
  int v20; // r0
  int v21; // r4
  unsigned int v22; // r2
  int v23; // r4
  unsigned int v24; // r1
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  unsigned __int16 v29[2]; // [sp+8h] [bp-38h] BYREF
  int v30; // [sp+Ch] [bp-34h]
  int v31; // [sp+10h] [bp-30h] BYREF
  unsigned int v32; // [sp+14h] [bp-2Ch]
  int v33; // [sp+18h] [bp-28h] BYREF
  unsigned int v34; // [sp+1Ch] [bp-24h]
  unsigned __int16 v35[2]; // [sp+20h] [bp-20h] BYREF
  int v36; // [sp+24h] [bp-1Ch]

  v30 = 0;
  v36 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(char *)(v3 + 346);
  if ( *(_BYTE *)(v3 + 346) )
  {
    if ( ((unsigned __int8)a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v31 = *a1;
    v5 = a1[1];
    v32 = v5;
    v6 = (unsigned __int16)v31;
    if ( !(_WORD)v31 )
      return -1073741670;
    if ( (v5 & 1) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v8 = MmUserProbeAddress;
    if ( (unsigned __int16)v31 + v5 > MmUserProbeAddress || (unsigned __int16)v31 + v5 < v5 )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v8 = MmUserProbeAddress;
    }
    v9 = a2;
    if ( ((unsigned __int8)a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a2);
    if ( (unsigned int)a2 >= v8 )
      v9 = (int *)v8;
    v33 = *a2;
    v10 = a2[1];
    v34 = v10;
    v11 = (unsigned __int16)v33;
    if ( !(_WORD)v33 )
      return -1073741670;
    if ( (v10 & 1) != 0 )
      ExRaiseDatatypeMisalignment(v9);
    if ( (unsigned __int16)v33 + v10 > MmUserProbeAddress || (unsigned __int16)v33 + v10 < v10 )
      *(_BYTE *)MmUserProbeAddress = 0;
    if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v4, (int)&SeSystemEnvironmentPrivilege) )
      return -1073741727;
  }
  else
  {
    v31 = *a1;
    v32 = a1[1];
    v33 = *a2;
    v34 = a2[1];
    v6 = (unsigned __int16)v31;
    v11 = (unsigned __int16)v33;
  }
  if ( NlsMbCodePageTag )
    v12 = RtlxUnicodeStringToOemSize((unsigned __int16 *)&v31, (int)a2, a3, (unsigned __int8)NlsMbCodePageTag);
  else
    v12 = (unsigned int)(v6 + 2) >> 1;
  v30 = ExAllocatePoolWithTag(512, v12, 1920364101);
  if ( !v30 )
    return -1073741670;
  v29[1] = v12;
  v7 = RtlUnicodeStringToAnsiString(v29, (unsigned __int16 *)&v31, 0, v13);
  if ( v7 >= 0 )
  {
    if ( NlsMbCodePageTag )
      v16 = RtlxUnicodeStringToOemSize((unsigned __int16 *)&v33, v14, v15, (unsigned __int8)NlsMbCodePageTag);
    else
      v16 = (unsigned int)(v11 + 2) >> 1;
    v36 = ExAllocatePoolWithTag(512, v16, 1920364101);
    if ( v36 )
    {
      v35[1] = v16;
      v7 = RtlUnicodeStringToAnsiString(v35, (unsigned __int16 *)&v33, 0, v17);
      if ( v7 >= 0 )
      {
        v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v18 + 308);
        v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v20 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
        v21 = v20;
        do
          v22 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
        while ( __strex(v22 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
        __dmb(0xBu);
        if ( (v22 & 1) == 0 )
          ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v20);
        if ( v21 )
          *(_BYTE *)(v21 + 14) |= 1u;
        dword_61A084 = v19;
        v23 = HalSetEnvironmentVariable(v30, v36);
        dword_61A084 = 0;
        __dmb(0xBu);
        do
          v24 = __ldrex((unsigned int *)&ExpEnvironmentLock);
        while ( !v24 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
        if ( v24 )
          ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v24);
        v25 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
        v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v27 = *(_WORD *)(v26 + 0x134) + 1;
        *(_WORD *)(v26 + 308) = v27;
        if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
          KiCheckForKernelApcDelivery(v25);
        ExFreePoolWithTag(v30);
        ExFreePoolWithTag(v36);
        if ( v23 )
          v7 = -1073741670;
        else
          v7 = 0;
      }
      else
      {
        ExFreePoolWithTag(v30);
        ExFreePoolWithTag(v36);
      }
    }
    else
    {
      ExFreePoolWithTag(v30);
      v7 = -1073741670;
    }
  }
  else
  {
    ExFreePoolWithTag(v30);
  }
  return v7;
}

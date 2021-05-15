// NtQueryBootOptions 
 
int __fastcall NtQueryBootOptions(unsigned int a1, unsigned int *a2)
{
  unsigned int *v2; // r9
  int v4; // r4
  unsigned int v5; // r3
  int v6; // r4
  unsigned int *v7; // r2
  unsigned int v8; // r5
  unsigned int v9; // r2
  unsigned int v10; // r5
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  int v17; // r0
  unsigned int v18; // r1
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  unsigned int v23; // [sp+8h] [bp-38h] BYREF
  unsigned int v24; // [sp+Ch] [bp-34h] BYREF
  int v25; // [sp+10h] [bp-30h] BYREF
  int v26; // [sp+14h] [bp-2Ch] BYREF
  unsigned int v27; // [sp+18h] [bp-28h]
  int v28; // [sp+1Ch] [bp-24h]
  unsigned int anonymous6; // [sp+48h] [bp+8h]
  unsigned int *anonymous7; // [sp+4Ch] [bp+Ch]

  v2 = a2;
  anonymous7 = a2;
  anonymous6 = a1;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  if ( dword_61A1F0 != 2 )
    return -1073741822;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(char *)(v5 + 346);
  if ( *(_BYTE *)(v5 + 346) )
  {
    v7 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v7 = (unsigned int *)MmUserProbeAddress;
    *v7 = *v7;
    v8 = *a2;
    v27 = *a2;
    if ( !a1 )
    {
      v8 = 0;
      v27 = 0;
    }
    if ( v8 )
      ProbeForWrite(a1, v8, 4);
    if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v6, (int)&SeSystemEnvironmentPrivilege) )
    {
      v4 = -1073741727;
      v28 = -1073741727;
      return v4;
    }
  }
  else
  {
    v8 = *a2;
    v27 = *a2;
    if ( !a1 )
    {
      v8 = 0;
      v27 = 0;
    }
  }
  if ( v8 >= 0x16 )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
    while ( __strex(v13 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
    __dmb(0xBu);
    if ( (v13 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v11);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    dword_61A084 = v10;
    v23 = 4;
    v14 = IoGetEnvironmentVariableEx((int)L"Timeout", (int)EfiBootVariablesGuid, (int)&v24, (int)&v23, 0);
    v4 = v14;
    if ( v14 == -1073741789 )
    {
      v24 = -2;
      goto LABEL_34;
    }
    if ( v14 == -1073741568 )
    {
      v24 = -1;
      goto LABEL_34;
    }
    if ( v14 )
      goto LABEL_46;
    v15 = v24;
    if ( v23 > 2 )
    {
      if ( v24 == -1 )
      {
LABEL_30:
        v24 = -1;
LABEL_34:
        v23 = 4;
        v16 = IoGetEnvironmentVariableEx((int)L"BootCurrent", (int)EfiBootVariablesGuid, (int)&v25, (int)&v23, 0);
        v4 = v16;
        if ( v16 == -1073741789 || v16 == -1073741568 )
        {
          v25 = -2;
LABEL_40:
          v23 = 2;
          v17 = IoGetEnvironmentVariableEx((int)L"BootNext", (int)EfiBootVariablesGuid, (int)&v26, (int)&v23, 0);
          v4 = v17;
          if ( v17 == -1073741789 || v17 == -1073741568 )
          {
            v26 = -2;
            v4 = 0;
          }
          else if ( !v17 && v23 > 2 )
          {
            v26 = (unsigned __int16)v26;
          }
          goto LABEL_46;
        }
        if ( !v16 )
        {
          if ( v23 > 2 )
            v25 = (unsigned __int16)v25;
          goto LABEL_40;
        }
LABEL_46:
        dword_61A084 = 0;
        __dmb(0xBu);
        do
          v18 = __ldrex((unsigned int *)&ExpEnvironmentLock);
        while ( !v18 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
        if ( v18 )
          ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v18);
        v19 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
        v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v21 = *(_WORD *)(v20 + 0x134) + 1;
        *(_WORD *)(v20 + 308) = v21;
        if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
          KiCheckForKernelApcDelivery(v19);
        goto LABEL_55;
      }
      if ( v24 > 0xFFFE )
      {
        v15 = 65534;
        v24 = 65534;
      }
    }
    if ( v15 != 0xFFFF )
      goto LABEL_34;
    goto LABEL_30;
  }
  v4 = -1073741789;
LABEL_55:
  if ( !v4 && a1 )
  {
    *(_DWORD *)a1 = 1;
    *(_DWORD *)(a1 + 4) = 22;
    *(_DWORD *)(a1 + 8) = v24;
    *(_DWORD *)(a1 + 12) = v25;
    *(_DWORD *)(a1 + 16) = v26;
    *(_WORD *)(a1 + 20) = 0;
  }
  *v2 = 22;
  v28 = v4;
  return v4;
}

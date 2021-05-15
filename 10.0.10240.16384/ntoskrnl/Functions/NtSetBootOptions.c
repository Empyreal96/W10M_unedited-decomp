// NtSetBootOptions 
 
int __fastcall NtSetBootOptions(unsigned int a1, int a2, int a3, int a4)
{
  char v4; // r8
  int v6; // r4
  unsigned int v7; // r3
  int v8; // r5
  unsigned int *v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r2
  unsigned int v12; // r2
  unsigned int v13; // r10
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  unsigned int v22; // [sp+8h] [bp-28h] BYREF
  unsigned int v23; // [sp+Ch] [bp-24h] BYREF
  int v24; // [sp+10h] [bp-20h]
  unsigned int anonymous3; // [sp+38h] [bp+8h]
  int anonymous4; // [sp+3Ch] [bp+Ch]

  anonymous3 = a1;
  v24 = a4;
  v4 = a2;
  anonymous4 = a2;
  v23 = 0;
  v22 = 0;
  if ( dword_61A1F0 != 2 )
    return -1073741822;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(char *)(v7 + 346);
  if ( *(_BYTE *)(v7 + 346) )
  {
    v9 = (unsigned int *)(a1 + 4);
    if ( a1 + 4 >= MmUserProbeAddress )
      v9 = (unsigned int *)MmUserProbeAddress;
    v10 = *v9;
  }
  else
  {
    v10 = *(_DWORD *)(a1 + 4);
  }
  if ( v10 >= 0x14 )
  {
    if ( !v8 )
      goto LABEL_19;
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( v10 + a1 > MmUserProbeAddress || v10 + a1 < a1 )
      *(_BYTE *)MmUserProbeAddress = 0;
    if ( SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v8, (int)&SeSystemEnvironmentPrivilege) )
    {
LABEL_19:
      if ( *(_DWORD *)a1 && *(_DWORD *)a1 <= 1u )
      {
        v23 = *(_DWORD *)(a1 + 8);
        v11 = *(_DWORD *)(a1 + 16);
        v22 = v11;
        if ( (v4 & 2) != 0 && v11 > 0xFFFF )
        {
          v6 = -1073741811;
        }
        else
        {
          v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v12 + 308);
          v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v14 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
          v15 = v14;
          do
            v16 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
          while ( __strex(v16 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
          __dmb(0xBu);
          if ( (v16 & 1) == 0 )
            ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v14);
          if ( v15 )
            *(_BYTE *)(v15 + 14) |= 1u;
          dword_61A084 = v13;
          v6 = 0;
          if ( (v4 & 1) != 0 )
          {
            if ( v23 == -1 )
            {
              v23 = 0xFFFF;
            }
            else if ( v23 > 0xFFFE )
            {
              v23 = 65534;
            }
            v6 = IoSetEnvironmentVariableEx((int)L"Timeout", (int)EfiBootVariablesGuid, (int)&v23, 2, 1);
          }
          if ( v6 >= 0 && (v4 & 2) != 0 )
            v6 = IoSetEnvironmentVariableEx((int)L"BootNext", (int)EfiBootVariablesGuid, (int)&v22, 2, 1);
          dword_61A084 = 0;
          __dmb(0xBu);
          do
            v17 = __ldrex((unsigned int *)&ExpEnvironmentLock);
          while ( !v17 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
          if ( v17 )
            ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v17);
          v18 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
          v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v20 = *(_WORD *)(v19 + 0x134) + 1;
          *(_WORD *)(v19 + 308) = v20;
          if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
            KiCheckForKernelApcDelivery(v18);
        }
      }
      else
      {
        v6 = -1073741811;
        v24 = -1073741811;
      }
    }
    else
    {
      v6 = -1073741727;
      v24 = -1073741727;
    }
  }
  else
  {
    v6 = -1073741811;
    v24 = -1073741811;
  }
  return v6;
}

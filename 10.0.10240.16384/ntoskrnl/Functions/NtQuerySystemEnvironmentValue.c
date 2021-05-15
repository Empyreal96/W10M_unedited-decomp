// NtQuerySystemEnvironmentValue 
 
int __fastcall NtQuerySystemEnvironmentValue(int *a1, int a2, int a3, _WORD *a4)
{
  unsigned int v5; // r4
  int v6; // r8
  unsigned int v7; // r3
  int v8; // r4
  _WORD *v9; // r1
  int v10; // r4
  int v11; // r3
  int v12; // r8
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  int v17; // r4
  unsigned int v18; // r1
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  unsigned int v25; // [sp+Ch] [bp-3Ch]
  int v26; // [sp+18h] [bp-30h] BYREF
  int v27; // [sp+1Ch] [bp-2Ch]
  unsigned __int16 v28[2]; // [sp+20h] [bp-28h] BYREF
  int v29; // [sp+24h] [bp-24h]
  int *varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  _WORD *varg_r3; // [sp+5Ch] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  v29 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(char *)(v5 + 346);
  if ( *(_BYTE *)(v5 + 346) )
  {
    if ( ((unsigned __int8)a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v26 = *a1;
    v7 = a1[1];
    v27 = v7;
    if ( !(_WORD)v26 )
      return -1073741819;
    if ( (v7 & 1) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( (unsigned __int16)v26 + v7 > MmUserProbeAddress || (unsigned __int16)v26 + v7 < v7 )
      *(_BYTE *)MmUserProbeAddress = 0;
    ProbeForWrite(a2, a3, 2);
    if ( a4 )
    {
      v9 = a4;
      if ( (unsigned int)a4 >= MmUserProbeAddress )
        v9 = (_WORD *)MmUserProbeAddress;
      *v9 = *v9;
    }
    if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v6, (int)&SeSystemEnvironmentPrivilege) )
      return -1073741727;
  }
  else
  {
    v26 = *a1;
    v27 = a1[1];
  }
  if ( NlsMbCodePageTag )
    v10 = RtlxUnicodeStringToOemSize((unsigned __int16 *)&v26, a2, a3, (unsigned __int8)NlsMbCodePageTag);
  else
    v10 = ((unsigned int)(unsigned __int16)v26 + 2) >> 1;
  v29 = ExAllocatePoolWithTag(512, v10, 1920364101);
  if ( !v29 )
    return -1073741670;
  v28[1] = v10;
  v8 = RtlUnicodeStringToAnsiString(v28, (unsigned __int16 *)&v26, 0, v11);
  if ( v8 >= 0 )
  {
    v12 = ExAllocatePoolWithTag(512, 1024, 1920364101);
    if ( v12 )
    {
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v13 + 308);
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
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
      dword_61A084 = v25;
      v17 = HalGetEnvironmentVariable(v29, 1024, v12);
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
      ExFreePoolWithTag(v29);
      if ( v17 )
      {
        ExFreePoolWithTag(v12);
        v8 = -1073741823;
      }
      else
      {
        RtlInitAnsiString((unsigned int)v28, v12);
        v27 = a2;
        HIWORD(v26) = a3;
        LOWORD(v26) = 0;
        v8 = RtlAnsiStringToUnicodeString((unsigned __int16 *)&v26, v28, 0, a3);
        if ( a4 )
          *a4 = v26;
        ExFreePoolWithTag(v12);
      }
    }
    else
    {
      ExFreePoolWithTag(v29);
      v8 = -1073741670;
    }
  }
  else
  {
    ExFreePoolWithTag(v29);
  }
  return v8;
}

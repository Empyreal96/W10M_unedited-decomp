// NtLoadDriver 
 
int __fastcall NtLoadDriver(int *a1)
{
  int *v1; // r4
  unsigned int v2; // r5
  unsigned int v3; // r10
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r3
  unsigned int v7; // r1
  int v8; // r0
  int v9; // r3
  char v11; // [sp+8h] [bp-60h]
  int v12; // [sp+18h] [bp-50h] BYREF
  int v13; // [sp+1Ch] [bp-4Ch]
  _DWORD v14[4]; // [sp+20h] [bp-48h] BYREF
  _DWORD v15[14]; // [sp+30h] [bp-38h] BYREF

  v1 = a1;
  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_BYTE *)(v3 + 0x15A);
  if ( v11 )
  {
    v4 = SeSinglePrivilegeCheck(SeLoadDriverPrivilege, dword_922B84, v11, (int)&SeLoadDriverPrivilege);
    if ( !v4 )
      return -1073741727;
    if ( (unsigned int)v1 >= MmUserProbeAddress )
      v1 = (int *)MmUserProbeAddress;
    v12 = *v1;
    v6 = v1[1];
    v13 = v6;
    v7 = (unsigned __int16)v12;
    if ( !(_WORD)v12 )
      return -1073741811;
    if ( (v6 & 1) != 0 )
      ExRaiseDatatypeMisalignment(v4);
    if ( (unsigned __int16)v12 + v6 > MmUserProbeAddress || (unsigned __int16)v12 + v6 < v6 )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v7 = (unsigned __int16)v12;
    }
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v9 = 40;
      else
        v9 = 32;
      v8 = ExAllocatePoolWithTagPriority(1, v7, 538996553, v9);
      if ( !v8 )
        RtlRaiseStatus(-1073741670);
    }
    else
    {
      v8 = ExAllocatePoolWithQuotaTag(1u, v7, 538996553);
    }
    v2 = v8;
    memmove(v8, v13, (unsigned __int16)v12);
    v13 = v2;
  }
  else
  {
    v12 = *a1;
    v13 = a1[1];
  }
  if ( v11 && PsIsCurrentThreadInServerSilo() )
  {
    if ( v2 )
      ExFreePoolWithTag(v2);
    v5 = 0;
  }
  else
  {
    KeInitializeEvent((int)v15, 0, 0);
    v15[4] = 0;
    v15[5] = &v12;
    if ( *(_DWORD *)(v3 + 116) == PsInitialSystemProcess )
    {
      IopLoadUnloadDriver(v14);
    }
    else
    {
      v14[2] = IopLoadUnloadDriver;
      v14[3] = v14;
      v14[0] = 0;
      ExQueueWorkItem(v14, 1);
      KeWaitForSingleObject((unsigned int)v15, 6, 0, 0, 0);
    }
    if ( v2 )
      ExFreePoolWithTag(v2);
    v5 = v15[6];
  }
  return v5;
}

// NtReplacePartitionUnit 
 
int __fastcall NtReplacePartitionUnit(unsigned int a1, unsigned int a2, int a3)
{
  int v6; // r5
  int v7; // r9
  int v8; // r6
  int v9; // r4
  int v10; // r8
  int v11; // r0
  _BYTE *v12; // r3
  int v13; // r0
  int v14; // r3
  int v15; // r0
  int v16; // r3
  int v18; // [sp+8h] [bp-48h] BYREF
  int v19; // [sp+Ch] [bp-44h]
  _DWORD v20[4]; // [sp+10h] [bp-40h] BYREF
  int v21; // [sp+20h] [bp-30h] BYREF
  int v22; // [sp+24h] [bp-2Ch]
  int v23; // [sp+28h] [bp-28h] BYREF
  int v24; // [sp+2Ch] [bp-24h]

  v6 = 0;
  v18 = 0;
  v7 = 0;
  v20[1] = 0;
  v19 = 0;
  v20[0] = 0;
  v8 = 0;
  v20[2] = 0;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) != 1 )
  {
    v9 = -1073741790;
LABEL_3:
    v10 = 0;
    goto LABEL_41;
  }
  v11 = SeSinglePrivilegeCheck(SeShutdownPrivilege, dword_922B8C, 1);
  if ( !v11 )
  {
    v9 = -1073741727;
    goto LABEL_3;
  }
  if ( a3 == 0x80000000 )
  {
    v9 = IoReplacePartitionUnit(0, 0);
    goto LABEL_3;
  }
  if ( a3 )
  {
    v9 = -1073741583;
    goto LABEL_3;
  }
  if ( (a2 & 3) != 0 )
    ExRaiseDatatypeMisalignment(v11);
  v12 = (_BYTE *)MmUserProbeAddress;
  if ( a2 + 8 > MmUserProbeAddress || a2 + 8 < a2 )
  {
    *(_BYTE *)MmUserProbeAddress = 0;
    v12 = (_BYTE *)MmUserProbeAddress;
  }
  if ( (a1 & 3) != 0 )
    ExRaiseDatatypeMisalignment(v11);
  if ( a1 + 8 > (unsigned int)v12 || a1 + 8 < a1 )
    *v12 = 0;
  v21 = *(_DWORD *)a2;
  v22 = *(_DWORD *)(a2 + 4);
  v23 = *(_DWORD *)a1;
  v24 = *(_DWORD *)(a1 + 4);
  if ( !(_WORD)v23 || (unsigned __int16)v23 > 0xC9u || (v23 & 0x10000) != 0 )
  {
    v9 = -1073741585;
    goto LABEL_40;
  }
  if ( !(_WORD)v21 || (unsigned __int16)v21 > 0xC9u || (v21 & 0x10000) != 0 )
  {
    v9 = -1073741584;
    goto LABEL_40;
  }
  v9 = PiControlMakeUserModeCallersCopy(&v18);
  if ( v9 < 0 )
  {
    v6 = v18;
LABEL_40:
    v10 = v19;
    goto LABEL_41;
  }
  v9 = PiControlMakeUserModeCallersCopy(v20);
  v6 = v18;
  v10 = v20[0];
  if ( v9 >= 0 )
  {
    v22 = v18;
    HIWORD(v21) = v21;
    v24 = v20[0];
    HIWORD(v23) = v23;
    v13 = PnpDeviceObjectFromDeviceInstance(&v21);
    v7 = v13;
    if ( v13 && (v14 = *(_DWORD *)(*(_DWORD *)(v13 + 176) + 20)) != 0 && (*(_DWORD *)(v14 + 268) & 0x20000) == 0 )
    {
      v15 = PnpDeviceObjectFromDeviceInstance(&v23);
      v8 = v15;
      if ( v15 && (v16 = *(_DWORD *)(*(_DWORD *)(v15 + 176) + 20)) != 0 && (*(_DWORD *)(v16 + 268) & 0x20000) == 0 )
        v9 = ((int (*)(void))IoReplacePartitionUnit)();
      else
        v9 = -1073741585;
    }
    else
    {
      v9 = -1073741584;
    }
  }
LABEL_41:
  if ( v7 )
    ObfDereferenceObjectWithTag(v7);
  if ( v8 )
    ObfDereferenceObjectWithTag(v8);
  if ( v6 )
    ExFreePoolWithTag(v6);
  if ( v10 )
    ExFreePoolWithTag(v10);
  return v9;
}

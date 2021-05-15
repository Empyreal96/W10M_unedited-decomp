// NtGetMUIRegistryInfo 
 
int __fastcall NtGetMUIRegistryInfo(int a1, unsigned int a2, _BYTE *a3, int a4)
{
  _DWORD *v4; // r9
  int v5; // r6
  int v6; // r4
  unsigned int v7; // r8
  unsigned int *v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r1
  _DWORD *v12; // r2
  int v13; // r3
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  int v18; // [sp+14h] [bp-7Ch]
  int v20; // [sp+20h] [bp-70h] BYREF
  _BYTE v21[16]; // [sp+28h] [bp-68h] BYREF
  _DWORD v22[7]; // [sp+38h] [bp-58h] BYREF
  int v23; // [sp+54h] [bp-3Ch]
  int v24; // [sp+58h] [bp-38h]
  int v25; // [sp+5Ch] [bp-34h]
  int v26; // [sp+60h] [bp-30h]
  int v27; // [sp+64h] [bp-2Ch]
  int v28; // [sp+68h] [bp-28h]
  int v29; // [sp+6Ch] [bp-24h]
  int v30; // [sp+70h] [bp-20h]
  int varg_r0; // [sp+98h] [bp+8h]
  unsigned int varg_r1; // [sp+9Ch] [bp+Ch]
  _BYTE *varg_r2; // [sp+A0h] [bp+10h]
  int varg_r3; // [sp+A4h] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  v4 = (_DWORD *)a2;
  varg_r1 = a2;
  v5 = a1;
  varg_r0 = a1;
  v18 = 0;
  if ( !*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) || InitSafeBootMode )
  {
    v6 = -1073741823;
    goto LABEL_59;
  }
  if ( !a2 )
  {
    if ( (a1 & 0xA) == 0 )
    {
LABEL_6:
      v6 = -1073741811;
      goto LABEL_59;
    }
    v7 = 0;
    goto LABEL_13;
  }
  v8 = (unsigned int *)a2;
  if ( a2 >= MmUserProbeAddress )
    v8 = (unsigned int *)MmUserProbeAddress;
  v7 = *v8;
  if ( !*v8 )
  {
LABEL_13:
    if ( a3 )
      goto LABEL_6;
    goto LABEL_14;
  }
  if ( !a3 )
    goto LABEL_6;
LABEL_14:
  if ( !a1 )
    v5 = 1;
  if ( (v5 & 0xFFFFFFF4) != 0 )
    goto LABEL_17;
  if ( MUIRegistryLock || (v6 = MUIInitializeResourceLock(&MUIRegistryLock), (v6 & 0xC0000000) != -1073741824) )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(__int16 *)(v9 + 0x134) - 1;
    *(_WORD *)(v9 + 308) = v10;
    ExAcquireResourceExclusiveLite(MUIRegistryLock, 1, v9, v10);
    v18 = 1;
    if ( MUIRegistryInfo == -1 )
    {
      if ( (v5 & 2) == 0 )
      {
        v6 = -1073741823;
        goto LABEL_59;
      }
      MUIRegistryInfo = 0;
      MUIRegistryInfoSize = 0;
      goto LABEL_58;
    }
    if ( (v5 & 1) == 0 )
    {
      if ( (v5 & 2) != 0 )
      {
        if ( MUIRegistryInfo )
        {
          ExFreePoolWithTag(MUIRegistryInfo);
          MUIRegistryInfo = 0;
          MUIRegistryInfoSize = 0;
          if ( (v5 & 8) != 0 )
            ++MEMORY[0xFFFF93A4];
        }
      }
      else
      {
        if ( (v5 & 8) == 0 )
        {
LABEL_17:
          v6 = -1073741811;
          goto LABEL_59;
        }
        v13 = ++MEMORY[0xFFFF93A4];
        if ( MUIRegistryInfo )
          *(_DWORD *)(MUIRegistryInfo + 12) = v13;
      }
LABEL_58:
      v6 = 0;
      goto LABEL_59;
    }
    v11 = 0;
    if ( !MUIRegistryInfo )
    {
      KeInitializeEvent((int)v21, 1, 0);
      v22[6] = v21;
      v23 = 0;
      v24 = 0;
      v25 = 0;
      v26 = (unsigned __int16)PsInstallUILanguageId;
      v27 = 0;
      v28 = (unsigned __int16)PsMachineUILanguageId;
      v29 = 0;
      v30 = -1073741823;
      v22[0] = 24;
      v22[1] = 0;
      v22[3] = 512;
      v22[2] = 0;
      v22[4] = 0;
      v22[5] = 0;
      v6 = PsCreateSystemThread((int)&v20, 0x1FFFFF, (int)v22);
      if ( v6 >= 0 )
      {
        ZwClose();
        v6 = KeWaitForSingleObject((unsigned int)v21, 0, 0, 0, 0);
        if ( v6 >= 0 )
        {
          v6 = v30;
          if ( v30 >= 0 )
          {
            MUIRegistryInfo = v23;
            MUIRegistryInfoSize = v24;
            if ( !v25 )
              MUIBugCheck(32770);
            if ( !v27 )
            {
              if ( PsUILanguageComitted )
                MUIBugCheck(32769);
              MigrateOOBELanguageToInstallationLanguage();
            }
            if ( !v29 )
              PsMachineUILanguageId = PsInstallUILanguageId;
          }
        }
      }
      if ( v6 < 0 )
      {
        MUIRegistryInfo = -1;
        MUIRegistryInfoSize = 0;
        goto LABEL_59;
      }
      v11 = 0;
    }
    if ( v7 )
    {
      if ( v7 < MUIRegistryInfoSize )
      {
        v6 = -1073741789;
LABEL_46:
        v12 = v4;
        if ( (unsigned int)v4 >= MmUserProbeAddress )
          v12 = (_DWORD *)MmUserProbeAddress;
        *v12 = *v12;
        *v4 = MUIRegistryInfoSize;
        if ( v11 )
        {
          ProbeForWrite(a3, v7, 1);
          memset(a3, 0, v7);
          memmove((int)a3, MUIRegistryInfo, MUIRegistryInfoSize);
        }
        goto LABEL_59;
      }
      v11 = 1;
    }
    v6 = 0;
    goto LABEL_46;
  }
LABEL_59:
  if ( v18 )
  {
    v14 = ExReleaseResourceLite(MUIRegistryLock);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery(v14);
  }
  return v6;
}

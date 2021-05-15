// CmpSaveBootControlSet 
 
int __fastcall CmpSaveBootControlSet(int a1)
{
  int v2; // r4
  int v3; // r0
  unsigned int v4; // r5
  int v5; // r0
  int v6; // r5
  int v7; // r6
  int v8; // r2
  int v9; // r0
  int v10; // r7
  int v11; // r0
  int v12; // r8
  int v13; // r4
  int v15; // [sp+10h] [bp-158h]
  int v16; // [sp+14h] [bp-154h] BYREF
  int v17; // [sp+18h] [bp-150h] BYREF
  int v18; // [sp+1Ch] [bp-14Ch] BYREF
  int v19; // [sp+20h] [bp-148h] BYREF
  int v20; // [sp+24h] [bp-144h] BYREF
  int v21; // [sp+28h] [bp-140h] BYREF
  int v22; // [sp+2Ch] [bp-13Ch]
  char *v23; // [sp+30h] [bp-138h]
  int v24; // [sp+34h] [bp-134h]
  unsigned int v25; // [sp+38h] [bp-130h]
  int v26; // [sp+3Ch] [bp-12Ch]
  int v27; // [sp+40h] [bp-128h]
  char v28[8]; // [sp+48h] [bp-120h] BYREF
  unsigned __int16 v29[140]; // [sp+50h] [bp-118h] BYREF

  v16 = 0;
  v21 = 24;
  v22 = 0;
  v23 = (char *)&CmRegistryMachineSystemCurrentControlSet;
  v24 = 576;
  v25 = 0;
  v26 = 0;
  v2 = NtOpenKey();
  if ( v2 < 0 )
    return v2;
  if ( NtQuerySecurityObject(v15, 4, 0, 0, &v16) == -1073741789 )
  {
    v3 = ExAllocatePoolWithTag(1, v16, 538987843);
    v4 = v3;
    if ( !v3 || NtQuerySecurityObject(v15, 4, v3, v16, &v16) >= 0 )
      goto LABEL_7;
    ExFreePoolWithTag(v4);
  }
  v4 = 0;
LABEL_7:
  swprintf_s((int)v29, 128, (int)L"\\Registry\\Machine\\System\\ControlSet%03d", a1);
  RtlInitUnicodeString((unsigned int)v28, v29);
  v21 = 24;
  v22 = 0;
  v23 = v28;
  v24 = 576;
  v25 = v4;
  v26 = 0;
  v2 = NtCreateKey((int)&v20, 131103, (int)&v21, 0, 0);
  if ( v4 )
    ExFreePoolWithTag(v4);
  if ( v2 >= 0 )
  {
    v2 = ObReferenceObjectByHandle(v15, 131097, (int)CmKeyObjectType, 0, (int)&v18, 0);
    if ( v2 >= 0 )
    {
      v2 = ObReferenceObjectByHandle(v20, 131078, (int)CmKeyObjectType, 0, (int)&v19, 0);
      if ( v2 >= 0 )
      {
        CmpLockRegistryExclusive();
        v7 = v18;
        v6 = v19;
        v8 = *(_DWORD *)(v19 + 4);
        v9 = *(_DWORD *)(v18 + 4);
        if ( v27 == 1 )
        {
          v17 = -1;
          v10 = CmpCopySyncTree(
                  *(_DWORD *)(v9 + 20),
                  *(_DWORD *)(v9 + 24),
                  *(_DWORD *)(v8 + 20),
                  *(_DWORD *)(v8 + 24),
                  2,
                  0);
          v11 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(*(_DWORD *)(v7 + 4) + 20) + 4))(
                  *(_DWORD *)(*(_DWORD *)(v7 + 4) + 20),
                  *(_DWORD *)(*(_DWORD *)(v7 + 4) + 24),
                  &v17);
          if ( v11 )
          {
            v12 = *(_DWORD *)(v11 + 52);
            (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(*(_DWORD *)(v7 + 4) + 20) + 8))(
              *(_DWORD *)(*(_DWORD *)(v7 + 4) + 20),
              &v17);
            v13 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(*(_DWORD *)(v6 + 4) + 20) + 4))(
                    *(_DWORD *)(*(_DWORD *)(v6 + 4) + 20),
                    *(_DWORD *)(*(_DWORD *)(v6 + 4) + 24),
                    &v17);
            if ( v13 )
            {
              if ( HvpMarkCellDirty(*(_DWORD *)(*(_DWORD *)(v6 + 4) + 20), *(_DWORD *)(*(_DWORD *)(v6 + 4) + 24), 0, 0) )
                *(_WORD *)(v13 + 52) = v12;
              (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(*(_DWORD *)(v6 + 4) + 20) + 8))(
                *(_DWORD *)(*(_DWORD *)(v6 + 4) + 20),
                &v17);
            }
          }
        }
        else
        {
          v10 = CmpCopySyncTree(
                  *(_DWORD *)(v9 + 20),
                  *(_DWORD *)(v9 + 24),
                  *(_DWORD *)(v8 + 20),
                  *(_DWORD *)(v8 + 24),
                  2,
                  1);
        }
        CmpRebuildKcbCache(*(_DWORD *)(v6 + 4));
        if ( v10 )
          v2 = 0;
        else
          v2 = -1073741492;
        CmpUnlockRegistry();
        ObfDereferenceObject(v7);
        v5 = v6;
      }
      else
      {
        v5 = v18;
      }
      ObfDereferenceObject(v5);
    }
    NtClose();
  }
  NtClose();
  return v2;
}

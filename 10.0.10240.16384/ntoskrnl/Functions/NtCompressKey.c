// NtCompressKey 
 
int __fastcall NtCompressKey(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r4
  int v7; // r6
  int v8; // r5
  int i; // r4
  int v10; // r2
  __int64 v11; // kr00_8
  int v12; // r3
  int v13; // r1
  _DWORD *v14; // r0
  unsigned __int64 v15; // r2
  int v17[6]; // [sp+8h] [bp-18h] BYREF

  v17[0] = a4;
  v5 = CmCheckNoTxContext();
  if ( v5 < 0 )
    return v5;
  v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( !SeSinglePrivilegeCheck(SeBackupPrivilege, dword_922BA4, v6, (int)&SeBackupPrivilege) )
    return -1073741727;
  v7 = a1 & 3;
  v5 = CmObReferenceObjectByHandle(a1, 131078, (int)CmKeyObjectType, v6, v17, 0);
  if ( v5 < 0 )
    return v5;
  v8 = v17[0];
  for ( i = *(_DWORD *)(*(_DWORD *)(v17[0] + 4) + 20); ; CmpWaitOnHiveWriteQueue(i, v13, 0) )
  {
    CmpLockRegistryExclusive();
    v10 = *(_DWORD *)(v8 + 4);
    if ( (*(_DWORD *)(v10 + 4) & 0x20000) != 0 )
    {
      if ( (*(_DWORD *)(v8 + 24) & 1) != 0 )
        v5 = -1073740763;
      else
        v5 = -1073741444;
      goto LABEL_24;
    }
    v11 = *(_QWORD *)(v10 + 20);
    if ( HIDWORD(v11) != *(_DWORD *)(*(_DWORD *)(v11 + 32) + 36) )
      goto LABEL_20;
    v12 = *(_DWORD *)(i + 3312);
    if ( (v12 & 2) != 0 )
    {
      ExAcquireResourceExclusiveLite(*(_DWORD *)(i + 1872), 1, SHIDWORD(v11), v11);
      v13 = i + 3300;
      continue;
    }
    if ( (v12 & 1) == 0 )
      break;
    ExAcquireResourceExclusiveLite(*(_DWORD *)(i + 1872), 1, SHIDWORD(v11), v11);
    v13 = i + 3288;
  }
  v14 = *(_DWORD **)(*(_DWORD *)(v8 + 4) + 20);
  if ( v14 == CmpMasterHive || (v7 & 0xFFFFFFFC) != 0 || !v14[444] || (LODWORD(v15) = v14[23], (v15 & 0x8003) != 0) )
  {
LABEL_20:
    v5 = -1073741811;
    goto LABEL_24;
  }
  HIDWORD(v15) = v14[8];
  if ( v7 == 3 )
    v7 = 0;
  *(_QWORD *)(HIDWORD(v15) + 168) = (unsigned int)v7;
  HvMarkBaseBlockDirty((int)v14, v15);
  v5 = 0;
LABEL_24:
  CmpUnlockRegistry();
  ObfDereferenceObject(v8);
  return v5;
}

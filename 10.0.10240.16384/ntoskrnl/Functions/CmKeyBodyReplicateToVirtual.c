// CmKeyBodyReplicateToVirtual 
 
int __fastcall CmKeyBodyReplicateToVirtual(int *a1, int a2, int *a3)
{
  int v3; // r4
  int v7; // r0
  int v8; // r1
  unsigned int *v9; // r2
  unsigned int v10; // r3
  int v11; // r0
  int v12; // r1
  int v13; // r0
  int v14; // r6
  char v16[4]; // [sp+10h] [bp-80h] BYREF
  int v17; // [sp+14h] [bp-7Ch] BYREF
  __int16 v18; // [sp+18h] [bp-78h] BYREF
  int v19; // [sp+1Ah] [bp-76h]
  __int16 v20; // [sp+1Eh] [bp-72h]
  char v21[8]; // [sp+20h] [bp-70h] BYREF
  int v22; // [sp+28h] [bp-68h] BYREF
  int v23[19]; // [sp+2Ch] [bp-64h] BYREF

  v3 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v16[0] = 0;
  while ( 1 )
  {
    if ( !CmpVEEnabled )
      return v3;
    v7 = *(_DWORD *)(*a1 + 4);
    if ( (*(_WORD *)(v7 + 106) & 0x200) != 0 || CmpIsMasterHive(v7) || CmpIsSystemEntity(a3, v8, v9, v10) )
      return v3;
    CmpLockRegistry();
    CmpLockKcbExclusive(*(_DWORD **)(*a1 + 4));
    v11 = *(_DWORD *)(*a1 + 4);
    if ( (*(_DWORD *)(v11 + 4) & 0x20000) != 0 )
    {
      v3 = -1073741444;
      goto LABEL_33;
    }
    if ( CmpReparseToVirtualPath(v11) )
      goto LABEL_21;
    v12 = *(_DWORD *)(*a1 + 4);
    if ( (*(_DWORD *)(v12 + 104) & 0x20) != 0 )
    {
      RtlFreeAnsiString(&v18);
      v3 = -1073741790;
LABEL_33:
      CmpUnlockKcb(*(_DWORD **)(*a1 + 4));
      CmpUnlockRegistry();
      return v3;
    }
    v3 = CmpCheckAdminAccess(a2, *(_DWORD *)(v12 + 48) + 24, v16);
    if ( v3 < 0 )
      goto LABEL_21;
    if ( !v16[0] )
      break;
    v13 = CmpReplicateKeyToVirtual(*(_DWORD *)(*a1 + 4), &v17);
    v3 = v13;
    if ( v13 != -1073741739 )
    {
      if ( v13 >= 0 )
      {
        v16[0] = 0;
        v3 = CmpExamineSaclForAuditEvent(*(_DWORD *)(*(_DWORD *)(*a1 + 4) + 48) + 24, v16);
        if ( v3 >= 0 )
        {
          if ( v16[0] )
            v3 = CmpReportAuditVirtualizationEvent(*(_DWORD *)(*a1 + 4));
          if ( v3 >= 0 && !CmpReparseToVirtualPath(*(_DWORD *)(*a1 + 4)) )
            v3 = -1073741670;
        }
      }
      goto LABEL_21;
    }
    CmpUnlockKcb(*(_DWORD **)(*a1 + 4));
    CmpUnlockRegistry();
    RtlFreeAnsiString(&v18);
  }
  v3 = -1073741790;
LABEL_21:
  CmpUnlockKcb(*(_DWORD **)(*a1 + 4));
  if ( v3 >= 0 )
  {
    v3 = CmpGetVirtualizationIDFromFullVirtualPath(&v18, v21);
    if ( v3 >= 0 )
    {
      v3 = CmpGetMappingHiveForString(v21, &v17);
      if ( v3 >= 0 )
        CmpSearchKeyControlBlockTree((int (__fastcall *)(int, int, int))CmpSyncKcbCacheForHive, v17, 0);
    }
  }
  CmpUnlockRegistry();
  if ( v3 >= 0 )
  {
    memset(v23, 0, sizeof(v23));
    v14 = *a1;
    v22 = 8;
    v23[12] = *(_DWORD *)(v14 + 28);
    v3 = ObReferenceObjectByName((int)&v18, 576, 0, 0, (int)CmKeyObjectType, 0, (int)&v22, a1);
    if ( v3 < 0 )
      *a1 = v14;
    else
      ObfDereferenceObject(v14);
  }
  RtlFreeAnsiString(&v18);
  return v3;
}

// CmGetSystemDriverList 
 
int __fastcall CmGetSystemDriverList(int a1)
{
  int v2; // r4
  int v3; // r1
  int v4; // r5
  int v5; // r0
  int v6; // r2
  int v7; // r6
  int *v9; // r2
  int i; // r1
  int v11; // r0
  int v12; // r4
  int *v13; // r6
  int v14; // r7
  int v15; // r8
  int v16; // [sp+4h] [bp-5Ch]
  char v17[4]; // [sp+10h] [bp-50h] BYREF
  int v18; // [sp+14h] [bp-4Ch]
  int v19; // [sp+18h] [bp-48h] BYREF
  int v20; // [sp+1Ch] [bp-44h]
  int v21[2]; // [sp+20h] [bp-40h] BYREF
  int v22; // [sp+28h] [bp-38h]
  int v23; // [sp+2Ch] [bp-34h]
  unsigned __int16 *v24; // [sp+30h] [bp-30h]
  int v25; // [sp+34h] [bp-2Ch]
  int v26; // [sp+38h] [bp-28h]
  int v27; // [sp+3Ch] [bp-24h]

  v21[1] = (int)v21;
  v21[0] = (int)v21;
  v22 = 24;
  v23 = 0;
  v25 = 576;
  v24 = CmRegistryMachineSystemName;
  v26 = 0;
  v27 = 0;
  if ( NtOpenKey() < 0 )
    JUMPOUT(0x96852C);
  if ( ObReferenceObjectByHandle(v18, 1, (int)CmKeyObjectType, 0, (int)&v19, 0) < 0 )
    JUMPOUT(0x968526);
  CmpLockRegistryExclusive();
  v2 = v19;
  v3 = *(_DWORD *)(*(_DWORD *)(v19 + 4) + 24);
  v4 = *(_DWORD *)(*(_DWORD *)(v19 + 4) + 20);
  v20 = v4;
  v5 = CmpFindControlSet(v4, v3, (int)&CmpCurrentString, v17);
  v7 = v5;
  if ( v5 == -1 )
    JUMPOUT(0x96851C);
  if ( !CmpFindDrivers(v4, v5, v6, (int)v21, (int)v21, v16, a1) )
    JUMPOUT(0x968516);
  if ( !CmpSortDriverList(v4, v7, (int)v21) )
    return sub_968514();
  CmpUnlockRegistry();
  ObfDereferenceObject(v2);
  NtClose();
  v9 = (int *)v21[0];
  for ( i = 0; v9 != v21; ++i )
    v9 = (int *)*v9;
  v11 = ExAllocatePoolWithTag(512, 4 * (i + 1), 538987843);
  v12 = v11;
  v19 = v11;
  if ( !v11 )
    KeBugCheckEx(103, 2, 1, 0, 0);
  v13 = (int *)v21[0];
  v14 = 0;
  if ( (int *)v21[0] != v21 )
  {
    v15 = v11;
    do
    {
      v23 = 0;
      v24 = (unsigned __int16 *)(v13 + 4);
      v26 = 0;
      v27 = 0;
      v22 = 24;
      v25 = 64;
      if ( NtOpenKey() >= 0 )
      {
        ++v14;
        v15 += 4;
      }
      v13 = (int *)*v13;
    }
    while ( v13 != v21 );
    v12 = v19;
    v4 = v20;
  }
  *(_DWORD *)(v12 + 4 * v14) = 0;
  CmpFreeDriverList(v4, v21);
  return v12;
}

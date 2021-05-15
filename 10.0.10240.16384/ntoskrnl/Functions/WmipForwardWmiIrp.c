// WmipForwardWmiIrp 
 
int __fastcall WmipForwardWmiIrp(_DWORD *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v9; // r0
  int v10; // r6
  int v11; // r2
  int (__fastcall **v13)(int, int, int, int, _DWORD, int *); // r4
  int v14; // r8
  int v15; // r3
  int v16; // r2
  int v17; // r3
  int v18; // r2
  int v19; // r2
  int v20; // r0
  int v21; // r4
  int v22; // r0
  int v23; // r3
  int v24; // [sp+8h] [bp-38h] BYREF
  int v25; // [sp+Ch] [bp-34h]
  char v26[48]; // [sp+10h] [bp-30h] BYREF

  v25 = a4;
  v9 = WmipFindRegEntryByDevice(a3);
  v10 = v9;
  if ( !v9 )
    JUMPOUT(0x7D6386);
  v11 = *(_DWORD *)(v9 + 24);
  if ( (v11 & 0x20000000) != 0 )
    return sub_7D6380();
  v13 = *(int (__fastcall ***)(int, int, int, int, _DWORD, int *))(v9 + 8);
  if ( (v11 & 0x10000000) != 0 )
  {
    v24 = 0;
    v22 = (*v13)(a2, a4, a5, a6, v13, &v24);
    v23 = v24;
    v21 = v22;
    a1[6] = v22;
    a1[7] = v23;
    WmipUnreferenceRegEntry(v10);
  }
  else
  {
    if ( a2 != 11
      && a2 != 8
      && (!memcmp(a6 + 24, (unsigned int)WmipDataProviderPnpidGuid, 16)
       || !memcmp(a6 + 24, (unsigned int)WmipDataProviderPnPIdInstanceNamesGuid, 16)) )
    {
      JUMPOUT(0x7D6394);
    }
    v14 = IoGetAttachedDeviceReference((int)v13);
    v15 = *(char *)(WmipServiceDeviceObject + 48);
    v24 = (char)(*(_BYTE *)(v14 + 48) + 1);
    if ( v24 > v15 )
      JUMPOUT(0x7D63A4);
    KeInitializeEvent((int)v26, 1, 0);
    v16 = a1[24];
    *(_DWORD *)(v16 - 8) = SmKmGenericCompletion;
    *(_DWORD *)(v16 - 4) = v26;
    *(_BYTE *)(v16 - 37) = -32;
    v17 = a1[24];
    *(_BYTE *)(v17 - 40) = 23;
    v18 = v25;
    *(_BYTE *)(v17 - 39) = a2;
    *(_DWORD *)(v17 - 32) = v13;
    *(_DWORD *)(v17 - 28) = v18;
    *(_DWORD *)(v17 - 24) = a5;
    *(_DWORD *)(v17 - 20) = a6;
    v19 = a1[24];
    a1[6] = -1073741637;
    *(_BYTE *)(v19 + 3) |= 1u;
    v20 = IofCallDriver(v14, (int)a1);
    v21 = v20;
    if ( v20 == 259 )
      JUMPOUT(0x7D63BC);
    if ( v20 == -1073741637 )
    {
      v21 = -1073741163;
      a1[6] = -1073741163;
    }
    if ( (a2 == 11 || a2 == 8) && v21 >= 0 && a1[7] > 0x14u )
      WmipTranslatePDOInstanceNames(a1, a2, a5, v10);
    WmipUnreferenceRegEntry(v10);
    ObfDereferenceObject(v14);
  }
  return v21;
}

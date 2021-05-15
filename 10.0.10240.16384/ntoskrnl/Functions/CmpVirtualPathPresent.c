// CmpVirtualPathPresent 
 
BOOL __fastcall CmpVirtualPathPresent(int *a1, int a2, int a3)
{
  int v3; // r5
  _DWORD *v5; // r7
  BOOL v6; // r4
  int v7; // r0
  int (__fastcall **v8)(void *); // r6
  _DWORD *v10; // [sp+8h] [bp-20h] BYREF
  int v11; // [sp+Ch] [bp-1Ch] BYREF
  int (__fastcall **v12)(void *); // [sp+10h] [bp-18h] BYREF
  int v13[5]; // [sp+14h] [bp-14h] BYREF

  v3 = 0;
  v11 = -1;
  v10 = 0;
  v5 = CmpMasterHive;
  if ( CmpGetCmHiveFromVirtualPath((int)a1, (int)&v10, a3, (int)&CmpMasterHive) < 0
    || CmpBlockTwoHiveWrites(v5, v10, 1) < 0 )
  {
    return 0;
  }
  v7 = CmpFindPathByName(0, a1, 0, v13, &v12);
  v8 = v12;
  v6 = v7;
  if ( v12 )
    v3 = ((int (__fastcall *)(int (__fastcall **)(void *), int, int *))v12[1])(v12, v13[0], &v11);
  if ( v6 )
  {
    if ( v3 )
      v6 = CmpVEEnabled && (*(_WORD *)(v3 + 2) & 0x100) != 0;
    else
      v6 = 0;
  }
  if ( v3 )
    ((void (__fastcall *)(int (__fastcall **)(void *), int *))v8[2])(v8, &v11);
  CmpUnblockTwoHiveWrites(v5, v10);
  return v6;
}

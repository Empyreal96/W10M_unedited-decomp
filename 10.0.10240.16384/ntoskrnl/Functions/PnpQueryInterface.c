// PnpQueryInterface 
 
int __fastcall PnpQueryInterface(int a1, int a2, __int16 a3, unsigned int a4, int a5, int a6)
{
  __int16 v6; // r4
  int v10; // r5
  _DWORD *v11; // r0
  int v12; // r2
  int v13; // r4
  char v15[8]; // [sp+10h] [bp-30h] BYREF
  char v16[40]; // [sp+18h] [bp-28h] BYREF

  v6 = a4;
  if ( a4 < 0x10 )
    return -1073741811;
  memset((_BYTE *)a6, 0, a4);
  *(_WORD *)a6 = v6;
  *(_WORD *)(a6 + 2) = a3;
  KeInitializeEvent((int)v16, 0, 0);
  v10 = IoGetAttachedDeviceReference(a1);
  v11 = IoBuildSynchronousFsdRequest(27, v10, 0, 0, 0, (int)v16, (int)v15);
  if ( v11 )
  {
    v12 = v11[24];
    *((_BYTE *)v11 + 32) = 0;
    v11[6] = -1073741637;
    *(_BYTE *)(v12 - 39) = 8;
    *(_DWORD *)(v12 - 24) = a6;
    *(_DWORD *)(v12 - 20) = a5;
    *(_DWORD *)(v12 - 32) = a2;
    *(_WORD *)(v12 - 28) = v6;
    *(_WORD *)(v12 - 26) = a3;
    v13 = IofCallDriver(v10, (int)v11);
    if ( v13 == 259 )
      return sub_7C9AE0();
  }
  else
  {
    v13 = -1073741670;
  }
  ObfDereferenceObject(v10);
  return v13;
}

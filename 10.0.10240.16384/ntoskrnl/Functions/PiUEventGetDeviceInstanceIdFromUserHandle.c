// PiUEventGetDeviceInstanceIdFromUserHandle 
 
int __fastcall PiUEventGetDeviceInstanceIdFromUserHandle(int a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int v6; // r3
  int v7; // r7
  int v8; // r6
  int v9; // r5
  int v11; // r0
  int v12; // r4
  int v13; // [sp+8h] [bp-20h] BYREF
  int v14[7]; // [sp+Ch] [bp-1Ch] BYREF

  v14[0] = a4;
  v13 = 0;
  *a3 = 0;
  v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v7 = ObReferenceObjectByHandle(a1, 0, IoFileObjectType, v6, v14);
  v8 = v14[0];
  if ( v7 >= 0 )
  {
    v7 = PnpGetRelatedTargetDevice(v14[0], &v13);
    v9 = v13;
    if ( v7 >= 0 )
    {
      *a2 = v13 + 20;
      v11 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      v13 = 0;
      v12 = PsReferencePrimaryToken(v11);
      SeQueryInformationToken(v12, 29, &v13);
      ObfDereferenceObject(v12);
      if ( v13 )
        *a3 = *(_DWORD *)(v9 + 16);
    }
    if ( v9 )
      ObfDereferenceObject(*(_DWORD *)(v9 + 16));
  }
  if ( v8 )
    ObfDereferenceObject(v8);
  return v7;
}

// SmKmStoreFileOpenVolume 
 
int __fastcall SmKmStoreFileOpenVolume(int a1, _DWORD *a2, int *a3)
{
  int v6; // r6
  int v7; // r5
  _DWORD *v8; // r4
  int v9; // r0
  _DWORD *v11[7]; // [sp+24h] [bp-244h] BYREF
  int v12; // [sp+40h] [bp-228h] BYREF
  char v13[536]; // [sp+50h] [bp-218h] BYREF

  v6 = IoSetThreadHardErrorMode(0);
  v7 = ObQueryNameStringMode(*(_DWORD *)(a1 + 4), (int)v13, 508, &v12, 0);
  if ( v7 >= 0 )
  {
    v11[1] = (_DWORD *)24;
    v11[2] = 0;
    v11[4] = (_DWORD *)576;
    v11[3] = v13;
    v11[5] = 0;
    v11[6] = 0;
    v7 = ZwCreateFile();
    if ( v7 >= 0 )
    {
      v7 = ObReferenceObjectByHandle(0, 3, 0, 0, (int)v11, 0);
      v8 = v11[0];
      if ( v7 >= 0 )
      {
        v9 = IoGetRelatedDeviceObject(v11[0]);
        *a2 = v8;
        v8 = 0;
        *a3 = v9;
      }
      if ( v8 )
        ObfDereferenceObject((int)v8);
    }
  }
  IoSetThreadHardErrorMode(v6);
  return v7;
}

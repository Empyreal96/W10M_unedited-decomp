// IopOpenLinkOrRenameTarget 
 
int __fastcall IopOpenLinkOrRenameTarget(_DWORD *a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r4
  int v9; // r9
  int v10; // r4
  int v12; // r3
  int v13; // r3
  int *v14; // r0
  int v15; // r0
  int v16; // r8
  _DWORD *v17; // r6
  int v18; // r4
  _DWORD *v19; // [sp+30h] [bp-88h] BYREF
  int v20; // [sp+34h] [bp-84h] BYREF
  int v21[2]; // [sp+38h] [bp-80h] BYREF
  int v22; // [sp+40h] [bp-78h]
  int v23; // [sp+44h] [bp-74h]
  __int16 v24[2]; // [sp+48h] [bp-70h] BYREF
  int v25; // [sp+4Ch] [bp-6Ch]
  int v26[6]; // [sp+50h] [bp-68h] BYREF
  char v27[8]; // [sp+68h] [bp-50h] BYREF
  char v28[72]; // [sp+70h] [bp-48h] BYREF

  v5 = a4[11];
  v19 = 0;
  v9 = 2;
  if ( (v5 & 0x800) == 0 )
  {
    v10 = IopGetBasicInformationFile(a4, v28);
    if ( v10 < 0 )
      return v10;
    if ( (v28[32] & 0x10) != 0 )
      v9 = 4;
  }
  if ( !*(_DWORD *)(a3 + 4) )
  {
    v12 = *(_DWORD *)(a3 + 8);
    v26[1] = 0;
    v24[0] = v12;
    v24[1] = v12;
    v25 = a3 + 12;
    v26[0] = 24;
    if ( (a4[11] & 0x20000) != 0 )
      v13 = 0;
    else
      v13 = 64;
    v26[3] = v13 | 0x200;
    v26[2] = (int)v24;
    v26[4] = 0;
    v26[5] = 0;
    v21[1] = 0;
    v22 = 0;
    v23 = 0;
    v21[0] = 16;
    v14 = (int *)IopGetFileObjectExtension((int)a4, 1, 0);
    if ( v14 )
      v22 = *v14;
    v15 = IopGetFileObjectExtension((int)a4, 0, 0);
    v16 = *(_DWORD *)(a2 + 96);
    v23 = v15;
    v10 = IoCreateFileEx(
            (int)&v20,
            v9 | 0x100000,
            (int)v26,
            (int)v27,
            0,
            0,
            3,
            1,
            0x4000,
            0,
            0,
            0,
            0,
            ((*(_BYTE *)(v16 - 38) & 1) == 0) | 0x104,
            v21);
    if ( v10 >= 0 )
    {
      v10 = ObReferenceObjectByHandle(v20, v9, (int)IoFileObjectType, 0, (int)&v19, (int)v21);
      if ( v10 < 0 )
      {
        ObCloseHandle(v20);
      }
      else
      {
        v17 = v19;
        ObfDereferenceObject((int)v19);
        v18 = IoGetRelatedDeviceObject(v17);
        if ( v18 == IoGetRelatedDeviceObject(a4) )
        {
          *(_DWORD *)(v16 - 24) = v17;
          v10 = 0;
          *a1 = v20;
        }
        else
        {
          ObCloseHandle(v20);
          v10 = -1073741612;
        }
      }
    }
    return v10;
  }
  return sub_806DC4();
}

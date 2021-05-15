// IopWriteCapsuleTriageDumpToFirmware 
 
int __fastcall IopWriteCapsuleTriageDumpToFirmware(int a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v10; // r8
  int v11; // r7
  int v12; // r4
  int v13; // r3
  int v16; // [sp+38h] [bp-48h] BYREF
  int v17; // [sp+3Ch] [bp-44h]
  void *v18; // [sp+40h] [bp-40h]
  int v19; // [sp+44h] [bp-3Ch]
  int v20; // [sp+48h] [bp-38h] BYREF
  _DWORD v21[12]; // [sp+50h] [bp-30h] BYREF

  v19 = a2;
  v20 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v10 = 0;
  if ( !CapsuleTriageDumpBlock )
    return 0;
  v11 = CapsuleTriageDumpBlock + 8220;
  VfDisableHalVerifier(a1);
  KiSweepCurrentIcache();
  v21[0] = a2;
  v21[1] = a3;
  v21[2] = a4;
  v21[3] = a5;
  IopUpdateMinidumpContext(a1, a2, a3, a4, a5, a6, a7);
  MmSnapTriageDumpInformation(a6, v21);
  IoFillDumpHeader(v11 - 4096, 4, a1, v19, a3, a4, a5, a7);
  v16 = IopNumTriageDumpDataBlocks;
  v17 = 256;
  v18 = &IopTriageDumpDataBlocks;
  v12 = IoFillTriageDumpBuffer(0x1F000u, v11, 1, 3583, 0, a6, a7, CmNtCSDVersion, 65, 1, (int)&v16, (int)&v16, &v20);
  memset((_BYTE *)(v11 - 4036), 0, 32);
  *(_DWORD *)(v11 - 112) = 0;
  v13 = *(_DWORD *)(v11 + 4);
  *(_DWORD *)(v11 - 92) = 0;
  *(_DWORD *)(v11 - 116) = 3583;
  *(_DWORD *)(v11 - 96) = v13;
  *(_DWORD *)(v11 - 1888) |= 0x88u;
  if ( v12 >= 0 && IopWriteTriageDumpToFirmware(CapsuleTriageDumpBlock) >= 0 )
    v10 = 1;
  KiSweepCurrentIcache();
  return v10;
}

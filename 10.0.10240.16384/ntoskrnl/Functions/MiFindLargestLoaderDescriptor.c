// MiFindLargestLoaderDescriptor 
 
int __fastcall MiFindLargestLoaderDescriptor(int a1)
{
  int *v2; // r4
  int *v3; // r5
  int *v4; // t1
  unsigned int v5; // r1
  int v6; // r3
  __int64 v7; // kr00_8
  int v8; // r3
  int v9; // r3
  unsigned int v10; // r2
  unsigned int v12; // r2
  _BYTE v13[80]; // [sp-4h] [bp-50h] BYREF

  dword_640500 = -1;
  MxComputeFreeNodeDescriptorRequirements(a1, v13);
  v4 = *(int **)(a1 + 24);
  v2 = (int *)(a1 + 24);
  v3 = v4;
  v5 = dword_640504;
  while ( v3 != v2 )
  {
    v6 = v3[2];
    if ( v6 != 6 && v6 != 32 && v6 != 31 && v6 != 30 && v6 != 23 && v6 != 3 && v6 != 22 )
    {
      v7 = *(_QWORD *)(v3 + 3);
      v8 = HIDWORD(v7) + v7;
      if ( HIDWORD(v7) + (int)v7 > v5 )
      {
        v5 = v8 - 1;
        dword_640504 = v8 - 1;
      }
      dword_640508 += HIDWORD(v7);
      if ( (unsigned int)v7 < dword_640500 )
        dword_640500 = v7;
      v9 = v3[2];
      if ( v9 == 2 || v9 == 5 || v9 == 4 || v9 == 24 || v9 == 8 )
      {
        MxInitializeFreeNodeDescriptors(v3, v13);
        v5 = dword_640504;
      }
    }
    v3 = (int *)*v3;
  }
  v10 = MmDynamicPfn;
  if ( !MmDynamicPfn )
    return sub_96B590();
  if ( v5 > MmDynamicPfn - 1 )
  {
    v10 = v5 + 1;
    MmDynamicPfn = v5 + 1;
  }
  if ( v10 > dword_633850 + 1 )
  {
    v10 = dword_633850 + 1;
    MmDynamicPfn = dword_633850 + 1;
  }
  dword_633850 = v10 - 1;
  v12 = dword_68125C;
  if ( !dword_68125C )
  {
    v12 = 0x80000;
    dword_68125C = 0x80000;
  }
  if ( (MiFlags & 1) != 0 )
  {
    v12 = -2;
    dword_68125C = -2;
  }
  if ( dword_640508 <= v12 || (MiFlags & 0x30000) != 0 )
    MxUseLargePagesForKernelAndHal = 0;
  return 1;
}

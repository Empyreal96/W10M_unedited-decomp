// MiCheckLargePageOk 
 
int __fastcall MiCheckLargePageOk(int a1)
{
  int *v1; // r1
  int v2; // r3
  int v3; // r1

  v1 = *(int **)(a1 + 16);
  PsNtosImageBase = v1[6];
  v2 = v1[8];
  dword_9833D0 = (int)v1;
  v3 = *v1;
  PsNtosImageEnd = v2 + PsNtosImageBase;
  PsHalImageBase = *(_DWORD *)(v3 + 24);
  MxHalDataTableEntry = v3;
  PsHalImageEnd = *(_DWORD *)(v3 + 32) + PsHalImageBase;
  if ( !MxUseLargePagesForKernelAndHal )
    JUMPOUT(0x96FD3A);
  return sub_96FC38();
}

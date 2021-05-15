// RawInitializeVcb 
 
int __fastcall RawInitializeVcb(int a1, unsigned int a2, unsigned int a3)
{
  unsigned __int64 v3; // r4
  int v5; // r0

  v3 = __PAIR64__(a3, a2);
  memset((_BYTE *)a1, 0, 224);
  *(_WORD *)a1 = 1536;
  *(_WORD *)(a1 + 2) = 224;
  *(_QWORD *)(a1 + 136) = v3;
  *(_DWORD *)(a1 + 144) = ExAllocatePoolWithTag(512, 88, 544694610);
  v5 = ExAllocateCacheAwareRundownProtection(512, 544694610);
  *(_DWORD *)(a1 + 156) = v5;
  if ( v5 )
    JUMPOUT(0x7CFD62);
  return sub_7CFD60();
}

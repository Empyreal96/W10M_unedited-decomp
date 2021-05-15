// MiZeroPfn 
 
int __fastcall MiZeroPfn(int a1)
{
  int v1; // r0
  int result; // r0

  v1 = (a1 - MmPfnDatabase) / 24;
  if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) )
    result = MiZeroPhysicalPage(v1, 0, 1);
  else
    result = MxFillPhysicalPage(v1, 0);
  return result;
}

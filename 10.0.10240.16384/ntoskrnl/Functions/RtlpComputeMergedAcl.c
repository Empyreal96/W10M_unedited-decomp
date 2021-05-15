// RtlpComputeMergedAcl 
 
int __fastcall RtlpComputeMergedAcl(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned int *a9, int a10)
{
  int v11; // r1
  int v15; // r6
  int v16; // r0
  int v17; // r4
  int v19[8]; // [sp+20h] [bp-20h] BYREF

  v11 = 1024;
  v19[0] = 1024;
  v15 = 0;
  while ( 1 )
  {
    v16 = ExAllocatePoolWithTag(1, v11, 1665230163);
    *a9 = v16;
    if ( !v16 )
      return -1073741801;
    v17 = RtlpComputeMergedAcl2(a1, a2, a3, a4, a5, a6, a7, a8, v19, v16, a10);
    if ( v17 >= 0 )
      break;
    ExFreePoolWithTag(*a9);
    *a9 = 0;
    if ( v17 != -1073741789 )
      return v17;
    if ( (unsigned int)++v15 >= 2 )
      return v17;
    v11 = v19[0];
  }
  if ( !v19[0] )
  {
    ExFreePoolWithTag(*a9);
    *a9 = 0;
  }
  return v17;
}

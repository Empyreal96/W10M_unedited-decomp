// VfGetVerifierInformation 
 
int __fastcall VfGetVerifierInformation(int a1, unsigned int a2, unsigned int *a3, int a4)
{
  unsigned int v6; // r5
  int v8; // r0
  unsigned int v9; // r6
  int v10; // r4

  v6 = a2;
  *a3 = 0;
  if ( a2 > 0xA00000 )
    v6 = 10485760;
  v8 = ExAllocatePoolWithTag(512, v6, 1886213206);
  v9 = v8;
  if ( !v8 )
    return -1073741801;
  v10 = VfSuspectDriversGetVerifierInformation(v8, v6, a3, a1, a4);
  if ( *a3 <= v6 )
    v6 = *a3;
  memmove(a1, v9, v6);
  ExFreePoolWithTag(v9);
  return v10;
}

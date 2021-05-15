// KeEnumerateKernelStackSegments 
 
int __fastcall KeEnumerateKernelStackSegments(int a1, int (__fastcall *a2)(int, int *, int), int a3)
{
  int v6; // r4
  int result; // r0
  int v8[4]; // [sp+0h] [bp-38h] BYREF
  int v9[10]; // [sp+10h] [bp-28h] BYREF

  KeGetNextKernelStackSegment(a1, v8, 1);
  do
  {
    v9[0] = v8[0];
    v9[1] = v8[1];
    v9[2] = v8[2];
    v9[3] = v8[3];
    v6 = KeGetNextKernelStackSegment(a1, v8, 0);
    result = a2(a1, v9, a3);
  }
  while ( v6 );
  return result;
}

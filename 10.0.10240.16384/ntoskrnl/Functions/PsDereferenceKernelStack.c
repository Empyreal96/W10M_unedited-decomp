// PsDereferenceKernelStack 
 
int __fastcall PsDereferenceKernelStack(int result)
{
  int v1; // r4
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r1

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 1048);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  if ( !v4 )
  {
    result = KeEnumerateKernelStackSegments(result, (int (__fastcall *)(int, int *, int))PspDeleteKernelStack, 0);
    *(_DWORD *)(v1 + 32) = 0;
  }
  return result;
}

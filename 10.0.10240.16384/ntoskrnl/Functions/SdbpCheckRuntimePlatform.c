// SdbpCheckRuntimePlatform 
 
int __fastcall SdbpCheckRuntimePlatform(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4

  v5 = *(_DWORD *)(a2 + 404);
  *a1 = (SdbReadDWORDTag(a3, a5, 31) & v5) != 0;
  return 1;
}

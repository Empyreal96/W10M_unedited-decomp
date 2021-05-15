// sub_8171EC 
 
int __fastcall sub_8171EC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  unsigned int v11; // r5
  int v12; // lr
  int (__fastcall *v13)(int); // [sp-4h] [bp-4h]

  if ( a10 != v12 )
    JUMPOUT(0x7AE756);
  PpmReleaseLock(&PpmPerfPolicyLock);
  if ( v11 )
    ExFreePoolWithTag(v11);
  return v13(-1073741811);
}

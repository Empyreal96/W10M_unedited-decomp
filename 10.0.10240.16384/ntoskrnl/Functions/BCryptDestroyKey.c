// BCryptDestroyKey 
 
int __fastcall BCryptDestroyKey(int a1)
{
  int v2; // r5
  int v3; // r0
  unsigned int *v4; // r0
  unsigned int v5; // r4
  unsigned int v6; // r1

  v2 = -1073741822;
  v3 = ExGetExtensionTable(SepBCryptExtensionHost);
  if ( v3 )
  {
    v2 = (*(int (__fastcall **)(int))(v3 + 32))(a1);
    v4 = (unsigned int *)(SepBCryptExtensionHost + 36);
    __pld((void *)(SepBCryptExtensionHost + 36));
    v5 = *v4 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v6 = __ldrex(v4);
    while ( v6 == v5 && __strex(v5 - 2, v4) );
    if ( v6 != v5 )
      ExfReleaseRundownProtection((unsigned __int8 *)v4);
  }
  return v2;
}

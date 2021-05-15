// BCryptGenRandom 
 
int __fastcall BCryptGenRandom(int a1, int a2, int a3)
{
  int v3; // r5
  int v6; // r0
  unsigned int *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1

  v3 = -1073741822;
  v6 = ExGetExtensionTable(SepBCryptExtensionHost);
  if ( v6 )
  {
    v3 = (*(int (__fastcall **)(_DWORD, int, int, int))(v6 + 80))(0, a2, a3, 2);
    v7 = (unsigned int *)(SepBCryptExtensionHost + 36);
    __pld((void *)(SepBCryptExtensionHost + 36));
    v8 = *v7 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v9 = __ldrex(v7);
    while ( v9 == v8 && __strex(v8 - 2, v7) );
    if ( v9 != v8 )
      ExfReleaseRundownProtection((unsigned __int8 *)v7);
  }
  return v3;
}

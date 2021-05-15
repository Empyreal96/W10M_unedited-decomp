// BCryptDecrypt 
 
int __fastcall BCryptDecrypt(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r5
  int v13; // r7
  unsigned int *v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1

  v9 = -1073741822;
  v13 = ExGetExtensionTable(SepBCryptExtensionHost);
  if ( v13 )
  {
    v9 = (*(int (__fastcall **)(int, int, int, int, _DWORD, _DWORD, int, int, int, _DWORD))(v13 + 24))(
           a1,
           a2,
           a3,
           a4,
           0,
           0,
           a7,
           a8,
           a9,
           0);
    v14 = (unsigned int *)(SepBCryptExtensionHost + 36);
    __pld((void *)(SepBCryptExtensionHost + 36));
    v15 = *v14 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v16 = __ldrex(v14);
    while ( v16 == v15 && __strex(v15 - 2, v14) );
    if ( v16 != v15 )
      ExfReleaseRundownProtection((unsigned __int8 *)v14);
  }
  return v9;
}

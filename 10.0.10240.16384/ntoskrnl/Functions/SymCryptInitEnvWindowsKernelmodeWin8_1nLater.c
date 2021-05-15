// SymCryptInitEnvWindowsKernelmodeWin8_1nLater 
 
void SymCryptInitEnvWindowsKernelmodeWin8_1nLater()
{
  unsigned int v0; // r1
  int v1; // [sp+10h] [bp-120h] BYREF
  unsigned int v2; // [sp+14h] [bp-11Ch]
  unsigned int v3; // [sp+18h] [bp-118h]

  if ( (g_SymCryptFlags & 1) == 0 )
  {
    v1 = 276;
    if ( RtlGetVersion(&v1) < 0 )
      sub_5556B4();
    if ( v2 < 6 || v2 == 6 && v3 < 3 )
      KeBugCheckEx(369, 1853059702, 0);
    g_SymCryptCpuFeaturesNotPresent = -2;
    __dmb(0xBu);
    do
      v0 = __ldrex((unsigned __int8 *)&g_SymCryptFlags);
    while ( __strex(v0 | 1, (unsigned __int8 *)&g_SymCryptFlags) );
    __dmb(0xBu);
  }
}

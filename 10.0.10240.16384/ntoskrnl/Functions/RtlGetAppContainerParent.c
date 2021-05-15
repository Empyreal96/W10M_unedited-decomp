// RtlGetAppContainerParent 
 
int __fastcall RtlGetAppContainerParent(int a1, unsigned int *a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r5
  int v9; // r4
  unsigned int v10; // r4
  int v11; // r7
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a4;
  *a2 = 0;
  if ( RtlGetAppContainerSidType(a1, v13) < 0 || v13[0] != 1 )
    return -1073741811;
  v6 = RtlLengthRequiredSid(8u);
  v7 = ExAllocatePoolWithQuotaTag(0x208u, v6, 1649439826);
  v8 = v7;
  if ( !v7 )
    return -1073741670;
  v9 = RtlInitializeSid(v7, (int)&RtlpAppPackageAuthority, 8u);
  if ( v9 < 0 )
  {
    ExFreePoolWithTag(v8);
  }
  else
  {
    v10 = 0;
    v11 = 0;
    do
    {
      *(_DWORD *)(v8 + 4 * v10 + 8) = *(_DWORD *)RtlSubAuthoritySid(a1, v11);
      v10 = (unsigned __int8)(v11 + 1);
      v11 = v10;
    }
    while ( v10 < 8 );
    *a2 = v8;
    v9 = 0;
  }
  return v9;
}

// sub_50B350 
 
void sub_50B350()
{
  int v0; // r4
  int v1; // r6
  int v2; // r7

  RtlInitializeSid(v1, &RtlpAppPackageAuthority, 2);
  *(_DWORD *)(v1 + 8) = v2;
  *(_DWORD *)(v1 + 12) = v0 + 1;
  JUMPOUT(0x45D770);
}

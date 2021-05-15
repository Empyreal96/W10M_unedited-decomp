// sub_96E8C0 
 
void sub_96E8C0()
{
  int v0; // r8
  int v1; // r0
  int v2; // r4

  v0 = *(unsigned __int8 *)(SeLocalSystemSid + 1) + 2 * *(unsigned __int8 *)(SeWorldSid + 1) + 17;
  v1 = ExAllocatePoolWithTag(1, 4 * v0, 1818452292);
  v2 = v1;
  if ( v1 )
  {
    RtlCreateAcl(v1, 4 * v0, 2);
    RtlAddAccessAllowedAce(v2, 2, -536870912, SeWorldSid);
    RtlAddAccessAllowedAce(v2, 2, 0x10000000, SeLocalSystemSid);
    RtlAddAccessAllowedAce(v2, 2, 0x10000000, SeWorldSid);
    JUMPOUT(0x961838);
  }
  JUMPOUT(0x96185C);
}

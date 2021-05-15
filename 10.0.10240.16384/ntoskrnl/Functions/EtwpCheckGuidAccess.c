// EtwpCheckGuidAccess 
 
int __fastcall EtwpCheckGuidAccess(int a1, int a2, char *a3, int a4)
{
  int v6; // r4
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[1] = a4;
  v8[0] = 0;
  EtwpGetSecurityDescriptorByGuid(a1, v8);
  v6 = EtwpAccessCheck(v8[0], a2, a3);
  EtwpFreeSecurityDescriptor(v8);
  return v6;
}

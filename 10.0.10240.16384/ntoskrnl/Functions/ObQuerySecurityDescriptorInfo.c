// ObQuerySecurityDescriptorInfo 
 
int __fastcall ObQuerySecurityDescriptorInfo(int a1, int *a2, int a3, unsigned int *a4)
{
  int v7; // r7
  int v8; // r4
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[1] = (int)a4;
  v7 = ObpReferenceSecurityDescriptor(a1 - 24);
  v10[0] = v7;
  v8 = SeQuerySecurityDescriptorInfo(a2, a3, a4, v10);
  if ( v7 )
    ObDereferenceSecurityDescriptor(v7, 1);
  return v8;
}

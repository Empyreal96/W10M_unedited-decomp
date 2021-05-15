// ObDeassignSecurity 
 
int __fastcall ObDeassignSecurity(int *a1)
{
  int v1; // r2

  v1 = *a1;
  *a1 = 0;
  ObDereferenceSecurityDescriptor(v1 & 0xFFFFFFF8, (v1 & 7) + 1);
  return 0;
}

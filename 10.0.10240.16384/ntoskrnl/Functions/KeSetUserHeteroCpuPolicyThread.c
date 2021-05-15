// KeSetUserHeteroCpuPolicyThread 
 
int __fastcall KeSetUserHeteroCpuPolicyThread(int a1, int a2)
{
  int v4; // r4

  v4 = KeQueryHeteroCpuPolicyThread(a1, 1);
  KiSetHeteroPolicyThread(a1, a2, 1, 1);
  return v4;
}

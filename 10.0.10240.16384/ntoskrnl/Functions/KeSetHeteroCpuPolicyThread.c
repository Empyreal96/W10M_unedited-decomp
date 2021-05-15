// KeSetHeteroCpuPolicyThread 
 
int __fastcall KeSetHeteroCpuPolicyThread(int a1, int a2, int a3)
{
  return KiSetHeteroPolicyThread(a1, a2, 0, a3);
}

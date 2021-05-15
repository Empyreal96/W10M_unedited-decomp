// KeReleaseSemaphore 
 
int __fastcall KeReleaseSemaphore(int a1, int a2, int a3)
{
  return KeReleaseSemaphoreEx(a1, a2, a3);
}

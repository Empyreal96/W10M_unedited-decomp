// KeReleaseMutex 
 
int __fastcall KeReleaseMutex(int a1)
{
  return KeReleaseMutant(a1, 1);
}

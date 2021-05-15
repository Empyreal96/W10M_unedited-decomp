// KeInitializeMutex 
 
int __fastcall KeInitializeMutex(int a1)
{
  return KiInitializeMutant(a1, 0, 1);
}

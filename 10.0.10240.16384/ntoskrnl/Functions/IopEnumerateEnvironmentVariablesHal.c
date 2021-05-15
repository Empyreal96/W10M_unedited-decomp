// IopEnumerateEnvironmentVariablesHal 
 
int __fastcall IopEnumerateEnvironmentVariablesHal(int a1, int a2, int a3, int a4, int a5)
{
  return HalEnumerateEnvironmentVariablesEx(a3, a4, a5);
}

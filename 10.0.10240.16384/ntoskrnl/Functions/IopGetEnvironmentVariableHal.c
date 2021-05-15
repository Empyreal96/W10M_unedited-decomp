// IopGetEnvironmentVariableHal 
 
int __fastcall IopGetEnvironmentVariableHal(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return HalGetEnvironmentVariableEx(a3, a4, a5, a6);
}

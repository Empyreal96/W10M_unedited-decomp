// IopQueryEnvironmentVariableInfoHal 
 
int __fastcall IopQueryEnvironmentVariableInfoHal(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return HalQueryEnvironmentVariableInfoEx(a3, a4, a5, a6);
}

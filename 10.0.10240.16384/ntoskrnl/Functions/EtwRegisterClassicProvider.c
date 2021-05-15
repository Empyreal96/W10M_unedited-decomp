// EtwRegisterClassicProvider 
 
int __fastcall EtwRegisterClassicProvider(unsigned int a1, int a2, void (__fastcall *a3)(int, int, int *, int), int a4, _DWORD *a5)
{
  int result; // r0
  int vars4; // [sp+14h] [bp+4h]

  if ( a3 )
    result = EtwpRegisterProvider(a1, 2, a3, a4, vars4, a5);
  else
    result = -1073741811;
  return result;
}

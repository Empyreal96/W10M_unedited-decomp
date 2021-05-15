// PoFxRegisterCrashdumpDevice 
 
int __fastcall PoFxRegisterCrashdumpDevice(int a1)
{
  int v1; // r3
  int result; // r0

  if ( !a1 )
    return -1073741811;
  v1 = *(_DWORD *)(a1 + 36);
  if ( v1 )
    result = PopPluginRegisterCrashdumpDevice(*(_DWORD *)(a1 + 36), *(_DWORD *)(a1 + 40), a1, v1);
  else
    result = -1073741637;
  return result;
}

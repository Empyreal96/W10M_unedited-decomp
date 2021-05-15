// PspSetRateControlProcessCallback 
 
int __fastcall PspSetRateControlProcessCallback(int a1, int a2)
{
  int (__fastcall *v2)(int, _DWORD); // r3
  int result; // r0

  v2 = *(int (__fastcall **)(int, _DWORD))(a2 + 4);
  result = 0;
  if ( v2 )
    result = v2(a1, *(_DWORD *)(a2 + 8));
  return result;
}

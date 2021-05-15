// KseDsHookIoCreateDevice 
 
int __fastcall KseDsHookIoCreateDevice(int a1, int a2, int a3, int a4, int a5, unsigned __int8 a6, int *a7)
{
  int v9; // r4
  int v10; // r1

  v9 = off_617D8C(a1, a2, a3, a4);
  if ( v9 < 0 )
    v10 = 0;
  else
    v10 = *a7;
  KsepDsEventIoCreateDevice(a1, v10, a4, a5, a6, v9);
  return v9;
}

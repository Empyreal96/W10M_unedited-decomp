// IopBusNumberUnpackRequirement 
 
int __fastcall IopBusNumberUnpackRequirement(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int result; // r0

  *a2 = a1[3];
  a2[1] = 0;
  *a3 = a1[4];
  a3[1] = 0;
  *a4 = a1[2];
  a4[1] = 0;
  result = 0;
  *a5 = 1;
  a5[1] = 0;
  return result;
}

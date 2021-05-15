// PopCreateKernelPowerRequest 
 
int __fastcall PopCreateKernelPowerRequest(int a1, _DWORD *a2, int a3, int a4)
{
  int result; // r0
  int v5[4]; // [sp+0h] [bp-10h] BYREF

  v5[0] = a4;
  result = PopCreatePowerRequestObject(v5, a2);
  if ( result >= 0 )
    result = sub_7F1524();
  return result;
}

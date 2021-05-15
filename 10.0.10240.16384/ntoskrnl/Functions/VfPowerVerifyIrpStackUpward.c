// VfPowerVerifyIrpStackUpward 
 
int __fastcall VfPowerVerifyIrpStackUpward(int *a1, int a2, int a3, int a4)
{
  int v5; // r2
  int result; // r0

  v5 = *a1;
  result = -1073741637;
  if ( *(_DWORD *)(v5 + 24) == -1073741637 && *(_DWORD *)(a3 + 64) != -1073741637 )
    result = VfErrorReport1(538, *(_DWORD *)(a4 + 24), v5);
  return result;
}

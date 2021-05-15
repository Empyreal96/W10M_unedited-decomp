// VfWmiVerifyIrpStackDownward 
 
int __fastcall VfWmiVerifyIrpStackDownward(int *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r4
  int v9; // r5
  int result; // r0
  int v11; // r0

  v7 = *a1;
  if ( *(_DWORD *)(a1[35] + 28) == 3 )
    VfErrorReport1(529, a7, *a1);
  v9 = *(_DWORD *)(a2 + 8);
  result = IovUtilHasDispatchHandler(v9, 23);
  if ( !result )
  {
    *(_DWORD *)(a5 + 4) |= 0x1000000u;
    v11 = VfGetPristineDriverInit(v9);
    result = VfErrorReport1(543, v11, v7);
    *(_DWORD *)(a6 + 4) |= 0x80000000;
  }
  return result;
}

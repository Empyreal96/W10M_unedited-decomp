// VfPowerVerifyIrpStackDownward 
 
int __fastcall VfPowerVerifyIrpStackDownward(int *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r5
  int v9; // r4
  BOOL v11; // r8
  int v12; // r6
  int result; // r0
  int v14; // r0

  v7 = *a1;
  v9 = *(_DWORD *)(*a1 + 24);
  v11 = v9 != *(_DWORD *)(a5 + 64);
  if ( *(_DWORD *)(a1[35] + 28) == 3 )
    VfErrorReport1(529, a7, *a1);
  v12 = *(_DWORD *)(a2 + 8);
  result = IovUtilHasDispatchHandler(v12, 22);
  if ( !result )
  {
    *(_DWORD *)(a5 + 4) |= 0x1000000u;
    v14 = VfGetPristineDriverInit(v12);
    result = VfErrorReport1(543, v14, v7);
    *(_DWORD *)(a6 + 4) |= 0x80000000;
  }
  if ( a3 && v9 < 0 )
  {
    if ( v9 == -1073741637 )
    {
      if ( v11 )
        result = VfErrorReport1(538, a7, v7);
    }
    else if ( (*(_DWORD *)(a5 + 4) & 0x2000000) == 0 )
    {
      result = VfErrorReport1(537, a7, v7);
      *(_DWORD *)(a5 + 4) |= 0x2000000u;
    }
  }
  return result;
}

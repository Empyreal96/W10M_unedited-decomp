// VfPnpVerifyIrpStackDownward 
 
int __fastcall VfPnpVerifyIrpStackDownward(int *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int result; // r0
  int v9; // r8
  int v10; // r6
  BOOL v11; // r9
  int v12; // r4
  int v13; // r0
  int v14; // r4
  int v15; // r2
  int v16; // r1
  int v20; // [sp+14h] [bp-24h]

  result = IovUtilIsWdmStack(a2);
  if ( result )
  {
    v9 = *a1;
    v10 = *(_DWORD *)(*a1 + 24);
    v11 = v10 != *(_DWORD *)(a5 + 64);
    v20 = a1[35];
    if ( *(_DWORD *)(v20 + 28) == 3 )
      VfErrorReport1(529, a7, v9);
    v12 = *(_DWORD *)(a2 + 8);
    result = IovUtilHasDispatchHandler(v12, 27);
    if ( !result )
    {
      *(_DWORD *)(a5 + 4) |= 0x1000000u;
      v13 = VfGetPristineDriverInit(v12);
      result = VfErrorReport1(543, v13, v9);
      *(_DWORD *)(a6 + 4) |= 0x80000000;
    }
    if ( a3 )
    {
      if ( v10 < 0 )
      {
        if ( v10 == -1073741637 )
        {
          if ( v11 && (*(_DWORD *)(a5 + 4) & 0x2000000) == 0 )
          {
            result = VfErrorReport1(534, a7, v9);
            *(_DWORD *)(a5 + 4) |= 0x2000000u;
          }
        }
        else if ( (*(_DWORD *)(a5 + 4) & 0x2000000) == 0 )
        {
          result = VfErrorReport1(533, a7, v9);
          *(_DWORD *)(a5 + 4) |= 0x2000000u;
        }
      }
      v14 = *(_DWORD *)(v20 + 24);
      if ( v14 )
      {
        result = IovUtilIsDeviceObjectMarked(*(_DWORD *)(v20 + 24), 2);
        if ( result )
        {
          if ( IovUtilIsDeviceObjectMarked(v14, 3) )
            v16 = 0;
          else
            v16 = 4;
          result = ViPnpVerifyMinorWasProcessedProperly(v9, a4, v16, v15, a7, 1);
        }
      }
    }
  }
  return result;
}

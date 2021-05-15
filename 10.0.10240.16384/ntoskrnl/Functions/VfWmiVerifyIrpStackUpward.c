// VfWmiVerifyIrpStackUpward 
 
int *__fastcall VfWmiVerifyIrpStackUpward(int *result, int a2, int a3, int a4, int a5)
{
  int v6; // r5
  int v7; // r6
  int v8; // r2
  int v9; // r3
  int v10; // r3

  if ( (MmVerifierData & 0x10) != 0 )
  {
    v6 = *result;
    v7 = *(_DWORD *)(a4 + 24);
    if ( a5 )
    {
      v8 = *(_DWORD *)(a4 + 4);
      if ( v8 >= 0 && (v8 & 0x10000000) == 0 )
      {
        result = *(int **)(a2 + 24);
        v9 = *(_DWORD *)(a2 + 8);
        if ( (int *)v9 != result )
        {
          result = (int *)VfDevObjIsDeviceRemoved((int)result, a2, v8, v9);
          if ( !result )
          {
            v10 = VfIoSwitchedOffNoReboot;
            __dmb(0xBu);
            if ( !v10 )
              result = (int *)VfErrorReport10(544, v7, v6, *(_DWORD *)(a2 + 8));
          }
        }
      }
    }
  }
  return result;
}

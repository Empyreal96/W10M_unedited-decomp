// VfFreeMapRegisters 
 
int __fastcall VfFreeMapRegisters(int a1, _DWORD *a2, int a3)
{
  _DWORD *v4; // r6
  int v5; // r8
  int v8; // r5
  int v9; // r7
  int result; // r0
  _DWORD *v11; // r4
  int (__fastcall *v12)(int, _DWORD *, int); // [sp+0h] [bp-20h]

  v4 = 0;
  v5 = 0;
  v12 = (int (__fastcall *)(int, _DWORD *, int))ViGetRealDmaOperation(a1, 28);
  v8 = ViGetAdapterInformationInternal(a1, 1);
  v9 = -559026163;
  if ( v8 )
  {
    VF_ASSERT_IRQL(2);
    v4 = a2;
    if ( a2 == (_DWORD *)-559026163 )
    {
      a2 = 0;
      v4 = 0;
      v5 = 1;
    }
    else if ( a2 && *a2 == -1393569779 )
    {
      a2 = (_DWORD *)a2[7];
    }
  }
  result = v12(a1, a2, a3);
  if ( v8 )
  {
    if ( v5 != 1 )
      v9 = (int)v4;
    result = ViRemoveChannelWcb(v8, v9, 0);
    v11 = (_DWORD *)result;
    if ( result )
    {
      SUBTRACT_MAP_REGISTERS(v8, *(_DWORD *)(result + 24));
      if ( v11[13] )
        ViFreeMapRegisterFile(v8);
      result = ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, v11);
    }
  }
  return result;
}

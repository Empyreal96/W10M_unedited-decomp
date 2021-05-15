// IovpCallDriverNoIrpTracking 
 
int __fastcall IovpCallDriverNoIrpTracking(int a1, int a2)
{
  int v4; // r1
  int v5; // r7
  int v6; // r0
  int v7; // r3
  unsigned __int8 *v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r4

  v5 = VfBeforeCallDriver(a1, a2, 0);
  if ( (IopFunctionPointerMask & 2) != 0 )
  {
    v6 = IopPerfCallDriver(a1, a2);
  }
  else
  {
    v7 = (char)(*(_BYTE *)(a2 + 35) - 1);
    *(_BYTE *)(a2 + 35) = v7;
    if ( v7 <= 0 )
      KeBugCheckEx(53, a2, 0, 0, 0);
    v8 = (unsigned __int8 *)(*(_DWORD *)(a2 + 96) - 40);
    *(_DWORD *)(a2 + 96) = v8;
    v9 = *v8;
    *((_DWORD *)v8 + 6) = a1;
    if ( v9 == 22 && ((v10 = v8[1], v10 == 2) || v10 == 3) )
      v6 = IopPoHandleIrp(a2, v4, 22, v10);
    else
      v6 = (*(int (__fastcall **)(int, int))(*(_DWORD *)(a1 + 8) + 4 * v9 + 56))(a1, a2);
  }
  v11 = v6;
  VfDeadlockAfterCallDriver(v5);
  return v11;
}

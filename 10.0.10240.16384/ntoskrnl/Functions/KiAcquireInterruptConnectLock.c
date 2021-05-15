// KiAcquireInterruptConnectLock 
 
int __fastcall KiAcquireInterruptConnectLock(int a1, _BYTE *a2, int a3, int a4)
{
  int v5; // r0
  int result; // r0
  _BYTE *v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+4h] [bp-Ch]
  int v9; // [sp+8h] [bp-8h]

  v7 = a2;
  v8 = a3;
  v9 = a4;
  v5 = (int)*(&KiProcessorBlock + a1);
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v8 = *(unsigned __int8 *)(v5 + 1052);
  v7 = *(_BYTE **)(v5 + 1048);
  KeSetSystemGroupAffinityThread(&v7, a3);
  result = KfRaiseIrql(15);
  *a2 = result;
  return result;
}

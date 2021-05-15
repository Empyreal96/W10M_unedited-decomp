// PpmClearSimulatedLoad 
 
int __fastcall PpmClearSimulatedLoad(int a1)
{
  int v1; // r4
  unsigned int v2; // r2
  unsigned int v3; // r4
  int v4; // r0
  int v5; // r5
  __int64 v6; // r0
  int v7; // r2
  int v8; // r3
  int v10[4]; // [sp+0h] [bp-28h] BYREF
  _DWORD v11[6]; // [sp+10h] [bp-18h] BYREF

  if ( *(_BYTE *)(a1 + 3) )
    return -1073741811;
  if ( *(_WORD *)a1 || (v2 = *(unsigned __int8 *)(a1 + 2), v2 >= KeNumberProcessors_0) )
    v2 = -1;
  if ( v2 == -1 )
    return -1073741811;
  v10[1] = 0;
  v10[2] = 0;
  v10[0] = 1 << v2;
  KeSetSystemGroupAffinityThread((int)v10, v11);
  v3 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  v4 = KfRaiseIrql(2);
  v5 = *(_DWORD *)(v3 + 3212);
  *(_DWORD *)(v3 + 3212) = 0;
  v6 = KfLowerIrql(v4);
  KeRevertToUserGroupAffinityThread((int)v11, SHIDWORD(v6), v7, v8);
  v1 = 0;
  if ( v5 )
    ExFreePoolWithTag(v5);
  return v1;
}

// PpmSetSimulatedLoad 
 
int __fastcall PpmSetSimulatedLoad(int a1)
{
  int v2; // r6
  int v3; // r4
  unsigned int v4; // r5
  _BYTE *v5; // r7
  unsigned int v6; // r4
  int v7; // r0
  __int64 v8; // r0
  int v9; // r2
  int v10; // r3
  int v12[4]; // [sp+0h] [bp-30h] BYREF
  _DWORD v13[8]; // [sp+10h] [bp-20h] BYREF

  v2 = 0;
  if ( *(_BYTE *)(a1 + 3) )
    return -1073741811;
  if ( *(_WORD *)a1 || (v4 = *(unsigned __int8 *)(a1 + 2), v4 >= KeNumberProcessors_0) )
    v4 = -1;
  if ( v4 == -1 || *(unsigned __int8 *)(a1 + 4) > 0x64u )
  {
    v3 = -1073741811;
  }
  else
  {
    v5 = (_BYTE *)ExAllocatePoolWithTag(512, 2);
    if ( !v5 )
      return -1073741670;
    *v5 = *(_BYTE *)(a1 + 4);
    v5[1] = *(_BYTE *)(a1 + 5);
    v12[1] = 0;
    v12[2] = 0;
    v12[0] = 1 << v4;
    KeSetSystemGroupAffinityThread((int)v12, v13);
    v6 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    v7 = KfRaiseIrql(2);
    v2 = *(_DWORD *)(v6 + 3212);
    *(_DWORD *)(v6 + 3212) = v5;
    v8 = KfLowerIrql(v7);
    KeRevertToUserGroupAffinityThread((int)v13, SHIDWORD(v8), v9, v10);
    v3 = 0;
  }
  if ( v2 )
    ExFreePoolWithTag(v2);
  return v3;
}

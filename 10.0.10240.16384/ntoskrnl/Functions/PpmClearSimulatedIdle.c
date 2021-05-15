// PpmClearSimulatedIdle 
 
int __fastcall PpmClearSimulatedIdle(int a1)
{
  unsigned int v1; // r2
  int v2; // r0
  int v3; // r2
  int v4; // r4
  __int64 v5; // r0
  int v6; // r2
  int v7; // r3
  int v9[4]; // [sp+0h] [bp-28h] BYREF
  _DWORD v10[6]; // [sp+10h] [bp-18h] BYREF

  if ( *(_BYTE *)(a1 + 3) )
    return -1073741811;
  if ( *(_WORD *)a1 || (v1 = *(unsigned __int8 *)(a1 + 2), v1 >= KeNumberProcessors_0) )
    v1 = -1;
  if ( v1 == -1 )
    return -1073741811;
  v9[1] = 0;
  v9[2] = 0;
  v9[0] = 1 << v1;
  KeSetSystemGroupAffinityThread((int)v9, v10);
  v2 = KfRaiseIrql(2);
  v3 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1100);
  if ( v3 )
  {
    if ( *(_BYTE *)(v3 + 1) )
    {
      *(_BYTE *)(v3 + 1) = 0;
      *(_DWORD *)(v3 + 24) = 0;
    }
    v4 = 0;
  }
  else
  {
    v4 = -1073741637;
  }
  v5 = KfLowerIrql(v2);
  KeRevertToUserGroupAffinityThread((int)v10, SHIDWORD(v5), v6, v7);
  return v4;
}

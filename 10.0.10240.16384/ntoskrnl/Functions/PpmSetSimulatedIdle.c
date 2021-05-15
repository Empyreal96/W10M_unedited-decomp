// PpmSetSimulatedIdle 
 
int __fastcall PpmSetSimulatedIdle(int *a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r2
  int v5; // r4
  int v6; // r1
  __int64 v7; // r0
  int v8; // r2
  int v9; // r3
  int v11[4]; // [sp+0h] [bp-28h] BYREF
  _DWORD v12[6]; // [sp+10h] [bp-18h] BYREF

  if ( *((_BYTE *)a1 + 7) )
    return -1073741811;
  if ( *((_WORD *)a1 + 2) || (v2 = *((unsigned __int8 *)a1 + 6), v2 >= KeNumberProcessors_0) )
    v2 = -1;
  if ( v2 == -1 )
    return -1073741811;
  v11[1] = 0;
  v11[2] = 0;
  v11[0] = 1 << v2;
  KeSetSystemGroupAffinityThread((int)v11, v12);
  v3 = KfRaiseIrql(2);
  v4 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1100);
  if ( v4 )
  {
    v6 = *a1;
    if ( (unsigned int)*a1 < *(_DWORD *)(v4 + 28) )
    {
      *(_BYTE *)(v4 + 1) = 1;
      *(_DWORD *)(v4 + 24) = v6;
      v5 = 0;
    }
    else
    {
      v5 = -1073741811;
    }
  }
  else
  {
    v5 = -1073741637;
  }
  v7 = KfLowerIrql(v3);
  KeRevertToUserGroupAffinityThread((int)v12, SHIDWORD(v7), v8, v9);
  return v5;
}

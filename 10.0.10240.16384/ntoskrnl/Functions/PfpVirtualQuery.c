// PfpVirtualQuery 
 
int __fastcall PfpVirtualQuery(int a1, int a2, _DWORD *a3, int a4)
{
  int result; // r0
  unsigned int v6; // r2
  int v7; // r3
  int v8; // [sp+18h] [bp-20h] BYREF
  int v9; // [sp+1Ch] [bp-1Ch]
  unsigned int *v10; // [sp+20h] [bp-18h]
  unsigned int v11; // [sp+24h] [bp-14h]
  int v12; // [sp+28h] [bp-10h]
  int varg_r0; // [sp+40h] [bp+8h]
  int varg_r1; // [sp+44h] [bp+Ch]
  _DWORD *varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  if ( *(_DWORD *)(a1 + 16) != 20 )
    return -1073741306;
  if ( (_BYTE)a2 )
  {
    v6 = *(_DWORD *)(a1 + 12);
    if ( (v6 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( v6 + 20 > MmUserProbeAddress || v6 + 20 < v6 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  memmove((int)&v8, *(_DWORD *)(a1 + 12), *(_DWORD *)(a1 + 16));
  if ( v8 != 1 || (v9 & 1) != 0 && (v9 & 2) != 0 || (v9 & 0xFFFFFFFC) != 0 )
    return -1073741811;
  v7 = 0;
  if ( (v9 & 1) != 0 )
  {
    v7 = 2;
  }
  else if ( (v9 & 2) != 0 )
  {
    v7 = 1;
  }
  result = MmQueryVirtualMemory(v12, 0, 4, v10, v11, 0, v7);
  if ( result >= 0 )
    *a3 = 20;
  return result;
}

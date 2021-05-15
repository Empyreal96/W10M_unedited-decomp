// RtlCreateUserStack 
 
int __fastcall RtlCreateUserStack(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  unsigned int v6; // r6
  unsigned int v7; // r5
  int v8; // r9
  int v9; // r4
  int v10; // r10
  int v11; // r0
  unsigned int v12; // r8
  unsigned int v13; // r6
  unsigned int v14; // r3
  BOOL v15; // r6
  unsigned int v17; // [sp+Ch] [bp-64h]
  int v18; // [sp+50h] [bp-20h]
  unsigned int varg_r0a; // [sp+78h] [bp+8h]
  unsigned int varg_r0b; // [sp+78h] [bp+8h]
  unsigned int varg_r1a; // [sp+7Ch] [bp+Ch]
  unsigned int varg_r1b; // [sp+7Ch] [bp+Ch]
  int varg_r3; // [sp+84h] [bp+14h]

  v6 = a2;
  v7 = a1;
  v8 = a4 & 0xFFFFFF;
  varg_r3 = a4 & 0xFFFFFF;
  if ( HIBYTE(a4) > 0x10u )
    return -1073741811;
  v10 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 320);
  if ( !a1 || !a2 )
  {
    v11 = RtlImageNtHeader(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 296));
    if ( !v11 )
      return -1073741701;
    if ( !v7 )
    {
      v7 = *(_DWORD *)(v11 + 100);
      varg_r0a = v7;
    }
    if ( !v6 )
    {
      v6 = *(_DWORD *)(v11 + 96);
      varg_r1a = v6;
    }
  }
  if ( !v7 )
    v7 = 0x4000;
  if ( v7 >= v6 )
    v6 = (v7 + 0xFFFFF) & 0xFFF00000;
  v12 = (v7 + v8 - 1) & ~(v8 - 1);
  varg_r0b = v12;
  v13 = (v6 + 0xFFFF) & 0xFFFF0000;
  varg_r1b = v13;
  v14 = *(_DWORD *)(v10 + 520);
  if ( v14 && v12 < v14 )
  {
    v12 = (v14 + v8 - 1) & ~(v8 - 1);
    v13 = (v12 + 0xFFFFF) & 0xFFF00000;
  }
  v9 = ZwSetInformationProcess();
  if ( v9 >= 0 )
  {
    *a6 = 0;
    a6[1] = 0;
    a6[4] = v18;
    a6[2] = v18 + v13;
    v17 = v18 - v12 + v13;
    v15 = v13 - v12 >= 2 * v8;
    v9 = ZwAllocateVirtualMemory();
    if ( v9 < 0 || (a6[3] = v17, v15) && (v9 = ZwAllocateVirtualMemory(), v9 < 0) )
      ZwFreeVirtualMemory();
    else
      v9 = 0;
  }
  return v9;
}

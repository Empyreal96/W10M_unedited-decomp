// PfpQueryScenarioInformation 
 
int __fastcall PfpQueryScenarioInformation(int a1, int a2, _DWORD *a3, int a4)
{
  int v5; // r8
  int v8; // r0
  unsigned int v9; // r2
  _DWORD _8[17]; // [sp+8h] [bp-38h] BYREF
  int varg_r1; // [sp+4Ch] [bp+Ch]
  _DWORD *varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  _8[16] = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  a2 = (char)a2;
  v5 = a2;
  LOBYTE(varg_r1) = a2;
  if ( *(_DWORD *)(a1 + 16) != 24 )
    return -1073741306;
  if ( (_BYTE)a2 && (*(_DWORD *)(a1 + 12) & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  memmove((int)_8, *(_DWORD *)(a1 + 12), 0x18u);
  if ( _8[0] != 4 )
    return -1073741811;
  v8 = PfpScenCtxQueryScenarioInformation((unsigned int)&unk_637290, _8);
  if ( v5 )
  {
    v9 = *(_DWORD *)(a1 + 12);
    if ( (v9 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v8);
    if ( v9 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)v9 = *(_BYTE *)v9;
    *(_BYTE *)(v9 + 20) = *(_BYTE *)(v9 + 20);
  }
  memmove(*(_DWORD *)(a1 + 12), (int)_8, 0x18u);
  *a3 = 24;
  return 0;
}

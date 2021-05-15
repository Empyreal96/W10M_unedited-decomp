// NtAddAtomEx 
 
int __fastcall NtAddAtomEx(unsigned int a1, unsigned int a2, _WORD *a3, int a4)
{
  int result; // r0
  int v8; // r0
  int v9; // r9
  _WORD *v10; // r10
  _WORD *v11; // r2
  int v12; // r3
  __int16 v13; // [sp-4h] [bp-238h] BYREF
  int v14; // [sp+0h] [bp-234h]
  int v15; // [sp+4h] [bp-230h] BYREF
  _WORD *v16; // [sp+8h] [bp-22Ch]
  _WORD *v17; // [sp+Ch] [bp-228h]
  _WORD _14[274]; // [sp+14h] [bp-220h] BYREF
  unsigned int varg_r0; // [sp+23Ch] [bp+8h]
  unsigned int varg_r1; // [sp+240h] [bp+Ch]
  _WORD *varg_r2; // [sp+244h] [bp+10h]
  int varg_r3; // [sp+248h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v14 = a4;
  varg_r3 = a4;
  v17 = a3;
  v15 = 0;
  if ( (a4 & 0xFFFFFFFD) != 0 )
    return -1073741811;
  v8 = PsInvokeWin32Callout(2, &v15, 0, 0);
  if ( !v15 )
    return -1073741790;
  if ( a2 > 0x1FE )
    return -1073741811;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  LOBYTE(v13) = v9;
  v10 = (_WORD *)a1;
  v16 = (_WORD *)a1;
  if ( v9 )
  {
    if ( a3 )
    {
      v11 = a3;
      if ( (unsigned int)a3 >= MmUserProbeAddress )
        v11 = (_WORD *)MmUserProbeAddress;
      *v11 = *v11;
    }
    if ( a1 )
    {
      if ( a2 )
      {
        if ( (a1 & 1) != 0 )
          ExRaiseDatatypeMisalignment(v8);
        if ( a2 + a1 > MmUserProbeAddress || a2 + a1 < a1 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      v10 = _14;
      v16 = _14;
      memmove((int)_14, a1, a2);
      _14[a2 >> 1] = 0;
    }
    v12 = v14;
  }
  else
  {
    v12 = v14;
  }
  result = RtlAddAtomToAtomTableEx(v15, v10, &v13, v12);
  if ( a3 )
  {
    if ( result >= 0 )
      *a3 = v13;
  }
  return result;
}

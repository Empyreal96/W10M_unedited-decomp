// NtCreateMutant 
 
int __fastcall NtCreateMutant(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v6; // r5
  int v7; // r4
  int result; // r0
  int v9[2]; // [sp+1Ch] [bp-24h] BYREF
  _DWORD _24[12]; // [sp+24h] [bp-1Ch] BYREF
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r3 = a4;
  v9[0] = a2;
  v9[1] = a3;
  _24[0] = a4;
  LOBYTE(varg_r3) = a4;
  _24[11] = a3;
  _24[10] = a2;
  v6 = a1;
  _24[9] = a1;
  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v7 )
  {
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      a1 = (_DWORD *)MmUserProbeAddress;
    *a1 = *a1;
  }
  result = ObCreateObject(v7, (_DWORD *)ExMutantObjectType, a3, v7, 0, 32, 0, 0, v9);
  if ( result >= 0 )
  {
    KeInitializeMutant(v9[0], a4);
    result = ObInsertObjectEx(v9[0], 0, a2, 0, 0, 0, _24);
    v9[0] = result;
    if ( result >= 0 )
      *v6 = _24[0];
  }
  return result;
}

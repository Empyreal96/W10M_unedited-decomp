// NtWaitForMultipleObjects32 
 
int __fastcall NtWaitForMultipleObjects32(unsigned int a1, unsigned int a2, int a3, int a4, unsigned int a5)
{
  __int64 *v7; // r4
  int v9; // r5
  unsigned int v10; // r3
  unsigned int v11; // r1
  __int64 v12; // [sp+18h] [bp-138h] BYREF
  unsigned int v13; // [sp+20h] [bp-130h]
  __int64 v14; // [sp+28h] [bp-128h]
  _DWORD _30[77]; // [sp+30h] [bp-120h] BYREF
  int varg_r3; // [sp+164h] [bp+14h]

  _30[75] = a2;
  varg_r3 = a4;
  LOBYTE(varg_r3) = a4;
  _30[76] = a3;
  _30[74] = a1;
  v7 = (__int64 *)a5;
  if ( !a1 || a1 > 0x40 )
    return -1073741585;
  if ( a3 != 1 && a3 )
    return -1073741583;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v9 )
  {
    if ( a5 )
    {
      if ( a5 >= MmUserProbeAddress )
        v7 = (__int64 *)MmUserProbeAddress;
      v14 = *v7;
      v12 = v14;
      v7 = &v12;
    }
    if ( 4 * a1 )
    {
      v10 = 4 * a1 + a2;
      if ( v10 > MmUserProbeAddress || v10 < a2 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  v11 = 0;
  v13 = 0;
  while ( v11 < a1 )
  {
    _30[v11] = *(_DWORD *)(a2 + 4 * v11);
    v13 = ++v11;
  }
  return ObWaitForMultipleObjects(a1, _30, v9, a3, v9, a4, v7);
}

// NtWaitForMultipleObjects 
 
int __fastcall NtWaitForMultipleObjects(unsigned int a1, unsigned int a2, int a3, int a4, unsigned int a5)
{
  __int64 *v8; // r5
  int v10; // r8
  unsigned int v11; // r3
  char v12; // [sp+10h] [bp-138h]
  __int64 *v14; // [sp+14h] [bp-134h]
  __int64 v15; // [sp+18h] [bp-130h] BYREF
  __int64 v16; // [sp+20h] [bp-128h]
  _DWORD _28[77]; // [sp+28h] [bp-120h] BYREF
  int varg_r3; // [sp+15Ch] [bp+14h]

  _28[75] = a2;
  varg_r3 = a4;
  LOBYTE(varg_r3) = a4;
  _28[76] = a3;
  _28[74] = a1;
  v8 = (__int64 *)a5;
  if ( !a1 || a1 > 0x40 )
    return -1073741585;
  if ( a3 != 1 && a3 )
    return -1073741583;
  v10 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v12 = v10;
  if ( v10 )
  {
    if ( a5 )
    {
      if ( a5 >= MmUserProbeAddress )
        v8 = (__int64 *)MmUserProbeAddress;
      v16 = *v8;
      v15 = v16;
      v8 = &v15;
      v14 = &v15;
    }
    if ( 4 * a1 )
    {
      v11 = 4 * a1 + a2;
      if ( v11 > MmUserProbeAddress || v11 < a2 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  memmove((int)_28, a2, 4 * a1);
  return ((int (__fastcall *)(unsigned int, _DWORD *, int, int, int, int, __int64 *))ObWaitForMultipleObjects)(
           a1,
           _28,
           v10,
           a3,
           v10,
           a4,
           v8);
}

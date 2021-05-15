// NtCreateProcessEx 
 
int __fastcall NtCreateProcessEx(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned int *a8)
{
  int v8; // r6
  _DWORD *v10; // r2
  _DWORD *varg_r0; // [sp+30h] [bp+8h]

  v8 = a3;
  varg_r0 = a1;
  if ( !a4 )
    return -1073741811;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v10 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v10 = (_DWORD *)MmUserProbeAddress;
    *v10 = *v10;
  }
  return PspCreateProcess(a1, a2, v8, a4, a5, a6, a7, a8);
}

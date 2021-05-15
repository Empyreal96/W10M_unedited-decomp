// sub_7E6DD8 
 
int __fastcall sub_7E6DD8(int a1, int a2, int a3, int a4, _DWORD *a5, int *a6)
{
  int v6; // r8
  int v7; // r9
  int v8; // r10
  char v9; // lr
  unsigned int *v10; // r2
  unsigned int v11; // r1
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int *v15; // [sp+18h] [bp-38h] BYREF
  int v16; // [sp+1Ch] [bp-34h] BYREF
  int v17[11]; // [sp+20h] [bp-30h] BYREF
  int (__fastcall *v18)(int); // [sp+4Ch] [bp-4h]

  v10 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4236);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 + 1, v10) );
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4) = 0;
  if ( v7 )
  {
    *a6 = CcGetVirtualAddress(
            *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4),
            *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4),
            *(_DWORD *)v6,
            *(_DWORD *)(v6 + 4),
            &v15,
            &v16,
            (v9 & 0x40) != 0,
            0);
  }
  else if ( !CcPinFileData(a1, (_DWORD *)v6, v8, 1, 0, v9, &v15, a6, v17) )
  {
    v12 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4300);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 + 1, v12) );
    return v18(0);
  }
  *a5 = v15;
  return v18(1);
}

// NtCreateProfile 
 
int __fastcall NtCreateProfile(_DWORD *a1, int a2, int a3, unsigned int a4, int a5, unsigned int a6, unsigned int a7, int a8, int a9)
{
  int v13; // r0
  int v15; // [sp+20h] [bp-28h] BYREF
  int v16; // [sp+24h] [bp-24h]
  int v17; // [sp+28h] [bp-20h]

  v15 = 0;
  v16 = 0;
  v17 = 0;
  v13 = *(unsigned __int8 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x99C);
  LOWORD(v16) = v13;
  if ( a9 == -1 )
    v15 = KeQueryGroupAffinity(v13);
  else
    v15 = a9;
  return ExpProfileCreate(a1, a2, a3, a4, a5, a6, a7, a8, 1u, (unsigned int)&v15, 1u);
}

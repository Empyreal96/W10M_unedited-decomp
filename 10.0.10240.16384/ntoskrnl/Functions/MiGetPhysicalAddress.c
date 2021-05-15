// MiGetPhysicalAddress 
 
int __fastcall MiGetPhysicalAddress(unsigned int a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int v5; // r7
  unsigned int v6; // r2
  int v9; // r1
  char *v10; // r0
  unsigned int *v11; // t1
  unsigned int *v12; // r0
  unsigned int v13; // r1
  unsigned int v14; // r3
  int v16; // [sp+0h] [bp-18h]
  char v17; // [sp+4h] [bp-14h] BYREF

  v16 = a4;
  *a3 = 0;
  v5 = (a1 >> 20) & 0xFFC;
  v6 = *(_DWORD *)(v5 - 1070596096);
  if ( (v6 & 0x402) == 1026 )
  {
LABEL_13:
    v14 = ((a1 >> 12) & 0x3FF) + (v6 >> 12);
LABEL_11:
    *a3 = 1;
    goto LABEL_12;
  }
  v9 = 1;
  v10 = &v17;
  v16 = v5 - 1070596096;
  do
  {
    v11 = (unsigned int *)*((_DWORD *)v10 - 1);
    v10 -= 4;
    --v9;
    v6 = *v11;
    if ( (*v11 & 2) == 0 )
      return 0;
  }
  while ( v9 );
  if ( (v6 & 0x400) != 0 )
    goto LABEL_13;
  v12 = (unsigned int *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  v13 = *v12;
  if ( (*v12 & 2) == 0 )
    return 0;
  if ( a1 >= dword_63389C
    && *((_BYTE *)&MiState[2423] + ((int)(v5 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 5 )
  {
    v13 = *(_DWORD *)MiSetNonPagedPoolNoSteal(v12);
  }
  v14 = v13 >> 12;
  if ( (v13 & 0x80) != 0 )
    goto LABEL_11;
LABEL_12:
  *a2 = (a1 & 0xFFF) + (v14 << 12);
  a2[1] = v14 >> 20;
  return 1;
}

// RtlAddMandatoryAce 
 
int __fastcall RtlAddMandatoryAce(unsigned __int8 *a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v9; // r3
  unsigned __int8 v10; // r7
  _BYTE *v11; // r1
  int v12; // r0
  __int16 v13; // r3
  _BYTE *v15; // [sp+0h] [bp-20h] BYREF
  char v16; // [sp+4h] [bp-1Ch]
  char v17; // [sp+5h] [bp-1Bh]

  v17 = 16;
  v15 = 0;
  v16 = 0;
  if ( !a1 )
    return -1073741705;
  if ( !RtlValidSid(a4, 16) )
    return -1073741704;
  if ( memcmp(a4 + 2, (unsigned int)&v15, 6) )
    return -1073741811;
  v9 = *a1;
  if ( v9 > 4 )
    return -1073741735;
  v10 = v9 > 2 ? *a1 : 2;
  if ( (a3 & 0xFFFFFFE0) != 0 || (a6 & 0xFFFFFFF8) != 0 )
    return -1073741811;
  if ( !RtlValidAcl(a1) || !RtlFirstFreeAce(a1, &v15) )
    return -1073741705;
  v11 = v15;
  v12 = 4 * (*(unsigned __int8 *)(a4 + 1) + 4);
  if ( !v15 || &v15[v12] > &a1[*((unsigned __int16 *)a1 + 1)] )
    return -1073741671;
  *v15 = 17;
  v11[1] = a3;
  *((_WORD *)v11 + 1) = v12;
  *((_DWORD *)v11 + 1) = a6;
  memmove((int)(v11 + 8), a4, 4 * (*(unsigned __int8 *)(a4 + 1) + 2));
  v13 = *((_WORD *)a1 + 2);
  *a1 = v10;
  *((_WORD *)a1 + 2) = v13 + 1;
  return 0;
}

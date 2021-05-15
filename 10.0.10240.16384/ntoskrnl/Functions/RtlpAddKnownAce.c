// RtlpAddKnownAce 
 
int __fastcall RtlpAddKnownAce(unsigned __int8 *a1, unsigned int a2, int a3, int a4, _BYTE *a5, unsigned __int8 a6)
{
  unsigned __int8 v6; // r10
  unsigned int v8; // r0
  unsigned __int8 v9; // r8
  unsigned __int8 *v11; // r7
  unsigned int v12; // r1
  unsigned __int8 *v13; // r2
  unsigned int v14; // r1
  int v15; // r2
  __int16 v16; // r3

  v6 = a3;
  if ( (unsigned int)a5 <= MmUserProbeAddress || !a5 || (*a5 & 0xF) != 1 || (unsigned __int8)a5[1] > 0xFu )
    return -1073741704;
  v8 = *a1;
  if ( v8 > 4 || a2 > 4 )
    return -1073741735;
  if ( v8 > (unsigned __int8)a2 )
    v9 = *a1;
  else
    v9 = a2;
  if ( (a3 & 0xFFFFFFE0) != 0 )
    return sub_7FC0C0();
  if ( !RtlValidAcl(a1) )
    return -1073741705;
  v11 = 0;
  v12 = 0;
  v13 = a1 + 8;
  if ( *((_WORD *)a1 + 2) )
  {
    while ( v13 < &a1[*((unsigned __int16 *)a1 + 1)] )
    {
      ++v12;
      v13 += *((unsigned __int16 *)v13 + 1);
      if ( v12 >= *((unsigned __int16 *)a1 + 2) )
        goto LABEL_15;
    }
    return -1073741705;
  }
LABEL_15:
  v14 = (unsigned int)&a1[*((unsigned __int16 *)a1 + 1)];
  if ( (unsigned int)v13 <= v14 )
    v11 = v13;
  v15 = 4 * ((unsigned __int8)a5[1] + 4);
  if ( !v11 || (unsigned int)&v11[v15] > v14 )
    return -1073741671;
  v11[1] = v6;
  *v11 = a6;
  *((_DWORD *)v11 + 1) = a4;
  *((_WORD *)v11 + 1) = v15;
  memmove((int)(v11 + 8), (int)a5, 4 * ((unsigned __int8)a5[1] + 2));
  v16 = *((_WORD *)a1 + 2);
  *a1 = v9;
  *((_WORD *)a1 + 2) = v16 + 1;
  return 0;
}

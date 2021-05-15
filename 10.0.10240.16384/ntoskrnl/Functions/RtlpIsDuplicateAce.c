// RtlpIsDuplicateAce 
 
int __fastcall RtlpIsDuplicateAce(int a1, unsigned __int8 *a2)
{
  unsigned int v3; // r3
  int v5; // r8
  int v6; // r9
  int v7; // r10
  int v8; // r6
  unsigned __int8 *v9; // r4
  unsigned int v10; // r2
  unsigned int v11; // r3
  int v13; // r2

  v3 = *a2;
  if ( v3 > 8 || v3 == 4 )
    return 0;
  if ( (a2[1] & 0x10) == 0 )
    return 0;
  v5 = *((_DWORD *)a2 + 1);
  if ( (a2[1] & 2) != 0 )
    v6 = *((_DWORD *)a2 + 1);
  else
    v6 = 0;
  if ( (a2[1] & 1) != 0 )
    v7 = *((_DWORD *)a2 + 1);
  else
    v7 = 0;
  if ( (a2[1] & 8) != 0 )
    v5 = 0;
  v8 = 0;
  v9 = (unsigned __int8 *)(a1 + 8);
  if ( *(unsigned __int16 *)(a1 + 4) - 1 <= 0 )
    return 0;
  while ( 1 )
  {
    v10 = *v9;
    if ( v10 > 8 || v10 == 4 || (v9[1] & 0x10) == 0 )
      goto LABEL_17;
    if ( v10 >= 5 )
      return sub_7C5950();
    v11 = *a2;
    if ( (v11 < 5 || v11 > 8) && RtlpCompareKnownAces(v9, a2) )
    {
      v13 = *((_DWORD *)v9 + 1);
      if ( (v9[1] & 2) != 0 )
        v6 &= ~v13;
      if ( (v9[1] & 1) != 0 )
        v7 &= ~v13;
      if ( (v9[1] & 8) == 0 )
        v5 &= ~v13;
      if ( !(v5 | v7 | v6) )
        return 1;
    }
LABEL_17:
    ++v8;
    v9 += *((unsigned __int16 *)v9 + 1);
    if ( v8 >= *(unsigned __int16 *)(a1 + 4) - 1 )
      return 0;
  }
}

// SepSecureBootGetQWordPolicyValue 
 
int __fastcall SepSecureBootGetQWordPolicyValue(int a1, int a2)
{
  int v2; // r6
  int v3; // r3
  unsigned int v4; // r4
  unsigned int v5; // r7

  v2 = 0;
  v3 = *(_WORD *)a1 & 0x1F;
  if ( v3 == 5 )
    goto LABEL_11;
  if ( v3 == 6 )
  {
    if ( *(_QWORD *)a2 >= *(_QWORD *)(a1 + 10) && *(_QWORD *)a2 <= *(_QWORD *)(a1 + 18) )
      return v2;
LABEL_11:
    *(_DWORD *)a2 = *(_DWORD *)(a1 + 2);
    *(_DWORD *)(a2 + 4) = *(_DWORD *)(a1 + 6);
    return v2;
  }
  if ( v3 != 7 )
    return -1069350909;
  v4 = 0;
  v5 = 0;
  if ( !*(_WORD *)(a1 + 10) )
    goto LABEL_11;
  while ( *(_QWORD *)(a1 + 8 * v4 + 12) != *(_QWORD *)a2 )
  {
    v5 = (__PAIR64__(v5, v4++) + 1) >> 32;
    if ( __PAIR64__(v5, v4) >= *(unsigned __int16 *)(a1 + 10) )
      goto LABEL_11;
  }
  return v2;
}

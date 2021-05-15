// IopReplaceSeperatorWithPound 
 
int __fastcall IopReplaceSeperatorWithPound(int a1, unsigned __int16 *a2)
{
  unsigned int v2; // r4
  unsigned __int16 *v4; // r5
  _WORD *v5; // r2
  unsigned int v6; // r4
  int v7; // r3
  int v8; // t1

  v2 = *a2;
  if ( v2 > *(unsigned __int16 *)(a1 + 2) )
    return -1073741789;
  v4 = (unsigned __int16 *)*((_DWORD *)a2 + 1);
  v5 = *(_WORD **)(a1 + 4);
  v6 = v2 >> 1;
  while ( v6 )
  {
    v6 = (unsigned __int16)(v6 - 1);
    v8 = *v4++;
    v7 = v8;
    if ( v8 == 92 || v7 == 47 )
      LOWORD(v7) = 35;
    *v5++ = v7;
  }
  *(_WORD *)a1 = *a2;
  return 0;
}

// SeGetLinkedToken 
 
int __fastcall SeGetLinkedToken(int a1, int a2, int *a3)
{
  _DWORD *v4; // r4
  int v5; // r5
  int v6; // r6
  _DWORD *v7; // r3
  int v8; // r2
  unsigned int *v9; // r5
  unsigned int i; // r2
  unsigned int v11; // r1
  int v12; // r1
  int v14[2]; // [sp+10h] [bp-38h] BYREF
  int v15[12]; // [sp+18h] [bp-30h] BYREF

  v4 = 0;
  v14[0] = 0;
  *a3 = 0;
  v5 = a2;
  if ( a1 != 3 && a1 != 2 )
    return -1073741811;
  v7 = *(_DWORD **)(a2 + 192);
  v8 = v7[6];
  if ( (v8 & 4) != 0 && a1 == 2 || (v8 & 2) != 0 && a1 == 3 )
  {
    v6 = SepReferenceLogonSessionSilo(v7 + 3, v7[22], v14);
    v4 = (_DWORD *)v14[0];
    if ( v6 < 0 )
      goto LABEL_11;
    v5 = *(_DWORD *)(v14[0] + 32);
  }
  v15[0] = 24;
  v15[1] = 0;
  v15[2] = 0;
  v15[3] = 0;
  v15[4] = 0;
  v15[5] = 0;
  v6 = SepDuplicateToken(v5, (int)v15, 0, 1, 0, 0, 0, a3);
LABEL_11:
  if ( v4 )
  {
    v9 = v4 + 5;
    __pld(v4 + 5);
    for ( i = v4[5]; (int)(i - 1) > 0; i = v11 )
    {
      __dmb(0xBu);
      do
        v11 = __ldrex(v9);
      while ( v11 == i && __strex(i - 1, v9) );
      if ( v11 == i )
        return v6;
    }
    if ( i != 1 )
      __fastfail(0xEu);
    v12 = v4[22];
    v14[0] = v4[1];
    v14[1] = v4[2];
    SepDeReferenceLogonSession(v14, v12);
  }
  return v6;
}

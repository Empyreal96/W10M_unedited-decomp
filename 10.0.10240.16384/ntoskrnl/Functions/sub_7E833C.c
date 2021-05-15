// sub_7E833C 
 
void __fastcall sub_7E833C(int a1, int a2, int a3, int *a4)
{
  unsigned int *v4; // r5
  unsigned int v5; // r6
  int v6; // r8
  unsigned int v7; // r9
  unsigned int v8; // lr
  int v9; // r7
  int v10; // r1
  unsigned int v11; // r1
  unsigned int v12; // r2
  unsigned int v13; // r2
  unsigned int v14; // r1

  v9 = *a4;
  v10 = *(unsigned __int8 *)(*a4 + 1052);
  if ( v10 == v6 )
  {
    v11 = *(_DWORD *)(v9 + 4 * v10 + 3384);
    if ( v11 )
      v12 = 31 - __clz(v11);
    else
      v12 = -1;
    if ( *(_DWORD *)(v9 + 20) == v12 )
    {
      v5 += 24;
      if ( v5 <= v8 )
      {
        *v4 = v11;
        v4[1] = 3;
        v4[4] = v7;
        v4[5] = v7;
        v4[2] = v7;
        v4[3] = v7;
        *((_BYTE *)v4 + 8) = v7;
      }
    }
    v13 = *(_DWORD *)(v9 + 3468);
    if ( v13 )
      v14 = 31 - __clz(v13);
    else
      v14 = -1;
    if ( *(_DWORD *)(v9 + 20) == v14 && v5 + 24 <= v8 )
      JUMPOUT(0x6FB662);
    JUMPOUT(0x6FB672);
  }
  JUMPOUT(0x6FB628);
}

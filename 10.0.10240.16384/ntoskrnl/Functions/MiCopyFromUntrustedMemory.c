// MiCopyFromUntrustedMemory 
 
int __fastcall MiCopyFromUntrustedMemory(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // r4
  int v5; // r6
  unsigned int v6; // r1
  int v7; // r2
  unsigned int i; // r2
  _DWORD _C[14]; // [sp+Ch] [bp-28h] BYREF
  unsigned int varg_r2; // [sp+44h] [bp+10h]
  unsigned int varg_r3; // [sp+48h] [bp+14h]

  _C[12] = a1;
  _C[13] = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = a3;
  v5 = a2;
  if ( a4 || (a1 & 3) != 0 || (a2 & 3) != 0 || (a3 & 3) != 0 )
  {
    while ( 1 )
    {
      if ( !v4 )
        return 0;
      if ( a4 )
        break;
      v6 = v4 & 3;
      if ( (v4 & 3) == 0 )
      {
        v6 = 4;
        goto LABEL_14;
      }
      if ( ((v6 - 1) & v6) != 0 )
        goto LABEL_13;
LABEL_14:
      if ( ((v6 - 1) & v5) != 0 )
      {
        v6 = 1;
LABEL_22:
        LOBYTE(_C[0]) = *(_BYTE *)v5;
        goto LABEL_24;
      }
      switch ( v6 )
      {
        case 4u:
          _C[0] = *(_DWORD *)v5;
          break;
        case 1u:
          goto LABEL_22;
        case 2u:
          LOWORD(_C[0]) = *(_WORD *)v5;
          break;
        case 8u:
          v7 = *(_DWORD *)(v5 + 4);
          _C[0] = *(_DWORD *)v5;
          _C[1] = v7;
          break;
      }
LABEL_24:
      for ( i = 0; i < v6; ++i )
        *(_BYTE *)a1++ = *((_BYTE *)_C + i);
      v4 -= v6;
      varg_r2 = v4;
      v5 += v6;
    }
    v6 = a4;
    if ( a4 <= v4 )
      goto LABEL_14;
LABEL_13:
    v6 = 1;
    goto LABEL_14;
  }
  memmove(a1, a2, a3);
  return 0;
}

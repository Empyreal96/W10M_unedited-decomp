// MiCopyToUntrustedMemory 
 
int __fastcall MiCopyToUntrustedMemory(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v5; // r5
  char *v6; // lr
  int v7; // r2
  __int16 v8; // r10
  unsigned int v9; // r1
  unsigned int v10; // r4
  char v11; // r3
  char v12; // t1
  int v14; // [sp+0h] [bp-40h]
  char v15; // [sp+4h] [bp-3Ch]
  int v16; // [sp+18h] [bp-28h] BYREF
  int v17; // [sp+1Ch] [bp-24h]
  int varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+50h] [bp+10h]
  unsigned int varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v5 = a3;
  v6 = (char *)a2;
  v7 = 0;
  v16 = 0;
  v14 = 0;
  v17 = 0;
  if ( a4 || (a2 & 3) != 0 || (a1 & 3) != 0 || (v5 & 3) != 0 )
  {
    v8 = v16;
    v15 = v16;
    while ( 1 )
    {
      if ( !v5 )
        return 0;
      if ( a4 )
        break;
      v9 = v5 & 3;
      if ( (v5 & 3) == 0 )
      {
        v9 = 4;
        goto LABEL_15;
      }
      if ( ((v9 - 1) & v9) != 0 )
        goto LABEL_14;
LABEL_15:
      if ( ((v9 - 1) & a1) != 0 )
        v9 = 1;
      v10 = 0;
      v11 = v15;
      while ( v10 < v9 )
      {
        v12 = *v6++;
        *((_BYTE *)&v16 + v10++) = v12;
        v14 = v17;
        v7 = v16;
        v8 = v16;
        v11 = v16;
        v15 = v16;
      }
      switch ( v9 )
      {
        case 1u:
          *(_BYTE *)a1 = v11;
          break;
        case 2u:
          *(_WORD *)a1 = v8;
          break;
        case 4u:
          *(_DWORD *)a1 = v7;
          break;
        case 8u:
          *(_DWORD *)a1 = v7;
          *(_DWORD *)(a1 + 4) = v14;
          break;
      }
      v5 -= v9;
      varg_r2 = v5;
      a1 += v9;
    }
    v9 = a4;
    if ( a4 <= v5 )
      goto LABEL_15;
LABEL_14:
    v9 = 1;
    goto LABEL_15;
  }
  memmove(a1, a2, v5);
  return 0;
}

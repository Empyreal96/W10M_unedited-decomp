// AuthzBasepCopyoutSecurityAttributeValues 
 
int __fastcall AuthzBasepCopyoutSecurityAttributeValues(int a1, int a2, unsigned int a3, int a4, _DWORD *a5)
{
  unsigned int v6; // r6
  int v7; // r4
  int v9; // r7
  unsigned int v10; // r2
  unsigned int v11; // r5
  _DWORD *v12; // r0
  _DWORD *v13; // r2
  _DWORD *v14; // t1
  _DWORD *v15; // r1
  int v16; // r5
  int v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r8
  int *v21; // r3
  int *v22; // r7
  unsigned int v23; // r2
  int v24; // r10
  int *v25; // [sp+0h] [bp-20h]

  v6 = a3 + a4;
  v7 = 0;
  if ( a3 + a4 < a3 )
    return -2147483643;
  *a5 = 0;
  if ( !*(_WORD *)(a1 + 24) )
    return -1073741811;
  if ( *(unsigned __int16 *)(a1 + 24) <= 2u )
  {
    v9 = *(_DWORD *)(a1 + 36);
    v10 = a3 + 7;
    if ( ((a3 + 7) & 0xFFFFFFF8) + 8 * v9 <= v6 )
    {
      v11 = v10 & 0xFFFFFFF8;
      *(_DWORD *)(a2 + 20) = v10 & 0xFFFFFFF8;
      v14 = *(_DWORD **)(a1 + 44);
      v12 = (_DWORD *)(a1 + 44);
      v13 = v14;
      if ( v14 != v12 )
      {
        v15 = (_DWORD *)v11;
        do
        {
          *v15 = v13[6];
          v15[1] = v13[7];
          v13 = (_DWORD *)*v13;
          v15 += 2;
        }
        while ( v13 != v12 );
      }
      v16 = v11 + 8 * v9;
LABEL_9:
      *a5 = v16 - a3;
      return v7;
    }
    return -2147483643;
  }
  if ( *(_WORD *)(a1 + 24) == 3 )
  {
    v18 = *(_DWORD *)(a1 + 36);
    v19 = a3 + 3;
    if ( ((a3 + 3) & 0xFFFFFFFC) + 8 * v18 <= v6 )
    {
      v20 = v19 & 0xFFFFFFFC;
      v21 = (int *)(a1 + 44);
      *(_DWORD *)(a2 + 20) = v19 & 0xFFFFFFFC;
      v22 = *(int **)(a1 + 44);
      v16 = (v19 & 0xFFFFFFFC) + 8 * v18;
      v25 = (int *)(a1 + 44);
      while ( v22 != v21 )
      {
        v23 = *((unsigned __int16 *)v22 + 12);
        v24 = v23 + v16;
        if ( v23 + v16 > v6 )
          return -2147483643;
        *(_WORD *)v20 = v23;
        *(_WORD *)(v20 + 2) = v23;
        *(_DWORD *)(v20 + 4) = v16;
        memmove(v16, v22[7], v23);
        v22 = (int *)*v22;
        v21 = v25;
        v16 = v24;
        v20 += 8;
      }
      goto LABEL_9;
    }
    return -2147483643;
  }
  return sub_520A24();
}

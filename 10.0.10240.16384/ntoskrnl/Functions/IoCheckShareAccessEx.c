// IoCheckShareAccessEx 
 
int __fastcall IoCheckShareAccessEx(int a1, char a2, int a3, unsigned int *a4, char a5, int a6)
{
  BOOL v9; // r2
  BOOL v10; // r6
  BOOL v11; // r1
  BOOL v13; // r7
  BOOL v14; // lr
  _DWORD *v15; // r3
  unsigned int v16; // r0
  unsigned int v17; // r1
  unsigned int v18; // r6
  unsigned int v19; // r2

  v9 = (a1 & 0x21) != 0;
  *(_BYTE *)(a3 + 38) = v9;
  v10 = (a1 & 6) != 0;
  *(_BYTE *)(a3 + 39) = v10;
  v11 = (a1 & 0x10000) != 0;
  *(_BYTE *)(a3 + 40) = v11;
  if ( (a1 & 0x21) == 0 && (a1 & 6) == 0 && (a1 & 0x10000) == 0 )
    return 0;
  *(_BYTE *)(a3 + 41) = (a2 & 1) != 0;
  v13 = (a2 & 2) != 0;
  *(_BYTE *)(a3 + 42) = v13;
  v14 = (a2 & 4) != 0;
  *(_BYTE *)(a3 + 43) = v14;
  if ( a6 )
    return sub_7E6A04();
  v15 = *(_DWORD **)(a3 + 124);
  if ( v15 && (*v15 & 1) != 0 )
    return 0;
  v16 = *a4;
  if ( (!v9 || a4[4] >= v16) && (!v10 || a4[5] >= v16) && (!v11 || a4[6] >= v16) )
  {
    v17 = a4[1];
    if ( !v17 || *(_BYTE *)(a3 + 41) )
    {
      v18 = a4[2];
      if ( !v18 || v13 )
      {
        v19 = a4[3];
        if ( !v19 || v14 )
        {
          if ( a5 )
          {
            *a4 = v16 + 1;
            a4[1] = *(unsigned __int8 *)(a3 + 38) + v17;
            a4[2] = *(unsigned __int8 *)(a3 + 39) + v18;
            a4[3] = *(unsigned __int8 *)(a3 + 40) + v19;
            a4[4] += *(unsigned __int8 *)(a3 + 41);
            a4[5] += *(unsigned __int8 *)(a3 + 42);
            a4[6] += *(unsigned __int8 *)(a3 + 43);
          }
          return 0;
        }
      }
    }
  }
  return -1073741757;
}

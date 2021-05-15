// IoSetShareAccessEx 
 
int __fastcall IoSetShareAccessEx(int a1, char a2, int a3, _DWORD *a4, _BYTE *a5)
{
  int v8; // lr
  BOOL v9; // r2
  BOOL v10; // r6
  BOOL v11; // r1
  _DWORD *v12; // r3
  int result; // r0

  v8 = 1;
  v9 = (a1 & 0x21) != 0;
  *(_BYTE *)(a3 + 38) = v9;
  v10 = (a1 & 6) != 0;
  *(_BYTE *)(a3 + 39) = v10;
  v11 = (a1 & 0x10000) != 0;
  v12 = *(_DWORD **)(a3 + 124);
  result = 1;
  *(_BYTE *)(a3 + 40) = v11;
  if ( v12 && (*v12 & 1) != 0 )
    v8 = 0;
  if ( !v9 && !v10 && !v11 )
    goto LABEL_8;
  *(_BYTE *)(a3 + 41) = (a2 & 1) != 0;
  *(_BYTE *)(a3 + 42) = (a2 & 2) != 0;
  *(_BYTE *)(a3 + 43) = (a2 & 4) != 0;
  if ( a5 && !*a5 && (a2 & 1) == 0 )
    *(_BYTE *)(a3 + 41) = 1;
  if ( v8 )
  {
    *a4 = 1;
    a4[1] = *(unsigned __int8 *)(a3 + 38);
    a4[2] = *(unsigned __int8 *)(a3 + 39);
    a4[3] = *(unsigned __int8 *)(a3 + 40);
    a4[4] = *(unsigned __int8 *)(a3 + 41);
    a4[5] = *(unsigned __int8 *)(a3 + 42);
    a4[6] = *(unsigned __int8 *)(a3 + 43);
  }
  else
  {
LABEL_8:
    a4[5] = 0;
    a4[6] = 0;
    a4[3] = 0;
    a4[4] = 0;
    a4[1] = 0;
    a4[2] = 0;
    *a4 = 0;
  }
  return result;
}

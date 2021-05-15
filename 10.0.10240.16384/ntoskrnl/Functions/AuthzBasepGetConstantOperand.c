// AuthzBasepGetConstantOperand 
 
int __fastcall AuthzBasepGetConstantOperand(unsigned __int8 *a1, int a2, int a3, int *a4)
{
  int v7; // r2
  int result; // r0
  int v9; // r5
  __int16 v10; // r3
  unsigned int v11; // r2

  *(_WORD *)a3 = 0;
  *(_BYTE *)(a3 + 4) = 0;
  *(_DWORD *)(a3 + 8) = 0;
  *(_DWORD *)(a3 + 16) = 0;
  *(_DWORD *)(a3 + 20) = 0;
  *(_DWORD *)(a3 + 24) = 0;
  *(_DWORD *)(a3 + 12) = 1;
  v7 = *a1;
  result = 0;
  v9 = 1;
  if ( v7 )
  {
    if ( v7 <= 4 )
    {
      if ( (unsigned int)(a2 - 1) >= 0xA )
      {
        *(_WORD *)a3 = 2;
        *(_DWORD *)(a3 + 20) = 10;
        *(_DWORD *)(a3 + 24) = a1 + 1;
        v9 = 11;
        goto LABEL_17;
      }
      goto LABEL_15;
    }
    if ( v7 == 16 || v7 == 24 || (unsigned int)(v7 - 80) <= 1 )
    {
      if ( (unsigned int)(a2 - 1) >= 4 )
      {
        if ( v7 == 16 )
        {
          v10 = 3;
        }
        else
        {
          if ( v7 == 80 )
            *(_BYTE *)(a3 + 4) = 1;
          v10 = 16;
        }
        *(_WORD *)a3 = v10;
        v11 = *(_DWORD *)(a1 + 1);
        v9 = 5;
        *(_DWORD *)(a3 + 20) = v11;
        if ( a2 - 5 >= v11 )
        {
          *(_DWORD *)(a3 + 24) = a1 + 5;
          v9 = v11 + 5;
          goto LABEL_17;
        }
      }
LABEL_15:
      result = -1073741406;
      goto LABEL_17;
    }
  }
LABEL_17:
  *a4 = v9;
  return result;
}

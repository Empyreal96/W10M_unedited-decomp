// SeSecureBootQueryInformation 
 
int __fastcall SeSecureBootQueryInformation(int a1, int a2, unsigned int a3, unsigned int *a4)
{
  int v6; // r9
  int v7; // r5
  _DWORD *v8; // r6
  unsigned int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3

  v6 = 0;
  v7 = 0;
  if ( a1 != 143 )
  {
    if ( a1 == 145 )
    {
      *a4 = 2;
      if ( a3 >= 2 )
      {
        *(_BYTE *)a2 = (dword_641868 & 1) != 0;
        *(_BYTE *)(a2 + 1) = (dword_641868 & 8) != 0;
        return v7;
      }
      return -1073741820;
    }
    if ( a1 != 171 )
      return -1073741821;
  }
  v8 = (_DWORD *)dword_641874;
  if ( !dword_641874 )
    return -2143092730;
  if ( a1 == 171 )
  {
    *a4 = 28;
    v9 = v8[14] + 28;
    v6 = a2;
  }
  else
  {
    v9 = 24;
  }
  *a4 = v9;
  if ( a3 < v9 )
    return -1073741820;
  v10 = v8[2];
  v11 = v8[3];
  v12 = v8[4];
  *(_DWORD *)a2 = v8[1];
  *(_DWORD *)(a2 + 4) = v10;
  *(_DWORD *)(a2 + 8) = v11;
  *(_DWORD *)(a2 + 12) = v12;
  *(_DWORD *)(a2 + 16) = v8[5];
  *(_DWORD *)(a2 + 20) = v8[8];
  if ( a1 == 171 )
  {
    memmove(v6 + 28, (int)(v8 + 15), v8[14]);
    *(_DWORD *)(v6 + 24) = v8[14];
  }
  return v7;
}

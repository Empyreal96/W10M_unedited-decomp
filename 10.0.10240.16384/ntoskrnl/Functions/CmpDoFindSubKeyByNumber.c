// CmpDoFindSubKeyByNumber 
 
int __fastcall CmpDoFindSubKeyByNumber(int a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned __int16 *v4; // r6
  int v5; // r4
  unsigned int v6; // r5
  int v8; // r2
  int result; // r0
  int v10; // r8
  unsigned __int16 *v11; // r4
  int v12; // t1
  unsigned __int16 *v13; // r0
  unsigned int v14; // r3
  int v15; // r2
  int v16; // r4
  int v17; // r4
  int v18[8]; // [sp+0h] [bp-20h] BYREF

  v18[0] = a3;
  v18[1] = a4;
  v4 = a2;
  v5 = *a2;
  v6 = a3;
  v18[0] = -1;
  if ( v5 == 26994 && (v10 = 0, a2[1]) )
  {
    v11 = a2;
    while ( 1 )
    {
      v12 = *((_DWORD *)v11 + 1);
      v11 += 2;
      v13 = (unsigned __int16 *)(*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v12, v18);
      if ( !v13 )
        return -1;
      v14 = v13[1];
      if ( v6 < v14 )
        break;
      v6 -= v14;
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v18);
      if ( ++v10 >= (unsigned int)v4[1] )
        goto LABEL_2;
    }
    v15 = *v13;
    if ( v15 == 26220 || v15 == 26732 )
    {
      v16 = *(_DWORD *)&v13[4 * v6 + 2];
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v18);
      result = v16;
    }
    else
    {
      v17 = *(_DWORD *)&v13[2 * v6 + 2];
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v18);
      result = v17;
    }
  }
  else
  {
LABEL_2:
    v8 = *v4;
    if ( v8 == 26220 || v8 == 26732 )
      result = *(_DWORD *)&v4[4 * v6 + 2];
    else
      result = sub_7FC1D8();
  }
  return result;
}

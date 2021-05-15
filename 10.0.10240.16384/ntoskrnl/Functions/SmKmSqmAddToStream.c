// SmKmSqmAddToStream 
 
int __fastcall SmKmSqmAddToStream(int a1, int a2, int a3, int a4, int *a5)
{
  char *v6; // r4
  int v8; // r7
  int v9; // r2
  int *v10; // r3
  unsigned __int16 *v11; // r6
  unsigned int v12; // r0
  int v14; // [sp+8h] [bp-228h] BYREF
  int v15; // [sp+Ch] [bp-224h] BYREF
  int v16; // [sp+10h] [bp-220h] BYREF
  int v17; // [sp+14h] [bp-21Ch]
  int v18[18]; // [sp+18h] [bp-218h] BYREF
  char v19; // [sp+60h] [bp-1D0h] BYREF

  v14 = 2;
  v16 = 6839;
  v17 = a2;
  v18[0] = 11;
  v15 = 0;
  v18[2] = (int)v18;
  v18[3] = 0;
  v18[4] = 4;
  v18[5] = 0;
  v6 = &v19;
  v18[6] = (int)&unk_6186F8;
  v18[7] = 0;
  v18[8] = 16;
  v18[9] = 0;
  v18[10] = (int)&v16;
  v18[11] = 0;
  v18[12] = 4;
  v18[13] = 0;
  v18[14] = (int)&v14;
  v18[15] = 0;
  v18[16] = 4;
  v18[17] = 0;
  v8 = 2;
  do
  {
    v9 = *a5;
    *(_DWORD *)v6 = a5;
    *((_DWORD *)v6 + 1) = 0;
    *((_DWORD *)v6 + 2) = 4;
    *((_DWORD *)v6 + 3) = 0;
    if ( v9 == 1 )
      v10 = a5 + 1;
    else
      v10 = &v15;
    *((_DWORD *)v6 + 4) = v10;
    *((_DWORD *)v6 + 5) = 0;
    *((_DWORD *)v6 + 6) = 4;
    *((_DWORD *)v6 + 7) = 0;
    if ( v9 == 2 )
      v11 = (unsigned __int16 *)a5[1];
    else
      v11 = L"0";
    v12 = wcslen(v11);
    *((_DWORD *)v6 + 9) = 0;
    *((_DWORD *)v6 + 10) = 2 * (v12 + 1);
    *((_DWORD *)v6 + 8) = v11;
    *((_DWORD *)v6 + 11) = 0;
    v6 += 48;
    a5 += 2;
    --v8;
  }
  while ( v8 );
  return EtwWrite(a1, v17, (int)SmEventSQMStreamRow, 0);
}

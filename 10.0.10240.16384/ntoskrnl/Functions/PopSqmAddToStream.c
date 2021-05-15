// PopSqmAddToStream 
 
_BYTE *__fastcall PopSqmAddToStream(int a1, int a2, int a3, int *a4)
{
  _BYTE *result; // r0
  int *v6; // r4
  int v7; // r7
  int v8; // r6
  int *v9; // r3
  unsigned __int16 *v10; // r0
  unsigned int v11; // r0
  const __int16 *v12; // r3
  int v13; // [sp+8h] [bp-220h] BYREF
  int v14; // [sp+Ch] [bp-21Ch] BYREF
  int v15; // [sp+10h] [bp-218h] BYREF
  int *v16; // [sp+18h] [bp-210h]
  int v17; // [sp+1Ch] [bp-20Ch]
  int v18[130]; // [sp+20h] [bp-208h] BYREF

  v13 = 11131;
  v14 = 4;
  v16 = 0;
  v17 = 0;
  result = memset(v18, 0, 488);
  v15 = 11;
  if ( PopDiagHandleRegistered && a4 )
  {
    v17 = 0;
    v18[0] = 4;
    v18[1] = 0;
    v6 = &v18[14];
    v18[2] = (int)dword_405F78;
    v18[3] = 0;
    v18[4] = 16;
    v18[5] = 0;
    v18[6] = (int)&v13;
    v18[7] = 0;
    v18[8] = 4;
    v18[9] = 0;
    v18[10] = (int)&v14;
    v18[11] = 0;
    v18[12] = 4;
    v7 = 4;
    v16 = &v15;
    v18[13] = 0;
    do
    {
      v8 = *a4;
      *v6 = (int)a4;
      v6[1] = 0;
      v6[2] = 4;
      v6[3] = 0;
      if ( v8 == 1 )
        v9 = a4 + 1;
      else
        v9 = &dword_417718;
      v6[4] = (int)v9;
      v6[5] = 0;
      v6[6] = 4;
      v6[7] = 0;
      if ( v8 == 2 )
        v10 = (unsigned __int16 *)a4[1];
      else
        v10 = L"0";
      v11 = wcslen(v10);
      if ( v8 == 2 )
        v12 = (const __int16 *)a4[1];
      else
        v12 = L"0";
      v6[8] = (int)v12;
      v6[9] = 0;
      v6[10] = 2 * (v11 + 1);
      v6[11] = 0;
      v6 += 12;
      a4 += 2;
      --v7;
    }
    while ( v7 );
    result = (_BYTE *)EtwWrite(PopDiagHandle, dword_61E154, (int)PopSqm_Add_StreamRow, 0);
  }
  return result;
}

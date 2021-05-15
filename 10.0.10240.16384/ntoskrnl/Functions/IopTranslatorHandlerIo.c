// IopTranslatorHandlerIo 
 
int __fastcall IopTranslatorHandlerIo(int a1, int *a2, int a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *v7; // r5
  int result; // r0
  int v9; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3
  _DWORD *v13; // r6
  int v14; // r1
  int v15; // r2
  int v16; // r3

  v7 = (_DWORD *)ExAllocatePoolWithTag(1, 32, 1684303952);
  if ( !v7 )
    return -1073741670;
  *a4 = 1;
  v9 = *a2;
  v10 = a2[1];
  v11 = a2[2];
  v12 = a2[3];
  v13 = a2 + 4;
  *v7 = v9;
  v7[1] = v10;
  v7[2] = v11;
  v7[3] = v12;
  v14 = v13[1];
  v15 = v13[2];
  v16 = v13[3];
  v7[4] = *v13;
  v7[5] = v14;
  v7[6] = v15;
  v7[7] = v16;
  result = 0;
  *a5 = v7;
  return result;
}

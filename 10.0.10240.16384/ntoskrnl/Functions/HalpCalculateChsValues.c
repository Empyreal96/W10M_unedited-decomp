// HalpCalculateChsValues 
 
int __fastcall HalpCalculateChsValues(__int64 *a1, __int64 *a2, char a3, unsigned int a4, unsigned int a5, unsigned int a6, _BYTE *a7)
{
  unsigned int v7; // r6
  unsigned int v8; // r8
  int v9; // r7
  unsigned int v10; // r5
  unsigned int v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1
  unsigned int v14; // r5
  char v15; // r9
  unsigned int v16; // r0
  char v17; // r10
  unsigned int v18; // r1
  unsigned int v19; // r4
  int result; // r0
  char v21; // r1

  v7 = a6;
  v8 = a4;
  if ( !a6 || a6 > 0x400 )
    v7 = 1024;
  v9 = a5;
  if ( !a5 || a5 > 0xFF )
    v9 = 255;
  if ( !a4 || a4 > 0x3F )
    v8 = 63;
  v10 = *a1 >> a3;
  v11 = v8 * v9;
  v12 = (*a2 >> a3) + v10 - 1;
  if ( !(v8 * v9) )
    __brkdiv0();
  v13 = v10 % v11;
  v14 = v10 / v11;
  v15 = v13 / v8;
  v16 = v8 * v9;
  v17 = v13 % v8 + 1;
  if ( !(v8 * v9) )
    __brkdiv0();
  v18 = v12 % v16;
  v19 = v12 / v16;
  result = v18 / v8;
  v21 = v18 % v8 + 1;
  if ( v14 >= v7 )
  {
    v14 = v7 - 1;
    v15 = v9 - 1;
    v17 = v8;
  }
  if ( v19 >= v7 )
  {
    v19 = v7 - 1;
    result = v9 - 1;
    v21 = v8;
  }
  a7[2] = (v17 ^ (v14 >> 2)) & 0x3F ^ (v14 >> 2);
  a7[6] = (v21 ^ (v19 >> 2)) & 0x3F ^ (v19 >> 2);
  a7[3] = v14;
  a7[7] = v19;
  a7[1] = v15;
  a7[5] = result;
  return result;
}

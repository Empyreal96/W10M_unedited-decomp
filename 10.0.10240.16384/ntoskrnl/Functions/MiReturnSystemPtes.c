// MiReturnSystemPtes 
 
int __fastcall MiReturnSystemPtes(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v7; // r7
  int v8; // r6
  int v9; // r5
  unsigned int *v10; // r2
  int v11; // r9
  unsigned int v12; // r0
  unsigned int *v13; // r1
  unsigned int v14; // r4
  int v15; // r2
  int v17; // [sp+0h] [bp-B8h] BYREF
  char v18; // [sp+4h] [bp-B4h]
  char v19; // [sp+5h] [bp-B3h]
  int v20; // [sp+8h] [bp-B0h]
  int v21; // [sp+Ch] [bp-ACh]
  int v22; // [sp+10h] [bp-A8h]
  int v23; // [sp+14h] [bp-A4h]

  v4 = a1[3];
  v7 = a3;
  if ( (v4 & 2) != 0 )
    v8 = 0;
  else
    v8 = 2;
  if ( (v4 & 4) != 0 )
  {
    v7 = 16 * a3;
    a2 *= 16;
  }
  v9 = -a3;
  v10 = a1 + 12;
  v11 = a1[2] + 4 * a2;
  do
    v12 = __ldrex(v10);
  while ( __strex(v12 + v9, v10) );
  v13 = a1 + 9;
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 + v9, v13) );
  v21 = 0;
  v22 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 33;
  v23 = 0;
  v17 = v8;
  MiInsertTbFlushEntry((int)&v17, v11 << 10, v7, 0);
  v15 = a1[4];
  if ( a4 == 1 )
    v15 = 16;
  return MiReturnSystemVa(v11 << 10, (v11 + 4 * v7) << 10, v15, &v17);
}

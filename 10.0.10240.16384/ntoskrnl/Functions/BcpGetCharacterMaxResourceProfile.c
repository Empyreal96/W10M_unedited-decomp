// BcpGetCharacterMaxResourceProfile 
 
int __fastcall BcpGetCharacterMaxResourceProfile(unsigned int a1, int a2, int *a3, int a4)
{
  int v4; // r4
  int v5; // r5
  int v6; // r6
  int v7; // r7
  int v8; // r2
  int *v9; // r8
  int v11; // r4
  int *v12; // r5
  int v13; // t1
  int result; // r0
  unsigned int v15; // r3
  unsigned int v16; // r2
  int v17; // [sp+0h] [bp-50h]
  unsigned int v18; // [sp+8h] [bp-48h] BYREF
  _DWORD v19[2]; // [sp+10h] [bp-40h] BYREF
  unsigned int v20; // [sp+18h] [bp-38h]
  _DWORD v21[3]; // [sp+20h] [bp-30h] BYREF
  int v22; // [sp+2Ch] [bp-24h]
  int v23; // [sp+30h] [bp-20h]

  v4 = *a3;
  v5 = a3[1];
  v6 = a3[2];
  v7 = a3[3];
  v8 = a3[4];
  v21[0] = v4;
  v21[1] = v5;
  v21[2] = v6;
  v22 = v7;
  v23 = v8;
  v9 = (int *)a4;
  v11 = 0;
  v12 = &dword_616150[a2];
  do
  {
    v13 = *v12;
    v12 += 14;
    v22 = v13;
    v19[0] = 0;
    v19[1] = 0;
    v20 = 0;
    result = RaspGetXExtent(a1, (int)v21, (int *)&v18, a4, v17, (int)v19);
    if ( result < 0 )
      break;
    v15 = v9[1];
    if ( v15 < v18 )
      v15 = v18;
    v16 = v20;
    v9[1] = v15;
    a4 = *v9;
    if ( *v9 < v16 )
      a4 = v16;
    ++v11;
    *v9 = a4;
  }
  while ( v11 < 5 );
  return result;
}

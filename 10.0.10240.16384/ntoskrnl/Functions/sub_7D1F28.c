// sub_7D1F28 
 
void __fastcall sub_7D1F28(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, int a8, char a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
  int v16; // r7
  unsigned __int16 *v17; // r8
  unsigned __int16 *v18; // r9
  int v19; // r10
  int v20; // r4
  int v21; // r5
  int *v22; // r3
  int v23; // r4
  int *v24; // r2
  int v25; // r3
  int *v26; // r3

  a7 = 0;
  v20 = 0;
  if ( *((_DWORD *)v17 + 1) )
  {
    a13 = *((_DWORD *)v17 + 1);
    a14 = 0;
    a15 = *v17;
    a16 = 0;
    v20 = 1;
  }
  v21 = *((_DWORD *)v18 + 1);
  v22 = &a13 + 4 * v20;
  v23 = v20 + 1;
  *v22 = (int)&a7;
  v22[1] = 0;
  v22[2] = 2;
  v22[3] = 0;
  if ( v21 )
  {
    v24 = &a13 + 4 * v23;
    v25 = *v18;
    *v24 = v21;
    v24[1] = 0;
    v24[2] = v25;
    v24[3] = 0;
    ++v23;
  }
  v26 = &a13 + 4 * v23;
  *v26 = (int)&a7;
  v26[1] = 0;
  v26[2] = 2;
  v26[3] = 0;
  EtwWrite(v19, v16, (int)&a9, 0);
  JUMPOUT(0x6D0EA0);
}

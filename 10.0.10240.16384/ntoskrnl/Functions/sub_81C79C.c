// sub_81C79C 
 
int __fastcall sub_81C79C(int *a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r4
  unsigned int v5; // r5
  int v6; // r1
  unsigned int v7; // r6
  int *v8; // r4
  int v9; // t1
  int (__fastcall *v11)(int); // [sp-4h] [bp-4h]

  v4[4] = a1;
  v4[6] = v5;
  v4[7] = a4;
  v6 = (int)v4 + (_DWORD)a1 + 16;
  v7 = 0;
  if ( v5 )
  {
    v8 = a1;
    do
    {
      v9 = *v8++;
      ++v7;
      v6 = ((*(int *)((char *)a1 + (v9 >> 4)) + v9) ^ v6) * v7;
    }
    while ( v7 < v5 );
  }
  KiTableInformation += 2 * v6;
  __dmb(0xFu);
  return v11(1);
}

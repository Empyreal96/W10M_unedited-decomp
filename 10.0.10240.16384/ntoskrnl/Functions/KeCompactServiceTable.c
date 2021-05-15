// KeCompactServiceTable 
 
int __fastcall KeCompactServiceTable(int *a1, unsigned __int8 *a2, unsigned int a3, int a4)
{
  unsigned __int8 *v5; // r2
  int *v7; // r1
  int *v9; // r8
  unsigned int v10; // r3
  int v11; // t1
  int v12; // r5
  unsigned int v13; // t1

  v5 = a2;
  v7 = a1;
  v9 = a1;
  if ( a3 )
  {
    v10 = a3;
    do
    {
      v11 = *v7++;
      v12 = v11 - (_DWORD)v9;
      v13 = *v5++;
      *a1++ = (v13 >> 2) | (16 * v12);
      --v10;
    }
    while ( v10 );
  }
  if ( a4 )
    memmove((int)a1, (int)v7, a3);
  return KiLockServiceTable(v9, a2, a3, a4);
}

// Mult64By64To128 
 
int __fastcall Mult64By64To128(unsigned int a1, unsigned int a2, __int64 a3, _QWORD *a4, _DWORD *a5)
{
  unsigned __int64 v5; // kr00_8
  unsigned __int64 v6; // kr08_8
  unsigned __int64 v7; // kr18_8
  int v8; // r5
  unsigned int v9; // r7
  unsigned int v10; // r6
  bool v11; // cf
  int result; // r0

  v5 = (unsigned int)a3 * (unsigned __int64)a1;
  v6 = HIDWORD(a3) * (unsigned __int64)a1;
  v7 = (unsigned int)a3 * (unsigned __int64)a2;
  v8 = 0;
  v9 = (a3 * (unsigned __int64)a1) >> 32;
  v10 = 0;
  v11 = v9 >= HIDWORD(v5);
  *a5 = v5;
  a5[1] = v9;
  result = a3 * a1;
  if ( v9 <= HIDWORD(v5) )
  {
    if ( v9 >= HIDWORD(v5) )
    {
      v11 = 1;
    }
    else
    {
      v8 = 1;
      v10 = 0;
    }
  }
  *a5 = v5;
  a5[1] = v9 + v11 + (_DWORD)v7;
  if ( a5[1] < v9 )
    v10 = ((unsigned __int64)(unsigned int)v8++ + 1) >> 32;
  *a4 = HIDWORD(v7) + (unsigned __int64)HIDWORD(v6) + HIDWORD(a3) * (unsigned __int64)a2 + __PAIR64__(v10, v8);
  return result;
}

// SepPrivilegeCheck 
 
int __fastcall SepPrivilegeCheck(int a1, int *a2, int a3, int a4, char a5)
{
  char v5; // r7
  unsigned __int64 v7; // kr00_8
  unsigned __int64 v8; // kr08_8
  int v9; // r6
  unsigned __int64 v10; // kr10_8
  int v11; // r4
  int v12; // r3
  int v13; // t1
  unsigned __int64 v15; // [sp+0h] [bp-28h] BYREF
  int v16; // [sp+8h] [bp-20h]

  v16 = a4;
  v5 = a4;
  v15 = 0i64;
  if ( a5 )
  {
    __dmb(0xBu);
    v7 = *(_QWORD *)(a1 + 72);
    do
      v8 = __ldrexd(&v15);
    while ( __strexd(v7, &v15) );
    __dmb(0xBu);
    __dmb(0xFu);
    v9 = 0;
    if ( a3 )
    {
      v10 = v15;
      v11 = a3;
      do
      {
        v12 = a2[2] & 0x7FFFFFFF;
        a2[2] = v12;
        v13 = *a2;
        a2 += 3;
        LODWORD(v15) = v12;
        if ( (1 << *(a2 - 3)) & (unsigned int)v10 | (1 << (v13 - 32)) & HIDWORD(v10) )
        {
          ++v9;
          *(a2 - 1) = v15 | 0x80000000;
        }
        --v11;
      }
      while ( v11 );
    }
    if ( (v5 & 1) != 0 )
    {
      if ( v9 != a3 )
        return 0;
    }
    else if ( !v9 )
    {
      return 0;
    }
  }
  return 1;
}

// DrvDbRegisterObjects 
 
int __fastcall DrvDbRegisterObjects(int a1, unsigned int a2)
{
  int *v2; // r6
  unsigned int i; // r5
  __int64 v6; // kr00_8
  int result; // r0
  unsigned int v8; // r4
  int v9; // r2
  int v10; // t1
  unsigned int *v11; // r2
  unsigned int v12; // r1

  v2 = &dword_40C3B8;
  for ( i = 0; i < 5; ++i )
  {
    v6 = *(_QWORD *)v2;
    result = 0;
    if ( (unsigned int)(*v2 - 1) > 9 )
    {
      result = -1073741811;
    }
    else
    {
      __dmb(0xBu);
      do
        v8 = __ldrex((unsigned int *)v6);
      while ( __strex(HIDWORD(v6), (unsigned int *)v6) );
      __dmb(0xBu);
    }
    if ( result < 0 )
      break;
    v10 = *v2;
    v2 += 2;
    v9 = v10;
    result = 0;
    if ( (unsigned int)(v10 - 1) > 9 )
    {
      result = -1073741811;
    }
    else
    {
      __dmb(0xBu);
      v11 = (unsigned int *)(a1 + 4 * (v9 + 27));
      do
        v12 = __ldrex(v11);
      while ( __strex(a2, v11) );
      __dmb(0xBu);
    }
    if ( result < 0 )
      break;
  }
  return result;
}

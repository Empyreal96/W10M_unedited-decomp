// CmpReleaseIXLock 
 
int *__fastcall CmpReleaseIXLock(int *result, int a2)
{
  int *v2; // r5
  unsigned int v4; // r2
  unsigned int v5; // r1
  int *v6; // r0
  int v7; // t1
  _DWORD *v8; // r2
  int v9; // r3
  int *v10; // r0
  int v11; // r4

  v2 = result;
  v4 = *result & 0x7FFFFFFF;
  if ( v4 == 1 )
  {
    if ( result[1] != a2 )
      KeBugCheckEx(81, 18, 1, (int)result, a2);
    *result = 0;
    result[1] = 0;
  }
  else
  {
    v5 = 0;
    if ( v4 )
    {
      v6 = (int *)result[1];
      do
      {
        v7 = *v6++;
        if ( v7 == a2 )
          break;
        ++v5;
      }
      while ( v5 < v4 );
    }
    if ( v5 == v4 )
      KeBugCheckEx(81, 18, 2, (int)v2, a2);
    result = (int *)(v4 - 1);
    while ( v5 < (unsigned int)result )
    {
      v8 = (_DWORD *)(v2[1] + 4 * v5++);
      *v8 = v8[1];
    }
    v9 = *v2 - 1;
    *v2 = v9;
    if ( v9 == 1 )
    {
      v10 = (int *)v2[1];
      v11 = *v10;
      result = (int *)ExFreePoolWithTag((unsigned int)v10);
      v2[1] = v11;
    }
  }
  return result;
}

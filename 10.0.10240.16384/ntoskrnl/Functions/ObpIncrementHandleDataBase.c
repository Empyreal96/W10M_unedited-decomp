// ObpIncrementHandleDataBase 
 
int *__fastcall ObpIncrementHandleDataBase(int *result, int a2)
{
  char *v2; // r4
  int *v3; // r3
  int *v4; // r4
  int v5; // r5
  int *i; // r2
  int v7; // t1

  v2 = (char *)result - ObpInfoMaskToOffset[*((_BYTE *)result + 14) & 7];
  if ( (*((_BYTE *)result + 15) & 0x40) != 0 )
  {
    --v2[7];
    *((_DWORD *)v2 + 1) = *((_DWORD *)v2 + 1) & 0xFF000000 | (*((_DWORD *)v2 + 1) + 1) & 0xFFFFFF;
  }
  else
  {
    v3 = *(int **)v2;
    v4 = 0;
    result = 0;
    v5 = *v3;
    for ( i = v3 + 1; v5; --v5 )
    {
      v7 = *i;
      i += 2;
      if ( v7 == a2 )
      {
        if ( !result )
          result = i - 2;
        v4 = i - 2;
        if ( *((unsigned __int8 *)i - 1) != 255 )
          break;
      }
    }
    result[1] = result[1] & 0xFF000000 | (result[1] + 1) & 0xFFFFFF;
    --*((_BYTE *)v4 + 7);
  }
  return result;
}

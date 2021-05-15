// SmKmStoreHelperWaitForCommand 
 
int __fastcall SmKmStoreHelperWaitForCommand(_DWORD *a1, _DWORD *a2, int *a3, int a4)
{
  int result; // r0
  int v9; // r4
  unsigned int *v10; // r2
  unsigned int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  _DWORD *v15; // r6
  int v16; // r3

  while ( 1 )
  {
    result = KeWaitForSingleObject((unsigned int)(a1 + 5), 0, 0, 0, a3);
    if ( !result )
      break;
    if ( !a4 )
      return result;
    v9 = a1[9];
    if ( (v9 & 1) == 0 )
    {
      __dmb(0xBu);
      v10 = a1 + 9;
      do
        v11 = __ldrex(v10);
      while ( v11 == v9 && __strex(v9 | 2, v10) );
      LOBYTE(v9) = v11;
      __dmb(0xBu);
    }
    if ( (v9 & 1) == 0 )
      return -1073741536;
  }
  KeResetEvent((int)(a1 + 5));
  if ( a2 )
  {
    v12 = a1[11];
    v13 = a1[12];
    v14 = a1[13];
    *a2 = a1[10];
    a2[1] = v12;
    a2[2] = v13;
    a2[3] = v14;
    v15 = a2 + 4;
    v16 = a1[15];
    *v15 = a1[14];
    v15[1] = v16;
  }
  if ( (a1[9] & 2) != 0 )
    result = -1073741536;
  else
    result = 0;
  a1[9] = 0;
  return result;
}

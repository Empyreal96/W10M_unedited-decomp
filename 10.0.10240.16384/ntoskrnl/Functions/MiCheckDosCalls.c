// MiCheckDosCalls 
 
int __fastcall MiCheckDosCalls(unsigned __int16 *a1, unsigned int a2)
{
  unsigned int v3; // r5
  int v5; // r3
  unsigned __int16 *v6; // r9
  unsigned int v7; // r7
  int v8; // r8
  int v9; // r2
  int v10; // t1
  int v11; // r1

  v3 = a1[15];
  if ( a1[15] )
  {
    v5 = a1[20];
    v6 = (unsigned __int16 *)((char *)a1 + v5);
    if ( v5 + 2 * v3 <= a2 )
    {
      LOWORD(v7) = 0;
      if ( a1[15] )
      {
        v8 = a1[21];
        do
        {
          v10 = *v6++;
          v9 = v10;
          if ( v10 + v8 >= a2 )
            break;
          v11 = *((unsigned __int8 *)a1 + v8 + v9);
          if ( !*((_BYTE *)a1 + v8 + v9) || v11 + v9 + v8 >= a2 )
            break;
          if ( v11 == 8 && !memcmp((unsigned int)a1 + v8 + v9 + 1, (unsigned int)"DOSCALLS", 8) )
            return 1;
          v7 = (unsigned __int16)(v7 + 1);
        }
        while ( v7 < v3 );
      }
    }
  }
  return 0;
}

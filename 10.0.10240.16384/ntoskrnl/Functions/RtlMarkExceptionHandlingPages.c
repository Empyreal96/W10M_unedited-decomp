// RtlMarkExceptionHandlingPages 
 
int __fastcall RtlMarkExceptionHandlingPages(unsigned int a1, int a2, unsigned int a3, unsigned int a4, _BYTE *a5)
{
  unsigned int v5; // r6
  unsigned int v8; // r9
  unsigned int v9; // r5
  unsigned int v10; // r4
  unsigned int v11; // r2
  unsigned int *v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r3
  int v16; // r7
  int v17; // r3
  unsigned int v18; // lr
  int v19; // r7

  v5 = a3;
  v8 = a1 + a2;
  if ( a3 >= a1 && a3 + a4 <= v8 && (a4 & 7) == 0 )
  {
    RtlSetBits(a5, (a3 - a1) >> 12, ((a3 - a1 + a4 + 4095) >> 12) - ((a3 - a1) >> 12));
    v9 = a4 >> 3;
    v10 = 0;
    if ( !(a4 >> 3) )
      return 0;
    while ( 1 )
    {
      v11 = *(_DWORD *)(v5 + 4);
      if ( (v11 & 3) == 0 )
      {
        v13 = (unsigned int *)(v11 + a1);
        if ( v11 + a1 < a1 || (unsigned int)(v13 + 2) > v8 )
          return -1073741569;
        v14 = *v13;
        v15 = *v13 >> 23;
        if ( v15 )
        {
          v16 = 4;
          v17 = v15 & 0x1F;
          v18 = v14 >> 28;
        }
        else
        {
          v17 = *((unsigned __int16 *)v13 + 2);
          v18 = *((unsigned __int8 *)v13 + 6);
          v16 = 8;
        }
        if ( (v14 & 0x200000) == 0 )
          v16 += 4 * v17;
        v19 = v16 + 4 * v18;
        if ( (v14 & 0x100000) != 0 )
          v19 += 4;
        if ( (unsigned int)v13 + v19 > v8 )
          return -1073741569;
        RtlSetBits(a5, v11 >> 12, ((v19 + v11 + 4095) >> 12) - (v11 >> 12));
      }
      ++v10;
      v5 += 8;
      if ( v10 >= v9 )
        return 0;
    }
  }
  return -1073741569;
}

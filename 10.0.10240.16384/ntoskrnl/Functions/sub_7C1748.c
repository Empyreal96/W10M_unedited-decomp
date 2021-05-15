// sub_7C1748 
 
void __fastcall sub_7C1748(int a1, int a2, int a3, int a4, int a5, unsigned int a6)
{
  unsigned int *v6; // r9
  int v7; // r10
  unsigned int v8; // r4
  int v9; // r3

  if ( a4 == 1 )
  {
    v6[13] = -1;
    v6[7] = 1;
    v6[14] = 0;
    v6[9] = 0;
    v6[10] = 0;
    v6[11] = 0;
    v6[12] = 0;
    *v6 = 60;
    goto LABEL_17;
  }
  if ( a4 != 4 )
  {
    if ( a4 == 9 )
    {
      if ( RtlStringCchLengthW((unsigned __int16 *)(v7 + 44), 0xC8u, &a5) < 0 )
        goto LABEL_17;
      v8 = 2 * (a5 + 19);
      if ( a6 >= v8 )
      {
        memmove((int)(v6 + 9), v7 + 44, 2 * (a5 + 1));
        v9 = 3;
LABEL_13:
        v6[7] = v9;
        *v6 = v8;
        goto LABEL_17;
      }
LABEL_18:
      JUMPOUT(0x6A976A);
    }
    if ( a4 != 10 && a4 != 11 )
LABEL_17:
      JUMPOUT(0x6A96FC);
  }
  if ( RtlStringCchLengthW((unsigned __int16 *)(v7 + 44), 0xC8u, &a5) < 0 )
    goto LABEL_17;
  v8 = 2 * (a5 + 19);
  if ( a6 >= v8 )
  {
    memmove((int)(v6 + 9), v7 + 44, 2 * (a5 + 1));
    v9 = 2;
    goto LABEL_13;
  }
  goto LABEL_18;
}

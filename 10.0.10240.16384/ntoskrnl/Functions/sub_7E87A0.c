// sub_7E87A0 
 
void __fastcall sub_7E87A0(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, int a8, int a9, int a10, __int16 *a11, int a12, int a13, int a14)
{
  int v14; // r2
  unsigned __int16 *v15; // r4
  int v16; // r5
  int v17; // r2
  int v18; // r0
  int v19; // r1
  int v20; // r2

  v17 = *v15;
  v18 = v17;
  v19 = *((_DWORD *)v15 + 1) + v17;
  if ( *v15 )
  {
    do
    {
      if ( *(_WORD *)(v19 - 2) == 92 )
        break;
      v19 -= 2;
      v18 -= 2;
    }
    while ( v18 );
  }
  v20 = v17 - v18;
  a7 = v20;
  a8 = v19;
  if ( (unsigned __int16)v20 == v20 )
  {
    v14 = 576;
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) == 1 )
      v14 = 1600;
    a9 = 24;
    a12 = v14;
    a10 = a5;
    a11 = &a7;
    a13 = 0;
    a14 = 0;
    if ( ZwOpenKey() >= 0 )
      RtlpProcessIFEOKeyFilter(v16);
  }
  JUMPOUT(0x6FC7AE);
}

// sub_7E7830 
 
void __fastcall sub_7E7830(int *a1, int a2, unsigned int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int *a14)
{
  int v14; // r5
  int v15; // r6
  unsigned __int16 *v16; // r7
  int v17; // r3
  unsigned __int16 *v18; // r1
  int v19; // r6
  int v20; // r5

  if ( *a1 < 0 )
  {
    v17 = *a1 & 0x7FFFFFFF;
    if ( a2 )
    {
      v18 = (unsigned __int16 *)(v17 + a3);
      if ( v17 + a3 < a3 || (unsigned int)v18 > (v15 & 0xFFFFFFFC) + v14 )
LABEL_12:
        JUMPOUT(0x6F6E3A);
    }
    else
    {
      v18 = (unsigned __int16 *)(v17 + a3);
    }
    if ( ((unsigned int)(v18 + 1) & 0xFFFF0000) == 0 )
      goto LABEL_12;
    v19 = *v18;
    v20 = wcsncmp(v16, v18 + 1, v19);
    if ( v20 || wcslen(v16) == v19 )
    {
      *a14 = v20;
      JUMPOUT(0x6F6E30);
    }
  }
  JUMPOUT(0x6F6E2C);
}

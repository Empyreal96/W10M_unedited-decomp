// sub_51D95C 
 
void __fastcall sub_51D95C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, bool *a15)
{
  _DWORD *v15; // r5
  _DWORD *v16; // r6
  int v17; // lr
  char *v18; // r3
  char v19; // r2

  *v15 = a3;
  if ( (v17 & 0x2000000) != 0 )
  {
    if ( a3 )
    {
      *v16 = 0;
      v18 = (char *)a15;
      if ( !a15 )
        goto LABEL_10;
      v19 = 1;
    }
    else
    {
      *v16 = -1073741790;
      v18 = (char *)a15;
      if ( !a15 )
        goto LABEL_10;
      v19 = 0;
    }
    *v18 = v19;
  }
  else
  {
    *v16 = -1073741790;
    if ( a15 )
      *a15 = *v15 != 0;
  }
LABEL_10:
  JUMPOUT(0x44B0EE);
}

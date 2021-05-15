// SepConstrainByMandatory 
 
int __fastcall SepConstrainByMandatory(int result, int a2, int *a3, int a4, int a5, unsigned int a6)
{
  int *v6; // r5
  unsigned int v8; // r1
  int v9; // r6
  int v10; // r3

  v6 = a3;
  if ( *(_DWORD *)(result + 8) && (!*(_BYTE *)(result + 5) || !*(_BYTE *)(result + 4) || !*(_BYTE *)(result + 6)) )
  {
    if ( !a6 )
    {
      if ( (*(_DWORD *)result & *a3) != *a3 )
        result = sub_51D95C();
      return result;
    }
    v8 = 0;
    v9 = a4 - (_DWORD)a3;
    do
    {
      v10 = *(_DWORD *)result & *v6;
      if ( v10 != *v6 )
      {
        *v6 = v10;
        if ( (a2 & 0x2000000) == 0 )
        {
          *(int *)((char *)v6 + v9) = -1073741790;
          if ( !a5 )
            goto LABEL_15;
          if ( *v6 )
            goto LABEL_21;
LABEL_14:
          *(_BYTE *)(v8 + a5) = 0;
          goto LABEL_15;
        }
        if ( v10 )
        {
          *(int *)((char *)v6 + v9) = 0;
          if ( !a5 )
            goto LABEL_15;
LABEL_21:
          *(_BYTE *)(v8 + a5) = 1;
          goto LABEL_15;
        }
        *(int *)((char *)v6 + v9) = -1073741790;
        if ( a5 )
          goto LABEL_14;
      }
LABEL_15:
      ++v8;
      ++v6;
    }
    while ( v8 < a6 );
  }
  return result;
}

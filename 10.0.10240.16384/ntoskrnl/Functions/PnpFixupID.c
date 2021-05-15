// PnpFixupID 
 
int __fastcall PnpFixupID(_WORD *a1, int a2, int a3, unsigned int a4)
{
  int v4; // r6
  unsigned int v5; // r5
  _WORD *v7; // lr
  _WORD *v8; // r3
  unsigned int v9; // r4

  v4 = 0;
  v5 = (unsigned int)&a1[a2];
  v7 = 0;
  v8 = a1;
  if ( (unsigned int)a1 >= v5 )
    goto LABEL_22;
  while ( 1 )
  {
    v9 = (unsigned __int16)*v8;
    if ( *v8 )
      break;
    if ( !a3 || v7 && v8 == v7 + 1 )
    {
LABEL_13:
      if ( (unsigned int)v8 < v5 && (v4 == a4 || a4 == -1) )
        return v8 - a1 + 1;
LABEL_22:
      JUMPOUT(0x7CAD12);
    }
    v5 += 2 * a2;
    v7 = v8;
LABEL_8:
    if ( (unsigned int)++v8 >= v5 )
      goto LABEL_13;
  }
  if ( v9 == 32 )
  {
    *v8 = 95;
    goto LABEL_8;
  }
  if ( v9 < 0x20 || v9 > 0x7F || v9 == 44 )
    JUMPOUT(0x7CAD0C);
  if ( v9 != 92 )
    goto LABEL_8;
  if ( ++v4 <= a4 )
    goto LABEL_8;
  return sub_7CACD8();
}

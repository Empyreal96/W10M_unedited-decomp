// sub_813C74 
 
void __fastcall sub_813C74(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned __int16 a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, _BYTE *a22, unsigned int *a23)
{
  unsigned int v23; // r5
  _DWORD *v24; // r7
  unsigned __int16 *v25; // r8
  _BYTE *v26; // r0
  _BYTE *v27; // r1
  int v28; // r0

  if ( a3 == 3 )
  {
    if ( *v24 < 0x10u )
      goto LABEL_26;
    RtlInitUnicodeString((unsigned int)&a9, v25);
    v28 = RtlGUIDFromString(&a9, a22);
    if ( v28 < 0 )
    {
      if ( v28 == -1073741789 )
        JUMPOUT(0x7A6820);
      JUMPOUT(0x7A6822);
    }
  }
  else
  {
    if ( a3 == 5 )
    {
      if ( v23 <= 8 )
      {
        if ( *a23 >= 8 )
        {
          v26 = a22;
          *(_DWORD *)a22 = 0;
          *((_DWORD *)v26 + 1) = 0;
          goto LABEL_8;
        }
        goto LABEL_26;
      }
      goto LABEL_25;
    }
    if ( a3 != 6 )
    {
      if ( a3 == 7 )
      {
        if ( v23 && (v23 & 7) == 0 )
        {
          if ( *a23 >= v23 )
            goto LABEL_7;
          goto LABEL_26;
        }
      }
      else if ( v23 )
      {
        if ( v23 <= *a23 )
        {
LABEL_7:
          v26 = a22;
LABEL_8:
          memmove((int)v26, (int)v25, v23);
          goto LABEL_27;
        }
LABEL_26:
        JUMPOUT(0x7A681E);
      }
LABEL_25:
      JUMPOUT(0x7A693E);
    }
    if ( v23 != 1 )
      goto LABEL_25;
    if ( *a23 < 2 )
      goto LABEL_26;
    v27 = a22;
    a22[1] = 0;
    if ( *(_BYTE *)v25 )
      *v27 = 1;
    else
      *v27 = 0;
  }
LABEL_27:
  JUMPOUT(0x7A68AE);
}

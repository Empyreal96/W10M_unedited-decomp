// sub_7D0A74 
 
void __fastcall sub_7D0A74(int a1, int a2, int a3, int a4, int a5, unsigned int *a6, int a7, int a8, unsigned int a9, int a10, int a11, int *a12, int a13, int *a14, int a15, int a16, int a17, int a18, int a19, int a20, char a21, int a22, unsigned int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, unsigned int a32, int a33)
{
  int v33; // r6
  int v34; // r5
  int v35; // r4

  v34 = 0;
  a14 = &a33;
  HIWORD(a13) = 4;
  RtlInitUnicodeString((unsigned int)&a21, L"SmallProcessorMask");
  a16 = a7;
  while ( 1 )
  {
    a6 = &a9;
    a5 = 24;
    v35 = ZwEnumerateKey();
    if ( v35 < 0 )
      goto LABEL_15;
    a9 = a32;
    if ( a32 <= 4 )
    {
      LOWORD(a13) = a32;
      v35 = RtlUnicodeStringToInteger((unsigned __int16 *)&a13, 0xAu, (int *)&a23);
      if ( v35 < 0 )
        goto LABEL_17;
      if ( a23 < *(unsigned __int16 *)(v33 + 2) )
        break;
    }
LABEL_16:
    if ( v35 < 0 )
    {
LABEL_17:
      ZwClose();
      JUMPOUT(0x78AD36);
    }
  }
  a11 = a13;
  a12 = &a5;
  v35 = ZwOpenKey();
  if ( v35 < 0 )
  {
LABEL_15:
    ++v34;
    goto LABEL_16;
  }
  a6 = &a9;
  v35 = ZwQueryValueKey();
  if ( v35 >= 0 && (a25 == 4 || a25 == 11) )
  {
    if ( a26 == 4 )
    {
      a28 = 0;
LABEL_13:
      *(_DWORD *)(v33 + 8) |= a27;
      goto LABEL_14;
    }
    if ( a26 == 8 )
      goto LABEL_13;
  }
LABEL_14:
  ZwClose();
  goto LABEL_15;
}

// sub_7E2CA4 
 
void __fastcall sub_7E2CA4(int a1, int a2, int a3, int a4, int a5, _WORD *a6, int a7, unsigned __int16 *a8)
{
  _WORD *v8; // r7
  unsigned __int16 **v9; // r8
  int v10; // r9
  _WORD *v11; // r0
  int v12; // r3
  int v13; // r5

  v11 = wcschr(v8 + 1, 58);
  if ( v11 )
  {
    a6 = v8 + 1;
    LOWORD(a5) = 2 * (v11 - (v8 + 1));
    HIWORD(a5) = a5;
    if ( v11 != (_WORD *)-2 )
    {
      if ( v11 + 1 != v8 )
      {
        if ( RtlDuplicateUnicodeString(1, (int)&a5, (int)&a7) >= 0 )
        {
          v13 = DrvDbFindDatabaseNode(v10, a8, v9, v12);
          RtlFreeAnsiString(&a7);
          if ( v13 != -1073741772 && v13 >= 0 )
            JUMPOUT(0x77B3AA);
        }
        JUMPOUT(0x77B3AE);
      }
      JUMPOUT(0x77B3A2);
    }
  }
  JUMPOUT(0x77B3A0);
}

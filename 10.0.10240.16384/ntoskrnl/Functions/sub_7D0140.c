// sub_7D0140 
 
void sub_7D0140(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  int v8; // r7
  int v9; // r9
  int v10; // r2
  int v11; // r3
  int v12; // r0
  int v13; // r2
  int v14; // r3
  int v15; // r5
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  if ( !v8 || MmIsDriverLoadedCurrentSession(v9) != 1 )
  {
    while ( 1 )
    {
      do
      {
        v12 = MmGetNextSession();
        v15 = v12;
        if ( !v12 )
          JUMPOUT(0x78A02E);
      }
      while ( MmAttachSession(v12, (int)va, v13, v14) < 0 );
      if ( MmIsDriverLoadedCurrentSession(v9) == 1 )
        break;
      MmDetachSession(v15, (int)va, v10, v11);
    }
  }
  JUMPOUT(0x78A018);
}

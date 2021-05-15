// sub_812E0C 
 
void __fastcall sub_812E0C(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r6
  unsigned int *v6; // r7
  unsigned int v7; // r8
  int v8; // r9
  unsigned __int16 *v9; // r5
  int v10; // r4
  unsigned int v11; // r2

  v9 = (unsigned __int16 *)ExAllocatePoolWithTag(1, a5, 1263556947);
  if ( v9 )
  {
    v10 = ZwQuerySystemInformation();
    if ( v10 >= 0 )
    {
      v11 = *v9 + 2;
      *v6 = v11;
      if ( v11 <= v7 )
        memmove(v8, *((_DWORD *)v9 + 1), v11);
      else
        v10 = v5;
    }
    ExFreePoolWithTag((unsigned int)v9);
    if ( v10 < 0 )
      JUMPOUT(0x7A461C);
    JUMPOUT(0x7A462E);
  }
  JUMPOUT(0x7A4620);
}

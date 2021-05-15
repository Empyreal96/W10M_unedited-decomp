// sub_8184F8 
 
void __fastcall sub_8184F8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  _DWORD *v13; // r5
  int v14; // r6

  if ( a4 == 1 )
  {
    if ( v14 >= 0 )
    {
      *v13 = v13[14] + a13;
      KeQuerySystemTime(v13 + 4);
LABEL_9:
      JUMPOUT(0x7B24EA);
    }
  }
  else
  {
    if ( a4 != 9 )
      JUMPOUT(0x7B2514);
    if ( v14 >= 0 )
    {
      *v13 = v13[15] + a13;
      KeQuerySystemTime(v13 + 4);
      v13[16] = a13;
      goto LABEL_9;
    }
  }
  JUMPOUT(0x7B24FE);
}

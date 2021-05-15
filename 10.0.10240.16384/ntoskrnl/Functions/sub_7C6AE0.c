// sub_7C6AE0 
 
void __fastcall sub_7C6AE0(int a1, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, unsigned int *a13)
{
  _DWORD *v13; // r5
  _DWORD *v14; // r6
  unsigned int v15; // r7
  unsigned int v16; // r2

  if ( a3 == 3 )
  {
    *a2 = 13;
    *a13 = 16;
    if ( v15 >= 0x10 )
    {
      *v14 = v13[1];
      v14[1] = v13[2];
      v14[2] = v13[3];
      v14[3] = v13[4];
      JUMPOUT(0x6C963C);
    }
  }
  else
  {
    if ( a3 != 4 )
      JUMPOUT(0x6C9672);
    *a2 = v13[1];
    v16 = v13[2];
    *a13 = v16;
    if ( v15 >= v16 )
      JUMPOUT(0x6C9636);
  }
  JUMPOUT(0x6C9664);
}

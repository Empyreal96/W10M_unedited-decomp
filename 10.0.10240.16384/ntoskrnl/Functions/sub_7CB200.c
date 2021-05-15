// sub_7CB200 
 
void __fastcall sub_7CB200(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _DWORD *a9)
{
  unsigned __int16 *v9; // r7
  unsigned int v10; // r2
  _WORD *v11; // r1
  __int16 *v12; // r2
  int i; // r0
  __int16 v14; // t1

  v10 = a9[3];
  if ( v10 > 2 && a9[1] == 1 )
  {
    *v9 = v10 - 2;
    v11 = a9;
    v9[1] = a9[3];
    v12 = (__int16 *)((char *)a9 + a9[2]);
    for ( i = *v9 >> 1; i; ++v11 )
    {
      v14 = *v12++;
      --i;
      *v11 = v14;
    }
    *((_DWORD *)v9 + 1) = a9;
    JUMPOUT(0x76C8FE);
  }
  ExFreePoolWithTag((unsigned int)a9);
  JUMPOUT(0x76C900);
}

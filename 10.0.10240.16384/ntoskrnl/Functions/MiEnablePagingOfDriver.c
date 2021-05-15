// MiEnablePagingOfDriver 
 
void __fastcall __spoils<R2,R3,R12> MiEnablePagingOfDriver(int a1, int a2, unsigned int a3, unsigned int a4)
{
  int v5; // r5
  unsigned int v6; // [sp+8h] [bp-18h] BYREF
  unsigned int v7[5]; // [sp+Ch] [bp-14h] BYREF

  v6 = a3;
  v7[0] = a4;
  if ( MiImagePagable(a1, *(_DWORD *)(a1 + 24)) )
  {
    v5 = 0;
    do
    {
      v5 = MiSnapDriverRange(a1, v5, 1, 0, &v6, v7);
      if ( v6 )
        MiSetPagingOfDriver(a1, v6, v7[0]);
    }
    while ( v5 );
  }
}

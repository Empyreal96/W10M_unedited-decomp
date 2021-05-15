// MiBackSingleImageWithPagefile 
 
int __fastcall MiBackSingleImageWithPagefile(int a1)
{
  unsigned int v1; // r4
  int result; // r0
  unsigned int v4; // [sp+8h] [bp-20h] BYREF
  unsigned int v5[7]; // [sp+Ch] [bp-1Ch] BYREF

  v1 = 0;
  do
  {
    result = MiSnapDriverRange(a1, v1, 8, 0, &v4, v5);
    v1 = result;
    if ( v4 )
      result = MiMakeDriverPagesPrivate(a1, v4, v5[0], 17, 4);
  }
  while ( v1 );
  return result;
}

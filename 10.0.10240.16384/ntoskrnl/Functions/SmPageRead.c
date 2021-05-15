// SmPageRead 
 
int __fastcall SmPageRead(int *a1, int a2, int a3, int a4)
{
  int v5[4]; // [sp+0h] [bp-10h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  if ( (*a1 & 0xF0000000) != -268435456 )
    v5[0] = *a1;
  return SmpPageRead(v5);
}

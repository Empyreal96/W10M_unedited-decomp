// sub_51710C 
 
void __fastcall sub_51710C(int a1)
{
  int v1; // r4
  int *v2; // r5
  int *v3; // r7
  int v4; // r8
  int v5; // lr
  int v6; // t1

  while ( 1 )
  {
    v6 = *v2++;
    if ( v6 != v5 )
      break;
    if ( v2 == v3 )
      JUMPOUT(0x436F2A);
  }
  KeBugCheckEx(218, 1280, v1, a1, v4);
}

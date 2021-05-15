// sub_51DD38 
 
void __fastcall sub_51DD38(int a1, int *a2)
{
  int v2; // r5
  int v3; // r3

  __dmb(0xFu);
  while ( 1 )
  {
    v3 = *a2;
    __dmb(0xBu);
    if ( (v3 & v2) == 0 )
      break;
    __dmb(0xAu);
    __yield();
  }
  if ( a1 )
    JUMPOUT(0x44BB0C);
  JUMPOUT(0x44BB1C);
}

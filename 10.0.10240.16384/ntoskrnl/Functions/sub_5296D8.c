// sub_5296D8 
 
void sub_5296D8()
{
  int v0; // r4
  unsigned int *v1; // r5
  unsigned int v2; // r2

  if ( !v0 )
  {
    __dmb(0xBu);
    do
      v2 = __ldrex(v1);
    while ( __strex(0, v1) );
    __dmb(0xBu);
    KeSetEvent((int)&PopUserPresentCompletedEvent, 0, 0);
  }
  JUMPOUT(0x466AC4);
}

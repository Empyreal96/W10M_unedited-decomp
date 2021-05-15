// sub_552B10 
 
void sub_552B10()
{
  unsigned int *v0; // r6
  unsigned int v1; // r5

  __dmb(0xBu);
  do
    v1 = __ldrex(v0);
  while ( __strex(0, v0) );
  __dmb(0xBu);
  JUMPOUT(0x4F256E);
}

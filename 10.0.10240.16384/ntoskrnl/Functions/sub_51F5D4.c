// sub_51F5D4 
 
void sub_51F5D4()
{
  int v0; // r4
  unsigned int v1; // r6
  unsigned int v2; // r7
  unsigned __int64 *v3; // r3
  unsigned __int64 v4; // kr00_8
  unsigned __int64 *v5; // r3
  unsigned __int64 v6; // kr08_8

  __dmb(0xBu);
  v3 = (unsigned __int64 *)(v0 + 80);
  do
    v4 = __ldrexd(v3);
  while ( __strexd(v4 + v2, v3) );
  __dmb(0xBu);
  v5 = (unsigned __int64 *)(v0 + 96);
  do
    v6 = __ldrexd(v5);
  while ( __strexd(v6 + v1, v5) );
  JUMPOUT(0x44F7F2);
}

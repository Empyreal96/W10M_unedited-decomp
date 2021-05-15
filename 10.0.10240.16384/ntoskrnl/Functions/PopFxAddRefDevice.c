// PopFxAddRefDevice 
 
int __fastcall PopFxAddRefDevice(int result)
{
  unsigned int *v1; // r1
  unsigned int v2; // r2

  __dmb(0xBu);
  v1 = (unsigned int *)(result + 112);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 + 1, v1) );
  __dmb(0xBu);
  if ( *(_BYTE *)(result + 108) )
    sub_50E1CC();
  return result;
}

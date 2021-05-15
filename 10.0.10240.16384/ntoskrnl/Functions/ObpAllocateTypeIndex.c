// ObpAllocateTypeIndex 
 
int __fastcall ObpAllocateTypeIndex(_BYTE *a1)
{
  int v1; // r1
  unsigned int *i; // r4
  unsigned int v3; // r2

  v1 = 3;
  for ( i = (unsigned int *)&unk_6820F4; ; ++i )
  {
    __dmb(0xBu);
    do
      v3 = __ldrex(i);
    while ( !v3 && __strex(1u, i) );
    __dmb(0xBu);
    if ( !v3 )
      break;
    if ( (unsigned int)++v1 >= 0x100 )
      return -1073741823;
  }
  *a1 = v1;
  return 0;
}

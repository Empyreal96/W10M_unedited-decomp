// MiCreateWriteWatchView 
 
int __fastcall MiCreateWriteWatchView(int a1)
{
  int result; // r0
  unsigned int *v3; // r2
  unsigned int v4; // r0

  result = MiCreateVadEventBitmap();
  if ( result >= 0 )
  {
    __dmb(0xBu);
    v3 = (unsigned int *)(a1 + 192);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 | 0x8000, v3) );
    __dmb(0xBu);
    result = 0;
  }
  return result;
}

// sub_7F223C 
 
void sub_7F223C()
{
  int v0; // r6
  unsigned int v1; // r1
  int v2; // r3
  int v3; // r0
  unsigned int v4; // r4

  v1 = MEMORY[0xFFFF9004];
  if ( MEMORY[0xFFFF9004] < 0x1000000u )
  {
    while ( 1 )
    {
      v3 = MEMORY[0xFFFF9324];
      __dmb(0xBu);
      v4 = MEMORY[0xFFFF9320];
      __dmb(0xBu);
      if ( v3 == MEMORY[0xFFFF9328] )
        break;
      __dmb(0xAu);
      __yield();
    }
    v2 = ((__int64)(v4 * (unsigned __int64)v1) >> 24) + (v3 << 8) * v1;
  }
  else
  {
    v2 = (__int64)(MEMORY[0xFFFF9320] * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24;
  }
  *(_DWORD *)(v0 + 28) = v2;
  JUMPOUT(0x70830C);
}

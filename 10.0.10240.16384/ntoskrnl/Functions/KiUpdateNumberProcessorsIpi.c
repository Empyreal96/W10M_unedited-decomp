// KiUpdateNumberProcessorsIpi 
 
int __fastcall KiUpdateNumberProcessorsIpi(_DWORD *a1)
{
  unsigned int *v2; // r2
  unsigned int v3; // r1
  int v4; // r3
  unsigned int *v5; // r2
  unsigned int v6; // r1
  int v7; // r3
  int v8; // r3

  if ( a1[1] == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) )
  {
    while ( 1 )
    {
      v7 = a1[2];
      __dmb(0xBu);
      if ( !v7 )
        break;
      __dmb(0xAu);
      __yield();
    }
    KiUpdateProcessorCount();
    __dmb(0xBu);
    a1[4] = 1;
    while ( 1 )
    {
      v8 = a1[3];
      __dmb(0xBu);
      if ( !v8 )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  else
  {
    __dmb(0xBu);
    v2 = a1 + 2;
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 - 1, v2) );
    __dmb(0xBu);
    while ( 1 )
    {
      v4 = a1[4];
      __dmb(0xBu);
      if ( v4 )
        break;
      __dmb(0xAu);
      __yield();
    }
    __dmb(0xBu);
    v5 = a1 + 3;
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 - 1, v5) );
    __dmb(0xBu);
  }
  return 0;
}

// sub_7D37F0 
 
void __fastcall sub_7D37F0(__int64 a1)
{
  _QWORD *v1; // r8
  int v2; // r5

  while ( 1 )
  {
    v2 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    __dmb(0xBu);
    if ( v2 == MEMORY[0xFFFF9010] )
      break;
    __dmb(0xAu);
    __yield();
  }
  if ( a1 != *v1 )
    JUMPOUT(0x6D3984);
  JUMPOUT(0x6D398C);
}

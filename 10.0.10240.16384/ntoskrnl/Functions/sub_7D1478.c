// sub_7D1478 
 
void __fastcall sub_7D1478(__int64 a1, _QWORD *a2)
{
  int v2; // r4
  unsigned int v3; // r5
  unsigned int v4; // r7

  while ( 1 )
  {
    v3 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v4 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    if ( v3 == MEMORY[0xFFFF9010] )
      break;
    __dmb(0xAu);
    __yield();
  }
  if ( a1 == *a2 )
  {
    *(_QWORD *)(v2 + 3240) = __PAIR64__(v3, v4) - a1;
    CmpIssueNewDirtyCallback();
    JUMPOUT(0x6D0166);
  }
  JUMPOUT(0x6D015E);
}

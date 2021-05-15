// sub_966528 
 
void __fastcall sub_966528(__int64 a1, _QWORD *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r4
  int v10; // r6
  int v11; // r7

  while ( 1 )
  {
    v10 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v11 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    if ( v10 == MEMORY[0xFFFF9010] )
      break;
    __dmb(0xAu);
    __yield();
  }
  if ( a1 == *a2 )
  {
    *(_DWORD *)(v9 + 32) = v11 - a1;
    *(_DWORD *)(v9 + 36) = v11 - a1;
    *(_BYTE *)(v9 + 60) = 1;
    PopTransitionTelemetryOsState();
    __asm { POP.W           {R4-R7,R11,PC} }
  }
  JUMPOUT(0x94B9BE);
}

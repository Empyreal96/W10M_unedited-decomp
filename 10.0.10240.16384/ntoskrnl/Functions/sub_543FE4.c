// sub_543FE4 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_543FE4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v13; // r5
  int v14; // r6
  char v15; // r7
  int v16; // r9
  int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r1

  v17 = MmIsFileObjectAPagingFile(v13);
  __dmb(0xBu);
  if ( v17 )
  {
    do
      v18 = __ldrex(&IoPageReadIrpAllocationFailure);
    while ( __strex(v18 + 1, &IoPageReadIrpAllocationFailure) );
    __dmb(0xBu);
    if ( !IopAllocateReserveIrp(v17, *(char *)(v14 + 48), 0) )
      goto LABEL_9;
  }
  else
  {
    do
      v19 = __ldrex(&IoPageReadNonPagefileIrpAllocationFailure);
    while ( __strex(v19 + 1, &IoPageReadNonPagefileIrpAllocationFailure) );
    __dmb(0xBu);
    if ( (*(_WORD *)(v16 + 6) & 0x40) == 0
      || (v15 & 0x40) == 0
      || !IopAllocateBackpocketIrp(v14, *(char *)(v14 + 48), 1) )
    {
LABEL_9:
      __asm { POP.W           {R4-R11,PC} }
    }
  }
  JUMPOUT(0x4B989E);
}

// sub_553F8C 
 
void __fastcall sub_553F8C(int a1, int a2, int a3, int *a4)
{
  int v4; // r5
  int v5; // r0

  if ( *a4 >= 1 && (*(_BYTE *)(v4 + 2) & 8) == 0 && ((v4 + 4095) & 0xFFFFF000) != v4 )
  {
    v5 = DbgPrint(
           "((FreeBlock->Flags & HEAP_ENTRY_DECOMMITTED) || (ROUND_UP_TO_POWER2(FreeBlock, PAGE_SIZE) == (ULONG_PTR)FreeBlock))");
    RtlpHeapHandleError(v5);
  }
  JUMPOUT(0x4F4E1C);
}

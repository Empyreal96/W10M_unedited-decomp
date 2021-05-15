// sub_52D328 
 
void __fastcall sub_52D328(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  unsigned int v10; // r4
  int v11; // r6
  int v12; // r9
  int v13; // r10
  int v14; // r2
  int v15; // r3

  if ( MmGetNextNode(v11, &a9) >= v10 )
  {
    v14 = a10;
    if ( *(&KeNodeBlock + *(unsigned __int16 *)(a10 + 266)) != (char *)&KiNodeInit
                                                             + 384 * *(unsigned __int16 *)(a10 + 266) )
    {
      v15 = *(_DWORD *)(a10 + v12);
      __dmb(0xBu);
      if ( (v15 & 2) != 0 )
      {
        ExpQueueWorkItemNode(a8, a7, v14, v13);
        JUMPOUT(0x477FEE);
      }
    }
    JUMPOUT(0x477FF0);
  }
  JUMPOUT(0x477F42);
}

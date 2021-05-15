// -SmpFlushStorePages@@YAXPAX@Z 
 
void __fastcall SmpFlushStorePages(void *a1)
{
  MmStoreFlushAllHintedPages();
  KeSetEvent((int)a1, 0, 0);
}

// ObIsObjectDeletionInline 
 
BOOL __fastcall ObIsObjectDeletionInline(int a1)
{
  return *(char *)(a1 - 9) < 0;
}

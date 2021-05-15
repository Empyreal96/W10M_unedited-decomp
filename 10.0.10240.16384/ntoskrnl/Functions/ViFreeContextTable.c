// ViFreeContextTable 
 
int __fastcall ViFreeContextTable(_DWORD *a1)
{
  return ExFreeToNPagedLookasideList((int)&ViObjectContextTableLookaside, a1);
}

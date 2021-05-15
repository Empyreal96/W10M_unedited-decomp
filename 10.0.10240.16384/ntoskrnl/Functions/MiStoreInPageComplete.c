// MiStoreInPageComplete 
 
void __fastcall MiStoreInPageComplete(int a1, int a2)
{
  if ( *(_WORD *)(a2 + 2) )
    --*(_WORD *)(a2 + 2);
}

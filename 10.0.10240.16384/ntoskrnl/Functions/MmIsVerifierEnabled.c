// MmIsVerifierEnabled 
 
int __fastcall MmIsVerifierEnabled(_DWORD *a1)
{
  if ( ViVerifierDriverAddedThunkListHead )
    return sub_8E537C();
  *a1 = 0;
  return -1073741637;
}

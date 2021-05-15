// MiSessionReferenceImage 
 
int __fastcall MiSessionReferenceImage(int a1)
{
  int v1; // r0

  v1 = MiSessionLookupImage(a1);
  if ( !v1 )
    return 0;
  ++*(_DWORD *)(v1 + 32);
  return 1;
}

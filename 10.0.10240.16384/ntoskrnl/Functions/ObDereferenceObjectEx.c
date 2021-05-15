// ObDereferenceObjectEx 
 
int __fastcall ObDereferenceObjectEx(int a1, int a2)
{
  unsigned int *v3; // r6
  unsigned int v5; // r5

  v3 = (unsigned int *)(a1 - 24);
  if ( ObpTraceFlags )
    return sub_52AFF4();
  __dmb(0xBu);
  do
    v5 = __ldrex(v3);
  while ( __strex(v5 - a2, v3) );
  if ( (int)(v5 - a2) <= 0 )
  {
    if ( v5 != a2 )
      KeBugCheckEx(24, 0, a1);
    ObpDeferObjectDeletion(a1 - 24);
  }
  return v5 - a2;
}

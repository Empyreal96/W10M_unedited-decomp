// IopUnloadSafeCompletion 
 
int __fastcall IopUnloadSafeCompletion(int a1, int a2, int *a3)
{
  int v7; // r7
  unsigned int *v8; // r5
  unsigned int v9; // r2
  signed int v10; // r2
  int v11; // r5

  if ( *(int *)(a2 + 24) < 0 )
  {
    if ( !*((_BYTE *)a3 + 12) )
      return sub_520678();
  }
  else if ( !*((_BYTE *)a3 + 13) )
  {
    return sub_520678();
  }
  v7 = *a3;
  v8 = (unsigned int *)(*a3 - 24);
  if ( ObpTraceFlags )
    ObpPushStackInfo(*a3 - 24, 1, 1, 1953261124);
  do
  {
    v9 = __ldrex(v8);
    v10 = v9 + 1;
  }
  while ( __strex(v10, v8) );
  __dmb(0xBu);
  if ( v10 <= 1 )
    KeBugCheckEx(24, 0, v8 + 6);
  v11 = ((int (__fastcall *)(int, int, int))a3[2])(a1, a2, a3[1]);
  ExFreePoolWithTag(a3, 0);
  ObfDereferenceObjectWithTag(v7);
  return v11;
}

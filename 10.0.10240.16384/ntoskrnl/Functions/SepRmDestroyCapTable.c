// SepRmDestroyCapTable 
 
unsigned int __fastcall SepRmDestroyCapTable(_DWORD *a1, int a2, int a3)
{
  _DWORD *v4; // r5
  int v5; // r1
  unsigned int v6; // r0
  int v8[8]; // [sp+0h] [bp-20h] BYREF

  v8[0] = 0;
  v8[1] = 0;
  v8[2] = 0;
  v8[3] = 0;
  v8[4] = 0;
  RtlInitEnumerationHashTable((int)a1, (int)v8, a3, 0);
  while ( 1 )
  {
    v4 = RtlEnumerateEntryHashTable(a1, v8);
    if ( !v4 )
      break;
    RtlRemoveEntryHashTable((int)a1, v4, 0);
    v4[4] = 0;
    ExFreePoolWithTag((unsigned int)v4);
  }
  RtlEndEnumerationHashTable((int)a1, v8);
  RtlDeleteHashTable((int)a1, v5);
  v6 = a1[11];
  if ( v6 )
    ExFreePoolWithTag(v6);
  return ExFreePoolWithTag((unsigned int)a1);
}

// CmpRecordUnloadEventForHive 
 
int __fastcall CmpRecordUnloadEventForHive(int a1, int a2)
{
  int v4; // r0
  int v6; // r3

  v4 = ExAllocatePoolWithTag(1, 4 * (*(_DWORD *)(a1 + 2520) + 1), 1984261443);
  if ( !v4 )
    return -1073741670;
  if ( *(_DWORD *)(a1 + 2520) )
    return sub_7F0CB8();
  v6 = *(_DWORD *)(a1 + 2520);
  *(_DWORD *)(a1 + 2524) = v4;
  *(_DWORD *)(v4 + 4 * v6) = a2;
  ++*(_DWORD *)(a1 + 2520);
  ObfReferenceObject(a2);
  return 0;
}

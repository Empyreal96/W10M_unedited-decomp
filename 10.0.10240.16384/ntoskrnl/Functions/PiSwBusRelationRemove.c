// PiSwBusRelationRemove 
 
unsigned int *__fastcall PiSwBusRelationRemove(int a1)
{
  int v1; // r2
  __int64 v3; // r0
  int v4; // r1
  int v5; // r3
  unsigned int v6; // r5

  v1 = a1 + 52;
  v3 = *(_QWORD *)(a1 + 52);
  if ( *(_DWORD *)(v3 + 4) != v1 || *(_DWORD *)HIDWORD(v3) != v1 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v3) = v3;
  *(_DWORD *)(v3 + 4) = HIDWORD(v3);
  v4 = *(_DWORD *)(a1 + 60);
  v5 = *(_DWORD *)(v4 + 8);
  if ( v5 == v4 + 8 )
  {
    v6 = *(_DWORD *)(v4 + 4);
    RtlDeleteElementGenericTableAvl((int)&PiSwBusRelationsTable, v4, v4 + 8, v5);
    if ( v6 )
      ExFreePoolWithTag(v6);
  }
  *(_DWORD *)(a1 + 60) = 0;
  return PiSwDeviceDereference((unsigned int *)a1);
}

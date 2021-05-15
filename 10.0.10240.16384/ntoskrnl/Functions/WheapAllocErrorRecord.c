// WheapAllocErrorRecord 
 
int __fastcall WheapAllocErrorRecord(int a1, int *a2)
{
  _BYTE *v4; // r0
  int v5; // r5
  int v6; // r4
  int v7; // r0

  *a2 = *(_DWORD *)(a1 + 24);
  if ( (unsigned int)KeGetCurrentIrql(a1) > 2 )
  {
    v7 = WheapGetPreallocatedErrorRecord(a1);
    v5 = v7;
    if ( v7 )
    {
      *(_DWORD *)(v7 + 16) = 1;
      goto LABEL_6;
    }
LABEL_7:
    *a2 = 0;
    return v5;
  }
  v4 = (_BYTE *)ExAllocatePoolWithTag(512, *a2);
  v5 = (int)v4;
  if ( !v4 )
    goto LABEL_7;
  v6 = *a2;
  memset(v4, 0, v6);
  WheapInitializeErrorRecordWrapper(v5, v6, a1);
LABEL_6:
  *(_DWORD *)(v5 + 24) = a1;
  return v5;
}

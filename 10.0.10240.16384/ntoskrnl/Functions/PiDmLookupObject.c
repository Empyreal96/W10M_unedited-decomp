// PiDmLookupObject 
 
int __fastcall PiDmLookupObject(int a1, int a2)
{
  int *v3; // r0
  int result; // r0
  char *v5; // [sp+0h] [bp-58h] BYREF
  char v6[80]; // [sp+8h] [bp-50h] BYREF

  v5 = v6;
  if ( a2
    && PiDmInitializeComparisonObject(a2, *(_DWORD *)(a1 + 112), v6) >= 0
    && (v3 = (int *)RtlLookupElementGenericTableAvl(a1 + 56, (int)&v5)) != 0 )
  {
    result = *v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

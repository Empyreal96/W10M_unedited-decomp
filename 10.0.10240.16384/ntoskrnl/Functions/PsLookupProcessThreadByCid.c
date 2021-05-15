// PsLookupProcessThreadByCid 
 
int __fastcall PsLookupProcessThreadByCid(_DWORD *a1, int *a2, int *a3, int a4)
{
  int result; // r0
  int v8; // r5
  int v9; // r4
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = (int)a3;
  v10[1] = a4;
  result = PsLookupThreadByThreadId(a1[1], v10);
  if ( result >= 0 )
  {
    v8 = v10[0];
    if ( *(_DWORD *)(v10[0] + 876) == *a1 )
    {
      if ( a2 )
      {
        v9 = *(_DWORD *)(v10[0] + 336);
        ObfReferenceObjectWithTag(v9);
        *a2 = v9;
      }
      *a3 = v8;
      result = 0;
    }
    else
    {
      result = sub_7E7A80();
    }
  }
  return result;
}

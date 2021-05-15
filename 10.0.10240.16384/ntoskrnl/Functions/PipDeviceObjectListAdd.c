// PipDeviceObjectListAdd 
 
int __fastcall PipDeviceObjectListAdd(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r6
  int result; // r0
  int *v10; // r4

  v5 = *(_DWORD **)a1;
  if ( **(_DWORD **)a1 + 1 == *(_DWORD *)(*(_DWORD *)a1 + 4) )
    return sub_7DFACC();
  v10 = &v5[4 * *v5 + 4];
  ObfReferenceObject(a2);
  v10[3] = 0;
  *v10 = a2;
  v10[1] = a3;
  if ( a4 == 1 )
  {
    v10[3] = 1;
    ++v5[2];
  }
  ++*v5;
  result = 0;
  *(_DWORD *)a1 = v5;
  return result;
}

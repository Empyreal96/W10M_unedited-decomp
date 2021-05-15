// PiDqSerializationAlloc 
 
int __fastcall PiDqSerializationAlloc(int result, _DWORD *a2, int *a3)
{
  int v4; // r5
  int v6; // r3

  v4 = result;
  if ( (unsigned int)*a3 <= *(_DWORD *)(result + 16) )
  {
LABEL_2:
    *a3 = *(_DWORD *)(v4 + 16);
    *a2 = *(_DWORD *)(v4 + 12);
    return result;
  }
  if ( !*(_DWORD *)(result + 12) )
  {
    if ( (unsigned int)*a3 < 0x1000 )
      *a3 = 4096;
    result = ExAllocatePoolWithTag(1, *a3, 1483763280);
    *(_DWORD *)(v4 + 12) = result;
    if ( result )
      v6 = *a3;
    else
      v6 = 0;
    *(_DWORD *)(v4 + 16) = v6;
    goto LABEL_2;
  }
  return sub_7E82EC();
}

// RtlCopyLuidAndAttributesArray 
 
int __fastcall RtlCopyLuidAndAttributesArray(int result, int a2, _DWORD *a3)
{
  int v3; // r6
  int v4; // r3
  int v5; // r4

  if ( result )
  {
    v3 = a2 - (_DWORD)a3;
    do
    {
      v4 = *(_DWORD *)((char *)a3 + v3 + 4);
      v5 = *(_DWORD *)((char *)a3 + v3 + 8);
      *a3 = *(_DWORD *)((char *)a3 + v3);
      a3[1] = v4;
      a3[2] = v5;
      a3 += 3;
      --result;
    }
    while ( result );
  }
  return result;
}

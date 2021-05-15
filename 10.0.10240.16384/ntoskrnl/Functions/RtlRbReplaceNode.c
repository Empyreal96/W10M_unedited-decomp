// RtlRbReplaceNode 
 
unsigned int *__fastcall RtlRbReplaceNode(unsigned int *result, _DWORD *a2, unsigned int a3)
{
  int v4; // r4
  int v5; // r5
  int v6; // r1
  _DWORD *v7; // r1

  v4 = a2[1];
  v5 = a2[2];
  *(_DWORD *)a3 = *a2;
  *(_DWORD *)(a3 + 4) = v4;
  *(_DWORD *)(a3 + 8) = v5;
  if ( *(_DWORD *)a3 )
  {
    *(_DWORD *)(*(_DWORD *)a3 + 8) = *(_DWORD *)(*(_DWORD *)a3 + 8) & 3 | a3;
  }
  else if ( (_DWORD *)result[1] == a2 )
  {
    result[1] = a3;
  }
  v6 = *(_DWORD *)(a3 + 4);
  if ( v6 )
    *(_DWORD *)(v6 + 8) = *(_DWORD *)(v6 + 8) & 3 | a3;
  v7 = (_DWORD *)(*(_DWORD *)(a3 + 8) & 0xFFFFFFFC);
  if ( v7 )
  {
    if ( (_DWORD *)*v7 == a2 )
      *v7 = a3;
    else
      v7[1] = a3;
  }
  else
  {
    *result = a3;
  }
  return result;
}

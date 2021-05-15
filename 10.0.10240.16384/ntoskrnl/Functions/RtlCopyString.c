// RtlCopyString 
 
int __fastcall RtlCopyString(int result, unsigned __int16 *a2)
{
  unsigned int v2; // r2

  *(_WORD *)result = 0;
  if ( a2 )
  {
    v2 = *a2;
    if ( v2 > *(unsigned __int16 *)(result + 2) )
      v2 = *(unsigned __int16 *)(result + 2);
    *(_WORD *)result = v2;
    result = memmove(*(_DWORD *)(result + 4), *((_DWORD *)a2 + 1), v2);
  }
  return result;
}

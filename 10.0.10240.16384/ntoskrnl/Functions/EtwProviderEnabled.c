// EtwProviderEnabled 
 
int __fastcall EtwProviderEnabled(int a1, int a2, unsigned int a3, int a4, __int64 a5)
{
  int v5; // r1

  if ( !a1 )
    return 0;
  v5 = *(_DWORD *)(a1 + 16);
  if ( *(_DWORD *)(v5 + 56)
    && (a3 <= *(unsigned __int8 *)(v5 + 60) || !*(_BYTE *)(v5 + 60))
    && ((*(_DWORD *)(v5 + 64) & 0x40) != 0 && !a5
     || (*(_QWORD *)(v5 + 72) & a5) != 0 && (*(_QWORD *)(v5 + 80) & a5) == *(_QWORD *)(v5 + 80)) )
  {
    return 1;
  }
  if ( *(_BYTE *)(a1 + 52) )
    return sub_51D30C();
  return 0;
}

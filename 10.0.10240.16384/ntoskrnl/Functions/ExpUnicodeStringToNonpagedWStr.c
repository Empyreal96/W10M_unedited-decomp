// ExpUnicodeStringToNonpagedWStr 
 
int __fastcall ExpUnicodeStringToNonpagedWStr(unsigned __int16 *a1)
{
  unsigned int v2; // r5
  int v3; // r0
  int v4; // r4

  v2 = *a1;
  v3 = ExAllocatePoolWithTag(512, v2 + 2, 1920364101);
  v4 = v3;
  if ( v3 )
  {
    memmove(v3, *((_DWORD *)a1 + 1), v2);
    *(_WORD *)(v4 + 2 * (v2 >> 1)) = 0;
  }
  return v4;
}

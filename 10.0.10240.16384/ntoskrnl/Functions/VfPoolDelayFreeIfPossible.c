// VfPoolDelayFreeIfPossible 
 
int __fastcall VfPoolDelayFreeIfPossible(int a1, unsigned int a2)
{
  char *v2; // r4
  int v3; // r3
  int result; // r0

  if ( a2 <= 1
    && (v2 = (char *)&VfPoolDelayFreeData + 48 * a2, ++*((_DWORD *)v2 + 8), v3 = *((_DWORD *)v2 + 7), __dmb(0xBu), v3) )
  {
    result = sub_50A658();
  }
  else
  {
    result = ExFreePoolWithTag(a1, 0);
  }
  return result;
}

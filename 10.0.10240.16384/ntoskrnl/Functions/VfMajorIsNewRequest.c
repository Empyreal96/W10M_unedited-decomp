// VfMajorIsNewRequest 
 
int __fastcall VfMajorIsNewRequest(int a1, unsigned __int8 *a2)
{
  unsigned int v3; // r3
  int (__fastcall *v5)(int, unsigned __int8 *); // r3

  v3 = *a2;
  if ( v3 > 0x1B )
  {
    if ( v3 == 255 )
      v3 = 28;
    else
      v3 = 29;
  }
  v5 = *(int (__fastcall **)(int, unsigned __int8 *))&ViMajorVerifierRoutines[48 * v3 + 28];
  if ( v5 && v5(a1, a2) )
    return 1;
  if ( dword_908BF4 )
    return ((int (__fastcall *)(int, unsigned __int8 *))dword_908BF4)(a1, a2);
  return 0;
}

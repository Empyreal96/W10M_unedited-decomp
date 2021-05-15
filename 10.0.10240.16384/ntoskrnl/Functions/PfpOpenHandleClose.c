// PfpOpenHandleClose 
 
int *__fastcall PfpOpenHandleClose(int *result, int a2)
{
  int *v2; // r4
  unsigned int *v3; // r2
  unsigned int v4; // r1
  int v5[6]; // [sp+0h] [bp-18h] BYREF

  v2 = result;
  if ( (result[4] & 0x10) == 0 )
  {
    v5[1] = *result;
    v5[2] = result[1];
    v5[3] = result[2];
    v5[0] = a2 + 20;
    __dmb(0xBu);
    v3 = (unsigned int *)(a2 + 56);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 + 1, v3) );
    __dmb(0xBu);
    result = (int *)(*(int (__fastcall **)(int *))(dword_637348 + 4))(v5);
  }
  v2[4] |= 8u;
  return result;
}

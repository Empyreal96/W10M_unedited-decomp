// MiGetAvailablePagesBelowPriority 
 
int __fastcall MiGetAvailablePagesBelowPriority(_DWORD *a1, int a2)
{
  int *v2; // r4
  int v3; // r2
  unsigned int v4; // r1
  int v5; // t1

  v2 = a1 + 384;
  v3 = a1[320] + a1[288];
  v4 = (unsigned int)&a1[5 * a2 + 384];
  while ( (unsigned int)v2 < v4 )
  {
    v5 = *v2;
    v2 += 5;
    v3 += v5;
  }
  return v3;
}
